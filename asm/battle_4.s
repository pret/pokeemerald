	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text
    
    
	thumb_func_start atk00_attackcanceler
atk00_attackcanceler: @ 8045FFC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r0, =gBattleOutcome
	ldrb r0, [r0]
	cmp r0, 0
	beq _08046020
	ldr r1, =gFightStateTracker
	movs r0, 0xC
	strb r0, [r1]
	b _08046398
	.pool
_08046020:
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08046064
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 2
	ands r0, r1
	cmp r0, 0
	bne _08046064
	movs r0, 0x80
	lsls r0, 12
	orrs r1, r0
	str r1, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D8A4E
	b _08046396
	.pool
_08046064:
	bl sub_8041A6C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08046072
	b _08046398
_08046072:
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	str r2, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _0804608A
	b _08046398
_0804608A:
	ldr r4, =gBattleMons
	ldr r0, =gCurrMovePos
	ldrb r1, [r0]
	ldr r3, =gBankAttacker
	ldrb r2, [r3]
	movs r0, 0x58
	muls r2, r0
	adds r1, r2
	adds r0, r4, 0
	adds r0, 0x24
	adds r1, r0
	ldrb r0, [r1]
	ldr r5, =gHitMarker
	cmp r0, 0
	bne _08046108
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xA5
	beq _08046108
	ldr r0, [r5]
	ldr r1, =0x00800200
	ands r0, r1
	cmp r0, 0
	bne _08046108
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	bne _08046108
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB07A
	str r0, [r1]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	b _08046398
	.pool
_08046108:
	ldr r0, [r5]
	ldr r1, =0xff7fffff
	ands r0, r1
	str r0, [r5]
	movs r6, 0x80
	lsls r6, 18
	ands r0, r6
	cmp r0, 0
	bne _08046160
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r1, r4, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	bne _08046160
	bl sub_8045CBC
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _08046160
	cmp r2, 0x2
	bne _08046150
	ldr r0, [r5]
	orrs r0, r6
	str r0, [r5]
	b _08046398
	.pool
_08046150:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _08046398
	.pool
_08046160:
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 18
	orrs r0, r1
	str r0, [r2]
	ldr r2, =gProtectStructs
	ldr r1, =gBankTarget
	ldrb r3, [r1]
	lsls r0, r3, 4
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 27
	mov r8, r1
	mov r9, r2
	cmp r0, 0
	bge _080461E8
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x8]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080461E8
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r2, =0x00000115
	adds r1, r3, 0
	bl sub_803F480
	mov r0, r8
	ldrb r1, [r0]
	lsls r1, 4
	add r1, r9
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB194
	b _08046396
	.pool
_080461E8:
	movs r2, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r2, r0
	bge _0804622A
	ldr r6, =gProtectStructs
	ldr r1, =gBattleMoves
	mov r12, r1
	adds r5, r0, 0
	ldr r7, =gTurnOrder
_080461FC:
	adds r4, r2, r7
	ldrb r3, [r4]
	lsls r0, r3, 4
	adds r0, r6
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _08046224
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r1, [r0, 0x8]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08046224
	b _08046350
_08046224:
	adds r2, 0x1
	cmp r2, r5
	blt _080461FC
_0804622A:
	ldr r0, =gSpecialStatuses
	mov r1, r8
	ldrb r2, [r1]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r3, [r1]
	lsls r0, r3, 30
	cmp r0, 0
	bge _08046288
	movs r0, 0x3
	negs r0, r0
	ands r0, r3
	strb r0, [r1]
	ldr r4, =gLastUsedAbility
	movs r0, 0x1F
	strb r0, [r4]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB53E
	str r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	ldrb r1, [r4]
	bl RecordAbilityBattle
	b _08046398
	.pool
_08046288:
	lsls r0, r2, 4
	add r0, r9
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	bne _08046296
	b _08046390
_08046296:
	ldr r1, =gBattleMoves
	ldr r2, =gCurrentMove
	ldrh r3, [r2]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x2
	ands r0, r1
	adds r4, r2, 0
	cmp r0, 0
	beq _08046390
	cmp r3, 0xAE
	bne _080462D4
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x7
	beq _080462D4
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08046390
_080462D4:
	ldrh r0, [r4]
	bl sub_8052F48
	lsls r0, 24
	cmp r0, 0
	beq _080462FA
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	beq _08046390
_080462FA:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl CancelMultiTurnMoves
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gUnknown_02024250
	ldr r3, =gBankTarget
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	strh r2, [r0]
	ldr r1, =gUnknown_02024258
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r1
	strh r2, [r0]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x6]
	b _08046390
	.pool
_08046350:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r2, =0x00000121
	adds r1, r3, 0
	bl sub_803F480
	ldrb r1, [r4]
	lsls r1, 4
	adds r1, r6
	ldrb r2, [r1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, =gBattleScripting
	ldrb r0, [r4]
	strb r0, [r1, 0x17]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB1AC
	b _08046396
	.pool
_08046390:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
_08046396:
	str r0, [r1]
_08046398:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk00_attackcanceler

	thumb_func_start mcmd_jump_if_move_not_executed
mcmd_jump_if_move_not_executed: @ 80463AC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r6, r1, 16
	ldr r1, =gBattlescriptCurrInstr
	ldr r5, [r1]
	adds r4, r5, r0
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _0804640C
	ldr r1, =gUnknown_02024250
	ldr r3, =gBankTarget
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	strh r2, [r0]
	ldr r1, =gUnknown_02024258
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r1
	strh r2, [r0]
	ldrb r4, [r5, 0x1]
	ldrb r0, [r5, 0x2]
	lsls r0, 8
	orrs r4, r0
	ldrb r0, [r5, 0x3]
	lsls r0, 16
	orrs r4, r0
	ldrb r0, [r5, 0x4]
	lsls r0, 24
	orrs r4, r0
	b _08046426
	.pool
_0804640C:
	bl b_feature_update_destiny_bond
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	str r6, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _0804642A
_08046426:
	ldr r0, =gBattlescriptCurrInstr
	str r4, [r0]
_0804642A:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mcmd_jump_if_move_not_executed

	thumb_func_start atk40_jump_if_move_affected_by_protect
atk40_jump_if_move_affected_by_protect: @ 804643C
	push {lr}
	ldr r1, =gProtectStructs
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _0804649C
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x8]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804649C
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x5
	movs r1, 0
	bl mcmd_jump_if_move_not_executed
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x6]
	b _080464A4
	.pool
_0804649C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080464A4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk40_jump_if_move_affected_by_protect

	thumb_func_start sub_80464AC
sub_80464AC: @ 80464AC
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r4, 0
	ldr r1, =gProtectStructs
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _080464F8
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x8]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080464F8
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	movs r0, 0x7
	adds r1, r3, 0
	bl mcmd_jump_if_move_not_executed
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x6]
	movs r4, 0x1
_080464F8:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80464AC

	thumb_func_start sub_8046518
sub_8046518: @ 8046518
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r2, =gStatuses3
	ldr r3, =gBankTarget
	ldrb r4, [r3]
	lsls r0, r4, 2
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0x18
	ands r1, r0
	adds r6, r2, 0
	cmp r1, 0
	beq _0804654A
	ldr r1, =gDisableStructs
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldr r1, =gBankAttacker
	ldrb r0, [r0, 0x15]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08046634
_0804654A:
	ldr r0, =gHitMarker
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 9
	ands r1, r2
	adds r2, r0, 0
	cmp r1, 0
	bne _08046590
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08046590
_0804656A:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _08046634
	.pool
_08046590:
	ldr r0, [r2]
	ldr r1, =0xfffeffff
	ands r0, r1
	str r0, [r2]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	bne _080465B2
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0804656A
_080465B2:
	ldr r0, [r2]
	ldr r1, =0xfffdffff
	ands r0, r1
	str r0, [r2]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	bne _080465D2
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, 0
	bne _0804656A
_080465D2:
	ldr r0, [r2]
	ldr r1, =0xfffbffff
	ands r0, r1
	str r0, [r2]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r5, 1
	cmp r0, 0
	bne _08046622
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08046622
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08046622
	ldr r0, =gBattleMoves
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x98
	beq _08046634
_08046622:
	ldr r1, =gBattleMoves
	adds r0, r4, r5
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x11
	beq _08046634
	cmp r0, 0x4E
	bne _08046654
_08046634:
	movs r0, 0x7
	adds r1, r5, 0
	bl mcmd_jump_if_move_not_executed
	movs r0, 0x1
	b _08046656
	.pool
_08046654:
	movs r0, 0
_08046656:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8046518

	thumb_func_start atk01_accuracycheck
atk01_accuracycheck: @ 8046660
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gBattlescriptCurrInstr
	ldr r5, [r0]
	ldrb r6, [r5, 0x5]
	ldrb r1, [r5, 0x6]
	lsls r1, 8
	orrs r6, r1
	adds r1, r6, 0x2
	lsls r1, 16
	lsrs r1, 16
	adds r7, r0, 0
	cmp r1, 0x1
	bhi _0804671C
	ldr r2, =gStatuses3
	ldr r3, =gBankTarget
	ldrb r4, [r3]
	lsls r0, r4, 2
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0x18
	ands r1, r0
	cmp r1, 0
	beq _080466D0
	ldr r0, =0x0000ffff
	cmp r6, r0
	bne _080466D0
	ldr r1, =gDisableStructs
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldr r1, =gBankAttacker
	ldrb r0, [r0, 0x15]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080466D0
	adds r0, r5, 0x7
	str r0, [r7]
	b _080469D2
	.pool
_080466D0:
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	beq _08046700
	ldr r2, [r7]
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
	str r1, [r7]
	b _080469D2
	.pool
_08046700:
	movs r0, 0
	bl sub_80464AC
	lsls r0, 24
	cmp r0, 0
	beq _0804670E
	b _080469D2
_0804670E:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x7
	str r0, [r1]
	b _080469D2
	.pool
_0804671C:
	cmp r6, 0
	bne _08046724
	ldr r0, =gCurrentMove
	ldrh r6, [r0]
_08046724:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08046744
	movs r1, 0x3F
	mov r10, r1
	mov r2, r10
	ands r2, r0
	mov r10, r2
	b _08046752
	.pool
_08046744:
	ldr r1, =gBattleMoves
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	mov r10, r0
_08046752:
	adds r0, r6, 0
	bl sub_80464AC
	lsls r0, 24
	cmp r0, 0
	beq _08046760
	b _080469D2
_08046760:
	adds r0, r6, 0
	bl sub_8046518
	lsls r0, 24
	cmp r0, 0
	beq _0804676E
	b _080469D2
_0804676E:
	ldr r3, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	movs r2, 0x58
	adds r4, r0, 0
	muls r4, r2
	adds r0, r3, 0
	adds r0, 0x50
	adds r0, r4, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 22
	ands r0, r1
	cmp r0, 0
	beq _080467A8
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	ldrb r5, [r0, 0x1E]
	b _080467BE
	.pool
_080467A8:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	ldrb r0, [r0, 0x1E]
	adds r0, 0x6
	adds r1, r4, r3
	ldrb r1, [r1, 0x1F]
	subs r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
_080467BE:
	lsls r0, r5, 24
	cmp r0, 0
	bge _080467C6
	movs r5, 0
_080467C6:
	lsls r0, r5, 24
	asrs r0, 24
	cmp r0, 0xC
	ble _080467D0
	movs r5, 0xC
_080467D0:
	ldr r1, =gBattleMoves
	lsls r4, r6, 1
	adds r0, r4, r6
	lsls r0, 2
	adds r7, r0, r1
	ldrb r3, [r7, 0x3]
	mov r8, r3
	movs r0, 0
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp, 0x4]
	cmp r0, 0
	bne _08046822
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08046822
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08046822
	ldrb r0, [r7]
	cmp r0, 0x98
	bne _08046822
	movs r0, 0x32
	mov r8, r0
_08046822:
	ldr r1, =gAccuracyStageRatios
	lsls r0, r5, 24
	asrs r0, 22
	adds r0, r1
	ldrb r1, [r0]
	mov r4, r8
	muls r4, r1
	ldrb r1, [r0, 0x1]
	adds r0, r4, 0
	bl __divsi3
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r7, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	movs r5, 0x58
	muls r0, r5
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0xE
	bne _08046860
	lsls r0, r4, 6
	adds r0, r4
	lsls r0, 1
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r4, r0, 16
_08046860:
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
	bne _080468B8
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _080468B8
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	muls r0, r5
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _080468B8
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _080468B8
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r4, r0, 16
_080468B8:
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	mov r9, r2
	cmp r0, 0x37
	bne _080468E4
	mov r1, r10
	cmp r1, 0x8
	bhi _080468E4
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 4
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r4, r0, 16
_080468E4:
	ldr r2, =gBankTarget
	mov r8, r2
	ldrb r2, [r2]
	movs r7, 0x58
	adds r0, r2, 0
	muls r0, r7
	mov r3, r9
	adds r1, r0, r3
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _08046928
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r5, [r0, 0x7]
	ldrb r2, [r0, 0x1A]
	b _08046944
	.pool
_08046928:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r7
	add r0, r9
	ldrh r0, [r0, 0x2E]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r2, r0, 24
_08046944:
	ldr r0, =gUnknown_0202420F
	ldr r1, =gBankTarget
	ldrb r1, [r1]
	strb r1, [r0]
	cmp r5, 0x16
	bne _08046960
	movs r0, 0x64
	subs r0, r2
	muls r0, r4
	movs r1, 0x64
	bl __divsi3
	lsls r0, 16
	lsrs r4, r0, 16
_08046960:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, 0x1
	cmp r0, r4
	ble _080469CA
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080469C0
	ldr r1, =gBattleMoves
	ldr r2, [sp, 0x4]
	adds r0, r2, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x6]
	cmp r0, 0x8
	beq _080469A2
	cmp r0, 0x20
	bne _080469C0
_080469A2:
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	b _080469C4
	.pool
_080469C0:
	ldr r1, =gBattleCommunication
	movs r0, 0
_080469C4:
	strb r0, [r1, 0x6]
	bl b_wonderguard_and_levitate
_080469CA:
	movs r0, 0x7
	adds r1, r6, 0
	bl mcmd_jump_if_move_not_executed
_080469D2:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk01_accuracycheck

	thumb_func_start atk02_attackstring
atk02_attackstring: @ 80469E8
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r5, [r0]
	cmp r5, 0
	bne _08046A20
	ldr r4, =gHitMarker
	ldr r0, [r4]
	movs r1, 0xC0
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	bne _08046A14
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x4
	bl b_std_message
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 3
	orrs r0, r1
	str r0, [r4]
_08046A14:
	ldr r0, =gBattlescriptCurrInstr
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	ldr r0, =gBattleCommunication
	strb r5, [r0, 0x7]
_08046A20:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk02_attackstring

	thumb_func_start atk03_ppreduce
atk03_ppreduce: @ 8046A3C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r6, 0x1
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _08046A54
	b _08046BEE
_08046A54:
	ldr r1, =gSpecialStatuses
	ldr r2, =gBankAttacker
	ldrb r3, [r2]
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 26
	lsrs r4, r0, 31
	mov r9, r2
	cmp r4, 0
	bne _08046AF6
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x6]
	cmp r0, 0x20
	beq _08046AA6
	cmp r0, 0x20
	bgt _08046AA0
	cmp r0, 0x8
	beq _08046ABC
	b _08046AD6
	.pool
_08046AA0:
	cmp r0, 0x40
	beq _08046ABC
	b _08046AD6
_08046AA6:
	str r4, [sp]
	movs r0, 0x12
	adds r1, r3, 0
	movs r2, 0x2E
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0x1
	b _08046AF6
_08046ABC:
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	movs r2, 0x2E
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0
	b _08046AF6
_08046AD6:
	ldr r1, =gBankTarget
	mov r2, r9
	ldrb r0, [r2]
	ldrb r7, [r1]
	cmp r0, r7
	beq _08046AF6
	ldr r2, =gBattleMons
	ldrb r1, [r1]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x2E
	bne _08046AF6
	adds r6, 0x1
_08046AF6:
	ldr r0, =gHitMarker
	ldr r4, [r0]
	movs r0, 0xA0
	lsls r0, 4
	ands r4, r0
	cmp r4, 0
	bne _08046BDC
	ldr r2, =gBattleMons
	ldr r3, =gCurrMovePos
	ldr r1, =gBankAttacker
	ldrb r5, [r1]
	movs r0, 0x58
	mov r8, r0
	mov r0, r8
	muls r0, r5
	ldrb r7, [r3]
	adds r0, r7
	movs r7, 0x24
	adds r7, r2
	mov r12, r7
	add r0, r12
	ldrb r0, [r0]
	mov r9, r1
	mov r10, r2
	adds r7, r3, 0
	cmp r0, 0
	beq _08046BDC
	ldr r0, =gProtectStructs
	lsls r1, r5, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x2]
	mov r1, r9
	ldrb r0, [r1]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	ldrb r1, [r7]
	adds r0, r1
	mov r1, r12
	adds r2, r0, r1
	ldrb r0, [r2]
	cmp r0, r6
	ble _08046B70
	subs r0, r6
	strb r0, [r2]
	b _08046B72
	.pool
_08046B70:
	strb r4, [r2]
_08046B72:
	mov r2, r9
	ldrb r3, [r2]
	movs r4, 0x58
	adds r0, r3, 0
	muls r0, r4
	mov r1, r10
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _08046BDC
	ldr r1, =gDisableStructs
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08046BDC
	ldr r0, =gActiveBank
	strb r3, [r0]
	ldrb r1, [r7]
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	mov r2, r9
	ldrb r0, [r2]
	muls r0, r4
	mov r2, r10
	adds r2, 0x24
	adds r0, r2
	ldrb r7, [r7]
	adds r0, r7
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl dp01_build_cmdbuf_x02_a_b_varargs
	mov r7, r9
	ldrb r0, [r7]
	bl dp01_battle_side_mark_buffer_for_execution
_08046BDC:
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffff7ff
	ands r0, r1
	str r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08046BEE:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk03_ppreduce

	thumb_func_start atk04_critcalc
atk04_critcalc: @ 8046C18
	push {r4-r7,lr}
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x2E]
	cmp r0, 0xAF
	bne _08046C48
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r6, [r0, 0x7]
	b _08046C50
	.pool
_08046C48:
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r6, r0, 24
_08046C50:
	ldr r1, =gUnknown_0202420F
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r4, =gBattleMons
	ldrb r1, [r3]
	movs r0, 0x58
	adds r7, r1, 0
	muls r7, r0
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r7, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 13
	ands r0, r1
	negs r0, r0
	asrs r5, r0, 31
	movs r0, 0x2
	ands r5, r0
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	mov r12, r3
	cmp r1, 0x2B
	bne _08046C90
	adds r5, 0x1
_08046C90:
	adds r0, r5, 0
	cmp r1, 0x4B
	bne _08046C98
	adds r0, 0x1
_08046C98:
	cmp r1, 0xC8
	bne _08046C9E
	adds r0, 0x1
_08046C9E:
	adds r2, r0, 0
	cmp r1, 0xD1
	bne _08046CA6
	adds r2, 0x1
_08046CA6:
	movs r1, 0
	cmp r6, 0x3F
	bne _08046CB6
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r0, 0x71
	bne _08046CB6
	movs r1, 0x1
_08046CB6:
	lsls r5, r1, 1
	movs r3, 0
	cmp r6, 0x42
	bne _08046CD0
	mov r0, r12
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0x53
	bne _08046CD0
	movs r3, 0x1
_08046CD0:
	lsls r1, r3, 1
	cmp r6, 0x29
	bne _08046CF0
	adds r0, r5, 0x1
	adds r0, r2, r0
	b _08046CF2
	.pool
_08046CF0:
	adds r0, r2, r5
_08046CF2:
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	adds r5, r0, 0
	cmp r5, 0x4
	bls _08046D00
	movs r5, 0x4
_08046D00:
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r4
	adds r0, 0x20
	ldrb r4, [r0]
	cmp r4, 0x4
	beq _08046D70
	cmp r4, 0x4B
	beq _08046D70
	ldr r1, =gStatuses3
	mov r2, r12
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	bne _08046D70
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x84
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	bne _08046D70
	bl Random
	ldr r2, =gCriticalHitChance
	lsls r1, r5, 1
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1]
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _08046D70
	ldr r1, =gCritMultiplier
	movs r0, 0x2
	b _08046D74
	.pool
_08046D70:
	ldr r1, =gCritMultiplier
	movs r0, 0x1
_08046D74:
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk04_critcalc

	thumb_func_start atk05_damagecalc1
atk05_damagecalc1: @ 8046D8C
	push {r4-r7,lr}
	sub sp, 0x10
	ldr r4, =gSideAffecting
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	bl GetBankIdentity
	movs r1, 0x1
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r3, [r1]
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	movs r4, 0x58
	muls r0, r4
	ldr r2, =gBattleMons
	adds r0, r2
	ldrb r1, [r5]
	muls r1, r4
	adds r1, r2
	ldr r7, =gCurrentMove
	ldrh r2, [r7]
	ldr r4, =gDynamicBasePower
	ldrh r4, [r4]
	str r4, [sp]
	ldr r4, =gBattleStruct
	ldr r4, [r4]
	ldrb r4, [r4, 0x13]
	str r4, [sp, 0x4]
	ldrb r4, [r6]
	str r4, [sp, 0x8]
	ldrb r4, [r5]
	str r4, [sp, 0xC]
	bl CalculateBaseDamage
	ldr r4, =gBattleMoveDamage
	ldr r1, =gCritMultiplier
	ldrb r1, [r1]
	muls r1, r0
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0xE]
	adds r3, r1, 0
	muls r3, r0
	str r3, [r4]
	ldr r1, =gStatuses3
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _08046E10
	ldr r2, =gBattleMoves
	ldrh r1, [r7]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	cmp r0, 0xD
	bne _08046E10
	lsls r0, r3, 1
	str r0, [r4]
_08046E10:
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 28
	cmp r0, 0
	bge _08046E32
	ldr r4, =gBattleMoveDamage
	ldr r1, [r4]
	lsls r0, r1, 4
	subs r0, r1
	movs r1, 0xA
	bl __divsi3
	str r0, [r4]
_08046E32:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk05_damagecalc1

	thumb_func_start AI_CalcDmg
AI_CalcDmg: @ 8046E7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	adds r5, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r5, 24
	lsrs r5, 24
	ldr r4, =gSideAffecting
	adds r0, r5, 0
	bl GetBankIdentity
	movs r1, 0x1
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r3, [r1]
	movs r1, 0x58
	adds r0, r7, 0
	muls r0, r1
	ldr r2, =gBattleMons
	adds r0, r2
	muls r1, r5
	adds r1, r2
	ldr r2, =gCurrentMove
	mov r8, r2
	ldrh r2, [r2]
	ldr r6, =gDynamicBasePower
	ldrh r4, [r6]
	str r4, [sp]
	ldr r4, =gBattleStruct
	ldr r4, [r4]
	ldrb r4, [r4, 0x13]
	str r4, [sp, 0x4]
	str r7, [sp, 0x8]
	str r5, [sp, 0xC]
	bl CalculateBaseDamage
	ldr r4, =gBattleMoveDamage
	movs r1, 0
	strh r1, [r6]
	ldr r1, =gCritMultiplier
	ldrb r1, [r1]
	muls r1, r0
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0xE]
	adds r3, r1, 0
	muls r3, r0
	str r3, [r4]
	ldr r1, =gStatuses3
	lsls r0, r7, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 2
	ands r0, r1
	cmp r0, 0
	beq _08046F0A
	ldr r2, =gBattleMoves
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	cmp r0, 0xD
	bne _08046F0A
	lsls r0, r3, 1
	str r0, [r4]
_08046F0A:
	ldr r0, =gProtectStructs
	lsls r1, r7, 4
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 28
	cmp r0, 0
	bge _08046F28
	ldr r4, =gBattleMoveDamage
	ldr r1, [r4]
	lsls r0, r1, 4
	subs r0, r1
	movs r1, 0xA
	bl __divsi3
	str r0, [r4]
_08046F28:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AI_CalcDmg

	thumb_func_start battle_attack_damage_modulate_by_effectivity
battle_attack_damage_modulate_by_effectivity: @ 8046F60
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gBattleMoveDamage
	ldr r0, [r5]
	muls r0, r4
	movs r1, 0xA
	bl __divsi3
	str r0, [r5]
	cmp r0, 0
	bne _08046F80
	cmp r4, 0
	beq _08046F80
	movs r0, 0x1
	str r0, [r5]
_08046F80:
	cmp r4, 0x5
	beq _08046FB0
	cmp r4, 0x5
	bgt _08046F94
	cmp r4, 0
	beq _08046F9A
	b _08047032
	.pool
_08046F94:
	cmp r4, 0x14
	beq _08046FF0
	b _08047032
_08046F9A:
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	movs r1, 0xFB
	ands r0, r1
	movs r1, 0xFD
	ands r0, r1
	b _08047030
	.pool
_08046FB0:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08047032
	ldr r2, =gBattleMoveFlags
	ldrb r1, [r2]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _08047032
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08046FEC
	movs r0, 0xFD
	ands r0, r1
	b _08047030
	.pool
_08046FEC:
	movs r0, 0x4
	b _0804702E
_08046FF0:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08047032
	ldr r2, =gBattleMoveFlags
	ldrb r1, [r2]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _08047032
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0804702C
	movs r0, 0xFB
	ands r0, r1
	b _08047030
	.pool
_0804702C:
	movs r0, 0x2
_0804702E:
	orrs r0, r1
_08047030:
	strb r0, [r2]
_08047032:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end battle_attack_damage_modulate_by_effectivity

	thumb_func_start atk06_typecalc
atk06_typecalc: @ 8047038
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r3, 0
	ldr r1, =gCurrentMove
	ldrh r0, [r1]
	cmp r0, 0xA5
	bne _0804704C
	b _08047260
_0804704C:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08047068
	movs r1, 0x3F
	mov r8, r1
	ands r1, r0
	mov r8, r1
	b _08047078
	.pool
_08047068:
	ldr r2, =gBattleMoves
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	mov r8, r0
_08047078:
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	adds r5, r2, 0
	cmp r0, r8
	beq _0804709A
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, r8
	bne _080470B0
_0804709A:
	ldr r4, =gBattleMoveDamage
	ldr r1, [r4]
	lsls r0, r1, 4
	subs r0, r1
	str r0, [r4]
	movs r1, 0xA
	str r3, [sp, 0x4]
	bl __divsi3
	str r0, [r4]
	ldr r3, [sp, 0x4]
_080470B0:
	ldr r2, =gBankTarget
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	adds r0, r5
	adds r0, 0x20
	ldrb r0, [r0]
	adds r4, r2, 0
	cmp r0, 0x1A
	bne _08047128
	mov r1, r8
	cmp r1, 0x4
	bne _08047128
	ldr r3, =gLastUsedAbility
	strb r0, [r3]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x9
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gUnknown_02024250
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	strh r2, [r0]
	ldr r1, =gUnknown_02024258
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	strh r2, [r0]
	ldr r0, =gBattleCommunication
	mov r1, r8
	strb r1, [r0, 0x6]
	ldrb r0, [r4]
	ldrb r1, [r3]
	bl RecordAbilityBattle
	b _080471C4
	.pool
_08047128:
	ldr r1, =gUnknown_0831ACE8
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r2, r1, 0
	b _080471A4
	.pool
_08047138:
	adds r3, 0x3
	b _080471A0
_0804713C:
	ldr r5, =gUnknown_0831ACE8
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, r8
	bne _08047198
	adds r1, r3, 0x1
	adds r1, r5
	ldr r2, =gBattleMons
	ldr r7, =gBankTarget
	ldrb r0, [r7]
	movs r6, 0x58
	muls r0, r6
	adds r0, r2
	adds r0, 0x21
	ldrb r4, [r1]
	ldrb r0, [r0]
	cmp r4, r0
	bne _08047172
	adds r0, r3, 0x2
	adds r0, r5
	ldrb r0, [r0]
	str r2, [sp]
	str r3, [sp, 0x4]
	bl battle_attack_damage_modulate_by_effectivity
	ldr r3, [sp, 0x4]
	ldr r2, [sp]
_08047172:
	ldrb r0, [r7]
	muls r0, r6
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0x22
	ldrb r1, [r1]
	cmp r4, r1
	bne _08047198
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, r4
	beq _08047198
	adds r0, r3, 0x2
	adds r0, r5
	ldrb r0, [r0]
	str r3, [sp, 0x4]
	bl battle_attack_damage_modulate_by_effectivity
	ldr r3, [sp, 0x4]
_08047198:
	adds r3, 0x3
	ldr r5, =gBattleMons
	ldr r4, =gBankTarget
	ldr r2, =gUnknown_0831ACE8
_080471A0:
	adds r0, r3, r2
	ldrb r0, [r0]
_080471A4:
	cmp r0, 0xFF
	beq _080471C4
	cmp r0, 0xFE
	bne _0804713C
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r1, r5, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 22
	ands r0, r1
	cmp r0, 0
	beq _08047138
_080471C4:
	ldr r2, =gBattleMons
	ldr r5, =gBankTarget
	ldrb r1, [r5]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r6, [r0]
	cmp r6, 0x19
	bne _08047242
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r7, =gCurrentMove
	ldrh r1, [r7]
	bl move_weather_interaction
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08047242
	ldr r1, =gBattleMoveFlags
	mov r8, r1
	ldrb r4, [r1]
	ands r0, r4
	cmp r0, 0
	beq _08047200
	movs r0, 0x6
	ands r0, r4
	cmp r0, 0x6
	bne _08047242
_08047200:
	ldr r2, =gBattleMoves
	ldrh r1, [r7]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08047242
	ldr r3, =gLastUsedAbility
	strb r6, [r3]
	movs r0, 0x1
	orrs r0, r4
	mov r1, r8
	strb r0, [r1]
	ldr r1, =gUnknown_02024250
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	movs r2, 0
	strh r2, [r0]
	ldr r1, =gUnknown_02024258
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	strh r2, [r0]
	ldr r1, =gBattleCommunication
	movs r0, 0x3
	strb r0, [r1, 0x6]
	ldrb r0, [r5]
	ldrb r1, [r3]
	bl RecordAbilityBattle
_08047242:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08047260
	ldr r2, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r2
	ldrb r0, [r1, 0x1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1, 0x1]
_08047260:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk06_typecalc

	thumb_func_start b_wonderguard_and_levitate
b_wonderguard_and_levitate: @ 80472A8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r6, 0
	movs r5, 0
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	mov r9, r0
	cmp r1, 0xA5
	bne _080472C0
	b _08047508
_080472C0:
	ldr r2, =gBattleMoves
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _080472D2
	b _08047508
_080472D2:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _080472F4
	movs r1, 0x3F
	mov r12, r1
	mov r2, r12
	ands r2, r0
	mov r12, r2
	b _080472F8
	.pool
_080472F4:
	ldrb r1, [r1, 0x2]
	mov r12, r1
_080472F8:
	ldr r2, =gBattleMons
	ldr r3, =gBankTarget
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r1, [r0]
	adds r7, r2, 0
	mov r8, r3
	cmp r1, 0x1A
	bne _0804733C
	mov r0, r12
	cmp r0, 0x4
	bne _0804733C
	ldr r0, =gLastUsedAbility
	strb r1, [r0]
	ldr r0, =gBattleCommunication
	mov r1, r12
	strb r1, [r0, 0x6]
	ldrb r0, [r3]
	movs r1, 0x1A
	bl RecordAbilityBattle
	b _08047508
	.pool
_0804733C:
	ldr r1, =gUnknown_0831ACE8
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r4, r1, 0
	b _0804748E
	.pool
_0804734C:
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, r12
	beq _08047356
	b _08047488
_08047356:
	adds r2, r5, 0x1
	adds r3, r2, r4
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7
	adds r0, 0x21
	ldrb r1, [r3]
	adds r3, r2, 0
	ldrb r0, [r0]
	cmp r1, r0
	bne _08047396
	adds r0, r5, 0x2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _08047396
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	lsls r2, 4
	adds r2, r1
	ldrb r0, [r2, 0x1]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x1]
_08047396:
	adds r2, r3, r4
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7
	adds r1, r0, 0
	adds r1, 0x22
	ldrb r2, [r2]
	ldrb r1, [r1]
	cmp r2, r1
	bne _080473DC
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, r2
	beq _080473DC
	adds r0, r5, 0x2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080473DC
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	lsls r2, 4
	adds r2, r1
	ldrb r0, [r2, 0x1]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x1]
_080473DC:
	adds r2, r3, r4
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7
	adds r0, 0x21
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08047400
	adds r0, r5, 0x2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x14
	bne _08047400
	movs r0, 0x1
	orrs r6, r0
_08047400:
	adds r2, r3, r4
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7
	adds r1, r0, 0
	adds r1, 0x22
	ldrb r2, [r2]
	ldrb r1, [r1]
	cmp r2, r1
	bne _0804742E
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, r2
	beq _0804742E
	adds r0, r5, 0x2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x14
	bne _0804742E
	movs r0, 0x1
	orrs r6, r0
_0804742E:
	adds r2, r3, r4
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7
	adds r0, 0x21
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08047456
	adds r0, r5, 0x2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _08047456
	movs r0, 0x2
	orrs r6, r0
	lsls r0, r6, 24
	lsrs r6, r0, 24
_08047456:
	adds r2, r3, r4
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7
	adds r1, r0, 0
	adds r1, 0x22
	ldrb r2, [r2]
	ldrb r1, [r1]
	cmp r2, r1
	bne _08047488
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, r2
	beq _08047488
	adds r0, r5, 0x2
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _08047488
	movs r0, 0x2
	orrs r6, r0
	lsls r0, r6, 24
	lsrs r6, r0, 24
_08047488:
	adds r5, 0x3
	adds r0, r5, r4
	ldrb r0, [r0]
_0804748E:
	cmp r0, 0xFF
	beq _080474B2
	cmp r0, 0xFE
	beq _08047498
	b _0804734C
_08047498:
	mov r2, r8
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	adds r1, r7, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 22
	ands r0, r1
	cmp r0, 0
	beq _08047488
_080474B2:
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7
	adds r0, 0x20
	ldrb r4, [r0]
	cmp r4, 0x19
	bne _08047508
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	mov r2, r9
	ldrh r1, [r2]
	bl move_weather_interaction
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08047508
	movs r0, 0x3
	ands r6, r0
	cmp r6, 0x1
	beq _08047508
	ldr r2, =gBattleMoves
	mov r0, r9
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _08047508
	ldr r0, =gLastUsedAbility
	strb r4, [r0]
	ldr r1, =gBattleCommunication
	movs r0, 0x3
	strb r0, [r1, 0x6]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x19
	bl RecordAbilityBattle
_08047508:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_wonderguard_and_levitate

	thumb_func_start b_attack_effectivity_adapt
b_attack_effectivity_adapt: @ 804752C
	push {r4-r7,lr}
	adds r6, r2, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	ldr r7, =gBattleMoveDamage
	ldr r0, [r7]
	muls r0, r4
	movs r1, 0xA
	bl __divsi3
	str r0, [r7]
	cmp r0, 0
	bne _08047552
	cmp r4, 0
	beq _08047552
	movs r0, 0x1
	str r0, [r7]
_08047552:
	cmp r4, 0x5
	beq _0804757A
	cmp r4, 0x5
	bgt _08047564
	cmp r4, 0
	beq _0804756A
	b _080475DE
	.pool
_08047564:
	cmp r4, 0x14
	beq _080475AC
	b _080475DE
_0804756A:
	ldrb r0, [r6]
	movs r1, 0x8
	orrs r0, r1
	movs r1, 0xFB
	ands r0, r1
	movs r1, 0xFD
	ands r0, r1
	b _080475DC
_0804757A:
	ldr r0, =gBattleMoves
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _080475DE
	ldrb r1, [r6]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _080475DE
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080475A8
	movs r0, 0xFD
	ands r0, r1
	b _080475DC
	.pool
_080475A8:
	movs r0, 0x4
	b _080475DA
_080475AC:
	ldr r0, =gBattleMoves
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _080475DE
	ldrb r1, [r6]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _080475DE
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080475D8
	movs r0, 0xFB
	ands r0, r1
	b _080475DC
	.pool
_080475D8:
	movs r0, 0x2
_080475DA:
	orrs r0, r1
_080475DC:
	strb r0, [r6]
_080475DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end b_attack_effectivity_adapt

	thumb_func_start TypeCalc
TypeCalc: @ 80475E4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x4]
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	movs r0, 0
	mov r8, r0
	mov r0, sp
	mov r1, r8
	strb r1, [r0]
	mov r2, r10
	cmp r2, 0xA5
	bne _08047616
	movs r0, 0
	b _0804779E
_08047616:
	ldr r1, =gBattleMoves
	mov r3, r10
	lsls r2, r3, 1
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x2]
	str r0, [sp, 0x8]
	ldr r1, =gBattleMons
	movs r0, 0x58
	ldr r3, [sp, 0x4]
	muls r0, r3
	adds r3, r0, r1
	adds r0, r3, 0
	adds r0, 0x21
	ldrb r0, [r0]
	str r2, [sp, 0xC]
	adds r5, r1, 0
	ldr r1, [sp, 0x8]
	cmp r0, r1
	beq _0804764A
	adds r0, r3, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, r1
	bne _0804765C
_0804764A:
	ldr r4, =gBattleMoveDamage
	ldr r1, [r4]
	lsls r0, r1, 4
	subs r0, r1
	str r0, [r4]
	movs r1, 0xA
	bl __divsi3
	str r0, [r4]
_0804765C:
	movs r0, 0x58
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	adds r0, r5
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1A
	bne _08047690
	ldr r3, [sp, 0x8]
	cmp r3, 0x4
	bne _08047690
	movs r1, 0x9
	mov r0, sp
	ldrb r0, [r0]
	orrs r0, r1
	mov r1, sp
	strb r0, [r1]
	b _08047740
	.pool
_08047690:
	ldr r1, =gUnknown_0831ACE8
	mov r2, r8
	adds r0, r2, r1
	ldrb r0, [r0]
	adds r2, r1, 0
	cmp r0, 0xFF
	beq _08047740
	cmp r0, 0xFE
	bne _080476B6
	movs r0, 0x58
	mov r3, r9
	muls r3, r0
	adds r0, r3, 0
	b _0804772E
	.pool
_080476B0:
	movs r0, 0x3
	add r8, r0
	b _08047718
_080476B6:
	ldr r7, =gUnknown_0831ACE8
	mov r1, r8
	adds r0, r1, r7
	ldrb r0, [r0]
	ldr r2, [sp, 0x8]
	cmp r0, r2
	bne _08047710
	adds r1, 0x1
	adds r1, r7
	ldr r2, =gBattleMons
	movs r0, 0x58
	mov r3, r9
	muls r3, r0
	adds r0, r3, 0
	adds r5, r0, r2
	adds r6, r5, 0
	adds r6, 0x21
	ldrb r4, [r1]
	ldrb r0, [r6]
	cmp r4, r0
	bne _080476F0
	mov r0, r8
	adds r0, 0x2
	adds r0, r7
	ldrb r0, [r0]
	mov r1, r10
	mov r2, sp
	bl b_attack_effectivity_adapt
_080476F0:
	adds r0, r5, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r4, r0
	bne _08047710
	ldrb r0, [r6]
	cmp r0, r4
	beq _08047710
	mov r0, r8
	adds r0, 0x2
	adds r0, r7
	ldrb r0, [r0]
	mov r1, r10
	mov r2, sp
	bl b_attack_effectivity_adapt
_08047710:
	movs r1, 0x3
	add r8, r1
	ldr r5, =gBattleMons
	ldr r2, =gUnknown_0831ACE8
_08047718:
	mov r3, r8
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _08047740
	cmp r0, 0xFE
	bne _080476B6
	movs r0, 0x58
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
_0804772E:
	adds r1, r5, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 22
	ands r0, r1
	cmp r0, 0
	beq _080476B0
_08047740:
	movs r0, 0x58
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	adds r0, r5
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x19
	bne _0804779A
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0804779A
	ldr r0, [sp, 0x4]
	mov r1, r10
	bl move_weather_interaction
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bne _0804779A
	mov r0, sp
	ldrb r3, [r0]
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _08047782
	movs r0, 0x6
	ands r0, r3
	cmp r0, 0x6
	bne _0804779A
_08047782:
	ldr r0, =gBattleMoves
	ldr r1, [sp, 0xC]
	add r1, r10
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _0804779A
	mov r0, sp
	movs r1, 0x1
	orrs r1, r3
	strb r1, [r0]
_0804779A:
	mov r0, sp
	ldrb r0, [r0]
_0804779E:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end TypeCalc

	thumb_func_start ai_rate_move
ai_rate_move: @ 80477BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x4]
	movs r7, 0
	mov r0, sp
	strb r7, [r0]
	ldr r2, =gBaseStats
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x6]
	mov r9, r1
	ldrb r0, [r0, 0x7]
	mov r8, r0
	cmp r6, 0xA5
	bne _080477FC
	movs r0, 0
	b _080478A0
	.pool
_080477FC:
	ldr r2, =gBattleMoves
	lsls r1, r6, 1
	adds r0, r1, r6
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	mov r10, r0
	str r1, [sp, 0x8]
	ldr r3, [sp, 0x4]
	cmp r3, 0x1A
	bne _08047824
	cmp r0, 0x4
	bne _08047824
	movs r1, 0x9
	mov r0, sp
	strb r1, [r0]
	b _0804786A
	.pool
_08047824:
	ldr r0, =gUnknown_0831ACE8
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0804786A
	adds r4, r1, 0
_08047830:
	ldrb r0, [r4]
	cmp r0, 0xFE
	beq _0804785C
	cmp r0, r10
	bne _0804785C
	ldrb r5, [r4, 0x1]
	cmp r5, r9
	bne _0804784A
	ldrb r0, [r4, 0x2]
	adds r1, r6, 0
	mov r2, sp
	bl b_attack_effectivity_adapt
_0804784A:
	cmp r5, r8
	bne _0804785C
	cmp r9, r8
	beq _0804785C
	ldrb r0, [r4, 0x2]
	adds r1, r6, 0
	mov r2, sp
	bl b_attack_effectivity_adapt
_0804785C:
	adds r4, 0x3
	adds r7, 0x3
	ldr r1, =gUnknown_0831ACE8
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08047830
_0804786A:
	ldr r3, [sp, 0x4]
	cmp r3, 0x19
	bne _0804789C
	mov r0, sp
	ldrb r2, [r0]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _08047884
	movs r0, 0x6
	ands r0, r2
	cmp r0, 0x6
	bne _0804789C
_08047884:
	ldr r0, =gBattleMoves
	ldr r3, [sp, 0x8]
	adds r1, r3, r6
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	beq _0804789C
	mov r0, sp
	movs r1, 0x8
	orrs r1, r2
	strb r1, [r0]
_0804789C:
	mov r0, sp
	ldrb r0, [r0]
_080478A0:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ai_rate_move

	thumb_func_start sub_80478B8
sub_80478B8: @ 80478B8
	push {r4,lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	ands r0, r1
	movs r1, 0x64
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r4, =gBattleMoveDamage
	ldr r0, [r4]
	cmp r0, 0
	beq _080478EA
	muls r0, r1
	str r0, [r4]
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _080478EA
	movs r0, 0x1
	str r0, [r4]
_080478EA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80478B8

	thumb_func_start atk07_dmg_adjustment
atk07_dmg_adjustment: @ 80478F4
	push {r4-r7,lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	ands r0, r1
	movs r1, 0x64
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r4, =gBattleMoveDamage
	ldr r0, [r4]
	cmp r0, 0
	beq _08047926
	muls r0, r1
	str r0, [r4]
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08047926
	movs r0, 0x1
	str r0, [r4]
_08047926:
	ldr r7, =gBattleMons
	ldr r6, =gBankTarget
	ldrb r2, [r6]
	movs r5, 0x58
	adds r0, r2, 0
	muls r0, r5
	adds r1, r0, r7
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0804795C
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x7]
	ldrb r6, [r0, 0x1A]
	b _08047976
	.pool
_0804795C:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r7
	ldrh r0, [r0, 0x2E]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r6, r0, 24
_08047976:
	ldr r1, =gUnknown_0202420F
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	strb r0, [r1]
	cmp r4, 0x27
	bne _080479B4
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r6
	bcs _080479B4
	ldrb r0, [r5]
	movs r1, 0x27
	bl RecordItemEffectBattle
	ldr r2, =gSpecialStatuses
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
_080479B4:
	ldr r2, =gBattleMons
	ldr r3, =gBankTarget
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, r2, 0
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r1, r0
	adds r5, r2, 0
	cmp r1, 0
	bne _08047A84
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x65
	beq _08047A06
	ldr r0, =gProtectStructs
	lsls r1, r4, 4
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _08047A06
	ldr r0, =gSpecialStatuses
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	beq _08047A84
_08047A06:
	ldrb r0, [r3]
	movs r4, 0x58
	muls r0, r4
	adds r0, r5
	ldrh r1, [r0, 0x28]
	ldr r2, =gBattleMoveDamage
	ldr r0, [r2]
	cmp r1, r0
	bgt _08047A84
	subs r0, r1, 0x1
	str r0, [r2]
	ldr r1, =gProtectStructs
	ldrb r3, [r3]
	lsls r0, r3, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	cmp r0, 0
	bge _08047A5C
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _08047A84
	.pool
_08047A5C:
	ldr r0, =gSpecialStatuses
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	beq _08047A84
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gLastUsedItem
	adds r0, r3, 0
	muls r0, r4
	adds r0, r5
	ldrh r0, [r0, 0x2E]
	strh r0, [r1]
_08047A84:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk07_dmg_adjustment

	thumb_func_start atk08_dmg_adjustment2
atk08_dmg_adjustment2: @ 8047AA4
	push {r4-r7,lr}
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xF
	ands r0, r1
	movs r1, 0x64
	subs r1, r0
	lsls r1, 16
	lsrs r1, 16
	ldr r4, =gBattleMoveDamage
	ldr r0, [r4]
	cmp r0, 0
	beq _08047AD6
	muls r0, r1
	str r0, [r4]
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08047AD6
	movs r0, 0x1
	str r0, [r4]
_08047AD6:
	ldr r7, =gBattleMons
	ldr r6, =gBankTarget
	ldrb r2, [r6]
	movs r5, 0x58
	adds r0, r2, 0
	muls r0, r5
	adds r1, r0, r7
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _08047B0C
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x7]
	ldrb r6, [r0, 0x1A]
	b _08047B26
	.pool
_08047B0C:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r7
	ldrh r0, [r0, 0x2E]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r6, r0, 24
_08047B26:
	ldr r1, =gUnknown_0202420F
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	strb r0, [r1]
	cmp r4, 0x27
	bne _08047B64
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r6
	bcs _08047B64
	ldrb r0, [r5]
	movs r1, 0x27
	bl RecordItemEffectBattle
	ldr r2, =gSpecialStatuses
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
_08047B64:
	ldr r4, =gBattleMons
	ldr r6, =gBankTarget
	ldrb r2, [r6]
	movs r7, 0x58
	adds r3, r2, 0
	muls r3, r7
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne _08047C10
	ldr r5, =gProtectStructs
	lsls r0, r2, 4
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 30
	cmp r0, 0
	blt _08047BA2
	ldr r0, =gSpecialStatuses
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	beq _08047C10
_08047BA2:
	adds r0, r3, r4
	ldrh r1, [r0, 0x28]
	ldr r2, =gBattleMoveDamage
	ldr r0, [r2]
	cmp r1, r0
	bgt _08047C10
	subs r0, r1, 0x1
	str r0, [r2]
	ldrb r3, [r6]
	lsls r0, r3, 4
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 30
	cmp r0, 0
	bge _08047BE8
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _08047C10
	.pool
_08047BE8:
	ldr r0, =gSpecialStatuses
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	beq _08047C10
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gLastUsedItem
	adds r0, r3, 0
	muls r0, r7
	adds r0, r4
	ldrh r0, [r0, 0x2E]
	strh r0, [r1]
_08047C10:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk08_dmg_adjustment2

	thumb_func_start atk09_attackanimation
atk09_attackanimation: @ 8047C30
	push {r4-r7,lr}
	sub sp, 0x10
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _08047C3E
	b _08047DB6
_08047C3E:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	ldr r5, =gCurrentMove
	cmp r0, 0
	beq _08047C8C
	ldrh r0, [r5]
	cmp r0, 0x90
	beq _08047C8C
	cmp r0, 0xA4
	beq _08047C8C
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DABB9
	str r0, [r4]
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x18]
	adds r0, 0x1
	strb r0, [r1, 0x18]
	ldrb r0, [r1, 0x19]
	adds r0, 0x1
	strb r0, [r1, 0x19]
	b _08047DB6
	.pool
_08047C8C:
	ldr r2, =gBattleMoves
	ldrh r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x6]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08047CB2
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08047CB2
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08047CBA
_08047CB2:
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x19]
	cmp r0, 0
	bne _08047D88
_08047CBA:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _08047DA8
	ldr r1, =gActiveBank
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	adds r4, r1, 0
	muls r4, r0
	adds r0, r2, 0
	adds r0, 0x50
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r1, r0
	adds r7, r3, 0
	mov r12, r2
	cmp r1, 0
	beq _08047D18
	ldr r0, =gUnknown_02024212
	ldrb r6, [r0]
	b _08047D42
	.pool
_08047D18:
	ldr r3, =gUnknown_02024212
	ldrb r0, [r3]
	cmp r0, 0x1
	bls _08047D40
	mov r1, r12
	adds r0, r4, r1
	ldrh r2, [r0, 0x28]
	ldr r0, =gBattleMoveDamage
	ldr r1, [r0]
	movs r6, 0x1
	adds r4, r0, 0
	cmp r2, r1
	ble _08047D44
	ldrb r6, [r3]
	b _08047D44
	.pool
_08047D40:
	ldrb r6, [r3]
_08047D42:
	ldr r4, =gBattleMoveDamage
_08047D44:
	ldrh r1, [r5]
	ldr r5, =gBattleScripting
	ldrb r2, [r5, 0x18]
	ldr r0, =gBattleMovePower
	ldrh r3, [r0]
	ldr r0, [r4]
	str r0, [sp]
	ldrb r4, [r7]
	movs r0, 0x58
	muls r0, r4
	add r0, r12
	adds r0, 0x2B
	ldrb r0, [r0]
	str r0, [sp, 0x4]
	ldrb r4, [r7]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r4, =gDisableStructs
	adds r0, r4
	str r0, [sp, 0x8]
	str r6, [sp, 0xC]
	movs r0, 0
	bl dp01_build_cmdbuf_x0F_aa_b_cc_dddd_e_mlc_weather_00_x1Cbytes
	ldrb r0, [r5, 0x18]
	adds r0, 0x1
	strb r0, [r5, 0x18]
	ldrb r0, [r5, 0x19]
	adds r0, 0x1
	strb r0, [r5, 0x19]
	ldrb r0, [r7]
	bl dp01_battle_side_mark_buffer_for_execution
_08047D88:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	b _08047DB6
	.pool
_08047DA8:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DABB9
	str r0, [r4]
_08047DB6:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk09_attackanimation

	thumb_func_start atk0A_waitanimation
atk0A_waitanimation: @ 8047DC8
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _08047DDA
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08047DDA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk0A_waitanimation

	thumb_func_start atk0B_healthbarupdate
atk0B_healthbarupdate: @ 8047DE8
	push {r4,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _08047EAA
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _08047EA2
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r2, =gActiveBank
	strb r0, [r2]
	ldr r1, =gBattleMons
	ldrb r2, [r2]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08047E68
	ldr r0, =gDisableStructs
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	beq _08047E68
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	bne _08047E68
	movs r0, 0x80
	adds r1, r2, 0
	bl b_std_message
	b _08047EA2
	.pool
_08047E68:
	ldr r0, =gBattleMoveDamage
	ldr r0, [r0]
	ldr r1, =0x00002710
	cmp r0, r1
	bgt _08047E76
	lsls r0, 16
	lsrs r1, r0, 16
_08047E76:
	movs r0, 0
	bl dp01_build_cmdbuf_x18_0_aa_health_bar_update
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08047EA2
	ldr r0, =gBattleMoveDamage
	ldr r0, [r0]
	cmp r0, 0
	ble _08047EA2
	ldr r0, =gBattleResults
	ldrb r1, [r0, 0x5]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x5]
_08047EA2:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_08047EAA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk0B_healthbarupdate

	thumb_func_start atk0C_datahpupdate
atk0C_datahpupdate: @ 8047EC4
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _08047ED2
	b _080482A2
_08047ED2:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r1, [r0, 0x13]
	cmp r1, 0
	beq _08047EF4
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08047EF4
	movs r6, 0x3F
	ands r6, r1
	b _08047F04
	.pool
_08047EF4:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r6, [r0, 0x2]
_08047F04:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08047F12
	b _08048274
_08047F12:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r7, =gActiveBank
	strb r0, [r7]
	ldr r1, =gBattleMons
	ldrb r2, [r7]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08048028
	ldr r0, =gDisableStructs
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r4, r1, r0
	ldrb r1, [r4, 0xA]
	mov r12, r0
	cmp r1, 0
	beq _08048028
	ldr r0, =gHitMarker
	ldr r3, [r0]
	movs r0, 0x80
	lsls r0, 1
	ands r3, r0
	cmp r3, 0
	bne _08048028
	adds r5, r1, 0
	ldr r6, =gBattleMoveDamage
	ldr r4, [r6]
	cmp r5, r4
	blt _08047FBC
	ldr r0, =gSpecialStatuses
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	bne _08047F76
	str r4, [r1]
_08047F76:
	ldrb r0, [r7]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	add r1, r12
	ldr r2, [r6]
	ldrb r0, [r1, 0xA]
	subs r0, r2
	strb r0, [r1, 0xA]
	ldr r1, =gUnknown_020241F4
	ldr r0, [r6]
	str r0, [r1]
	b _08047FEC
	.pool
_08047FBC:
	ldr r0, =gSpecialStatuses
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	bne _08047FD0
	str r5, [r1]
_08047FD0:
	ldr r2, =gUnknown_020241F4
	ldrb r1, [r7]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r0, [r0, 0xA]
	str r0, [r2]
	ldrb r1, [r7]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	strb r3, [r0, 0xA]
_08047FEC:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r0, [r0, 0xA]
	cmp r0, 0
	beq _08048000
	b _0804829A
_08048000:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	bl b_movescr_stack_push_cursor
	ldr r0, =gUnknown_082DB6FB
	str r0, [r4]
	b _080482A2
	.pool
_08048028:
	ldr r0, =gHitMarker
	ldr r2, [r0]
	ldr r1, =0xfffffeff
	ands r2, r1
	str r2, [r0]
	ldr r1, =gBattleMoveDamage
	ldr r5, [r1]
	mov r12, r0
	adds r7, r1, 0
	cmp r5, 0
	bge _0804807C
	ldr r4, =gBattleMons
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	movs r3, 0x58
	adds r1, r0, 0
	muls r1, r3
	adds r1, r4
	ldrh r0, [r1, 0x28]
	subs r0, r5
	strh r0, [r1, 0x28]
	ldrb r0, [r2]
	muls r0, r3
	adds r1, r0, r4
	ldrh r3, [r1, 0x2C]
	ldrh r0, [r1, 0x28]
	adds r5, r2, 0
	cmp r0, r3
	bhi _08048064
	b _0804823A
_08048064:
	strh r3, [r1, 0x28]
	b _0804823A
	.pool
_0804807C:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _08048098
	movs r0, 0x21
	negs r0, r0
	ands r2, r0
	mov r0, r12
	str r2, [r0]
	ldr r5, =gActiveBank
	b _080480E0
	.pool
_08048098:
	ldr r0, =gUnknown_020241F8
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	adds r0, r5
	str r0, [r1]
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	adds r5, r2, 0
	cmp r0, 0
	bne _080480D4
	ldr r1, =gUnknown_02024288
	ldrb r0, [r5]
	adds r0, r1
	ldr r1, =gBankAttacker
	b _080480DC
	.pool
_080480D4:
	ldr r1, =gUnknown_02024288
	ldrb r0, [r5]
	adds r0, r1
	ldr r1, =gBankTarget
_080480DC:
	ldrb r1, [r1]
	strb r1, [r0]
_080480E0:
	ldr r4, =gBattleMons
	ldrb r0, [r5]
	movs r3, 0x58
	muls r0, r3
	adds r2, r0, r4
	ldrh r0, [r2, 0x28]
	ldr r1, [r7]
	cmp r0, r1
	ble _08048110
	subs r0, r1
	strh r0, [r2, 0x28]
	ldr r0, =gUnknown_020241F4
	str r1, [r0]
	adds r7, r0, 0
	b _08048120
	.pool
_08048110:
	ldr r2, =gUnknown_020241F4
	str r0, [r2]
	ldrb r0, [r5]
	muls r0, r3
	adds r0, r4
	movs r1, 0
	strh r1, [r0, 0x28]
	adds r7, r2, 0
_08048120:
	ldr r2, =gSpecialStatuses
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r1, r2, 0x4
	adds r3, r0, r1
	ldr r0, [r3]
	adds r4, r2, 0
	cmp r0, 0
	bne _08048148
	mov r1, r12
	ldr r0, [r1]
	movs r1, 0x80
	lsls r1, 13
	ands r0, r1
	cmp r0, 0
	bne _08048148
	ldr r0, [r7]
	str r0, [r3]
_08048148:
	cmp r6, 0x8
	bhi _080481D0
	mov r1, r12
	ldr r0, [r1]
	movs r1, 0x80
	lsls r1, 13
	ands r0, r1
	cmp r0, 0
	bne _080481CC
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xDC
	beq _080481CC
	ldr r3, =gProtectStructs
	ldrb r0, [r5]
	lsls r0, 4
	adds r1, r3, 0x4
	adds r0, r1
	ldr r2, [r7]
	str r2, [r0]
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x8
	adds r0, r1
	str r2, [r0]
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _080481AC
	ldrb r0, [r5]
	lsls r0, 4
	adds r0, r3
	ldr r2, =gBankAttacker
	b _080481B4
	.pool
_080481AC:
	ldrb r0, [r5]
	lsls r0, 4
	adds r0, r3
	ldr r2, =gBankTarget
_080481B4:
	ldrb r1, [r2]
	strb r1, [r0, 0xC]
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r2]
	strb r1, [r0, 0x10]
	b _0804823A
	.pool
_080481CC:
	cmp r6, 0x8
	bls _0804823A
_080481D0:
	mov r1, r12
	ldr r0, [r1]
	movs r1, 0x80
	lsls r1, 13
	ands r0, r1
	cmp r0, 0
	bne _0804823A
	ldr r3, =gProtectStructs
	ldrb r0, [r5]
	lsls r0, 4
	adds r1, r3, 0
	adds r1, 0x8
	adds r0, r1
	ldr r2, [r7]
	str r2, [r0]
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0xC
	adds r0, r1
	str r2, [r0]
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _08048220
	ldrb r0, [r5]
	lsls r0, 4
	adds r0, r3
	ldr r2, =gBankAttacker
	b _08048228
	.pool
_08048220:
	ldrb r0, [r5]
	lsls r0, 4
	adds r0, r3
	ldr r2, =gBankTarget
_08048228:
	ldrb r1, [r2]
	strb r1, [r0, 0xD]
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r2]
	strb r1, [r0, 0x11]
_0804823A:
	mov r1, r12
	ldr r0, [r1]
	ldr r1, =0xffefffff
	ands r0, r1
	mov r1, r12
	str r0, [r1]
	ldrb r1, [r5]
	movs r0, 0x58
	muls r0, r1
	ldr r1, =gBattleMons + 0x28
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2A
	movs r2, 0
	movs r3, 0x2
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804829A
	.pool
_08048274:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldr r2, =gSpecialStatuses
	ldrb r1, [r1]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, 0
	bne _0804829A
	ldr r0, =0x0000ffff
	str r0, [r1]
_0804829A:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_080482A2:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk0C_datahpupdate

	thumb_func_start atk0D_critmessage
atk0D_critmessage: @ 80482BC
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _080482F2
	ldr r0, =gCritMultiplier
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080482EA
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _080482EA
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0xD9
	bl b_std_message
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x7]
_080482EA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_080482F2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk0D_critmessage

	thumb_func_start atk0E_effectiveness_sound
atk0E_effectiveness_sound: @ 8048310
	push {r4,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _080483D0
	ldr r4, =gActiveBank
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, =gBattleMoveFlags
	ldrb r2, [r1]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _080483C8
	movs r0, 0xFE
	ands r0, r2
	cmp r0, 0x10
	beq _08048382
	cmp r0, 0x10
	bgt _0804835E
	cmp r0, 0x4
	beq _08048372
	cmp r0, 0x4
	bgt _08048358
	cmp r0, 0x2
	beq _0804836C
	b _08048382
	.pool
_08048358:
	cmp r0, 0x8
	beq _080483C8
	b _08048382
_0804835E:
	cmp r0, 0x40
	beq _08048382
	cmp r0, 0x40
	bgt _08048382
	cmp r0, 0x20
	beq _080483C8
	b _08048382
_0804836C:
	movs r0, 0
	movs r1, 0xE
	b _08048376
_08048372:
	movs r0, 0
	movs r1, 0xC
_08048376:
	bl dp01_build_cmdbuf_x2B_aa_0
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _080483C8
_08048382:
	ldrb r1, [r1]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08048392
	movs r0, 0
	movs r1, 0xE
	b _0804839E
_08048392:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080483B0
	movs r0, 0
	movs r1, 0xC
_0804839E:
	bl dp01_build_cmdbuf_x2B_aa_0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	b _080483C8
	.pool
_080483B0:
	movs r0, 0x28
	ands r0, r1
	cmp r0, 0
	bne _080483C8
	movs r0, 0
	movs r1, 0xD
	bl dp01_build_cmdbuf_x2B_aa_0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
_080483C8:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_080483D0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk0E_effectiveness_sound

	thumb_func_start atk0F_resultmessage
atk0F_resultmessage: @ 80483E0
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _080483EE
	b _08048580
_080483EE:
	ldr r1, =gBattleMoveFlags
	ldrb r2, [r1]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r2
	adds r6, r1, 0
	ldr r7, =gBattleCommunication
	cmp r0, 0
	beq _0804842C
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _0804840E
	ldrb r0, [r7, 0x6]
	cmp r0, 0x2
	bls _0804842C
_0804840E:
	ldr r1, =gUnknown_085CC834
	ldrb r0, [r7, 0x6]
	lsls r0, 1
	adds r0, r1
	ldrh r3, [r0]
	strb r4, [r7, 0x7]
	b _0804856A
	.pool
_0804842C:
	movs r0, 0x1
	strb r0, [r7, 0x7]
	ldrb r5, [r6]
	movs r0, 0xFE
	ands r0, r5
	cmp r0, 0x10
	beq _08048470
	cmp r0, 0x10
	bgt _08048452
	cmp r0, 0x4
	beq _0804846C
	cmp r0, 0x4
	bgt _0804844C
	cmp r0, 0x2
	beq _08048468
	b _080484B8
_0804844C:
	cmp r0, 0x8
	beq _080484C4
	b _080484B8
_08048452:
	cmp r0, 0x40
	beq _08048474
	cmp r0, 0x40
	bgt _08048462
	cmp r0, 0x20
	bne _08048460
	b _08048564
_08048460:
	b _080484B8
_08048462:
	cmp r0, 0x80
	beq _08048478
	b _080484B8
_08048468:
	movs r3, 0xDE
	b _0804856E
_0804846C:
	movs r3, 0xDD
	b _0804856E
_08048470:
	movs r3, 0xDA
	b _0804856E
_08048474:
	movs r3, 0x99
	b _0804856E
_08048478:
	ldr r4, =gLastUsedItem
	ldr r2, =gBattleMons
	ldr r3, =gBankTarget
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x2E]
	strh r0, [r4]
	ldr r1, =gUnknown_0202420F
	ldrb r0, [r3]
	strb r0, [r1]
	movs r0, 0x3F
	ands r0, r5
	strb r0, [r6]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB816
	b _0804857E
	.pool
_080484B8:
	adds r2, r6, 0
	ldrb r5, [r2]
	movs r0, 0x8
	ands r0, r5
	cmp r0, 0
	beq _080484C8
_080484C4:
	movs r3, 0x1B
	b _0804856E
_080484C8:
	movs r0, 0x10
	ands r0, r5
	cmp r0, 0
	beq _080484F0
	movs r0, 0xEF
	ands r0, r5
	movs r1, 0xFD
	ands r0, r1
	movs r1, 0xFB
	ands r0, r1
	strb r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB1CE
	b _0804857E
	.pool
_080484F0:
	movs r0, 0x40
	ands r0, r5
	cmp r0, 0
	beq _08048510
	movs r0, 0x3F
	ands r0, r5
	strb r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB1C7
	b _0804857E
	.pool
_08048510:
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	beq _08048558
	ldr r4, =gLastUsedItem
	ldr r2, =gBattleMons
	ldr r3, =gBankTarget
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x2E]
	strh r0, [r4]
	ldr r1, =gUnknown_0202420F
	ldrb r0, [r3]
	strb r0, [r1]
	movs r0, 0x3F
	ands r0, r5
	strb r0, [r6]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB816
	b _0804857E
	.pool
_08048558:
	movs r0, 0x20
	ands r0, r5
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08048568
_08048564:
	movs r3, 0xE5
	b _0804856E
_08048568:
	strb r0, [r7, 0x7]
_0804856A:
	cmp r3, 0
	beq _08048578
_0804856E:
	adds r0, r3, 0
	ldr r1, =gBankAttacker
	ldrb r1, [r1]
	bl b_std_message
_08048578:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
_0804857E:
	str r0, [r1]
_08048580:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk0F_resultmessage

	thumb_func_start atk10_printstring
atk10_printstring: @ 8048590
	push {r4,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _080485BA
	ldr r4, =gBattlescriptCurrInstr
	ldr r1, [r4]
	ldrb r0, [r1, 0x1]
	ldrb r1, [r1, 0x2]
	lsls r1, 8
	orrs r0, r1
	ldr r1, =gBankAttacker
	ldrb r1, [r1]
	bl b_std_message
	ldr r0, [r4]
	adds r0, 0x3
	str r0, [r4]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x7]
_080485BA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk10_printstring

	thumb_func_start atk11_printstring_playeronly
atk11_printstring_playeronly: @ 80485D0
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0
	bl dp01_build_cmdbuf_x11_TODO
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r4]
	adds r0, 0x3
	str r0, [r4]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x7]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk11_printstring_playeronly

	thumb_func_start atk12_waitmessage
atk12_waitmessage: @ 8048614
	push {r4-r6,lr}
	ldr r0, =gBattleExecBuffer
	ldr r4, [r0]
	cmp r4, 0
	bne _08048662
	ldr r6, =gBattleCommunication
	ldrb r0, [r6, 0x7]
	cmp r0, 0
	bne _0804863C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x3
	str r0, [r1]
	b _08048662
	.pool
_0804863C:
	ldr r5, =gBattlescriptCurrInstr
	ldr r2, [r5]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldr r3, =gUnknown_0202432C
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bcc _08048662
	movs r1, 0
	strh r4, [r3]
	adds r0, r2, 0x3
	str r0, [r5]
	strb r1, [r6, 0x7]
_08048662:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk12_waitmessage

	thumb_func_start atk13_printfromtable
atk13_printfromtable: @ 8048670
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _080486AE
	ldr r4, =gBattlescriptCurrInstr
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
	ldr r5, =gBattleCommunication
	ldrb r0, [r5, 0x5]
	lsls r0, 1
	adds r1, r0
	ldrh r0, [r1]
	ldr r1, =gBankAttacker
	ldrb r1, [r1]
	bl b_std_message
	ldr r0, [r4]
	adds r0, 0x5
	str r0, [r4]
	movs r0, 0x1
	strb r0, [r5, 0x7]
_080486AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk13_printfromtable

	thumb_func_start atk14_printfromtable_playeronly
atk14_printfromtable_playeronly: @ 80486C4
	push {r4-r6,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804870E
	ldr r5, =gBattlescriptCurrInstr
	ldr r2, [r5]
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
	ldr r6, =gBattleCommunication
	ldrb r0, [r6, 0x5]
	lsls r0, 1
	adds r1, r0
	ldr r4, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r4]
	ldrh r1, [r1]
	movs r0, 0
	bl dp01_build_cmdbuf_x11_TODO
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x5
	str r0, [r5]
	movs r0, 0x1
	strb r0, [r6, 0x7]
_0804870E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk14_printfromtable_playeronly

	thumb_func_start sub_8048728
sub_8048728: @ 8048728
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r0, =gNoOfAllBanks
	ldrb r3, [r0]
	cmp r1, r3
	bge _0804874E
	ldr r4, =gTurnOrder
	ldrb r0, [r4]
	cmp r0, r2
	beq _0804874E
_08048740:
	adds r1, 0x1
	cmp r1, r3
	bge _0804874E
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, r2
	bne _08048740
_0804874E:
	lsls r0, r1, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8048728

	thumb_func_start sub_8048760
sub_8048760: @ 8048760
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	movs r0, 0
	mov r10, r0
	movs r7, 0
	movs r1, 0x1
	str r1, [sp, 0x4]
	ldr r1, =gBattleCommunication
	ldrb r3, [r1, 0x3]
	movs r0, 0x40
	ands r0, r3
	cmp r0, 0
	beq _080487B8
	ldr r2, =gUnknown_0202420E
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0xBF
	ands r0, r3
	adds r3, r1, 0
	strb r0, [r3, 0x3]
	movs r7, 0x40
	ldr r1, =gBattleScripting
	ldr r0, =gBankTarget
	b _080487C4
	.pool
_080487B8:
	ldr r2, =gUnknown_0202420E
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, =gBattleScripting
	ldr r0, =gBankAttacker
_080487C4:
	ldrb r0, [r0]
	strb r0, [r1, 0x17]
	mov r9, r2
	ldr r2, =gBattleMons
	mov r4, r9
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x13
	bne _08048828
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	ands r0, r1
	cmp r0, 0
	bne _08048828
	cmp r5, 0
	bne _08048828
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x3]
	cmp r0, 0x9
	bhi _08048828
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r2, =gBattleCommunication
	strb r5, [r2, 0x3]
	bl _080499B8
	.pool
_08048828:
	mov r3, r9
	ldrb r0, [r3]
	bl GetBankIdentity
	ldr r2, =gSideAffecting
	movs r1, 0x1
	ands r1, r0
	lsls r1, 1
	adds r1, r2
	ldrh r1, [r1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08048880
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	ands r0, r1
	cmp r0, 0
	bne _08048880
	cmp r5, 0
	bne _08048880
	ldr r0, =gBattleCommunication
	ldrb r1, [r0, 0x3]
	cmp r1, 0x7
	bhi _08048880
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r4, =gBattleCommunication
	strb r5, [r4, 0x3]
	bl _080499B8
	.pool
_08048880:
	ldr r3, =gBattleMons
	ldr r2, =gUnknown_0202420E
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	adds r0, r3
	ldrh r4, [r0, 0x28]
	mov r9, r2
	mov r8, r3
	cmp r4, 0
	bne _080488C4
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x3]
	cmp r0, 0xB
	beq _080488C4
	cmp r0, 0x1F
	beq _080488C4
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r2, =gBattleCommunication
	strb r4, [r2, 0x3]
	bl _080499B8
	.pool
_080488C4:
	mov r3, r9
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	mov r1, r8
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _080488FC
	cmp r7, 0x40
	beq _080488FC
	ldr r0, =gBattlescriptCurrInstr
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	movs r0, 0
	ldr r4, =gBattleCommunication
	strb r0, [r4, 0x3]
	bl _080499B8
	.pool
_080488FC:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x3]
	cmp r0, 0x6
	bls _08048906
	b _08048F40
_08048906:
	ldr r1, =gStatusFlagsForMoveEffects
	ldr r2, =gBattleCommunication
	ldrb r0, [r2, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0x10
	bne _08048918
	b _08048AFC
_08048918:
	cmp r0, 0x10
	bhi _08048930
	cmp r0, 0x7
	beq _0804894A
	cmp r0, 0x8
	beq _08048A00
	b _08048DF4
	.pool
_08048930:
	cmp r0, 0x40
	bne _08048936
	b _08048C84
_08048936:
	cmp r0, 0x40
	bhi _08048942
	cmp r0, 0x20
	bne _08048940
	b _08048BEA
_08048940:
	b _08048DF4
_08048942:
	cmp r0, 0x80
	bne _08048948
	b _08048D02
_08048948:
	b _08048DF4
_0804894A:
	mov r3, r9
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	add r0, r8
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x2B
	beq _080489AC
	ldr r0, =gActiveBank
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gNoOfAllBanks
	ldrb r3, [r1]
	adds r7, r0, 0
	mov r12, r1
	cmp r3, 0
	beq _080489B8
	mov r4, r8
	ldr r0, [r4, 0x50]
	movs r1, 0x70
	ands r0, r1
	cmp r0, 0
	bne _080489B8
	adds r1, r7, 0
	mov r6, r8
	adds r6, 0x50
	movs r5, 0x58
	movs r4, 0x70
_08048984:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r3
	bcs _080489B8
	ldrb r0, [r7]
	muls r0, r5
	adds r0, r6
	ldr r0, [r0]
	ands r0, r4
	cmp r0, 0
	beq _08048984
	b _080489B8
	.pool
_080489AC:
	ldr r0, =gActiveBank
	ldr r2, =gNoOfAllBanks
	ldrb r1, [r2]
	strb r1, [r0]
	adds r7, r0, 0
	mov r12, r2
_080489B8:
	mov r0, r9
	ldrb r2, [r0]
	movs r0, 0x58
	adds r1, r2, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _080489D0
	b _08048DF4
_080489D0:
	ldrb r0, [r7]
	mov r3, r12
	ldrb r3, [r3]
	cmp r0, r3
	beq _080489DC
	b _08048DF4
_080489DC:
	mov r4, r8
	adds r0, r1, r4
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x48
	bne _080489EA
	b _08048DF4
_080489EA:
	cmp r0, 0xF
	bne _080489F0
	b _08048DF4
_080489F0:
	adds r0, r2, 0
	bl CancelMultiTurnMoves
	b _08048DE4
	.pool
_08048A00:
	mov r2, r9
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	add r0, r8
	adds r0, 0x20
	ldrb r1, [r0]
	cmp r1, 0x11
	bne _08048A70
	cmp r5, 0x1
	beq _08048A1A
	cmp r6, 0x80
	bne _08048A70
_08048A1A:
	ldr r0, =gLastUsedAbility
	strb r1, [r0]
	mov r3, r9
	ldrb r0, [r3]
	movs r1, 0x11
	bl RecordAbilityBattle
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB5E9
	str r0, [r4]
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	bne _08048A46
	b _08048D20
_08048A46:
	movs r0, 0x1
	ldr r4, =gBattleCommunication
	strb r0, [r4, 0x5]
_08048A4C:
	ldr r0, =0xffffdfff
	ands r1, r0
	str r1, [r2]
	bl _080499B2
	.pool
_08048A70:
	mov r2, r9
	ldrb r0, [r2]
	movs r1, 0x58
	muls r0, r1
	add r0, r8
	adds r1, r0, 0
	adds r1, 0x21
	ldrb r1, [r1]
	cmp r1, 0x3
	beq _08048A94
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08048A94
	cmp r1, 0x8
	beq _08048A94
	cmp r0, 0x8
	bne _08048AAE
_08048A94:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	ands r0, r1
	cmp r0, 0
	beq _08048AAE
	cmp r5, 0x1
	bne _08048AA8
	b _08048D66
_08048AA8:
	cmp r6, 0x80
	bne _08048AAE
	b _08048D66
_08048AAE:
	mov r3, r9
	ldrb r1, [r3]
	movs r0, 0x58
	muls r1, r0
	mov r4, r8
	adds r3, r1, r4
	adds r0, r3, 0
	adds r0, 0x21
	ldrb r4, [r0]
	cmp r4, 0x3
	bne _08048AC6
	b _08048DF4
_08048AC6:
	adds r0, 0x1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _08048AD0
	b _08048DF4
_08048AD0:
	cmp r4, 0x8
	bne _08048AD6
	b _08048DF4
_08048AD6:
	cmp r0, 0x8
	bne _08048ADC
	b _08048DF4
_08048ADC:
	mov r0, r8
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _08048AEA
	b _08048DF4
_08048AEA:
	adds r0, r3, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x11
	bne _08048AF6
	b _08048DF4
_08048AF6:
	b _08048DE4
	.pool
_08048AFC:
	mov r2, r9
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	add r0, r8
	adds r0, 0x20
	ldrb r1, [r0]
	cmp r1, 0x29
	bne _08048B54
	cmp r5, 0x1
	beq _08048B16
	cmp r6, 0x80
	bne _08048B54
_08048B16:
	ldr r0, =gLastUsedAbility
	strb r1, [r0]
	mov r3, r9
	ldrb r0, [r3]
	movs r1, 0x29
	bl RecordAbilityBattle
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB5D1
	str r0, [r4]
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _08048B42
	b _08048A46
_08048B42:
	b _08048D20
	.pool
_08048B54:
	mov r2, r9
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	mov r3, r8
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0xA
	beq _08048B74
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0xA
	bne _08048BA4
_08048B74:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	ands r0, r1
	cmp r0, 0
	beq _08048BA4
	cmp r5, 0x1
	beq _08048B8A
	cmp r6, 0x80
	bne _08048BA4
_08048B8A:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB5D1
	b _08048D72
	.pool
_08048BA4:
	mov r4, r9
	ldrb r0, [r4]
	movs r1, 0x58
	adds r2, r0, 0
	muls r2, r1
	mov r0, r8
	adds r1, r2, r0
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0xA
	bne _08048BBE
	b _08048DF4
_08048BBE:
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0xA
	bne _08048BCA
	b _08048DF4
_08048BCA:
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x29
	bne _08048BD6
	b _08048DF4
_08048BD6:
	mov r0, r8
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _08048BE4
	b _08048DF4
_08048BE4:
	movs r1, 0x1
	mov r10, r1
	b _08048DF4
_08048BEA:
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
	bne _08048C26
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08048C26
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08048C26
	movs r2, 0
	str r2, [sp, 0x4]
_08048C26:
	ldr r4, =gBattleMons
	ldr r0, =gUnknown_0202420E
	ldrb r3, [r0]
	movs r0, 0x58
	adds r2, r3, 0
	muls r2, r0
	adds r1, r2, r4
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0xF
	bne _08048C40
	b _08048DF4
_08048C40:
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0xF
	bne _08048C4C
	b _08048DF4
_08048C4C:
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, 0
	beq _08048C5A
	b _08048DF4
_08048C5A:
	ldr r4, [sp, 0x4]
	cmp r4, 0
	bne _08048C62
	b _08048DF4
_08048C62:
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x28
	bne _08048C6E
	b _08048DF4
_08048C6E:
	adds r0, r3, 0
	bl CancelMultiTurnMoves
	b _08048DE4
	.pool
_08048C84:
	mov r2, r9
	ldrb r1, [r2]
	movs r0, 0x58
	muls r1, r0
	mov r3, r8
	adds r0, r1, r3
	adds r0, 0x20
	ldrb r2, [r0]
	cmp r2, 0x7
	bne _08048CF4
	cmp r5, 0x1
	beq _08048CA2
	cmp r6, 0x80
	beq _08048CA2
	b _08048DF4
_08048CA2:
	ldr r0, =gLastUsedAbility
	strb r2, [r0]
	mov r4, r9
	ldrb r0, [r4]
	movs r1, 0x7
	bl RecordAbilityBattle
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB5DD
	str r0, [r4]
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _08048CE8
	movs r0, 0x1
	ldr r3, =gBattleCommunication
	strb r0, [r3, 0x5]
	b _08048A4C
	.pool
_08048CE8:
	ldr r4, =gBattleCommunication
	strb r0, [r4, 0x5]
	bl _080499B2
	.pool
_08048CF4:
	mov r0, r8
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08048DF4
	b _08048DE4
_08048D02:
	mov r2, r9
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	add r0, r8
	adds r0, 0x20
	ldrb r1, [r0]
	cmp r1, 0x11
	bne _08048D2C
	cmp r5, 0x1
	bne _08048D1A
	b _08048A1A
_08048D1A:
	cmp r6, 0x80
	bne _08048D2C
	b _08048A1A
_08048D20:
	ldr r1, =gBattleCommunication
	strb r0, [r1, 0x5]
	bl _080499B2
	.pool
_08048D2C:
	mov r2, r9
	ldrb r0, [r2]
	movs r1, 0x58
	muls r0, r1
	add r0, r8
	adds r1, r0, 0
	adds r1, 0x21
	ldrb r1, [r1]
	cmp r1, 0x3
	beq _08048D50
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08048D50
	cmp r1, 0x8
	beq _08048D50
	cmp r0, 0x8
	bne _08048D94
_08048D50:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	ands r0, r1
	cmp r0, 0
	beq _08048D94
	cmp r5, 0x1
	beq _08048D66
	cmp r6, 0x80
	bne _08048D94
_08048D66:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB5E9
_08048D72:
	str r0, [r4]
	ldr r1, =gBattleCommunication
	movs r2, 0
	movs r0, 0x2
	strb r0, [r1, 0x5]
	strb r2, [r1, 0x3]
	bl _080499B8
	.pool
_08048D94:
	mov r3, r9
	ldrb r0, [r3]
	movs r6, 0x58
	muls r0, r6
	mov r2, r8
	adds r2, 0x4C
	adds r5, r0, r2
	ldr r4, [r5]
	cmp r4, 0
	bne _08048DF4
	mov r3, r8
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r3, [r0]
	cmp r3, 0x3
	beq _08048DEA
	adds r0, 0x1
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _08048DEA
	cmp r3, 0x8
	beq _08048DEA
	cmp r0, 0x8
	beq _08048DEA
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x11
	beq _08048DF4
	mov r4, r9
	ldrb r0, [r4]
	adds r1, r0, 0
	muls r1, r6
	adds r1, r2
	ldr r0, [r1]
	movs r2, 0x9
	negs r2, r2
	ands r0, r2
	str r0, [r1]
_08048DE4:
	movs r0, 0x1
	mov r10, r0
	b _08048DF4
_08048DEA:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_08048DF4:
	mov r1, r10
	cmp r1, 0x1
	beq _08048DFC
	b _08048F1C
_08048DFC:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r1, =gStatusFlagsForMoveEffects
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	cmp r3, 0x7
	bne _08048E50
	bl Random
	ldr r2, =gBattleMons
	ldr r1, =gUnknown_0202420E
	ldrb r3, [r1]
	movs r1, 0x58
	muls r3, r1
	adds r2, 0x4C
	adds r3, r2
	movs r1, 0x3
	ands r1, r0
	adds r1, 0x2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	b _08048E64
	.pool
_08048E50:
	ldr r2, =gBattleMons
	ldr r0, =gUnknown_0202420E
	ldrb r1, [r0]
	movs r0, 0x58
	muls r1, r0
	adds r2, 0x4C
	adds r1, r2
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_08048E64:
	ldr r2, =gBattlescriptCurrInstr
	ldr r1, =gMoveEffectBS_Ptrs
	ldr r5, =gBattleCommunication
	ldrb r0, [r5, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r4, =gActiveBank
	ldr r1, =gUnknown_0202420E
	ldrb r0, [r1]
	strb r0, [r4]
	ldrb r1, [r1]
	movs r0, 0x58
	muls r0, r1
	ldr r1, =gBattleMons + 0x4C
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 6
	ands r0, r1
	cmp r0, 0
	beq _08048ED8
	movs r0, 0x1
	strb r0, [r5, 0x5]
	ldr r0, =0xffffdfff
	ands r1, r0
	str r1, [r2]
	b _08048EDA
	.pool
_08048ED8:
	strb r0, [r5, 0x5]
_08048EDA:
	ldr r0, =gBattleCommunication
	ldrb r2, [r0, 0x3]
	cmp r2, 0x2
	beq _08048EF2
	cmp r2, 0x6
	beq _08048EF2
	cmp r2, 0x5
	beq _08048EF2
	cmp r2, 0x3
	beq _08048EF2
	bl _080499B8
_08048EF2:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xB2
	ldr r2, =gBattleCommunication
	ldrb r1, [r2, 0x3]
	strb r1, [r0]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 7
	orrs r0, r1
	str r0, [r2]
	bl _080499B8
	.pool
_08048F1C:
	mov r3, r10
	cmp r3, 0
	beq _08048F26
	bl _080499B8
_08048F26:
	ldr r0, =gBattleCommunication
	strb r3, [r0, 0x3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bl _080499B8
	.pool
_08048F40:
	mov r4, r9
	ldrb r1, [r4]
	movs r0, 0x58
	muls r1, r0
	mov r0, r8
	adds r0, 0x50
	adds r1, r0
	ldr r2, =gStatusFlagsForMoveEffects
	ldr r0, =gBattleCommunication
	ldrb r3, [r0, 0x3]
	lsls r0, r3, 2
	adds r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08048F66
	bl _08049994
_08048F66:
	subs r0, r3, 0x7
	cmp r0, 0x34
	bls _08048F70
	bl _080499B2
_08048F70:
	lsls r0, 2
	ldr r1, =_08048F88
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08048F88:
	.4byte _0804905C
	.4byte _080490D0
	.4byte _08049244
	.4byte _0804915C
	.4byte _080491D8
	.4byte _0804927C
	.4byte _080492C4
	.4byte _08049390
	.4byte _080493D4
	.4byte _080493D4
	.4byte _080493D4
	.4byte _080493D4
	.4byte _080493D4
	.4byte _080493D4
	.4byte _080493D4
	.4byte _0804941C
	.4byte _0804941C
	.4byte _0804941C
	.4byte _0804941C
	.4byte _0804941C
	.4byte _0804941C
	.4byte _0804941C
	.4byte _080494FC
	.4byte _08049544
	.4byte _08049564
	.4byte _08049720
	.4byte _0804975C
	.4byte _08049778
	.4byte _08049790
	.4byte _080497A8
	.4byte _08049808
	.4byte _08049820
	.4byte _08049468
	.4byte _08049468
	.4byte _08049468
	.4byte _08049468
	.4byte _08049468
	.4byte _08049468
	.4byte _08049468
	.4byte _080494B0
	.4byte _080494B0
	.4byte _080494B0
	.4byte _080494B0
	.4byte _080494B0
	.4byte _080494B0
	.4byte _080494B0
	.4byte _08049864
	.4byte _080498C0
	.4byte _080499B2
	.4byte _080499B2
	.4byte _080499B2
	.4byte _080499B2
	.4byte _080499A4
_0804905C:
	mov r1, r9
	ldrb r0, [r1]
	movs r5, 0x58
	adds r1, r0, 0
	muls r1, r5
	mov r2, r8
	adds r0, r1, r2
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x14
	bne _08049076
	bl _08049994
_08049076:
	mov r4, r8
	adds r4, 0x50
	adds r0, r1, r4
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0804908A
	bl _08049994
_0804908A:
	bl Random
	mov r3, r9
	ldrb r1, [r3]
	adds r2, r1, 0
	muls r2, r5
	adds r2, r4
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 16
	adds r1, 0x2
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r1, =gMoveEffectBS_Ptrs
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _080499B0
	.pool
_080490D0:
	mov r4, r9
	ldrb r2, [r4]
	movs r4, 0x58
	adds r0, r2, 0
	muls r0, r4
	add r0, r8
	adds r0, 0x20
	ldrb r1, [r0]
	cmp r1, 0x27
	bne _08049114
	cmp r5, 0x1
	beq _080490F0
	cmp r6, 0x80
	beq _080490F0
	bl _08049994
_080490F0:
	ldr r0, =gLastUsedAbility
	strb r1, [r0]
	mov r1, r9
	ldrb r0, [r1]
	movs r1, 0x27
	bl RecordAbilityBattle
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB603
	str r0, [r1]
	bl _080499B2
	.pool
_08049114:
	adds r0, r2, 0
	bl sub_8048728
	ldr r1, =gUnknown_02024082
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bhi _0804912A
	bl _08049994
_0804912A:
	mov r2, r9
	ldrb r0, [r2]
	adds r2, r0, 0
	muls r2, r4
	mov r0, r8
	adds r0, 0x50
	adds r2, r0
	ldr r1, =gStatusFlagsForMoveEffects
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r2]
	bl _08049994
	.pool
_0804915C:
	mov r3, r9
	ldrb r0, [r3]
	movs r5, 0x58
	muls r0, r5
	mov r4, r8
	adds r4, 0x50
	adds r2, r0, r4
	ldr r1, [r2]
	movs r0, 0x70
	ands r0, r1
	cmp r0, 0
	beq _08049178
	bl _08049994
_08049178:
	movs r0, 0x80
	lsls r0, 5
	orrs r1, r0
	str r1, [r2]
	ldr r1, =gUnknown_02024268
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r1
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	strh r1, [r0]
	bl Random
	mov r2, r9
	ldrb r1, [r2]
	adds r2, r1, 0
	muls r2, r5
	adds r2, r4
	movs r1, 0x3
	ands r1, r0
	adds r1, 0x2
	lsls r1, 4
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r1, =gMoveEffectBS_Ptrs
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _080499B0
	.pool
_080491D8:
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	bl GetBankIdentity
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	bne _08049210
	ldr r4, =gUnknown_0202432E
	ldrh r3, [r4]
	ldr r2, =gBattleMons
	ldrb r1, [r5]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x2A
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	adds r0, r3, r0
	strh r0, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r3, r0
	bls _08049210
	ldr r3, =0x0000ffff
	adds r0, r3, 0
	strh r0, [r4]
_08049210:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r1, =gMoveEffectBS_Ptrs
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	b _080499B0
	.pool
_08049244:
	mov r4, r9
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	mov r1, r8
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0804925A
	b _08049994
_0804925A:
	bl Random
	ldr r4, =gBattleCommunication
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	adds r0, 0x3
	strb r0, [r4, 0x3]
	movs r0, 0
	movs r1, 0
	bl sub_8048760
	b _080499B2
	.pool
_0804927C:
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	mov r0, r8
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 5
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gUnknown_02024268
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r1
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	strh r1, [r0]
	ldr r0, =gProtectStructs
	ldrb r1, [r2]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1, 0x1]
	b _08049994
	.pool
_080492C4:
	mov r3, r9
	ldrb r0, [r3]
	movs r6, 0x58
	muls r0, r6
	mov r4, r8
	adds r4, 0x50
	adds r0, r4
	ldr r5, [r0]
	movs r0, 0xE0
	lsls r0, 8
	ands r5, r0
	cmp r5, 0
	beq _080492E0
	b _08049994
_080492E0:
	bl Random
	mov r2, r9
	ldrb r1, [r2]
	adds r2, r1, 0
	muls r2, r6
	adds r2, r4
	movs r1, 0x3
	ands r1, r0
	adds r1, 0x3
	lsls r1, 13
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	mov r3, r9
	ldrb r1, [r3]
	ldr r2, =gBattleStruct
	ldr r0, [r2]
	lsls r1, 1
	adds r1, r0
	ldr r6, =gCurrentMove
	ldrh r0, [r6]
	strb r0, [r1, 0x4]
	ldrb r1, [r3]
	ldr r0, [r2]
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r6]
	lsrs r0, 8
	strb r0, [r1, 0x5]
	ldrb r1, [r3]
	ldr r0, [r2]
	adds r1, r0
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r1, 0x14]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r1, =gMoveEffectBS_Ptrs
	ldr r2, =gBattleCommunication
	ldrb r0, [r2, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r4]
	strb r5, [r2, 0x5]
	ldr r3, =gUnknown_085CC982
	ldrh r0, [r3]
	ldrh r4, [r6]
	cmp r0, r4
	bne _0804934E
	b _080499B2
_0804934E:
	adds r1, r2, 0
	adds r2, r6, 0
_08049352:
	ldrb r0, [r1, 0x5]
	adds r0, 0x1
	strb r0, [r1, 0x5]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _08049362
	b _080499B2
_08049362:
	ldrb r0, [r1, 0x5]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	ldrh r4, [r2]
	cmp r0, r4
	bne _08049352
	b _080499B2
	.pool
_08049390:
	ldr r1, =gBattleMoveDamage
	ldr r0, =gUnknown_020241F4
	ldr r0, [r0]
	cmp r0, 0
	bge _0804939C
	adds r0, 0x3
_0804939C:
	asrs r0, 2
	str r0, [r1]
	cmp r0, 0
	bne _080493A8
	movs r0, 0x1
	str r0, [r1]
_080493A8:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r1, =gMoveEffectBS_Ptrs
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	b _080499B0
	.pool
_080493D4:
	ldr r4, =gBattleCommunication
	ldrb r1, [r4, 0x3]
	adds r1, 0xF2
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x10
	adds r2, r7, 0
	movs r3, 0
	bl sub_8050A1C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _080493F2
	b _08049994
_080493F2:
	ldr r2, =gBattleScripting
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2, 0x10]
	strb r3, [r2, 0x11]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082D8CD4
	b _080499B0
	.pool
_0804941C:
	movs r0, 0x70
	negs r0, r0
	ldr r4, =gBattleCommunication
	ldrb r1, [r4, 0x3]
	adds r1, 0xEB
	lsls r1, 24
	lsrs r1, 24
	adds r2, r7, 0
	movs r3, 0
	bl sub_8050A1C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _0804943C
	b _08049994
_0804943C:
	ldr r2, =gBattleScripting
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2, 0x10]
	strb r3, [r2, 0x11]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082D8D65
	b _080499B0
	.pool
_08049468:
	ldr r4, =gBattleCommunication
	ldrb r1, [r4, 0x3]
	adds r1, 0xDA
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x20
	adds r2, r7, 0
	movs r3, 0
	bl sub_8050A1C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _08049486
	b _08049994
_08049486:
	ldr r2, =gBattleScripting
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2, 0x10]
	strb r3, [r2, 0x11]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082D8CD4
	b _080499B0
	.pool
_080494B0:
	movs r0, 0x60
	negs r0, r0
	ldr r4, =gBattleCommunication
	ldrb r1, [r4, 0x3]
	adds r1, 0xD3
	lsls r1, 24
	lsrs r1, 24
	adds r2, r7, 0
	movs r3, 0
	bl sub_8050A1C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _080494D0
	b _08049994
_080494D0:
	ldr r2, =gBattleScripting
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	ands r0, r1
	strb r0, [r2, 0x10]
	strb r3, [r2, 0x11]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082D8D65
	b _080499B0
	.pool
_080494FC:
	mov r0, r9
	ldrb r1, [r0]
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	mov r0, r8
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 15
	orrs r0, r1
	str r0, [r2]
	ldr r2, =gDisableStructs
	mov r3, r9
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0, 0x19]
	ldr r1, =gUnknown_02024268
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r1
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	strh r1, [r0]
	b _08049994
	.pool
_08049544:
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	mov r0, r8
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 16
_0804955A:
	orrs r0, r1
	str r0, [r2]
	b _08049994
	.pool
_08049564:
	ldr r5, =gBattleTypeFlags
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 19
	ands r0, r1
	cmp r0, 0
	beq _08049574
	b _08049994
_08049574:
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080495A8
	ldr r0, [r5]
	ldr r1, =0x0a3f0902
	ands r0, r1
	cmp r0, 0
	bne _080495D4
	b _08049994
	.pool
_080495A8:
	ldr r0, [r5]
	ldr r1, =0x0a3f0902
	ands r0, r1
	cmp r0, 0
	bne _080495D4
	ldr r0, =gUnknown_020243D0
	adds r0, 0x29
	adds r0, r4, r0
	ldrb r1, [r0]
	ldr r3, =gBitTable
	ldr r2, =gBattlePartyID
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _080495D4
	b _08049994
_080495D4:
	ldr r2, =gBattleMons
	ldr r1, =gBankTarget
	ldrb r0, [r1]
	movs r5, 0x58
	muls r0, r5
	adds r4, r0, r2
	ldrh r0, [r4, 0x2E]
	adds r7, r1, 0
	mov r8, r2
	cmp r0, 0
	beq _0804963C
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x3C
	bne _0804963C
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB682
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
	b _080499B2
	.pool
_0804963C:
	ldr r4, =gBankAttacker
	mov r10, r4
	ldrb r2, [r4]
	movs r0, 0x58
	mov r9, r0
	mov r0, r9
	muls r0, r2
	add r0, r8
	ldrh r4, [r0, 0x2E]
	cmp r4, 0
	beq _08049654
	b _08049994
_08049654:
	ldrb r0, [r7]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	add r0, r8
	ldrh r3, [r0, 0x2E]
	adds r1, r3, 0
	cmp r1, 0xAF
	bne _08049668
	b _08049994
_08049668:
	adds r0, r3, 0
	subs r0, 0x79
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xB
	bhi _08049676
	b _08049994
_08049676:
	cmp r1, 0
	bne _0804967C
	b _08049994
_0804967C:
	ldr r5, =gBattleStruct
	lsls r0, r2, 1
	adds r0, 0xD0
	ldr r1, [r5]
	adds r1, r0
	ldr r2, =gLastUsedItem
	strh r3, [r1]
	strh r3, [r2]
	ldrb r0, [r7]
	mov r3, r9
	muls r3, r0
	adds r0, r3, 0
	add r0, r8
	movs r6, 0
	strh r4, [r0, 0x2E]
	ldr r4, =gActiveBank
	mov r1, r10
	ldrb r0, [r1]
	strb r0, [r4]
	str r2, [sp]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x2
	bl dp01_build_cmdbuf_x02_a_b_varargs
	mov r2, r10
	ldrb r0, [r2]
	bl dp01_battle_side_mark_buffer_for_execution
	ldrb r0, [r7]
	strb r0, [r4]
	ldrb r0, [r7]
	mov r3, r9
	muls r3, r0
	adds r0, r3, 0
	mov r1, r8
	adds r1, 0x2E
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x2
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r7]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB422
	str r0, [r4]
	ldrb r0, [r7]
	ldr r1, [r5]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC8
	strb r6, [r0]
	ldrb r0, [r7]
	ldr r1, [r5]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC9
	strb r6, [r0]
	b _080499B2
	.pool
_08049720:
	ldr r3, =gBankTarget
	ldrb r1, [r3]
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	mov r0, r8
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 19
	orrs r0, r1
	str r0, [r2]
	ldr r2, =gDisableStructs
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gBankAttacker
	ldrb r1, [r1]
	strb r1, [r0, 0x14]
	b _08049994
	.pool
_0804975C:
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	mov r0, r8
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 20
	b _0804955A
	.pool
_08049778:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DAF27
	b _080499B0
	.pool
_08049790:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DAFC3
	b _080499B0
	.pool
_080497A8:
	ldr r6, =gBankTarget
	ldrb r0, [r6]
	movs r2, 0x58
	muls r0, r2
	mov r1, r8
	adds r1, 0x4C
	adds r5, r0, r1
	ldr r4, [r5]
	movs r0, 0x40
	ands r0, r4
	cmp r0, 0
	bne _080497C2
	b _08049994
_080497C2:
	movs r0, 0x41
	negs r0, r0
	ands r4, r0
	str r4, [r5]
	ldr r4, =gActiveBank
	ldrb r0, [r6]
	strb r0, [r4]
	ldrb r0, [r4]
	muls r0, r2
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB361
	b _080499B0
	.pool
_08049808:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB117
	b _080499B0
	.pool
_08049820:
	ldr r4, =gBattleMoveDamage
	ldr r0, =gUnknown_020241F4
	ldr r0, [r0]
	movs r1, 0x3
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08049836
	movs r0, 0x1
	str r0, [r4]
_08049836:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r1, =gMoveEffectBS_Ptrs
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	b _080499B0
	.pool
_08049864:
	mov r4, r9
	ldrb r0, [r4]
	movs r5, 0x58
	muls r0, r5
	mov r4, r8
	adds r4, 0x50
	adds r2, r0, r4
	ldr r1, [r2]
	movs r0, 0xC0
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	beq _08049880
	b _08049994
_08049880:
	movs r0, 0x80
	lsls r0, 5
	orrs r1, r0
	str r1, [r2]
	ldr r1, =gUnknown_02024268
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r1
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	strh r1, [r0]
	bl Random
	mov r3, r9
	ldrb r1, [r3]
	adds r2, r1, 0
	muls r2, r5
	adds r2, r4
	movs r1, 0x1
	ands r1, r0
	adds r1, 0x2
	lsls r1, 10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _080499B2
	.pool
_080498C0:
	mov r4, r9
	ldrb r3, [r4]
	movs r5, 0x58
	adds r0, r3, 0
	muls r0, r5
	mov r2, r8
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r2, [r0]
	cmp r2, 0x3C
	bne _08049900
	ldrh r0, [r1, 0x2E]
	cmp r0, 0
	beq _08049994
	ldr r0, =gLastUsedAbility
	strb r2, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB63F
	str r0, [r1]
	ldrb r0, [r4]
	movs r1, 0x3C
	bl RecordAbilityBattle
	b _080499B2
	.pool
_08049900:
	ldrh r0, [r1, 0x2E]
	cmp r0, 0
	beq _08049994
	adds r0, r3, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gLastUsedItem
	mov r3, r9
	ldrb r0, [r3]
	muls r0, r5
	add r0, r8
	ldrh r0, [r0, 0x2E]
	strh r0, [r1]
	ldrb r0, [r3]
	muls r0, r5
	add r0, r8
	movs r5, 0
	movs r1, 0
	strh r1, [r0, 0x2E]
	ldr r2, =gUnknown_020243D0
	adds r2, 0x29
	adds r2, r4, r2
	ldr r3, =gBitTable
	ldr r1, =gBattlePartyID
	mov r4, r9
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB168
	str r0, [r4]
	mov r1, r9
	ldrb r0, [r1]
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC8
	strb r5, [r0]
	mov r3, r9
	ldrb r0, [r3]
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC9
	strb r5, [r0]
	b _080499B2
	.pool
_08049994:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	b _080499B2
	.pool
_080499A4:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB1D5
_080499B0:
	str r0, [r4]
_080499B2:
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x3]
_080499B8:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8048760

	thumb_func_start atk15_seteffectwithchancetarget
atk15_seteffectwithchancetarget: @ 80499D4
	push {r4,lr}
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x20
	bne _08049A10
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 1
	b _08049A20
	.pool
_08049A10:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r4, [r0, 0x5]
_08049A20:
	ldr r3, =gBattleCommunication
	ldrb r2, [r3, 0x3]
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _08049A50
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _08049A50
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r3, 0x3]
	b _08049A7E
	.pool
_08049A50:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r4
	bcs _08049A9A
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _08049A9A
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _08049A9A
	cmp r4, 0x63
	bls _08049A90
_08049A7E:
	movs r0, 0
	movs r1, 0x80
	bl sub_8048760
	b _08049AA2
	.pool
_08049A90:
	movs r0, 0
	movs r1, 0
	bl sub_8048760
	b _08049AA2
_08049A9A:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08049AA2:
	ldr r0, =gBattleCommunication
	movs r1, 0
	strb r1, [r0, 0x3]
	ldr r0, =gBattleScripting
	strb r1, [r0, 0x16]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk15_seteffectwithchancetarget

	thumb_func_start atk16_seteffectprimary
atk16_seteffectprimary: @ 8049AC0
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl sub_8048760
	pop {r0}
	bx r0
	thumb_func_end atk16_seteffectprimary

	thumb_func_start atk17_seteffectsecondary
atk17_seteffectsecondary: @ 8049AD0
	push {lr}
	movs r0, 0
	movs r1, 0
	bl sub_8048760
	pop {r0}
	bx r0
	thumb_func_end atk17_seteffectsecondary

	thumb_func_start atk18_status_effect_clear
atk18_status_effect_clear: @ 8049AE0
	push {lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r2, =gActiveBank
	strb r0, [r2]
	ldr r3, =gBattleCommunication
	ldrb r0, [r3, 0x3]
	cmp r0, 0x6
	bhi _08049B14
	ldr r1, =gBattleMons
	ldrb r2, [r2]
	movs r0, 0x58
	muls r2, r0
	adds r1, 0x4C
	b _08049B1E
	.pool
_08049B14:
	ldr r1, =gBattleMons
	ldrb r2, [r2]
	movs r0, 0x58
	muls r2, r0
	adds r1, 0x50
_08049B1E:
	adds r2, r1
	ldr r1, =gStatusFlagsForMoveEffects
	ldrb r0, [r3, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, =gBattleCommunication
	movs r2, 0
	strb r2, [r0, 0x3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	ldr r0, =gBattleScripting
	strb r2, [r0, 0x16]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk18_status_effect_clear

	thumb_func_start atk19_faint_pokemon
atk19_faint_pokemon: @ 8049B5C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r0, =gBattlescriptCurrInstr
	ldr r2, [r0]
	ldrb r1, [r2, 0x2]
	adds r6, r0, 0
	cmp r1, 0
	beq _08049BE0
	ldrb r0, [r2, 0x1]
	bl get_battle_side_of_something
	ldr r5, =gActiveBank
	strb r0, [r5]
	ldr r2, =gHitMarker
	ldr r1, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _08049B94
	b _08049E2C
_08049B94:
	ldr r1, [r6]
	ldrb r4, [r1, 0x3]
	ldrb r0, [r1, 0x4]
	lsls r0, 8
	orrs r4, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 16
	orrs r4, r0
	ldrb r0, [r1, 0x6]
	lsls r0, 24
	orrs r4, r0
	bl b_movescr_stack_pop_cursor
	str r4, [r6]
	ldrb r0, [r5]
	bl GetBankSide
	ldr r1, =gSideAffecting
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r2, [r0]
	ldr r1, =0x0000fdff
	ands r1, r2
	strh r1, [r0]
	b _08049E32
	.pool
_08049BE0:
	ldrb r0, [r2, 0x1]
	cmp r0, 0x1
	bne _08049C08
	ldr r1, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	mov r9, r0
	ldr r4, =gUnknown_082DA7AA
	b _08049C18
	.pool
_08049C08:
	ldr r1, =gActiveBank
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	mov r9, r0
	ldr r4, =gUnknown_082DA7B7
_08049C18:
	mov r8, r1
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	mov r7, r8
	ldrb r3, [r7]
	lsls r0, r3, 2
	adds r0, r2
	ldr r2, [r0]
	ands r1, r2
	cmp r1, 0
	beq _08049C32
	b _08049E2C
_08049C32:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08049C42
	b _08049E2C
_08049C42:
	ldr r5, =gHitMarker
	lsls r1, r2, 28
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r6]
	adds r0, 0x7
	bl b_movescr_stack_push
	str r4, [r6]
	ldrb r0, [r7]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08049CA4
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 15
	orrs r0, r1
	str r0, [r5]
	ldr r1, =gBattleResults
	ldrb r0, [r1]
	cmp r0, 0xFE
	bhi _08049C78
	adds r0, 0x1
	strb r0, [r1]
_08049C78:
	ldrb r0, [r7]
	bl sub_80570F4
	b _08049CCE
	.pool
_08049CA4:
	ldr r4, =gBattleResults
	ldrb r0, [r4, 0x1]
	cmp r0, 0xFE
	bhi _08049CB0
	adds r0, 0x1
	strb r0, [r4, 0x1]
_08049CB0:
	ldr r1, =gBattlePartyID
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	strh r0, [r4, 0x20]
_08049CCE:
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08049D0C
	ldr r6, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	movs r5, 0x58
	muls r0, r5
	adds r0, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08049D0C
	movs r0, 0x41
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	bl b_movescr_stack_push
	ldr r1, =gBattleMoveDamage
	mov r0, r9
	muls r0, r5
	adds r0, r6
	ldrh r0, [r0, 0x28]
	str r0, [r1]
	ldr r0, =gUnknown_082DAE3E
	str r0, [r4]
_08049D0C:
	ldr r1, =gStatuses3
	ldr r6, =gBankTarget
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 7
	ands r0, r1
	cmp r0, 0
	bne _08049D24
	b _08049E32
_08049D24:
	ldr r0, =gHitMarker
	ldr r5, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r5, r0
	cmp r5, 0
	beq _08049D34
	b _08049E32
_08049D34:
	ldr r3, =gBankAttacker
	mov r8, r3
	ldrb r0, [r3]
	bl GetBankSide
	adds r4, r0, 0
	ldrb r0, [r6]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _08049E32
	ldr r0, =gBattleMons
	mov r9, r0
	mov r2, r8
	ldrb r1, [r2]
	movs r7, 0x58
	adds r2, r1, 0
	muls r2, r7
	adds r0, r2, r0
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08049E32
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xA5
	beq _08049E32
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, r1, r0
	adds r0, 0x80
	ldrb r4, [r0]
	adds r0, r4, r2
	mov r6, r9
	adds r6, 0x24
	adds r0, r6
	strb r5, [r0]
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB18D
	str r0, [r5]
	ldr r5, =gActiveBank
	mov r3, r8
	ldrb r0, [r3]
	strb r0, [r5]
	adds r1, r4, 0
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r5]
	muls r0, r7
	adds r0, r6
	adds r0, r4
	str r0, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	lsls r4, 1
	mov r2, r8
	ldrb r0, [r2]
	muls r0, r7
	adds r0, r4, r0
	mov r2, r9
	adds r2, 0xC
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1, 0x2]
	mov r3, r8
	ldrb r0, [r3]
	muls r0, r7
	adds r4, r0
	adds r4, r2
	ldrh r0, [r4]
	lsrs r0, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	b _08049E32
	.pool
_08049E2C:
	ldr r0, [r6]
	adds r0, 0x7
	str r0, [r6]
_08049E32:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk19_faint_pokemon

	thumb_func_start atk1A_faint_animation
atk1A_faint_animation: @ 8049E40
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _08049E6A
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x0A_A_A_A
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
_08049E6A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk1A_faint_animation

	thumb_func_start atk1B_faint_effects_clear
atk1B_faint_effects_clear: @ 8049E7C
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gBattleExecBuffer
	ldr r5, [r0]
	cmp r5, 0
	bne _08049EE8
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _08049EB4
	ldr r2, =gBattleMons
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08049EDC
_08049EB4:
	ldr r1, =gBattleMons
	ldrb r0, [r4]
	movs r2, 0x58
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	str r5, [r0]
	ldrb r0, [r4]
	muls r0, r2
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_08049EDC:
	bl sub_803A75C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_08049EE8:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk1B_faint_effects_clear

	thumb_func_start atk1C_jumpifstatus
atk1C_jumpifstatus: @ 8049F04
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	ldrb r4, [r2, 0x2]
	ldrb r1, [r2, 0x3]
	lsls r1, 8
	adds r4, r1
	ldrb r1, [r2, 0x4]
	lsls r1, 16
	adds r4, r1
	ldrb r1, [r2, 0x5]
	lsls r1, 24
	adds r4, r1
	ldrb r3, [r2, 0x6]
	ldrb r1, [r2, 0x7]
	lsls r1, 8
	adds r3, r1
	ldrb r1, [r2, 0x8]
	lsls r1, 16
	adds r3, r1
	ldrb r1, [r2, 0x9]
	lsls r1, 24
	adds r3, r1
	ldr r2, =gBattleMons
	movs r1, 0x58
	muls r1, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r0, [r0]
	ands r0, r4
	cmp r0, 0
	beq _08049F68
	adds r0, r1, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08049F68
	str r3, [r5]
	b _08049F70
	.pool
_08049F68:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
_08049F70:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk1C_jumpifstatus

	thumb_func_start atk1D_jumpifstatus2
atk1D_jumpifstatus2: @ 8049F7C
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	ldrb r4, [r2, 0x2]
	ldrb r1, [r2, 0x3]
	lsls r1, 8
	adds r4, r1
	ldrb r1, [r2, 0x4]
	lsls r1, 16
	adds r4, r1
	ldrb r1, [r2, 0x5]
	lsls r1, 24
	adds r4, r1
	ldrb r3, [r2, 0x6]
	ldrb r1, [r2, 0x7]
	lsls r1, 8
	adds r3, r1
	ldrb r1, [r2, 0x8]
	lsls r1, 16
	adds r3, r1
	ldrb r1, [r2, 0x9]
	lsls r1, 24
	adds r3, r1
	ldr r2, =gBattleMons
	movs r1, 0x58
	muls r1, r0
	adds r0, r2, 0
	adds r0, 0x50
	adds r0, r1, r0
	ldr r0, [r0]
	ands r0, r4
	cmp r0, 0
	beq _08049FE0
	adds r0, r1, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08049FE0
	str r3, [r5]
	b _08049FE8
	.pool
_08049FE0:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
_08049FE8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk1D_jumpifstatus2

	thumb_func_start atk1E_jumpifability
atk1E_jumpifability: @ 8049FF4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r6, =gBattlescriptCurrInstr
	ldr r2, [r6]
	ldrb r5, [r2, 0x2]
	mov r8, r5
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	adds r7, r1, r0
	ldrb r0, [r2, 0x1]
	cmp r0, 0x8
	bne _0804A054
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xD
	adds r2, r5, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0804A0C8
	ldr r1, =gLastUsedAbility
	strb r5, [r1]
	str r7, [r6]
	subs r4, 0x1
	lsls r0, r4, 24
	lsrs r0, 24
	ldrb r1, [r1]
	b _0804A0B0
	.pool
_0804A054:
	cmp r0, 0x9
	bne _0804A08C
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	adds r2, r5, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _0804A0C8
	ldr r1, =gLastUsedAbility
	strb r5, [r1]
	str r7, [r6]
	subs r4, 0x1
	lsls r0, r4, 24
	lsrs r0, 24
	ldrb r1, [r1]
	b _0804A0B0
	.pool
_0804A08C:
	ldrb r0, [r2, 0x1]
	bl get_battle_side_of_something
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r4
	adds r0, r1
	adds r0, 0x20
	ldrb r1, [r0]
	cmp r1, r8
	bne _0804A0C8
	ldr r0, =gLastUsedAbility
	strb r1, [r0]
	str r7, [r6]
	ldrb r1, [r0]
	adds r0, r4, 0
_0804A0B0:
	bl RecordAbilityBattle
	ldr r0, =gBattleScripting
	strb r4, [r0, 0x15]
	b _0804A0CE
	.pool
_0804A0C8:
	ldr r0, [r6]
	adds r0, 0x7
	str r0, [r6]
_0804A0CE:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk1E_jumpifability

	thumb_func_start atk1F_jumpifsideaffecting
atk1F_jumpifsideaffecting: @ 804A0DC
	push {r4-r6,lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r4, [r0, 0x1]
	cmp r4, 0x1
	bne _0804A0FC
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity
	b _0804A106
	.pool
_0804A0FC:
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	bl GetBankIdentity
	movs r4, 0x1
_0804A106:
	ands r4, r0
	ldr r6, =gBattlescriptCurrInstr
	ldr r3, [r6]
	ldrb r2, [r3, 0x2]
	ldrb r0, [r3, 0x3]
	lsls r0, 8
	orrs r2, r0
	ldrb r1, [r3, 0x4]
	ldrb r0, [r3, 0x5]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x6]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x7]
	lsls r0, 24
	adds r5, r1, r0
	ldr r1, =gSideAffecting
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _0804A148
	str r5, [r6]
	b _0804A14E
	.pool
_0804A148:
	adds r0, r3, 0
	adds r0, 0x8
	str r0, [r6]
_0804A14E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk1F_jumpifsideaffecting

	thumb_func_start atk20_jumpifstat
atk20_jumpifstat: @ 804A154
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleMons
	ldr r3, [r4]
	movs r1, 0x58
	muls r0, r1
	ldrb r1, [r3, 0x3]
	adds r0, r1
	adds r2, 0x18
	adds r0, r2
	ldrb r2, [r0]
	ldrb r0, [r3, 0x2]
	cmp r0, 0x5
	bhi _0804A212
	lsls r0, 2
	ldr r1, =_0804A194
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804A194:
	.4byte _0804A1AC
	.4byte _0804A1BC
	.4byte _0804A1CC
	.4byte _0804A1DC
	.4byte _0804A1EC
	.4byte _0804A200
_0804A1AC:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	bne _0804A212
	b _0804A20C
	.pool
_0804A1BC:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	beq _0804A212
	b _0804A20C
	.pool
_0804A1CC:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	bls _0804A212
	b _0804A20C
	.pool
_0804A1DC:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	cmp r2, r0
	bcs _0804A212
	b _0804A20C
	.pool
_0804A1EC:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	ands r2, r0
	cmp r2, 0
	beq _0804A212
	b _0804A20C
	.pool
_0804A200:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x4]
	ands r2, r0
	cmp r2, 0
	bne _0804A212
_0804A20C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0804A212:
	cmp r5, 0
	beq _0804A238
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	adds r1, r0
	str r1, [r3]
	b _0804A240
	.pool
_0804A238:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x9
	str r0, [r1]
_0804A240:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk20_jumpifstat

	thumb_func_start atk21_jumpifstatus3
atk21_jumpifstatus3: @ 804A24C
	push {r4-r6,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r5, =gActiveBank
	strb r0, [r5]
	ldr r2, [r4]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	adds r6, r1, r0
	ldrb r1, [r2, 0x7]
	ldrb r0, [r2, 0x8]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x9]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0xA]
	lsls r0, 24
	adds r3, r1, r0
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _0804A2AC
	ldr r0, =gStatuses3
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	ands r0, r6
	cmp r0, 0
	bne _0804A2C4
	b _0804A2BC
	.pool
_0804A2AC:
	ldr r0, =gStatuses3
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	ands r0, r6
	cmp r0, 0
	beq _0804A2C4
_0804A2BC:
	str r3, [r4]
	b _0804A2CA
	.pool
_0804A2C4:
	adds r0, r2, 0
	adds r0, 0xB
	str r0, [r4]
_0804A2CA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk21_jumpifstatus3

	thumb_func_start atk22_jumpiftype
atk22_jumpiftype: @ 804A2D0
	push {r4-r6,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [r4]
	ldrb r5, [r3, 0x2]
	ldrb r2, [r3, 0x3]
	ldrb r1, [r3, 0x4]
	lsls r1, 8
	adds r2, r1
	ldrb r1, [r3, 0x5]
	lsls r1, 16
	adds r2, r1
	ldrb r1, [r3, 0x6]
	lsls r1, 24
	adds r6, r2, r1
	ldr r2, =gBattleMons
	movs r1, 0x58
	muls r0, r1
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, r5
	beq _0804A314
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, r5
	bne _0804A320
_0804A314:
	str r6, [r4]
	b _0804A324
	.pool
_0804A320:
	adds r0, r3, 0x7
	str r0, [r4]
_0804A324:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk22_jumpiftype

	thumb_func_start atk23_getexp
atk23_getexp: @ 804A32C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r6, 0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x50
	mov r9, r0
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gUnknown_0202420D
	strb r0, [r1]
	ldr r2, =gUnknown_020243FE
	movs r1, 0x2
	ands r1, r0
	lsls r1, 24
	lsrs r1, 25
	adds r1, r2
	ldrb r1, [r1]
	mov r8, r1
	ldr r0, =gBattleScripting
	ldrb r0, [r0, 0x1C]
	cmp r0, 0x6
	bls _0804A368
	bl _0804ACB2
_0804A368:
	lsls r0, 2
	ldr r1, =_0804A38C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804A38C:
	.4byte _0804A3A8
	.4byte _0804A414
	.4byte _0804A52E
	.4byte _0804A850
	.4byte _0804A954
	.4byte _0804AC40
	.4byte _0804AC88
_0804A3A8:
	ldr r4, =gUnknown_0202420D
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0804A3BC
	bl _0804AC7C
_0804A3BC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x063f0982
	ands r0, r1
	cmp r0, 0
	beq _0804A3CC
	bl _0804AC7C
_0804A3CC:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x1C]
	adds r0, 0x1
	strb r0, [r1, 0x1C]
	ldr r0, =gBattleStruct
	ldr r2, [r0]
	adds r2, 0xDF
	ldr r3, =gBitTable
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	bl _0804ACB2
	.pool
_0804A414:
	movs r5, 0
	movs r7, 0
_0804A418:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804A486
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804A486
	ldr r0, =gBitTable
	lsls r1, r7, 2
	adds r1, r0
	ldr r0, [r1]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	beq _0804A44C
	adds r5, 0x1
_0804A44C:
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _0804A478
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003226
	adds r0, r2
	ldrb r4, [r0]
	b _0804A480
	.pool
_0804A478:
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
_0804A480:
	cmp r4, 0x19
	bne _0804A486
	adds r6, 0x1
_0804A486:
	adds r7, 0x1
	cmp r7, 0x5
	ble _0804A418
	ldr r3, =gBaseStats
	ldr r2, =gBattleMons
	ldr r0, =gUnknown_0202420D
	ldrb r1, [r0]
	movs r0, 0x58
	muls r1, r0
	adds r1, r2
	ldrh r2, [r1]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r2, [r0, 0x9]
	adds r1, 0x2A
	ldrb r0, [r1]
	muls r0, r2
	movs r1, 0x7
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r6, 0
	beq _0804A4FC
	lsrs r4, r0, 17
	adds r0, r4, 0
	adds r1, r5, 0
	bl __divsi3
	mov r1, r9
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bne _0804A4D2
	movs r0, 0x1
	strh r0, [r1]
_0804A4D2:
	ldr r5, =gUnknown_02024402
	adds r0, r4, 0
	adds r1, r6, 0
	bl __divsi3
	strh r0, [r5]
	lsls r0, 16
	cmp r0, 0
	bne _0804A516
	movs r0, 0x1
	strh r0, [r5]
	b _0804A516
	.pool
_0804A4FC:
	adds r0, r1, 0
	adds r1, r5, 0
	bl __divsi3
	mov r2, r9
	strh r0, [r2]
	lsls r0, 16
	cmp r0, 0
	bne _0804A512
	movs r0, 0x1
	strh r0, [r2]
_0804A512:
	ldr r0, =gUnknown_02024402
	strh r6, [r0]
_0804A516:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x1C]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1, 0x1C]
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	strb r2, [r0, 0x10]
	ldr r0, [r1]
	adds r0, 0x53
	mov r4, r8
	strb r4, [r0]
_0804A52E:
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0804A538
	b _0804ACB2
_0804A538:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _0804A57C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003226
	adds r0, r1
	ldrb r4, [r0]
	b _0804A584
	.pool
_0804A57C:
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
_0804A584:
	ldr r5, =gBattleStruct
	cmp r4, 0x19
	beq _0804A5AC
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0x53
	ldrb r0, [r1]
	movs r2, 0x1
	ands r2, r0
	cmp r2, 0
	bne _0804A5AC
	lsrs r0, 1
	strb r0, [r1]
	ldr r1, =gBattleScripting
	b _0804A5D0
	.pool
_0804A5AC:
	ldr r0, [r5]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	bl GetMonData
	cmp r0, 0x64
	bne _0804A5E8
	ldr r1, [r5]
	adds r1, 0x53
	ldrb r0, [r1]
	lsrs r0, 1
	strb r0, [r1]
	ldr r1, =gBattleScripting
	movs r2, 0
_0804A5D0:
	movs r0, 0x5
	strb r0, [r1, 0x1C]
	ldr r0, =gBattleMoveDamage
	str r2, [r0]
	b _0804ACB2
	.pool
_0804A5E8:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0804A616
	ldr r0, =gBattleMons
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _0804A616
	ldr r0, [r5]
	ldrb r0, [r0, 0x12]
	cmp r0, 0
	bne _0804A616
	bl sub_805EA60
	ldr r0, =0x00000161
	bl PlayBGM
	ldr r1, [r5]
	ldrb r0, [r1, 0x12]
	adds r0, 0x1
	strb r0, [r1, 0x12]
_0804A616:
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _0804A630
	b _0804A824
_0804A630:
	ldr r0, [r5]
	adds r0, 0x53
	ldrb r0, [r0]
	movs r3, 0x1
	ands r3, r0
	cmp r3, 0
	beq _0804A664
	ldr r1, =gBattleMoveDamage
	mov r2, r9
	ldrh r0, [r2]
	str r0, [r1]
	mov r9, r1
	b _0804A66A
	.pool
_0804A664:
	ldr r0, =gBattleMoveDamage
	str r3, [r0]
	mov r9, r0
_0804A66A:
	cmp r4, 0x19
	bne _0804A67A
	ldr r0, =gUnknown_02024402
	ldrh r1, [r0]
	mov r2, r9
	ldr r0, [r2]
	adds r0, r1
	str r0, [r2]
_0804A67A:
	cmp r4, 0x28
	bne _0804A68E
	mov r4, r9
	ldr r1, [r4]
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
_0804A68E:
	ldr r5, =gBattleTypeFlags
	ldr r0, [r5]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0804A6AA
	ldr r4, =gBattleMoveDamage
	ldr r1, [r4]
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
_0804A6AA:
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl IsTradedMon
	lsls r0, 24
	cmp r0, 0
	beq _0804A714
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _0804A6F8
	ldr r0, [r4]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x2
	bls _0804A6F8
	ldr r7, =0x00000149
	ldr r0, =gBattleMoveDamage
	mov r9, r0
	b _0804A71A
	.pool
_0804A6F8:
	ldr r4, =gBattleMoveDamage
	ldr r1, [r4]
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	movs r7, 0xA5
	lsls r7, 1
	mov r9, r4
	b _0804A71A
	.pool
_0804A714:
	ldr r7, =0x00000149
	ldr r1, =gBattleMoveDamage
	mov r9, r1
_0804A71A:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0804A786
	ldr r0, =gBattlePartyID
	ldr r1, =gBattleStruct
	ldr r4, [r1]
	ldrh r0, [r0, 0x4]
	adds r5, r1, 0
	ldr r3, =gBitTable
	ldr r2, =gAbsentBankFlags
	ldrb r1, [r4, 0x10]
	cmp r0, r1
	bne _0804A76C
	ldrb r1, [r2]
	ldr r0, [r3, 0x8]
	ands r1, r0
	cmp r1, 0
	bne _0804A76C
	adds r1, r4, 0
	adds r1, 0x8F
	movs r0, 0x2
	strb r0, [r1]
	b _0804A78E
	.pool
_0804A76C:
	ldrb r2, [r2]
	ldr r0, [r3]
	ands r2, r0
	cmp r2, 0
	bne _0804A77E
	ldr r0, [r5]
	adds r0, 0x8F
	strb r2, [r0]
	b _0804A78E
_0804A77E:
	ldr r0, [r5]
	adds r0, 0x8F
	movs r1, 0x2
	b _0804A78C
_0804A786:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x8F
_0804A78C:
	strb r1, [r0]
_0804A78E:
	ldr r1, =gBattleTextBuff1
	movs r2, 0
	mov r12, r2
	movs r3, 0xFD
	strb r3, [r1]
	movs r5, 0x4
	strb r5, [r1, 0x1]
	ldr r6, =gBattleStruct
	ldr r2, [r6]
	movs r4, 0x8F
	adds r4, r2
	mov r8, r4
	ldrb r0, [r4]
	strb r0, [r1, 0x2]
	ldrb r0, [r2, 0x10]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattleTextBuff2
	strb r3, [r1]
	mov r0, r12
	strb r0, [r1, 0x1]
	strb r7, [r1, 0x2]
	movs r4, 0xFF
	lsls r4, 8
	ands r7, r4
	asrs r0, r7, 8
	strb r0, [r1, 0x3]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1, 0x4]
	ldr r1, =gBattleTextBuff3
	strb r3, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	strb r5, [r1, 0x2]
	movs r0, 0x5
	strb r0, [r1, 0x3]
	mov r0, r9
	ldr r2, [r0]
	strb r2, [r1, 0x4]
	adds r0, r2, 0
	ands r0, r4
	asrs r0, 8
	strb r0, [r1, 0x5]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r2
	asrs r0, 16
	strb r0, [r1, 0x6]
	lsrs r2, 24
	strb r2, [r1, 0x7]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1, 0x8]
	mov r2, r8
	ldrb r1, [r2]
	movs r0, 0xD
	bl b_std_message
	ldr r0, [r6]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r3, =gBattleMons
	ldr r1, =gUnknown_0202420D
	ldrb r2, [r1]
	movs r1, 0x58
	muls r1, r2
	adds r1, r3
	ldrh r1, [r1]
	bl MonGainEVs
_0804A824:
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r1, 0x53
	ldrb r0, [r1]
	lsrs r0, 1
	strb r0, [r1]
	b _0804A92A
	.pool
_0804A850:
	ldr r0, =gBattleExecBuffer
	ldr r2, [r0]
	cmp r2, 0
	beq _0804A85A
	b _0804ACB2
_0804A85A:
	ldr r1, =gBattleBufferB
	ldr r7, =gBattleStruct
	ldr r0, [r7]
	adds r0, 0x8F
	ldrb r0, [r0]
	lsls r0, 9
	adds r0, r1
	strb r2, [r0]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804A92A
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0x38
	bl GetMonData
	cmp r0, 0x64
	beq _0804A92A
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0x3A
	bl GetMonData
	ldr r4, =gBattleResources
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	strh r0, [r1]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0x3B
	bl GetMonData
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	strh r0, [r1, 0x2]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0x3C
	bl GetMonData
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	strh r0, [r1, 0x4]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0x3D
	bl GetMonData
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	strh r0, [r1, 0x6]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0x3E
	bl GetMonData
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	strh r0, [r1, 0x8]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0x3F
	bl GetMonData
	ldr r1, [r4]
	ldr r1, [r1, 0x10]
	strh r0, [r1, 0xA]
	ldr r4, =gActiveBank
	ldr r1, [r7]
	adds r0, r1, 0
	adds r0, 0x8F
	ldrb r0, [r0]
	strb r0, [r4]
	ldrb r1, [r1, 0x10]
	ldr r0, =gBattleMoveDamage
	ldrh r2, [r0]
	movs r0, 0
	bl dp01_build_cmdbuf_x19_a_bb
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804A92A:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x1C]
	adds r0, 0x1
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804A954:
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0804A95E
	b _0804ACB2
_0804A95E:
	ldr r1, =gActiveBank
	ldr r0, =gBattleStruct
	ldr r4, [r0]
	adds r0, r4, 0
	adds r0, 0x8F
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r3, =gBattleBufferB
	ldrb r2, [r1]
	lsls r1, r2, 9
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0x21
	beq _0804A97C
	b _0804AC28
_0804A97C:
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0xB
	beq _0804A988
	b _0804AC28
_0804A988:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0804A9B2
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrh r0, [r1]
	ldrb r4, [r4, 0x10]
	cmp r0, r4
	bne _0804A9B2
	adds r1, r0, 0
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r2, 0
	bl sub_805E990
_0804A9B2:
	ldr r1, =gBattleTextBuff1
	movs r3, 0xFD
	strb r3, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	strb r0, [r1, 0x2]
	ldr r4, =gBattleStruct
	mov r9, r4
	ldr r2, [r4]
	ldrb r0, [r2, 0x10]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r4, =gBattleTextBuff2
	strb r3, [r4]
	movs r0, 0x1
	strb r0, [r4, 0x1]
	strb r0, [r4, 0x2]
	movs r0, 0x3
	strb r0, [r4, 0x3]
	ldrb r0, [r2, 0x10]
	movs r1, 0x64
	mov r8, r1
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	ldr r7, =gPlayerParty
	adds r0, r7
	movs r1, 0x38
	bl GetMonData
	strb r0, [r4, 0x4]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r4, 0x5]
	bl b_movescr_stack_push_cursor
	ldr r2, =gUnknown_03005D54
	ldr r1, =gBitTable
	mov r4, r9
	ldr r5, [r4]
	ldrb r0, [r5, 0x10]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DABBD
	str r0, [r1]
	ldr r4, =gBattleMoveDamage
	ldr r2, =gBattleBufferB
	ldrb r1, [r6]
	lsls r1, 9
	adds r0, r2, 0x2
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r2, 0x3
	adds r1, r2
	ldrb r0, [r1]
	lsls r0, 8
	orrs r3, r0
	str r3, [r4]
	ldrb r0, [r5, 0x10]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r7
	movs r1, 0
	bl AdjustFriendship
	ldr r1, =gBattlePartyID
	mov r2, r9
	ldr r0, [r2]
	ldrb r2, [r0, 0x10]
	ldrh r0, [r1]
	cmp r0, r2
	bne _0804AB1E
	ldr r4, =gBattleMons
	ldrh r0, [r4, 0x28]
	cmp r0, 0
	beq _0804AB1E
	mov r0, r8
	muls r0, r2
	adds r0, r7
	movs r1, 0x38
	bl GetMonData
	adds r1, r4, 0
	adds r1, 0x2A
	strb r0, [r1]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x39
	bl GetMonData
	strh r0, [r4, 0x28]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r4, 0x2C]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x3B
	bl GetMonData
	strh r0, [r4, 0x2]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x3C
	bl GetMonData
	strh r0, [r4, 0x4]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x3D
	bl GetMonData
	strh r0, [r4, 0x6]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x3D
	bl GetMonData
	strh r0, [r4, 0x6]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x3E
	bl GetMonData
	strh r0, [r4, 0x8]
	mov r1, r9
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	movs r1, 0x3F
	bl GetMonData
	strh r0, [r4, 0xA]
_0804AB1E:
	ldr r0, =gBattlePartyID
	ldr r7, =gBattleStruct
	ldr r1, [r7]
	ldrb r2, [r1, 0x10]
	ldrh r0, [r0, 0x4]
	cmp r0, r2
	beq _0804AB2E
	b _0804AC2E
_0804AB2E:
	ldr r6, =gBattleMons
	movs r4, 0xD8
	adds r4, r6
	mov r8, r4
	ldrh r0, [r4]
	cmp r0, 0
	beq _0804AC2E
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804AC2E
	movs r5, 0x64
	adds r0, r2, 0
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x38
	bl GetMonData
	adds r1, r6, 0
	adds r1, 0xDA
	strb r0, [r1]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	adds r1, r6, 0
	adds r1, 0xDC
	strh r0, [r1]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	movs r1, 0x3B
	bl GetMonData
	adds r1, r6, 0
	adds r1, 0xB2
	strh r0, [r1]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	movs r1, 0x3C
	bl GetMonData
	adds r1, r6, 0
	adds r1, 0xB4
	strh r0, [r1]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	movs r1, 0x3D
	bl GetMonData
	movs r2, 0xB6
	adds r2, r6
	mov r8, r2
	strh r0, [r2]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	movs r1, 0x3D
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	ldr r0, [r7]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	movs r1, 0x3E
	bl GetMonData
	adds r1, r6, 0
	adds r1, 0xB8
	strh r0, [r1]
	b _0804AC2E
	.pool
_0804AC28:
	ldr r1, =gBattleMoveDamage
	movs r0, 0
	str r0, [r1]
_0804AC2E:
	ldr r1, =gBattleScripting
	movs r0, 0x5
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC40:
	ldr r0, =gBattleMoveDamage
	ldr r0, [r0]
	cmp r0, 0
	beq _0804AC58
	ldr r1, =gBattleScripting
	movs r0, 0x3
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC58:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x5
	bhi _0804AC7C
	ldr r1, =gBattleScripting
	movs r0, 0x2
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC7C:
	ldr r1, =gBattleScripting
	movs r0, 0x6
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC88:
	ldr r0, =gBattleExecBuffer
	ldr r5, [r0]
	cmp r5, 0
	bne _0804ACB2
	ldr r4, =gBattleMons
	ldr r2, =gUnknown_0202420D
	ldrb r0, [r2]
	movs r1, 0x58
	muls r0, r1
	adds r0, r4
	movs r3, 0
	strh r5, [r0, 0x2E]
	ldrb r0, [r2]
	muls r0, r1
	adds r0, r4
	adds r0, 0x20
	strb r3, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_0804ACB2:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk23_getexp

	thumb_func_start atk24
atk24: @ 804ACD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0804ACE2
	b _0804AF22
_0804ACE2:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _0804AD48
	ldr r0, =gUnknown_02038BCE
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _0804AD48
	movs r5, 0
_0804ACFC:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804AD2C
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0804AD2C
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
_0804AD2C:
	adds r5, 0x1
	cmp r5, 0x2
	ble _0804ACFC
	b _0804ADA8
	.pool
_0804AD48:
	movs r5, 0
_0804AD4A:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804ADA2
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0804ADA2
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0804AD94
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	movs r1, 0xA8
	lsls r1, 2
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0804ADA2
_0804AD94:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
_0804ADA2:
	adds r5, 0x1
	cmp r5, 0x5
	ble _0804AD4A
_0804ADA8:
	cmp r6, 0
	bne _0804ADB6
	ldr r0, =gBattleOutcome
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
_0804ADB6:
	movs r6, 0
	movs r5, 0
_0804ADBA:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804AE10
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0804AE10
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0804AE02
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldr r1, =0x000002a1
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0804AE10
_0804AE02:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	adds r0, r6, r0
	lsls r0, 16
	lsrs r6, r0, 16
_0804AE10:
	adds r5, 0x1
	cmp r5, 0x5
	ble _0804ADBA
	ldr r2, =gBattleOutcome
	cmp r6, 0
	bne _0804AE24
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_0804AE24:
	ldrb r0, [r2]
	cmp r0, 0
	bne _0804AF1A
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r2, =0x02000002
	ands r1, r2
	mov r8, r0
	cmp r1, 0
	beq _0804AF1A
	movs r3, 0
	movs r5, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	mov r12, r0
	ldr r7, =gBattlescriptCurrInstr
	cmp r3, r1
	bge _0804AE70
	ldr r0, =gHitMarker
	movs r6, 0x80
	lsls r6, 21
	ldr r4, [r0]
	adds r2, r1, 0
	ldr r1, =gSpecialStatuses
_0804AE54:
	adds r0, r6, 0
	lsls r0, r5
	ands r0, r4
	cmp r0, 0
	beq _0804AE68
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804AE68
	adds r3, 0x1
_0804AE68:
	adds r1, 0x28
	adds r5, 0x2
	cmp r5, r2
	blt _0804AE54
_0804AE70:
	movs r2, 0
	movs r5, 0x1
	mov r4, r12
	ldrb r1, [r4]
	cmp r5, r1
	bge _0804AEAA
	ldr r0, =gHitMarker
	movs r4, 0x80
	lsls r4, 21
	mov r12, r4
	ldr r6, [r0]
	ldr r0, =gSpecialStatuses
	adds r4, r1, 0
	adds r1, r0, 0
	adds r1, 0x14
_0804AE8E:
	mov r0, r12
	lsls r0, r5
	ands r0, r6
	cmp r0, 0
	beq _0804AEA2
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804AEA2
	adds r2, 0x1
_0804AEA2:
	adds r1, 0x28
	adds r5, 0x2
	cmp r5, r4
	blt _0804AE8E
_0804AEAA:
	mov r1, r8
	ldr r0, [r1]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804AEF0
	adds r0, r2, r3
	cmp r0, 0x1
	bgt _0804AEF8
	b _0804AF12
	.pool
_0804AEF0:
	cmp r2, 0
	beq _0804AF12
	cmp r3, 0
	beq _0804AF12
_0804AEF8:
	ldr r2, [r7]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	str r1, [r7]
	b _0804AF22
_0804AF12:
	ldr r0, [r7]
	adds r0, 0x5
	str r0, [r7]
	b _0804AF22
_0804AF1A:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0804AF22:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk24

	thumb_func_start sub_804AF30
sub_804AF30: @ 804AF30
	ldr r1, =gBattleMoveFlags
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gBattleScripting
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0, 0xE]
	ldr r0, =gCritMultiplier
	strb r1, [r0]
	ldr r0, =gBattleCommunication
	strb r2, [r0, 0x3]
	strb r2, [r0, 0x6]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	subs r1, 0x42
	ands r0, r1
	ldr r1, =0xffffbfff
	ands r0, r1
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_804AF30

	thumb_func_start atk25_move_values_cleanup
atk25_move_values_cleanup: @ 804AF70
	push {lr}
	bl sub_804AF30
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk25_move_values_cleanup

	thumb_func_start atk26_set_multihit
atk26_set_multihit: @ 804AF88
	ldr r3, =gUnknown_02024212
	ldr r2, =gBattlescriptCurrInstr
	ldr r0, [r2]
	ldrb r1, [r0, 0x1]
	strb r1, [r3]
	adds r0, 0x2
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end atk26_set_multihit

	thumb_func_start atk27_decrement_multihit
atk27_decrement_multihit: @ 804AFA0
	push {lr}
	ldr r1, =gUnknown_02024212
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _0804AFC4
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _0804AFDE
	.pool
_0804AFC4:
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	str r1, [r3]
_0804AFDE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk27_decrement_multihit

	thumb_func_start atk28_goto
atk28_goto: @ 804AFE8
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	str r1, [r3]
	bx lr
	.pool
	thumb_func_end atk28_goto

	thumb_func_start atk29_jumpifbyte
atk29_jumpifbyte: @ 804B008
	push {r4-r6,lr}
	ldr r3, =gBattlescriptCurrInstr
	ldr r1, [r3]
	ldrb r6, [r1, 0x1]
	ldrb r2, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	adds r5, r2, r0
	ldrb r4, [r1, 0x6]
	ldrb r2, [r1, 0x7]
	ldrb r0, [r1, 0x8]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x9]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0xA]
	lsls r0, 24
	adds r2, r0
	adds r1, 0xB
	str r1, [r3]
	cmp r6, 0x5
	bhi _0804B0A0
	lsls r0, r6, 2
	ldr r1, =_0804B054
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804B054:
	.4byte _0804B06C
	.4byte _0804B074
	.4byte _0804B07C
	.4byte _0804B084
	.4byte _0804B08C
	.4byte _0804B096
_0804B06C:
	ldrb r0, [r5]
	cmp r0, r4
	bne _0804B0A0
	b _0804B09E
_0804B074:
	ldrb r0, [r5]
	cmp r0, r4
	beq _0804B0A0
	b _0804B09E
_0804B07C:
	ldrb r0, [r5]
	cmp r0, r4
	bls _0804B0A0
	b _0804B09E
_0804B084:
	ldrb r0, [r5]
	cmp r0, r4
	bcs _0804B0A0
	b _0804B09E
_0804B08C:
	ldrb r0, [r5]
	ands r4, r0
	cmp r4, 0
	beq _0804B0A0
	b _0804B09E
_0804B096:
	ldrb r0, [r5]
	ands r4, r0
	cmp r4, 0
	bne _0804B0A0
_0804B09E:
	str r2, [r3]
_0804B0A0:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk29_jumpifbyte

	thumb_func_start atk2A_jumpifhalfword
atk2A_jumpifhalfword: @ 804B0A8
	push {r4-r6,lr}
	ldr r3, =gBattlescriptCurrInstr
	ldr r1, [r3]
	ldrb r6, [r1, 0x1]
	ldrb r2, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	adds r5, r2, r0
	ldrb r4, [r1, 0x6]
	ldrb r0, [r1, 0x7]
	lsls r0, 8
	orrs r4, r0
	ldrb r2, [r1, 0x8]
	ldrb r0, [r1, 0x9]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0xA]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0xB]
	lsls r0, 24
	adds r2, r0
	adds r1, 0xC
	str r1, [r3]
	cmp r6, 0x5
	bhi _0804B148
	lsls r0, r6, 2
	ldr r1, =_0804B0FC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804B0FC:
	.4byte _0804B114
	.4byte _0804B11C
	.4byte _0804B124
	.4byte _0804B12C
	.4byte _0804B134
	.4byte _0804B13E
_0804B114:
	ldrh r0, [r5]
	cmp r0, r4
	bne _0804B148
	b _0804B146
_0804B11C:
	ldrh r0, [r5]
	cmp r0, r4
	beq _0804B148
	b _0804B146
_0804B124:
	ldrh r0, [r5]
	cmp r0, r4
	bls _0804B148
	b _0804B146
_0804B12C:
	ldrh r0, [r5]
	cmp r0, r4
	bcs _0804B148
	b _0804B146
_0804B134:
	ldrh r0, [r5]
	ands r4, r0
	cmp r4, 0
	beq _0804B148
	b _0804B146
_0804B13E:
	ldrh r0, [r5]
	ands r4, r0
	cmp r4, 0
	bne _0804B148
_0804B146:
	str r2, [r3]
_0804B148:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk2A_jumpifhalfword

	thumb_func_start atk2B_jumpifword
atk2B_jumpifword: @ 804B150
	push {r4-r6,lr}
	ldr r3, =gBattlescriptCurrInstr
	ldr r1, [r3]
	ldrb r6, [r1, 0x1]
	ldrb r2, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	adds r5, r2, r0
	ldrb r4, [r1, 0x6]
	ldrb r0, [r1, 0x7]
	lsls r0, 8
	orrs r4, r0
	ldrb r0, [r1, 0x8]
	lsls r0, 16
	orrs r4, r0
	ldrb r0, [r1, 0x9]
	lsls r0, 24
	orrs r4, r0
	ldrb r2, [r1, 0xA]
	ldrb r0, [r1, 0xB]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0xC]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0xD]
	lsls r0, 24
	adds r2, r0
	adds r1, 0xE
	str r1, [r3]
	cmp r6, 0x5
	bhi _0804B1FC
	lsls r0, r6, 2
	ldr r1, =_0804B1B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804B1B0:
	.4byte _0804B1C8
	.4byte _0804B1D0
	.4byte _0804B1D8
	.4byte _0804B1E0
	.4byte _0804B1E8
	.4byte _0804B1F2
_0804B1C8:
	ldr r0, [r5]
	cmp r0, r4
	bne _0804B1FC
	b _0804B1FA
_0804B1D0:
	ldr r0, [r5]
	cmp r0, r4
	beq _0804B1FC
	b _0804B1FA
_0804B1D8:
	ldr r0, [r5]
	cmp r0, r4
	bls _0804B1FC
	b _0804B1FA
_0804B1E0:
	ldr r0, [r5]
	cmp r0, r4
	bcs _0804B1FC
	b _0804B1FA
_0804B1E8:
	ldr r0, [r5]
	ands r0, r4
	cmp r0, 0
	beq _0804B1FC
	b _0804B1FA
_0804B1F2:
	ldr r0, [r5]
	ands r0, r4
	cmp r0, 0
	bne _0804B1FC
_0804B1FA:
	str r2, [r3]
_0804B1FC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk2B_jumpifword

	thumb_func_start atk2C_jumpifarrayequal
atk2C_jumpifarrayequal: @ 804B204
	push {r4-r7,lr}
	ldr r2, =gBattlescriptCurrInstr
	ldr r3, [r2]
	ldrb r1, [r3, 0x1]
	ldrb r0, [r3, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 24
	adds r5, r1, r0
	ldrb r1, [r3, 0x5]
	ldrb r0, [r3, 0x6]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x7]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x8]
	lsls r0, 24
	adds r4, r1, r0
	ldrb r6, [r3, 0x9]
	ldrb r1, [r3, 0xA]
	ldrb r0, [r3, 0xB]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0xC]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0xD]
	lsls r0, 24
	adds r1, r0
	mov r12, r1
	movs r1, 0
	cmp r1, r6
	bcs _0804B27C
	ldrb r0, [r5]
	ldrb r7, [r4]
	cmp r0, r7
	beq _0804B260
	adds r0, r3, 0
	b _0804B278
	.pool
_0804B260:
	adds r5, 0x1
	adds r4, 0x1
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r6
	bcs _0804B27C
	ldrb r0, [r5]
	ldrb r3, [r4]
	cmp r0, r3
	beq _0804B260
	ldr r0, [r2]
_0804B278:
	adds r0, 0xE
	str r0, [r2]
_0804B27C:
	cmp r1, r6
	bne _0804B284
	mov r7, r12
	str r7, [r2]
_0804B284:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk2C_jumpifarrayequal

	thumb_func_start atk2D_jumpifarraynotequal
atk2D_jumpifarraynotequal: @ 804B28C
	push {r4-r7,lr}
	movs r7, 0
	ldr r3, =gBattlescriptCurrInstr
	ldr r1, [r3]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	adds r5, r2, r0
	ldrb r2, [r1, 0x5]
	ldrb r0, [r1, 0x6]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x7]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x8]
	lsls r0, 24
	adds r4, r2, r0
	ldrb r6, [r1, 0x9]
	ldrb r2, [r1, 0xA]
	ldrb r0, [r1, 0xB]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0xC]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0xD]
	lsls r0, 24
	adds r2, r0
	mov r12, r2
	movs r1, 0
	cmp r7, r6
	bcs _0804B2F6
_0804B2DA:
	ldrb r0, [r5]
	ldrb r2, [r4]
	cmp r0, r2
	bne _0804B2E8
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_0804B2E8:
	adds r5, 0x1
	adds r4, 0x1
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, r6
	bcc _0804B2DA
_0804B2F6:
	cmp r7, r6
	beq _0804B304
	mov r0, r12
	b _0804B308
	.pool
_0804B304:
	ldr r0, [r3]
	adds r0, 0xE
_0804B308:
	str r0, [r3]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk2D_jumpifarraynotequal

	thumb_func_start atk2E_setbyte
atk2E_setbyte: @ 804B310
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	ldrb r0, [r2, 0x5]
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x6
	str r0, [r3]
	bx lr
	.pool
	thumb_func_end atk2E_setbyte

	thumb_func_start atk2F_addbyte
atk2F_addbyte: @ 804B338
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	ldrb r0, [r2, 0x5]
	ldrb r2, [r1]
	adds r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x6
	str r0, [r3]
	bx lr
	.pool
	thumb_func_end atk2F_addbyte

	thumb_func_start atk30_subbyte
atk30_subbyte: @ 804B364
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	ldrb r0, [r1]
	ldrb r2, [r2, 0x5]
	subs r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x6
	str r0, [r3]
	bx lr
	.pool
	thumb_func_end atk30_subbyte

	thumb_func_start atk31_copyarray
atk31_copyarray: @ 804B390
	push {r4-r6,lr}
	ldr r3, =gBattlescriptCurrInstr
	ldr r1, [r3]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	adds r6, r2, r0
	ldrb r2, [r1, 0x5]
	ldrb r0, [r1, 0x6]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x7]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x8]
	lsls r0, 24
	adds r5, r2, r0
	ldrb r4, [r1, 0x9]
	movs r2, 0
	cmp r2, r4
	bge _0804B3D4
_0804B3C6:
	adds r0, r6, r2
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r4
	blt _0804B3C6
_0804B3D4:
	ldr r0, [r3]
	adds r0, 0xA
	str r0, [r3]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk31_copyarray

	thumb_func_start atk32_copyarray_withindex
atk32_copyarray_withindex: @ 804B3E4
	push {r4-r7,lr}
	ldr r3, =gBattlescriptCurrInstr
	ldr r1, [r3]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	adds r7, r2, r0
	ldrb r2, [r1, 0x5]
	ldrb r0, [r1, 0x6]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0x7]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0x8]
	lsls r0, 24
	adds r6, r2, r0
	ldrb r2, [r1, 0x9]
	ldrb r0, [r1, 0xA]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r1, 0xB]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r1, 0xC]
	lsls r0, 24
	adds r5, r2, r0
	ldrb r4, [r1, 0xD]
	movs r2, 0
	cmp r2, r4
	bge _0804B440
_0804B42E:
	adds r0, r7, r2
	ldrb r1, [r5]
	adds r1, r2, r1
	adds r1, r6, r1
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, r4
	blt _0804B42E
_0804B440:
	ldr r0, [r3]
	adds r0, 0xE
	str r0, [r3]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk32_copyarray_withindex

	thumb_func_start atk33_orbyte
atk33_orbyte: @ 804B450
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	ldrb r0, [r1]
	ldrb r2, [r2, 0x5]
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x6
	str r0, [r3]
	bx lr
	.pool
	thumb_func_end atk33_orbyte

	thumb_func_start atk34_orhalfword
atk34_orhalfword: @ 804B47C
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r3, [r4]
	ldrb r2, [r3, 0x1]
	ldrb r0, [r3, 0x2]
	lsls r0, 8
	adds r2, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 16
	adds r2, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 24
	adds r2, r0
	ldrb r1, [r3, 0x5]
	ldrb r0, [r3, 0x6]
	lsls r0, 8
	orrs r1, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	ldr r0, [r4]
	adds r0, 0x7
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk34_orhalfword

	thumb_func_start atk35_orword
atk35_orword: @ 804B4B4
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r2, [r4]
	ldrb r3, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r3, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r3, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r3, r0
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	adds r1, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, [r4]
	adds r0, 0x9
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk35_orword

	thumb_func_start atk36_bicbyte
atk36_bicbyte: @ 804B4F8
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r1, r0
	ldrb r2, [r2, 0x5]
	ldrb r0, [r1]
	bics r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	adds r0, 0x6
	str r0, [r3]
	bx lr
	.pool
	thumb_func_end atk36_bicbyte

	thumb_func_start atk37_bichalfword
atk37_bichalfword: @ 804B524
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r3, [r4]
	ldrb r1, [r3, 0x1]
	ldrb r0, [r3, 0x2]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r3, 0x3]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r3, 0x4]
	lsls r0, 24
	adds r1, r0
	ldrb r2, [r3, 0x5]
	ldrb r0, [r3, 0x6]
	lsls r0, 8
	orrs r2, r0
	ldrh r0, [r1]
	bics r0, r2
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, 0x7
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk37_bichalfword

	thumb_func_start atk38_bicword
atk38_bicword: @ 804B55C
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r2, [r4]
	ldrb r3, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	adds r3, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	adds r3, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	adds r3, r0
	ldrb r1, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	adds r1, r0
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	ldr r0, [r4]
	adds r0, 0x9
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk38_bicword

	thumb_func_start atk39_pause
atk39_pause: @ 804B5A0
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r4, [r0]
	cmp r4, 0
	bne _0804B5CC
	ldr r5, =gBattlescriptCurrInstr
	ldr r2, [r5]
	ldrb r1, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r1, r0
	ldr r3, =gUnknown_0202432C
	ldrh r0, [r3]
	adds r0, 0x1
	strh r0, [r3]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bcc _0804B5CC
	strh r4, [r3]
	adds r0, r2, 0x3
	str r0, [r5]
_0804B5CC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk39_pause

	thumb_func_start atk3A_waitstate
atk3A_waitstate: @ 804B5E0
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804B5F2
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_0804B5F2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk3A_waitstate

	thumb_func_start atk3B_healthbar_update
atk3B_healthbar_update: @ 804B600
	push {lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0804B620
	ldr r0, =gActiveBank
	ldr r1, =gBankTarget
	b _0804B624
	.pool
_0804B620:
	ldr r0, =gActiveBank
	ldr r1, =gBankAttacker
_0804B624:
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, =gBattleMoveDamage
	ldrh r1, [r0]
	movs r0, 0
	bl dp01_build_cmdbuf_x18_0_aa_health_bar_update
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk3B_healthbar_update

	thumb_func_start atk3C_return
atk3C_return: @ 804B658
	push {lr}
	bl b_movescr_stack_pop_cursor
	pop {r0}
	bx r0
	thumb_func_end atk3C_return

	thumb_func_start atk3D_end
atk3D_end: @ 804B664
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0804B67C
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl sub_81A5718
_0804B67C:
	ldr r0, =gBattleMoveFlags
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gActiveBank
	strb r1, [r0]
	ldr r1, =gFightStateTracker
	movs r0, 0xB
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk3D_end

	thumb_func_start atk3E_end2
atk3E_end2: @ 804B6A4
	ldr r1, =gActiveBank
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0xB
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end atk3E_end2

	thumb_func_start atk3F_end3
atk3F_end3: @ 804B6BC
	push {lr}
	bl b_movescr_stack_pop_cursor
	ldr r3, =gBattleResources
	ldr r0, [r3]
	ldr r0, [r0, 0xC]
	adds r1, r0, 0
	adds r1, 0x20
	ldrb r0, [r1]
	cmp r0, 0
	beq _0804B6D6
	subs r0, 0x1
	strb r0, [r1]
_0804B6D6:
	ldr r2, =gBattleMainFunc
	ldr r0, [r3]
	ldr r1, [r0, 0xC]
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk3F_end3

	thumb_func_start atk41_call
atk41_call: @ 804B6F8
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x5
	bl b_movescr_stack_push
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
	thumb_func_end atk41_call

	thumb_func_start atk42_jumpiftype2
atk42_jumpiftype2: @ 804B728
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [r4]
	ldr r2, =gBattleMons
	movs r1, 0x58
	muls r0, r1
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0x21
	ldrb r2, [r3, 0x2]
	ldrb r1, [r1]
	cmp r2, r1
	beq _0804B756
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r2, r0
	bne _0804B778
_0804B756:
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
	b _0804B77C
	.pool
_0804B778:
	adds r0, r3, 0x7
	str r0, [r4]
_0804B77C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end atk42_jumpiftype2

	thumb_func_start atk43_jumpifabilitypresent
atk43_jumpifabilitypresent: @ 804B784
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r2, [r0, 0x1]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _0804B7C0
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
	b _0804B7C6
	.pool
_0804B7C0:
	ldr r0, [r4]
	adds r0, 0x6
	str r0, [r4]
_0804B7C6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end atk43_jumpifabilitypresent

	thumb_func_start atk44
atk44: @ 804B7D0
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x54
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end atk44

	thumb_func_start atk45_playanimation
atk45_playanimation: @ 804B7EC
	push {r4-r6,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r6, =gActiveBank
	strb r0, [r6]
	ldr r2, [r5]
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x6]
	lsls r0, 24
	adds r3, r1, r0
	ldrb r4, [r2, 0x2]
	adds r0, r4, 0
	cmp r0, 0x1
	beq _0804B822
	cmp r0, 0x11
	beq _0804B822
	cmp r0, 0x2
	bne _0804B848
_0804B822:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r1, [r0, 0x2]
	ldrh r2, [r3]
	movs r0, 0
	bl dp01_build_cmdbuf_x34_a_bb_aka_battle_anim
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r4]
	adds r0, 0x7
	str r0, [r4]
	b _0804B8AA
	.pool
_0804B848:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804B868
	adds r0, r2, 0x7
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DABB9
	b _0804B8A8
	.pool
_0804B868:
	adds r0, r4, 0
	subs r0, 0xA
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0804B894
	ldr r1, =gStatuses3
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	beq _0804B894
	adds r0, r2, 0x7
	b _0804B8A8
	.pool
_0804B894:
	ldrb r1, [r2, 0x2]
	ldrh r2, [r3]
	movs r0, 0
	bl dp01_build_cmdbuf_x34_a_bb_aka_battle_anim
	ldrb r0, [r6]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x7
_0804B8A8:
	str r0, [r5]
_0804B8AA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk45_playanimation

	thumb_func_start atk46_playanimation2
atk46_playanimation2: @ 804B8B0
	push {r4-r7,lr}
	ldr r6, =gBattlescriptCurrInstr
	ldr r0, [r6]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r7, =gActiveBank
	strb r0, [r7]
	ldr r2, [r6]
	ldrb r1, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	adds r3, r1, r0
	ldrb r1, [r2, 0x6]
	ldrb r0, [r2, 0x7]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x9]
	lsls r0, 24
	adds r4, r1, r0
	ldrb r5, [r3]
	adds r0, r5, 0
	cmp r0, 0x1
	beq _0804B8FA
	cmp r0, 0x11
	beq _0804B8FA
	cmp r0, 0x2
	bne _0804B920
_0804B8FA:
	ldrb r1, [r3]
	ldrh r2, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x34_a_bb_aka_battle_anim
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
	b _0804B976
	.pool
_0804B920:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804B934
	adds r0, r2, 0
	b _0804B972
	.pool
_0804B934:
	adds r0, r5, 0
	subs r0, 0xA
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bls _0804B960
	ldr r1, =gStatuses3
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	beq _0804B960
	adds r0, r2, 0
	b _0804B972
	.pool
_0804B960:
	ldrb r1, [r3]
	ldrh r2, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x34_a_bb_aka_battle_anim
	ldrb r0, [r7]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r6]
_0804B972:
	adds r0, 0xA
	str r0, [r6]
_0804B976:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk46_playanimation2

	thumb_func_start atk47_setgraphicalstatchangevalues
atk47_setgraphicalstatchangevalues: @ 804B97C
	push {r4,lr}
	movs r3, 0
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x1A]
	movs r2, 0xF0
	ands r2, r0
	adds r4, r1, 0
	cmp r2, 0x20
	beq _0804B9AA
	cmp r2, 0x20
	bgt _0804B99C
	cmp r2, 0x10
	beq _0804B9A6
	b _0804B9B4
	.pool
_0804B99C:
	cmp r2, 0x90
	beq _0804B9AE
	cmp r2, 0xA0
	beq _0804B9B2
	b _0804B9B4
_0804B9A6:
	movs r3, 0xF
	b _0804B9B4
_0804B9AA:
	movs r3, 0x27
	b _0804B9B4
_0804B9AE:
	movs r3, 0x16
	b _0804B9B4
_0804B9B2:
	movs r3, 0x2E
_0804B9B4:
	ldrb r1, [r4, 0x1A]
	movs r0, 0xF
	ands r0, r1
	adds r0, r3, r0
	subs r0, 0x1
	movs r1, 0
	strb r0, [r4, 0x10]
	strb r1, [r4, 0x11]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk47_setgraphicalstatchangevalues

	thumb_func_start atk48_playstatchangeanimation
atk48_playstatchangeanimation: @ 804B9D8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r7, 0
	movs r0, 0
	mov r8, r0
	movs r3, 0
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	str r3, [sp]
	bl get_battle_side_of_something
	ldr r2, =gActiveBank
	strb r0, [r2]
	ldr r0, [r5]
	ldrb r4, [r0, 0x2]
	ldrb r1, [r0, 0x3]
	movs r0, 0x1
	ands r0, r1
	ldr r3, [sp]
	cmp r0, 0
	beq _0804BAEC
	movs r0, 0x2
	ands r0, r1
	movs r1, 0x15
	cmp r0, 0
	beq _0804BA18
	movs r1, 0x2D
_0804BA18:
	cmp r4, 0
	beq _0804BAC0
	movs r0, 0x1
	mov r10, r0
	ldr r0, =gBattleMons + 0x18
	mov r9, r0
	lsls r5, r1, 16
_0804BA26:
	adds r0, r4, 0
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _0804BAB2
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r1, [r0, 0x3]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0804BA58
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7, r0
	b _0804BAA0
	.pool
_0804BA58:
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	str r3, [sp]
	bl GetBankIdentity
	mov r1, r10
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSideTimers
	adds r0, r1
	ldrb r0, [r0, 0x4]
	ldr r3, [sp]
	cmp r0, 0
	bne _0804BAB2
	ldr r0, =gBattleMons
	ldrb r2, [r6]
	movs r1, 0x58
	muls r2, r1
	adds r0, r2, r0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1D
	beq _0804BAB2
	cmp r0, 0x49
	beq _0804BAB2
	cmp r0, 0x33
	bne _0804BA96
	cmp r7, 0x6
	beq _0804BAB2
_0804BA96:
	cmp r0, 0x34
	bne _0804BA9E
	cmp r7, 0x1
	beq _0804BAB2
_0804BA9E:
	adds r0, r7, r2
_0804BAA0:
	add r0, r9
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	ble _0804BAB2
	lsrs r0, r5, 16
	mov r8, r0
	adds r3, 0x1
_0804BAB2:
	lsrs r4, 1
	movs r1, 0x80
	lsls r1, 9
	adds r5, r1
	adds r7, 0x1
	cmp r4, 0
	bne _0804BA26
_0804BAC0:
	ldr r0, =gBattlescriptCurrInstr
	mov r9, r0
	cmp r3, 0x1
	ble _0804BB4E
	ldr r0, [r0]
	ldrb r1, [r0, 0x3]
	movs r0, 0x2
	ands r0, r1
	movs r1, 0x39
	mov r8, r1
	cmp r0, 0
	beq _0804BB4E
	movs r0, 0x3A
	b _0804BB4C
	.pool
_0804BAEC:
	movs r0, 0x2
	ands r0, r1
	movs r1, 0xE
	cmp r0, 0
	beq _0804BAF8
	movs r1, 0x26
_0804BAF8:
	mov r9, r5
	cmp r4, 0
	beq _0804BB34
	ldr r6, =gBattleMons + 0x18
	adds r5, r2, 0
	lsls r2, r1, 16
_0804BB04:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0804BB26
	ldrb r1, [r5]
	movs r0, 0x58
	muls r0, r1
	adds r0, r7, r0
	adds r0, r6
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xB
	bgt _0804BB26
	lsrs r1, r2, 16
	mov r8, r1
	adds r3, 0x1
_0804BB26:
	lsrs r4, 1
	movs r0, 0x80
	lsls r0, 9
	adds r2, r0
	adds r7, 0x1
	cmp r4, 0
	bne _0804BB04
_0804BB34:
	cmp r3, 0x1
	ble _0804BB4E
	mov r1, r9
	ldr r0, [r1]
	ldrb r1, [r0, 0x3]
	movs r0, 0x2
	ands r0, r1
	movs r1, 0x37
	mov r8, r1
	cmp r0, 0
	beq _0804BB4E
	movs r0, 0x38
_0804BB4C:
	mov r8, r0
_0804BB4E:
	mov r1, r9
	ldr r2, [r1]
	ldrb r1, [r2, 0x3]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0804BB6C
	cmp r3, 0x1
	bgt _0804BB6C
	adds r0, r2, 0x4
	mov r1, r9
	b _0804BBBA
	.pool
_0804BB6C:
	cmp r3, 0
	beq _0804BBB4
	ldr r4, =gBattleScripting
	ldrb r0, [r4, 0x1B]
	cmp r0, 0
	bne _0804BBB4
	movs r0, 0
	movs r1, 0x1
	mov r2, r8
	str r3, [sp]
	bl dp01_build_cmdbuf_x34_a_bb_aka_battle_anim
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r1, [r0, 0x3]
	movs r0, 0x4
	ands r0, r1
	ldr r3, [sp]
	cmp r0, 0
	beq _0804BBA4
	cmp r3, 0x1
	ble _0804BBA4
	movs r0, 0x1
	strb r0, [r4, 0x1B]
_0804BBA4:
	ldr r1, =gBattlescriptCurrInstr
	b _0804BBB6
	.pool
_0804BBB4:
	mov r1, r9
_0804BBB6:
	ldr r0, [r1]
	adds r0, 0x4
_0804BBBA:
	str r0, [r1]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk48_playstatchangeanimation

	thumb_func_start atk49_moveendturn
atk49_moveendturn: @ 804BBCC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	movs r0, 0
	mov r10, r0
	ldr r2, =gUnknown_020241EC
	ldrh r1, [r2]
	ldr r0, =0x0000ffff
	movs r3, 0
	str r3, [sp, 0x18]
	cmp r1, r0
	beq _0804BBEE
	ldrh r2, [r2]
	str r2, [sp, 0x18]
_0804BBEE:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r4, [r0, 0x1]
	str r4, [sp, 0x10]
	ldrb r0, [r0, 0x2]
	str r0, [sp, 0x14]
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0804BC34
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x7]
	b _0804BC3E
	.pool
_0804BC34:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r0, 24
_0804BC3E:
	str r0, [sp, 0x8]
	ldr r1, =gBattleStruct
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, 0xC8
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp, 0xC]
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	beq _0804BCF0
	movs r5, 0x3F
	ands r5, r0
	str r5, [sp, 0x4]
	b _0804BD02
	.pool
_0804BC68:
	ldr r4, =gActiveBank
	strb r2, [r4]
	movs r0, 0
	movs r1, 0x1
	bl dp01_build_cmdbuf_x33_a_33_33
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804C15A
	.pool
_0804BC80:
	ldr r4, =gActiveBank
	strb r2, [r4]
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x33_a_33_33
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r5
	ldr r0, [r1]
	ldr r2, =0xfffbff3f
	ands r0, r2
	str r0, [r1]
	b _0804C15A
	.pool
_0804BCAC:
	strb r2, [r7]
	ldr r0, [r5]
	orrs r0, r6
	str r0, [r5]
	ldr r0, =gBattleScripting
	strb r4, [r0, 0x14]
	bl sub_804AF30
	ldr r2, =gUnknown_082D86A8
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	add r0, r9
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	bl b_movescr_stack_push
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB87D
	bl _0804C5B8
	.pool
_0804BCF0:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	str r0, [sp, 0x4]
_0804BD02:
	ldr r1, =gBattleScripting
	mov r12, r1
	b _0804BD1E
	.pool
_0804BD14:
	mov r2, r10
	cmp r2, 0
	beq _0804BD1E
	bl _0804C5A4
_0804BD1E:
	mov r3, r12
	ldrb r0, [r3, 0x14]
	cmp r0, 0x11
	bls _0804BD2A
	bl _0804C570
_0804BD2A:
	lsls r0, 2
	ldr r1, =_0804BD38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804BD38:
	.4byte _0804BD80
	.4byte _0804BE5C
	.4byte _0804BF18
	.4byte _0804BF3C
	.4byte _0804BF54
	.4byte _0804BF7C
	.4byte _0804BFA0
	.4byte _0804C048
	.4byte _0804C0BE
	.4byte _0804C0F4
	.4byte _0804C194
	.4byte _0804C088
	.4byte _0804C0A8
	.4byte _0804C1D8
	.4byte _0804C21C
	.4byte _0804C3FC
	.4byte _0804C4E4
	.4byte _0804C570
_0804BD80:
	ldr r6, =gBattleMons
	ldr r5, =gBankTarget
	ldrb r3, [r5]
	movs r7, 0x58
	adds r2, r3, 0
	muls r2, r7
	adds r0, r6, 0
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 16
	ands r0, r1
	cmp r0, 0
	bne _0804BDA0
	b _0804C184
_0804BDA0:
	adds r0, r2, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _0804BDAA
	b _0804C184
_0804BDAA:
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	cmp r1, r3
	bne _0804BDB4
	b _0804C184
_0804BDB4:
	adds r0, r1, 0
	bl GetBankSide
	adds r4, r0, 0
	ldrb r0, [r5]
	bl GetBankSide
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _0804BDCC
	b _0804C184
_0804BDCC:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _0804BDDA
	b _0804C184
_0804BDDA:
	ldr r2, =gSpecialStatuses
	ldrb r3, [r5]
	lsls r0, r3, 2
	adds r0, r3
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _0804BDFE
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _0804BDFE
	b _0804C184
_0804BDFE:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0804BE14
	b _0804C184
_0804BE14:
	adds r0, r3, 0
	muls r0, r7
	adds r1, r0, r6
	ldrb r2, [r1, 0x19]
	movs r0, 0x19
	ldrsb r0, [r1, r0]
	cmp r0, 0xB
	ble _0804BE26
	b _0804C184
_0804BE26:
	adds r0, r2, 0x1
	strb r0, [r1, 0x19]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAE0D
	str r0, [r1]
	b _0804C0B8
	.pool
_0804BE5C:
	ldr r4, =gBattleMons
	ldr r6, =gBankTarget
	ldrb r2, [r6]
	movs r5, 0x58
	mov r12, r5
	mov r1, r12
	muls r1, r2
	adds r7, r4, 0
	adds r7, 0x4C
	adds r5, r1, r7
	ldr r3, [r5]
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	bne _0804BE7C
	b _0804C184
_0804BE7C:
	adds r0, r1, r4
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _0804BE86
	b _0804C184
_0804BE86:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	cmp r0, r2
	bne _0804BE90
	b _0804C184
_0804BE90:
	ldr r0, =gSpecialStatuses
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r0, 0xC
	adds r1, r0
	ldr r0, [r1]
	cmp r0, 0
	bne _0804BEA4
	b _0804C184
_0804BEA4:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _0804BEB2
	b _0804C184
_0804BEB2:
	ldr r0, [sp, 0x4]
	cmp r0, 0xA
	beq _0804BEBA
	b _0804C184
_0804BEBA:
	movs r0, 0x21
	negs r0, r0
	ands r3, r0
	str r3, [r5]
	ldr r4, =gActiveBank
	ldrb r0, [r6]
	strb r0, [r4]
	ldrb r0, [r6]
	mov r1, r12
	muls r1, r0
	adds r0, r1, 0
	adds r0, r7
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB282
	str r0, [r1]
	movs r2, 0x1
	mov r10, r2
	b _0804C184
	.pool
_0804BF18:
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x7
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _0804BF32
	b _0804C184
_0804BF32:
	movs r3, 0x1
	mov r10, r3
	b _0804C184
	.pool
_0804BF3C:
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	b _0804C0B2
	.pool
_0804BF54:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x5
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _0804BF6C
	b _0804C184
_0804BF6C:
	movs r5, 0x1
	mov r10, r5
	ldr r0, =gBattleScripting
	mov r12, r0
	b _0804C570
	.pool
_0804BF7C:
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x8
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _0804BF96
	b _0804C184
_0804BF96:
	movs r1, 0x1
	mov r10, r1
	b _0804C184
	.pool
_0804BFA0:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _0804BFE4
	ldr r2, [sp, 0x8]
	cmp r2, 0x1D
	bne _0804BFE4
	ldr r0, =gUnknown_020241EC
	ldrh r2, [r0]
	adds r3, r0, 0
	cmp r2, 0xA5
	beq _0804BFE4
	ldr r4, [sp, 0xC]
	ldrh r1, [r4]
	cmp r1, 0
	beq _0804BFCC
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0804BFE4
_0804BFCC:
	cmp r2, 0xE2
	bne _0804BFDE
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0804BFDE
	b _0804C4B6
_0804BFDE:
	ldrh r0, [r3]
	ldr r1, [sp, 0xC]
	strh r0, [r1]
_0804BFE4:
	movs r4, 0
	ldr r2, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r2, 0xC
	adds r0, r2
	ldrh r0, [r0]
	ldr r5, [sp, 0xC]
	ldrh r1, [r5]
	mov r9, r3
	cmp r0, r1
	beq _0804C01C
	mov r6, r9
	movs r3, 0x58
	adds r5, r1, 0
_0804C006:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0804C01C
	lsls r0, r4, 1
	ldrb r1, [r6]
	muls r1, r3
	adds r0, r1
	adds r0, r2
	ldrh r0, [r0]
	cmp r0, r5
	bne _0804C006
_0804C01C:
	cmp r4, 0x4
	bne _0804C026
	movs r0, 0
	ldr r1, [sp, 0xC]
	strh r0, [r1]
_0804C026:
	mov r2, r12
	ldrb r0, [r2, 0x14]
	adds r0, 0x1
	strb r0, [r2, 0x14]
	b _0804C570
	.pool
_0804C048:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r3, [r0]
	cmp r4, r3
	blt _0804C054
	b _0804C202
_0804C054:
	ldr r7, =gBattleStruct
	movs r6, 0
	movs r3, 0xD0
	adds r5, r0, 0
	ldr r2, =gBattleMons
_0804C05E:
	ldr r0, [r7]
	adds r0, r3
	ldrh r1, [r0]
	cmp r1, 0
	beq _0804C06C
	strh r1, [r2, 0x2E]
	strh r6, [r0]
_0804C06C:
	adds r3, 0x2
	adds r2, 0x58
	adds r4, 0x1
	ldrb r0, [r5]
	cmp r4, r0
	blt _0804C05E
	b _0804C202
	.pool
_0804C088:
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl berry_effects_maybe
	lsls r0, 24
	cmp r0, 0
	beq _0804C184
	movs r2, 0x1
	mov r10, r2
	ldr r3, =gBattleScripting
	mov r12, r3
	b _0804C570
	.pool
_0804C0A8:
	movs r0, 0x4
	movs r1, 0
	movs r2, 0
	bl berry_effects_maybe
_0804C0B2:
	lsls r0, 24
	cmp r0, 0
	beq _0804C184
_0804C0B8:
	movs r4, 0x1
	mov r10, r4
	b _0804C184
_0804C0BE:
	ldr r1, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	bne _0804C0D4
	b _0804C4B6
_0804C0D4:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804C0E2
	b _0804BC68
_0804C0E2:
	b _0804C4B6
	.pool
_0804C0F4:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _0804C120
	ldr r1, =gStatuses3
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	beq _0804C120
	adds r0, r2, 0
	bl sub_803F90C
	lsls r0, 24
	cmp r0, 0
	beq _0804C184
_0804C120:
	ldr r4, =gActiveBank
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	strb r0, [r4]
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x33_a_33_33
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, =gStatuses3
	ldrb r2, [r5]
	lsls r2, 2
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xfffbff3f
	ands r0, r1
	str r0, [r2]
	ldr r2, =gSpecialStatuses
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0804C15A:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	b _0804C5BA
	.pool
_0804C184:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	mov r12, r1
	b _0804C570
	.pool
_0804C194:
	ldr r0, =gSpecialStatuses
	ldr r6, =gBankTarget
	ldrb r2, [r6]
	lsls r3, r2, 2
	adds r1, r3, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 29
	cmp r0, 0
	blt _0804C202
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r2, r0
	bcs _0804C202
	ldr r5, =gStatuses3
	adds r0, r3, r5
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	bne _0804C1C2
	b _0804BC80
_0804C1C2:
	b _0804C202
	.pool
_0804C1D8:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r2, [r0]
	cmp r4, r2
	bge _0804C202
	ldr r2, =gDisableStructs
	ldr r5, =0xfeffffff
	adds r3, r0, 0
	ldr r1, =gBattleMons + 0x50
_0804C1EA:
	ldrb r0, [r2, 0xA]
	cmp r0, 0
	bne _0804C1F6
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
_0804C1F6:
	adds r2, 0x1C
	adds r1, 0x58
	adds r4, 0x1
	ldrb r0, [r3]
	cmp r4, r0
	blt _0804C1EA
_0804C202:
	mov r1, r12
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	b _0804C570
	.pool
_0804C21C:
	ldr r1, =gHitMarker
	ldr r3, [r1]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r3
	ldr r2, =gBankAttacker
	mov r9, r2
	adds r5, r1, 0
	cmp r0, 0
	beq _0804C246
	ldr r0, =gActiveBank
	ldrb r2, [r2]
	strb r2, [r0]
	ldr r1, =gBankTarget
	ldrb r0, [r1]
	mov r4, r9
	strb r0, [r4]
	strb r2, [r1]
	ldr r0, =0xffffefff
	ands r3, r0
	str r3, [r5]
_0804C246:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0804C262
	ldr r0, =gUnknown_02024240
	mov r2, r9
	ldrb r1, [r2]
	lsls r1, 1
	adds r1, r0
	ldr r0, =gUnknown_020241EC
	ldrh r0, [r0]
	strh r0, [r1]
_0804C262:
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	mov r3, r9
	ldrb r4, [r3]
	lsls r0, r4, 2
	adds r0, r2
	ldr r3, [r0]
	ands r1, r3
	adds r6, r2, 0
	cmp r1, 0
	beq _0804C27C
	b _0804C3E8
_0804C27C:
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r1, 0x91
	ldrb r1, [r1]
	ands r1, r3
	adds r7, r0, 0
	cmp r1, 0
	beq _0804C28E
	b _0804C3E8
_0804C28E:
	ldr r0, =gBattleMoves
	ldr r2, [sp, 0x18]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, 0x7F
	bne _0804C2A4
	b _0804C3E8
_0804C2A4:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _0804C308
	ldr r0, =gLastUsedMovesByBanks
	lsls r1, r4, 1
	adds r1, r0
	ldr r0, =gUnknown_020241EC
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, =gUnknown_02024260
	mov r3, r9
	ldrb r1, [r3]
	lsls r1, 1
	adds r1, r0
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	strh r0, [r1]
	b _0804C322
	.pool
_0804C308:
	ldr r1, =gLastUsedMovesByBanks
	lsls r0, r4, 1
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0]
	ldr r1, =gUnknown_02024260
	mov r4, r9
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0]
_0804C322:
	ldr r2, =gBankTarget
	ldrb r3, [r2]
	lsls r0, r3, 2
	adds r0, r6
	ldr r0, [r0]
	lsls r0, 28
	ldr r1, [r5]
	ands r1, r0
	cmp r1, 0
	bne _0804C340
	ldr r0, =gUnknown_02024270
	adds r0, r3, r0
	mov r3, r9
	ldrb r1, [r3]
	strb r1, [r0]
_0804C340:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 18
	ands r0, r1
	cmp r0, 0
	beq _0804C3DC
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _0804C3DC
	ldr r0, =gUnknown_020241EC
	ldrh r3, [r0]
	ldr r0, =0x0000ffff
	cmp r3, r0
	bne _0804C390
	ldr r1, =gUnknown_02024250
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r1
	strh r3, [r0]
	b _0804C3E8
	.pool
_0804C390:
	ldr r0, =gUnknown_02024250
	ldrb r1, [r2]
	lsls r1, 1
	adds r1, r0
	ldr r4, =gCurrentMove
	ldrh r0, [r4]
	strh r0, [r1]
	ldr r0, [r7]
	ldrb r3, [r0, 0x13]
	cmp r3, 0
	beq _0804C3C0
	ldr r0, =gUnknown_02024258
	ldrb r1, [r2]
	lsls r1, 1
	adds r1, r0
	movs r0, 0x3F
	ands r0, r3
	b _0804C3E6
	.pool
_0804C3C0:
	ldr r0, =gUnknown_02024258
	ldrb r2, [r2]
	lsls r2, 1
	adds r2, r0
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0x2]
	strh r0, [r2]
	b _0804C3E8
	.pool
_0804C3DC:
	ldr r0, =gUnknown_02024250
	ldrb r1, [r2]
	lsls r1, 1
	adds r1, r0
	ldr r0, =0x0000ffff
_0804C3E6:
	strh r0, [r1]
_0804C3E8:
	mov r4, r12
	ldrb r0, [r4, 0x14]
	adds r0, 0x1
	strb r0, [r4, 0x14]
	b _0804C570
	.pool
_0804C3FC:
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r7, =gBitTable
	ldr r2, =gBankAttacker
	ldrb r3, [r2]
	lsls r0, r3, 2
	adds r0, r7
	ldr r4, [r0]
	ands r1, r4
	mov r9, r2
	cmp r1, 0
	bne _0804C4B6
	ldr r6, =gBattleStruct
	ldr r5, [r6]
	adds r0, r5, 0
	adds r0, 0x91
	ldrb r0, [r0]
	ands r0, r4
	cmp r0, 0
	bne _0804C4B6
	ldr r1, =gBattleMoves
	ldr r2, [sp, 0x18]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0804C4B6
	ldr r0, =gHitMarker
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 18
	ands r0, r1
	cmp r0, 0
	beq _0804C4B6
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	cmp r3, r0
	beq _0804C4B6
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r7
	ldr r0, [r0]
	lsls r0, 28
	ands r1, r0
	cmp r1, 0
	bne _0804C4B6
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _0804C4B6
	lsls r1, r2, 1
	adds r1, r5
	adds r1, 0x98
	ldr r3, =gUnknown_020241EC
	ldrh r0, [r3]
	strb r0, [r1]
	ldrb r1, [r4]
	ldr r0, [r6]
	lsls r1, 1
	adds r1, r0
	adds r1, 0x99
	ldrh r0, [r3]
	lsrs r0, 8
	strb r0, [r1]
	ldrb r0, [r4]
	mov r2, r9
	ldrb r1, [r2]
	ldr r2, [r6]
	lsls r0, 3
	lsls r1, 1
	adds r0, r1
	adds r0, r2
	adds r0, 0xE0
	ldrh r1, [r3]
	strb r1, [r0]
	ldrb r1, [r4]
	mov r4, r9
	ldrb r0, [r4]
	ldr r2, [r6]
	lsls r1, 3
	lsls r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0xE1
	ldrh r0, [r3]
	lsrs r0, 8
	strb r0, [r1]
_0804C4B6:
	mov r5, r12
	ldrb r0, [r5, 0x14]
	adds r0, 0x1
	strb r0, [r5, 0x14]
	b _0804C570
	.pool
_0804C4E4:
	ldr r5, =gHitMarker
	ldr r2, [r5]
	movs r0, 0x80
	lsls r0, 12
	ands r0, r2
	cmp r0, 0
	bne _0804C568
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804C568
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	cmp r0, 0
	blt _0804C568
	ldr r0, =gBattleMoves
	mov r9, r0
	ldr r1, =gCurrentMove
	mov r8, r1
	ldrh r0, [r1]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	add r1, r9
	ldrb r0, [r1, 0x6]
	cmp r0, 0x8
	bne _0804C568
	movs r6, 0x80
	lsls r6, 2
	adds r4, r6, 0
	ands r4, r2
	cmp r4, 0
	bne _0804C568
	ldr r7, =gBankTarget
	ldrb r0, [r7]
	bl GetBankIdentity
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _0804C55E
	bl _0804BCAC
_0804C55E:
	ldr r0, [r5]
	orrs r0, r6
	str r0, [r5]
	ldr r2, =gBattleScripting
	mov r12, r2
_0804C568:
	mov r3, r12
	ldrb r0, [r3, 0x14]
	adds r0, 0x1
	strb r0, [r3, 0x14]
_0804C570:
	ldr r4, [sp, 0x10]
	cmp r4, 0x1
	bne _0804C582
	mov r5, r10
	cmp r5, 0
	bne _0804C582
	movs r0, 0x11
	mov r1, r12
	strb r0, [r1, 0x14]
_0804C582:
	ldr r2, [sp, 0x10]
	cmp r2, 0x2
	bne _0804C598
	ldr r4, [sp, 0x14]
	mov r3, r12
	ldrb r3, [r3, 0x14]
	cmp r4, r3
	bne _0804C598
	movs r0, 0x11
	mov r4, r12
	strb r0, [r4, 0x14]
_0804C598:
	mov r5, r12
	ldrb r0, [r5, 0x14]
	cmp r0, 0x11
	beq _0804C5A4
	bl _0804BD14
_0804C5A4:
	mov r1, r12
	ldrb r0, [r1, 0x14]
	cmp r0, 0x11
	bne _0804C5BA
	mov r2, r10
	cmp r2, 0
	bne _0804C5BA
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x3
_0804C5B8:
	str r0, [r1]
_0804C5BA:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk49_moveendturn

	thumb_func_start atk4A_typecalc2
atk4A_typecalc2: @ 804C5F4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r4, 0
	movs r5, 0
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	mov r8, r0
	ldr r2, =gBattleMons
	ldr r3, =gBankTarget
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	mov r12, r2
	adds r7, r3, 0
	cmp r0, 0x1A
	bne _0804C688
	mov r1, r8
	cmp r1, 0x4
	bne _0804C688
	ldr r3, =gLastUsedAbility
	strb r0, [r3]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x9
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gUnknown_02024250
	ldrb r0, [r7]
	lsls r0, 1
	adds r0, r1
	strh r4, [r0]
	ldr r0, =gBattleCommunication
	mov r2, r8
	strb r2, [r0, 0x6]
	ldrb r0, [r7]
	ldrb r1, [r3]
	bl RecordAbilityBattle
	b _0804C76A
	.pool
_0804C678:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
	b _0804C76A
	.pool
_0804C688:
	ldr r1, =gUnknown_0831ACE8
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r6, r1, 0
	b _0804C74A
	.pool
_0804C698:
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r8
	bne _0804C744
	adds r2, r5, 0x1
	adds r3, r2, r6
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	add r0, r12
	adds r0, 0x21
	ldrb r1, [r3]
	adds r3, r2, 0
	ldrb r0, [r0]
	cmp r1, r0
	bne _0804C6D6
	adds r0, r5, 0x2
	adds r0, r6
	ldrb r1, [r0]
	cmp r1, 0
	beq _0804C678
	cmp r1, 0x5
	bne _0804C6CA
	movs r0, 0x4
	orrs r4, r0
_0804C6CA:
	cmp r1, 0x14
	bne _0804C6D6
	movs r0, 0x2
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0804C6D6:
	adds r2, r3, r6
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	add r0, r12
	adds r1, r0, 0
	adds r1, 0x22
	ldrb r2, [r2]
	ldrb r1, [r1]
	cmp r2, r1
	bne _0804C744
	adds r0, 0x21
	ldrb r1, [r0]
	cmp r1, r2
	beq _0804C6FE
	adds r0, r5, 0x2
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804C678
_0804C6FE:
	cmp r1, r2
	beq _0804C714
	adds r0, r5, 0x2
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x5
	bne _0804C714
	movs r0, 0x4
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0804C714:
	adds r2, r3, r6
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	add r0, r12
	adds r1, r0, 0
	adds r1, 0x22
	ldrb r2, [r2]
	ldrb r1, [r1]
	cmp r2, r1
	bne _0804C744
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, r2
	beq _0804C744
	adds r0, r5, 0x2
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x14
	bne _0804C744
	movs r0, 0x2
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0804C744:
	adds r5, 0x3
	adds r0, r5, r6
	ldrb r0, [r0]
_0804C74A:
	cmp r0, 0xFF
	beq _0804C76A
	cmp r0, 0xFE
	bne _0804C698
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	mov r1, r12
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 22
	ands r0, r1
	cmp r0, 0
	beq _0804C744
_0804C76A:
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	mov r8, r0
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r6, [r0]
	cmp r6, 0x19
	bne _0804C7E6
	movs r5, 0x29
	ands r5, r4
	cmp r5, 0
	bne _0804C7E6
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r7, =gCurrentMove
	ldrh r1, [r7]
	bl move_weather_interaction
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bne _0804C7E6
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0804C7AC
	movs r0, 0x6
	ands r4, r0
	cmp r4, 0x6
	bne _0804C7E6
_0804C7AC:
	ldr r2, =gBattleMoves
	ldrh r1, [r7]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _0804C7E6
	ldr r3, =gLastUsedAbility
	strb r6, [r3]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gUnknown_02024250
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r1
	strh r5, [r0]
	ldr r1, =gBattleCommunication
	movs r0, 0x3
	strb r0, [r1, 0x6]
	ldrb r0, [r2]
	ldrb r1, [r3]
	bl RecordAbilityBattle
_0804C7E6:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0804C804
	ldr r2, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r2
	ldrb r0, [r1, 0x1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1, 0x1]
_0804C804:
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
	thumb_func_end atk4A_typecalc2

	thumb_func_start atk4B_return_atk_to_ball
atk4B_return_atk_to_ball: @ 804C844
	push {r4,lr}
	ldr r4, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r2, =gHitMarker
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	ands r0, r1
	cmp r0, 0
	bne _0804C872
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x06_a
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804C872:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk4B_return_atk_to_ball

	thumb_func_start atk4C_copy_poke_data
atk4C_copy_poke_data: @ 804C894
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804C8E4
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r3, =gBattlePartyID
	ldrb r0, [r4]
	lsls r2, r0, 1
	adds r2, r3
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	strh r0, [r2]
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0]
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x00_a_b_0
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
_0804C8E4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk4C_copy_poke_data

	thumb_func_start atk4D_switch_data_update
atk4D_switch_data_update: @ 804C904
	push {r4-r7,lr}
	sub sp, 0x58
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0804C912
	b _0804CAA4
_0804C912:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r6, =gBattleMons
	ldrb r0, [r4]
	movs r5, 0x58
	adds r1, r0, 0
	muls r1, r5
	adds r1, r6
	mov r0, sp
	movs r2, 0x58
	bl memcpy
	ldrb r0, [r4]
	muls r0, r5
	adds r3, r0, r6
	movs r2, 0
	ldr r5, =gBattleBufferB
_0804C93E:
	adds r0, r3, r2
	ldrb r1, [r4]
	lsls r1, 9
	adds r1, 0x4
	adds r1, r2, r1
	adds r1, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x57
	bls _0804C93E
	ldr r4, =gBattleMons
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	movs r7, 0x58
	adds r2, r0, 0
	muls r2, r7
	adds r2, r4
	ldr r3, =gBaseStats
	ldrh r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x6]
	adds r2, 0x21
	strb r0, [r2]
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r7
	adds r1, r4
	ldrh r2, [r1]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x7]
	adds r1, 0x22
	strb r0, [r1]
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r7
	adds r1, r4
	ldrh r0, [r1]
	ldrb r1, [r1, 0x17]
	lsrs r1, 7
	bl GetAbilityBySpecies
	ldrb r1, [r6]
	muls r1, r7
	adds r1, r4
	adds r1, 0x20
	strb r0, [r1]
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_020243D0
	adds r0, 0x29
	adds r0, r2, r0
	ldrb r1, [r0]
	ldr r3, =gBitTable
	ldr r2, =gBattlePartyID
	ldrb r5, [r6]
	lsls r0, r5, 1
	adds r0, r2
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ands r1, r0
	mov r12, r4
	cmp r1, 0
	beq _0804C9DE
	adds r0, r5, 0
	muls r0, r7
	add r0, r12
	movs r1, 0
	strh r1, [r0, 0x2E]
_0804C9DE:
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x7F
	bne _0804CA26
	movs r2, 0
	adds r4, r6, 0
	movs r6, 0x58
	mov r5, r12
	adds r5, 0x18
	add r3, sp, 0x18
_0804C9FE:
	ldrb r0, [r4]
	adds r1, r0, 0
	muls r1, r6
	adds r1, r2, r1
	adds r1, r5
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x7
	ble _0804C9FE
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	mov r1, r12
	adds r1, 0x50
	adds r0, r1
	ldr r1, [sp, 0x50]
	str r1, [r0]
_0804CA26:
	bl sub_803A284
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0804CA78
	ldr r4, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	movs r0, 0x58
	adds r2, r3, 0
	muls r2, r0
	adds r1, r2, r4
	ldrh r0, [r1, 0x2C]
	lsrs r0, 1
	ldrh r1, [r1, 0x28]
	cmp r0, r1
	bcc _0804CA78
	cmp r1, 0
	beq _0804CA78
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0804CA78
	ldr r0, =gBattleStruct
	ldr r2, [r0]
	adds r2, 0x92
	ldr r1, =gBitTable
	lsls r0, r3, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_0804CA78:
	ldr r0, =gBattleScripting
	ldr r3, =gActiveBank
	ldrb r2, [r3]
	strb r2, [r0, 0x17]
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
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_0804CAA4:
	add sp, 0x58
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk4D_switch_data_update

	thumb_func_start atk4E_switchin_anim
atk4E_switchin_anim: @ 804CAE8
	push {r4-r6,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804CB86
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r6, =gActiveBank
	strb r0, [r6]
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0804CB3E
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x063f0902
	ands r0, r1
	cmp r0, 0
	bne _0804CB3E
	ldr r4, =gBattleMons
	ldrb r0, [r6]
	movs r5, 0x58
	muls r0, r5
	adds r0, r4
	ldrh r0, [r0]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	ldrb r1, [r6]
	muls r1, r5
	adds r4, 0x48
	adds r1, r4
	ldr r2, [r1]
	movs r1, 0x2
	bl SetPokedexFlag
_0804CB3E:
	ldr r2, =gAbsentBankFlags
	ldr r1, =gBitTable
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrb r1, [r0]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r2, [r0, 0x2]
	movs r0, 0
	bl dp01_build_cmdbuf_x05_a_b_c
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r4]
	adds r0, 0x3
	str r0, [r4]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0804CB86
	bl sub_81A56B4
_0804CB86:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk4E_switchin_anim

	thumb_func_start atk4F_jump_if_cannot_switch
atk4F_jump_if_cannot_switch: @ 804CBB0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r1, [r0, 0x1]
	movs r0, 0x7F
	ands r0, r1
	bl get_battle_side_of_something
	ldr r3, =gActiveBank
	strb r0, [r3]
	ldr r2, [r4]
	ldrb r1, [r2, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0804CC28
	ldr r1, =gBattleMons
	ldrb r3, [r3]
	movs r0, 0x58
	muls r0, r3
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0400e000
	ands r0, r1
	cmp r0, 0
	bne _0804CBFC
	ldr r1, =gStatuses3
	lsls r0, r3, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	beq _0804CC28
_0804CBFC:
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
	b _0804CF00
	.pool
_0804CC28:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 15
	ands r0, r1
	cmp r0, 0
	beq _0804CCC0
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty
	mov r8, r1
	cmp r0, 0x1
	bne _0804CC4E
	ldr r0, =gEnemyParty
	mov r8, r0
_0804CC4E:
	movs r4, 0
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804CC5C
	movs r4, 0x3
_0804CC5C:
	adds r6, r4, 0x3
	cmp r4, r6
	bge _0804CCA4
	ldr r7, =gBattlePartyID
_0804CC64:
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804CC9E
	adds r0, r5, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0804CC9E
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804CC9E
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, r4
	bne _0804CCA4
_0804CC9E:
	adds r4, 0x1
	cmp r4, r6
	blt _0804CC64
_0804CCA4:
	cmp r4, r6
	bne _0804CCAA
	b _0804CED0
_0804CCAA:
	b _0804CEF8
	.pool
_0804CCC0:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804CD8C
	movs r0, 0x80
	lsls r0, 16
	ands r1, r0
	cmp r1, 0
	beq _0804CD00
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0804CCEC
	ldr r0, =gPlayerParty
	b _0804CD16
	.pool
_0804CCEC:
	ldr r1, =gEnemyParty
	mov r8, r1
	ldrb r0, [r5]
	movs r4, 0x3
	cmp r0, 0x1
	bne _0804CD32
	movs r4, 0
	b _0804CD32
	.pool
_0804CD00:
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gPlayerParty
	mov r8, r1
	cmp r0, 0x1
	bne _0804CD18
	ldr r0, =gEnemyParty
_0804CD16:
	mov r8, r0
_0804CD18:
	movs r4, 0
	ldrb r0, [r5]
	bl sub_806D864
	lsls r0, 24
	lsrs r0, 24
	bl sub_806D82C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _0804CD32
	movs r4, 0x3
_0804CD32:
	adds r6, r4, 0x3
	cmp r4, r6
	bge _0804CCA4
	ldr r7, =gBattlePartyID
_0804CD3A:
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804CD74
	adds r0, r5, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0804CD74
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804CD74
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, r4
	bne _0804CCA4
_0804CD74:
	adds r4, 0x1
	cmp r4, r6
	blt _0804CD3A
	b _0804CCA4
	.pool
_0804CD8C:
	movs r0, 0x80
	lsls r0, 8
	ands r1, r0
	cmp r1, 0
	beq _0804CE10
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0804CE10
	ldr r0, =gEnemyParty
	mov r8, r0
	movs r4, 0
	ldrb r0, [r5]
	cmp r0, 0x3
	bne _0804CDB4
	movs r4, 0x3
_0804CDB4:
	adds r6, r4, 0x3
	cmp r4, r6
	blt _0804CDBC
	b _0804CCA4
_0804CDBC:
	ldr r7, =gBattlePartyID
_0804CDBE:
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804CDFA
	adds r0, r5, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0804CDFA
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804CDFA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, r4
	beq _0804CDFA
	b _0804CCA4
_0804CDFA:
	adds r4, 0x1
	cmp r4, r6
	blt _0804CDBE
	b _0804CCA4
	.pool
_0804CE10:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1
	bne _0804CE54
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ands r0, r4
	cmp r0, 0
	beq _0804CE48
	movs r0, 0x3
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	b _0804CE4A
	.pool
_0804CE48:
	adds r6, r7, 0
_0804CE4A:
	ldr r0, =gEnemyParty
	mov r8, r0
	b _0804CE82
	.pool
_0804CE54:
	movs r0, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804CE7C
	movs r0, 0x2
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	b _0804CE7E
	.pool
_0804CE7C:
	adds r6, r7, 0
_0804CE7E:
	ldr r1, =gPlayerParty
	mov r8, r1
_0804CE82:
	movs r4, 0
_0804CE84:
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804CEC6
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _0804CEC6
	adds r0, r5, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0804CEC6
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _0804CEC6
	lsls r0, r6, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _0804CECC
_0804CEC6:
	adds r4, 0x1
	cmp r4, 0x5
	ble _0804CE84
_0804CECC:
	cmp r4, 0x6
	bne _0804CEF8
_0804CED0:
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
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
	b _0804CF00
	.pool
_0804CEF8:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
_0804CF00:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk4F_jump_if_cannot_switch

	thumb_func_start sub_804CF10
sub_804CF10: @ 804CF10
	push {r4,r5,lr}
	sub sp, 0x4
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r4, =gBattleStruct
	ldr r1, [r4]
	adds r1, r0, r1
	adds r1, 0x58
	ldr r3, =gBattlePartyID
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r5]
	ldr r1, [r4]
	adds r0, r1
	adds r0, 0x5C
	movs r1, 0x6
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0x93
	ldr r3, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r3
	ldr r3, [r0]
	ldrb r0, [r1]
	bics r0, r3
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, 0x60
	ldr r0, [r4]
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804CF10

	thumb_func_start atk50_openpartyscreen
atk50_openpartyscreen: @ 804CF88
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r7, 0
	movs r0, 0
	mov r9, r0
	ldr r6, =gBattlescriptCurrInstr
	ldr r2, [r6]
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
	mov r8, r1
	ldrb r1, [r2, 0x1]
	adds r0, r1, 0
	mov r12, r6
	cmp r0, 0x5
	beq _0804CFBE
	b _0804D464
_0804CFBE:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x41
	ands r1, r0
	cmp r1, 0x1
	beq _0804D0B0
	ldr r1, =gActiveBank
	strb r7, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r7, r0
	bcc _0804CFD8
	b _0804D450
_0804CFD8:
	ldr r7, =gHitMarker
	ldr r6, =gBitTable
	adds r4, r1, 0
	ldr r2, =gAbsentBankFlags
	mov r8, r2
_0804CFE2:
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r6
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r7]
	ands r0, r1
	cmp r0, 0
	beq _0804D088
	adds r0, r2, 0
	movs r1, 0x6
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D054
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	mov r2, r8
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804D098
	.pool
_0804D054:
	ldr r5, =gSpecialStatuses
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D098
	movs r0, 0x6
	bl sub_804CF10
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _0804D098
	.pool
_0804D088:
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804D098:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0804CFE2
	b _0804D450
	.pool
_0804D0B0:
	ands r0, r1
	cmp r0, 0
	bne _0804D0B8
	b _0804D450
_0804D0B8:
	ldr r0, =gHitMarker
	mov r8, r0
	ldr r0, [r0]
	lsrs r5, r0, 28
	ldr r6, =gBitTable
	ldr r0, [r6]
	ands r0, r5
	cmp r0, 0
	beq _0804D170
	ldr r4, =gActiveBank
	strb r7, [r4]
	movs r0, 0
	movs r1, 0x6
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D120
	ldr r2, =gAbsentBankFlags
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	lsls r1, 28
	mov r2, r8
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x2A_2A_2A_2A
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804D170
	.pool
_0804D120:
	ldr r6, =gSpecialStatuses
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D15C
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x5E
	ldrb r0, [r0]
	bl sub_804CF10
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _0804D170
	.pool
_0804D15C:
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	movs r0, 0x1
	mov r9, r0
_0804D170:
	ldr r6, =gBitTable
	ldr r0, [r6, 0x8]
	ands r0, r5
	cmp r0, 0
	beq _0804D22E
	ldr r0, [r6]
	ands r0, r5
	cmp r0, 0
	bne _0804D22E
	ldr r4, =gActiveBank
	movs r0, 0x2
	strb r0, [r4]
	movs r0, 0x2
	movs r1, 0x6
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D1D8
	ldr r2, =gAbsentBankFlags
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, =gHitMarker
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x2A_2A_2A_2A
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804D22E
	.pool
_0804D1D8:
	ldr r6, =gSpecialStatuses
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D214
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x5C
	ldrb r0, [r0]
	bl sub_804CF10
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _0804D22E
	.pool
_0804D214:
	movs r0, 0x1
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	bne _0804D22E
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804D22E:
	ldr r6, =gBitTable
	ldr r0, [r6, 0x4]
	ands r0, r5
	cmp r0, 0
	beq _0804D2E4
	ldr r4, =gActiveBank
	movs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	movs r1, 0x6
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D290
	ldr r2, =gAbsentBankFlags
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, =gHitMarker
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x2A_2A_2A_2A
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804D2E4
	.pool
_0804D290:
	ldr r6, =gSpecialStatuses
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D2CC
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x5F
	ldrb r0, [r0]
	bl sub_804CF10
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _0804D2E4
	.pool
_0804D2CC:
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	movs r0, 0x2
	mov r2, r9
	orrs r2, r0
	mov r9, r2
_0804D2E4:
	ldr r6, =gBitTable
	ldr r0, [r6, 0xC]
	ands r0, r5
	cmp r0, 0
	beq _0804D3A2
	ldr r0, [r6, 0x4]
	ands r0, r5
	cmp r0, 0
	bne _0804D3A2
	ldr r4, =gActiveBank
	movs r0, 0x3
	strb r0, [r4]
	movs r0, 0x3
	movs r1, 0x6
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D34C
	ldr r2, =gAbsentBankFlags
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, =gHitMarker
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r6
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x2A_2A_2A_2A
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804D3A2
	.pool
_0804D34C:
	ldr r6, =gSpecialStatuses
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D388
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x5D
	ldrb r0, [r0]
	bl sub_804CF10
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _0804D3A2
	.pool
_0804D388:
	movs r0, 0x2
	mov r1, r9
	ands r1, r0
	cmp r1, 0
	bne _0804D3A2
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804D3A2:
	ldr r1, =gSpecialStatuses
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D3FA
	adds r0, r1, 0
	adds r0, 0x28
	ldrb r0, [r0]
	lsls r0, 25
	cmp r0, 0
	blt _0804D3FA
	cmp r5, 0
	beq _0804D3FA
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r0, =gBitTable
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0804D3E4
	ldr r1, =gActiveBank
	movs r0, 0x2
	strb r0, [r1]
	b _0804D3E8
	.pool
_0804D3E4:
	ldr r0, =gActiveBank
	strb r1, [r0]
_0804D3E8:
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
_0804D3FA:
	ldr r1, =gSpecialStatuses
	ldrb r0, [r1, 0x14]
	lsls r0, 25
	cmp r0, 0
	blt _0804D450
	adds r0, r1, 0
	adds r0, 0x3C
	ldrb r0, [r0]
	lsls r0, 25
	cmp r0, 0
	blt _0804D450
	cmp r5, 0
	beq _0804D450
	ldr r0, =gAbsentBankFlags
	ldrb r0, [r0]
	ldr r1, =gBitTable
	ldr r1, [r1, 0x4]
	ands r0, r1
	cmp r0, 0
	beq _0804D438
	ldr r1, =gActiveBank
	movs r0, 0x3
	b _0804D43C
	.pool
_0804D438:
	ldr r1, =gActiveBank
	movs r0, 0x1
_0804D43C:
	strb r0, [r1]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
_0804D450:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
	b _0804D804
	.pool
_0804D464:
	cmp r0, 0x6
	beq _0804D46A
	b _0804D658
_0804D46A:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804D478
	b _0804D5F4
_0804D478:
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	bne _0804D482
	b _0804D5F4
_0804D482:
	ldr r7, =gHitMarker
	ldr r0, [r7]
	lsrs r5, r0, 28
	ldr r4, =gBitTable
	ldr r0, [r4, 0x8]
	ands r0, r5
	cmp r0, 0
	beq _0804D52A
	ldr r0, [r4]
	ands r0, r5
	cmp r0, 0
	beq _0804D52A
	ldr r6, =gActiveBank
	movs r0, 0x2
	strb r0, [r6]
	ldr r0, =gBattleBufferB
	ldrb r1, [r0, 0x1]
	movs r0, 0x2
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D4F8
	ldr r2, =gAbsentBankFlags
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r4
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	movs r0, 0
	bl dp01_build_cmdbuf_x2A_2A_2A_2A
	ldrb r0, [r6]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804D52A
	.pool
_0804D4F8:
	ldr r4, =gSpecialStatuses
	ldrb r0, [r6]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D52A
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x5C
	ldrb r0, [r0]
	bl sub_804CF10
	ldrb r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
_0804D52A:
	ldr r4, =gBitTable
	ldr r0, [r4, 0xC]
	ands r0, r5
	cmp r0, 0
	beq _0804D5DA
	ldr r0, [r4, 0x4]
	ands r5, r0
	cmp r5, 0
	beq _0804D5DA
	ldr r5, =gActiveBank
	movs r0, 0x3
	strb r0, [r5]
	ldr r0, =gBattleBufferB
	ldr r2, =0x00000201
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x3
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D5A8
	ldr r2, =gAbsentBankFlags
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, =gHitMarker
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r4
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x2A_2A_2A_2A
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804D5DA
	.pool
_0804D5A8:
	ldr r4, =gSpecialStatuses
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D5DA
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x5D
	ldrb r0, [r0]
	bl sub_804CF10
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
_0804D5DA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
	mov r12, r1
	b _0804D5F8
	.pool
_0804D5F4:
	adds r0, r2, 0x6
	str r0, [r6]
_0804D5F8:
	ldr r0, =gHitMarker
	ldr r0, [r0]
	lsrs r5, r0, 28
	ldr r1, =gUnknown_0202420D
	movs r0, 0
	strb r0, [r1]
	ldr r4, =gBitTable
	ldr r2, [r4]
	ands r2, r5
	ldr r6, =gNoOfAllBanks
	cmp r2, 0
	bne _0804D634
	adds r7, r6, 0
	ldrb r0, [r6]
	cmp r2, r0
	bcs _0804D634
	adds r3, r1, 0
_0804D61A:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	ldrb r2, [r3]
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	ands r0, r5
	cmp r0, 0
	bne _0804D634
	ldrb r0, [r7]
	cmp r2, r0
	bcc _0804D61A
_0804D634:
	ldrb r0, [r1]
	ldrb r6, [r6]
	cmp r0, r6
	beq _0804D63E
	b _0804D804
_0804D63E:
	mov r1, r8
	mov r2, r12
	str r1, [r2]
	b _0804D804
	.pool
_0804D658:
	movs r0, 0x80
	ands r0, r1
	movs r5, 0x1
	cmp r0, 0
	beq _0804D664
	movs r5, 0
_0804D664:
	movs r0, 0x7F
	ands r0, r1
	bl get_battle_side_of_something
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gSpecialStatuses
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 25
	cmp r0, 0
	bge _0804D690
	ldr r0, [r6]
	adds r0, 0x6
	str r0, [r6]
	b _0804D804
	.pool
_0804D690:
	adds r0, r7, 0
	movs r1, 0x6
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	beq _0804D6E0
	ldr r2, =gActiveBank
	strb r7, [r2]
	ldr r3, =gAbsentBankFlags
	ldr r4, =gBitTable
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r4
	ldr r0, [r0]
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r3]
	ldr r3, =gHitMarker
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r4
	ldr r1, [r0]
	lsls r1, 28
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	mov r0, r8
	str r0, [r6]
	b _0804D804
	.pool
_0804D6E0:
	ldr r4, =gActiveBank
	strb r7, [r4]
	ldrb r0, [r4]
	ldr r3, =gBattleStruct
	ldr r1, [r3]
	adds r1, r0, r1
	adds r1, 0x58
	ldr r2, =gBattlePartyID
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r4]
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0x5C
	movs r1, 0x6
	strb r1, [r0]
	ldr r1, [r3]
	adds r1, 0x93
	ldr r2, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0]
	ldrb r0, [r1]
	bics r0, r2
	strb r0, [r1]
	ldrb r1, [r4]
	movs r0, 0x2
	eors r0, r1
	ldr r3, [r3]
	adds r0, r3
	adds r0, 0x5C
	ldrb r2, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	adds r0, 0x60
	adds r3, r0
	str r3, [sp]
	movs r0, 0
	adds r1, r5, 0
	movs r3, 0
	bl dp01_build_cmdbuf_x16_a_b_c_ptr_d_e_f
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r6]
	adds r0, 0x6
	str r0, [r6]
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	cmp r0, 0
	bne _0804D760
	ldr r1, =gBattleResults
	ldrb r0, [r1, 0x2]
	cmp r0, 0xFE
	bhi _0804D760
	adds r0, 0x1
	strb r0, [r1, 0x2]
_0804D760:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804D7C4
	ldr r1, =gActiveBank
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804D804
	adds r4, r1, 0
_0804D77C:
	ldrb r0, [r4]
	cmp r0, r7
	beq _0804D792
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804D792:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0804D77C
	b _0804D804
	.pool
_0804D7C4:
	adds r0, r7, 0
	bl GetBankIdentity
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r3, [r4]
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0804D7F4
	movs r0, 0x2
	eors r3, r0
	strb r3, [r4]
_0804D7F4:
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	bl sub_8034464
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804D804:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk50_openpartyscreen

	thumb_func_start atk51_switch_handle_order
atk51_switch_handle_order: @ 804D820
	push {r4-r7,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	beq _0804D82C
	b _0804DA8A
_0804D82C:
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r5, =gActiveBank
	strb r0, [r5]
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x1
	beq _0804D8CC
	cmp r0, 0x1
	bgt _0804D858
	cmp r0, 0
	beq _0804D862
	b _0804DA82
	.pool
_0804D858:
	cmp r0, 0x2
	beq _0804D8E8
	cmp r0, 0x3
	beq _0804D922
	b _0804DA82
_0804D862:
	movs r6, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r6, r0
	blt _0804D86E
	b _0804DA82
_0804D86E:
	ldr r7, =gBattleBufferB
_0804D870:
	ldrb r0, [r7]
	cmp r0, 0x22
	bne _0804D8AA
	ldr r5, =gBattleStruct
	ldr r0, [r5]
	adds r0, r6, r0
	adds r0, 0x5C
	ldrb r1, [r7, 0x1]
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, 0x93
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r6, 2
	adds r0, r2
	ldr r4, [r0]
	ands r1, r4
	cmp r1, 0
	bne _0804D8AA
	lsls r0, r6, 24
	lsrs r0, 24
	ldrb r1, [r7, 0x1]
	bl sub_8184FBC
	ldr r1, [r5]
	adds r1, 0x93
	ldrb r0, [r1]
	orrs r4, r0
	strb r4, [r1]
_0804D8AA:
	movs r0, 0x80
	lsls r0, 2
	adds r7, r0
	adds r6, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r6, r0
	blt _0804D870
	b _0804DA82
	.pool
_0804D8CC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804D8DA
	b _0804DA82
_0804D8DA:
	ldrb r0, [r5]
	bl sub_803BDA0
	b _0804DA82
	.pool
_0804D8E8:
	ldr r4, =gBattleStruct
	ldr r0, [r4]
	adds r0, 0x93
	ldrb r1, [r0]
	ldr r6, =gBitTable
	ldrb r2, [r5]
	lsls r0, r2, 2
	adds r0, r6
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0804D922
	ldr r0, =gBattleBufferB
	lsls r1, r2, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r1, [r1]
	adds r0, r2, 0
	bl sub_8184FBC
	ldr r2, [r4]
	adds r2, 0x93
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_0804D922:
	ldr r1, =gBattleCommunication
	ldr r6, =gBattleBufferB
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	lsls r0, 9
	adds r2, r6, 0x1
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	ldr r1, =gBattleStruct
	mov r12, r1
	ldr r1, [r1]
	adds r1, r0, r1
	adds r1, 0x5C
	lsls r0, 9
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _0804DA14
	ldrb r0, [r7]
	mov r3, r12
	ldr r2, [r3]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	ldr r2, [r3]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	lsls r0, 9
	adds r5, r6, 0x2
	adds r0, r5
	ldrb r2, [r0]
	movs r3, 0xF0
	adds r0, r3, 0
	ands r0, r2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r1, [r7]
	mov r0, r12
	ldr r2, [r0]
	lsls r0, r1, 1
	adds r0, r1
	adds r0, r2
	adds r0, 0x61
	lsls r1, 9
	adds r6, 0x3
	adds r1, r6
	ldrb r1, [r1]
	strb r1, [r0]
	ldrb r0, [r7]
	movs r4, 0x2
	eors r0, r4
	mov r1, r12
	ldr r2, [r1]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	ldrb r2, [r1]
	adds r0, r3, 0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	eors r0, r4
	mov r1, r12
	ldr r2, [r1]
	lsls r1, r0, 1
	adds r1, r0
	adds r1, r2
	adds r1, 0x60
	ldrb r0, [r7]
	lsls r0, 9
	adds r0, r5
	ldrb r0, [r0]
	ands r3, r0
	lsrs r3, 4
	ldrb r0, [r1]
	orrs r3, r0
	strb r3, [r1]
	ldrb r0, [r7]
	eors r4, r0
	mov r2, r12
	ldr r0, [r2]
	lsls r1, r4, 1
	adds r1, r4
	adds r1, r0
	adds r1, 0x62
	ldrb r0, [r7]
	lsls r0, 9
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	b _0804DA36
	.pool
_0804DA14:
	movs r0, 0x80
	lsls r0, 15
	ands r1, r0
	cmp r1, 0
	beq _0804DA30
	ldrb r0, [r7]
	mov r3, r12
	ldr r1, [r3]
	adds r1, r0, r1
	adds r1, 0x5C
	ldrb r1, [r1]
	bl sub_80571DC
	b _0804DA36
_0804DA30:
	ldrb r0, [r7]
	bl sub_803BDA0
_0804DA36:
	ldr r1, =gBattleTextBuff1
	movs r5, 0xFD
	strb r5, [r1]
	movs r0, 0x6
	strb r0, [r1, 0x1]
	ldr r4, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	movs r2, 0x58
	muls r0, r2
	adds r0, r4
	ldrh r0, [r0]
	strb r0, [r1, 0x2]
	ldrb r0, [r3]
	muls r0, r2
	adds r0, r4
	ldrh r0, [r0]
	lsrs r0, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r2, =gBattleTextBuff2
	strb r5, [r2]
	movs r0, 0x7
	strb r0, [r2, 0x1]
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	strb r0, [r2, 0x2]
	ldr r1, =gBattleBufferB
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2, 0x3]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r2, 0x4]
_0804DA82:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x3
	str r0, [r1]
_0804DA8A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk51_switch_handle_order

	thumb_func_start atk52_switch_in_effects
atk52_switch_in_effects: @ 804DAAC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gBattlescriptCurrInstr
	mov r9, r0
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldrb r0, [r4]
	bl sub_803FA70
	ldr r1, =gHitMarker
	mov r8, r1
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 28
	mov r2, r8
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r2, =gSpecialStatuses
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r4]
	bl GetBankSide
	ldr r5, =gSideAffecting
	lsls r0, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r1, [r0]
	movs r7, 0x80
	lsls r7, 2
	mov r10, r7
	mov r0, r10
	ands r0, r1
	cmp r0, 0
	beq _0804DB1C
	b _0804DC30
_0804DB1C:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0804DB34
	b _0804DC30
_0804DB34:
	ldr r7, =gBattleMons
	ldrb r2, [r4]
	movs r6, 0x58
	adds r0, r2, 0
	muls r0, r6
	adds r1, r0, r7
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0804DC30
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _0804DC30
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1A
	beq _0804DC30
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 23
	adds r0, r5
	ldrh r2, [r0]
	mov r1, r10
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r4]
	adds r2, r0, 0
	muls r2, r6
	adds r0, r7, 0
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xfdffffff
	ands r0, r1
	str r0, [r2]
	mov r1, r8
	ldr r0, [r1]
	movs r2, 0x41
	negs r2, r2
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r4]
	bl GetBankSide
	ldr r2, =gSideTimers
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0xA]
	movs r1, 0x5
	subs r1, r0
	lsls r1, 25
	lsrs r1, 24
	ldr r5, =gBattleMoveDamage
	ldrb r0, [r4]
	muls r0, r6
	adds r0, r7
	ldrh r0, [r0, 0x2C]
	bl __divsi3
	str r0, [r5]
	cmp r0, 0
	bne _0804DBC8
	movs r0, 0x1
	str r0, [r5]
_0804DBC8:
	ldr r0, =gBattleScripting
	ldrb r1, [r4]
	strb r1, [r0, 0x17]
	bl b_movescr_stack_push_cursor
	mov r7, r9
	ldr r0, [r7]
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0804DC14
	ldr r0, =gUnknown_082DAE90
	str r0, [r7]
	b _0804DD8E
	.pool
_0804DC14:
	cmp r0, 0x1
	bne _0804DC24
	ldr r0, =gUnknown_082DAE59
	mov r1, r9
	str r0, [r1]
	b _0804DD8E
	.pool
_0804DC24:
	ldr r0, =gUnknown_082DAEC7
	mov r2, r9
	str r0, [r2]
	b _0804DD8E
	.pool
_0804DC30:
	ldr r2, =gBattleMons
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	movs r0, 0x58
	muls r0, r3
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	adds r5, r1, 0
	ldr r4, =gDisableStructs
	cmp r0, 0x36
	bne _0804DC5E
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r2, r0, r4
	ldrb r1, [r2, 0x18]
	lsls r0, r1, 30
	cmp r0, 0
	blt _0804DC5E
	movs r0, 0x1
	orrs r0, r1
	strb r0, [r2, 0x18]
_0804DC5E:
	ldrb r0, [r5]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x18]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x18]
	ldrb r1, [r5]
	movs r0, 0
	str r0, [sp]
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _0804DC88
	b _0804DD8E
_0804DC88:
	ldrb r1, [r5]
	movs r0, 0
	movs r2, 0
	bl berry_effects_maybe
	lsls r0, 24
	cmp r0, 0
	bne _0804DD8E
	ldrb r0, [r5]
	bl GetBankSide
	ldr r1, =gSideAffecting
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r2, [r0]
	ldr r1, =0x0000fdff
	ands r1, r2
	strh r1, [r0]
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r7, [r0]
	cmp r4, r7
	bge _0804DCD8
	ldr r6, =gTurnOrder
	adds r1, r5, 0
	ldr r5, =gUnknown_0202407A
	movs r3, 0xC
	adds r2, r0, 0
_0804DCC2:
	adds r0, r4, r6
	ldrb r0, [r0]
	ldrb r7, [r1]
	cmp r0, r7
	bne _0804DCD0
	adds r0, r4, r5
	strb r3, [r0]
_0804DCD0:
	adds r4, 0x1
	ldrb r0, [r2]
	cmp r4, r0
	blt _0804DCC2
_0804DCD8:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bge _0804DD0C
	ldr r6, =gBattleStruct
	ldr r5, =gBattleMons
_0804DCE6:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 23
	adds r0, 0xA8
	ldr r1, [r6]
	adds r1, r0
	movs r0, 0x58
	muls r0, r4
	adds r0, r5
	ldrh r0, [r0, 0x28]
	strh r0, [r1]
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0804DCE6
_0804DD0C:
	ldr r0, =gBattlescriptCurrInstr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r5, r0, 0
	cmp r1, 0x5
	bne _0804DD88
	ldr r0, =gHitMarker
	ldr r0, [r0]
	lsrs r4, r0, 28
	ldr r1, =gUnknown_0202420D
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r2, =gBitTable
	b _0804DD6E
	.pool
_0804DD60:
	ldr r0, =gNoOfAllBanks
	ldrb r3, [r1]
	ldrb r0, [r0]
	cmp r3, r0
	bcs _0804DD88
	adds r0, r3, 0x1
	strb r0, [r1]
_0804DD6E:
	ldrb r0, [r1]
	lsls r0, 2
	adds r0, r2
	ldr r3, [r0]
	adds r0, r4, 0
	ands r0, r3
	cmp r0, 0
	beq _0804DD60
	ldr r0, =gAbsentBankFlags
	ldrb r0, [r0]
	ands r0, r3
	cmp r0, 0
	bne _0804DD60
_0804DD88:
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
_0804DD8E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk52_switch_in_effects

	thumb_func_start atk53_trainer_slide
atk53_trainer_slide: @ 804DDA8
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x08_8_8_8
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk53_trainer_slide

	thumb_func_start atk54_effectiveness_sound
atk54_effectiveness_sound: @ 804DDD8
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0
	bl dp01_build_cmdbuf_x2B_aa_0
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r4]
	adds r0, 0x3
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk54_effectiveness_sound

	thumb_func_start atk55_play_sound
atk55_play_sound: @ 804DE14
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r1, [r0, 0x1]
	ldrb r0, [r0, 0x2]
	lsls r0, 8
	orrs r1, r0
	movs r0, 0
	movs r2, 0
	bl sub_8034300
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r4]
	adds r0, 0x3
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk55_play_sound

	thumb_func_start atk56_fainting_cry
atk56_fainting_cry: @ 804DE50
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x2D_2D_2D_2D
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk56_fainting_cry

	thumb_func_start atk57
atk57: @ 804DE80
	push {r4,lr}
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r0, =gBattleOutcome
	ldrb r1, [r0]
	movs r0, 0
	bl dp01_build_cmdbuf_x37_a
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk57

	thumb_func_start atk58_return_to_ball
atk58_return_to_ball: @ 804DEB8
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	movs r1, 0x1
	bl dp01_build_cmdbuf_x06_a
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk58_return_to_ball

	thumb_func_start atk59_learnmove_inbattle
atk59_learnmove_inbattle: @ 804DEEC
	push {r4-r7,lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r2, [r0]
	ldrb r6, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r6, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r6, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r6, r0
	ldrb r4, [r2, 0x5]
	ldrb r0, [r2, 0x6]
	lsls r0, 8
	orrs r4, r0
	ldrb r0, [r2, 0x7]
	lsls r0, 16
	orrs r4, r0
	ldrb r0, [r2, 0x8]
	lsls r0, 24
	orrs r4, r0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r2, 0x9]
	bl MonTryLearningNewMove
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000fffe
	cmp r5, r0
	bne _0804DF56
	adds r7, r5, 0
_0804DF3A:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	bl MonTryLearningNewMove
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, r7
	beq _0804DF3A
_0804DF56:
	cmp r5, 0
	bne _0804DF70
	ldr r0, =gBattlescriptCurrInstr
	str r4, [r0]
	b _0804E018
	.pool
_0804DF70:
	ldr r0, =0x0000ffff
	cmp r5, r0
	bne _0804DF88
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0xA
	str r0, [r1]
	b _0804E018
	.pool
_0804DF88:
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldr r2, =gBattlePartyID
	ldrb r3, [r1]
	lsls r0, r3, 1
	adds r0, r2
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	ldrh r0, [r0]
	ldrb r1, [r1, 0x10]
	cmp r0, r1
	bne _0804DFC8
	ldr r4, =gBattleMons
	movs r0, 0x58
	adds r2, r3, 0
	muls r2, r0
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0804DFC8
	adds r0, r2, r4
	adds r1, r5, 0
	bl GiveMoveToBattleMon
_0804DFC8:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804E014
	movs r0, 0x2
	bl GetBankByPlayerAI
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldr r2, =gBattlePartyID
	ldrb r3, [r1]
	lsls r0, r3, 1
	adds r0, r2
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	ldrh r0, [r0]
	ldrb r1, [r1, 0x10]
	cmp r0, r1
	bne _0804E014
	ldr r4, =gBattleMons
	movs r0, 0x58
	adds r2, r3, 0
	muls r2, r0
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0804E014
	adds r0, r2, r4
	adds r1, r5, 0
	bl GiveMoveToBattleMon
_0804E014:
	ldr r0, =gBattlescriptCurrInstr
	str r6, [r0]
_0804E018:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk59_learnmove_inbattle

	thumb_func_start atk5A
atk5A: @ 804E038
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r0, =gActiveBank
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gBattleScripting
	ldrb r1, [r0, 0x1F]
	adds r2, r0, 0
	cmp r1, 0x6
	bls _0804E052
	b _0804E3B8
_0804E052:
	lsls r0, r1, 2
	ldr r1, =_0804E068
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804E068:
	.4byte _0804E084
	.4byte _0804E0BC
	.4byte _0804E162
	.4byte _0804E1B8
	.4byte _0804E1E4
	.4byte _0804E38C
	.4byte _0804E3AC
_0804E084:
	movs r4, 0
	str r4, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gUnknown_085CCABB
	movs r1, 0xC
	bl battle_show_message_maybe
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x1F]
	adds r0, 0x1
	strb r0, [r1, 0x1F]
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x1]
	movs r0, 0
	bl sub_8056B74
	b _0804E3B8
	.pool
_0804E0BC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804E0E4
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _0804E0E4
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0
	strb r0, [r4, 0x1]
	bl sub_8056B74
_0804E0E4:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804E10C
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _0804E10C
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0x1
	strb r0, [r4, 0x1]
	bl sub_8056B74
_0804E10C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0804E150
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gBattleCommunication
	ldrb r4, [r0, 0x1]
	cmp r4, 0
	bne _0804E20A
	str r5, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	movs r0, 0x1
	negs r0, r0
	str r4, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	b _0804E192
	.pool
_0804E150:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0804E15A
	b _0804E3B8
_0804E15A:
	movs r0, 0x5
	bl PlaySE
	b _0804E20A
_0804E162:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804E170
	b _0804E3B8
_0804E170:
	bl FreeAllWindowBuffers
	ldr r0, =gPlayerParty
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	ldrb r1, [r1, 0x10]
	ldr r2, =gPlayerPartyCount
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_80A92F8
	ldr r4, =gMoveToLearn
	ldrh r4, [r4]
	str r4, [sp]
	bl sub_81BFA38
_0804E192:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x1F]
	adds r0, 0x1
	strb r0, [r1, 0x1F]
	b _0804E3B8
	.pool
_0804E1B8:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804E1C6
	b _0804E3B8
_0804E1C6:
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	beq _0804E1D2
	b _0804E3B8
_0804E1D2:
	ldrb r0, [r2, 0x1F]
	adds r0, 0x1
	b _0804E3B6
	.pool
_0804E1E4:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804E1F2
	b _0804E3B8
_0804E1F2:
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	beq _0804E1FE
	b _0804E3B8
_0804E1FE:
	bl sub_81C1B94
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x4
	bne _0804E224
_0804E20A:
	ldr r1, =gBattleScripting
	movs r0, 0x5
	strb r0, [r1, 0x1F]
	b _0804E3B8
	.pool
_0804E224:
	ldr r6, =gBattleStruct
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	movs r1, 0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r7, =gPlayerParty
	adds r0, r7
	adds r1, r5, 0
	adds r1, 0xD
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl IsHMMove2
	cmp r0, 0
	beq _0804E274
	ldr r0, =0x0000013f
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	bl b_std_message
	ldr r1, =gBattleScripting
	movs r0, 0x6
	strb r0, [r1, 0x1F]
	b _0804E3B8
	.pool
_0804E274:
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
	ldr r1, =gBattleTextBuff2
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	strb r4, [r1, 0x2]
	lsrs r0, r4, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r7
	adds r1, r5, 0
	bl RemoveMonPPBonus
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r7
	ldr r7, =gMoveToLearn
	ldrh r1, [r7]
	adds r2, r5, 0
	bl SetMonMoveSlot
	ldr r0, =gBattlePartyID
	ldr r1, [r6]
	ldrh r0, [r0]
	ldrb r1, [r1, 0x10]
	cmp r0, r1
	bne _0804E30A
	ldr r4, =gBattleMons
	ldr r0, [r4, 0x50]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0804E30A
	ldr r0, =gDisableStructs
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0804E30A
	adds r0, r4, 0
	adds r1, r5, 0
	bl RemoveBattleMonPPBonus
	ldrh r1, [r7]
	adds r0, r4, 0
	adds r2, r5, 0
	bl SetBattleMonMoveSlot
_0804E30A:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804E3B8
	ldr r2, =gBattlePartyID
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	ldrh r0, [r2, 0x4]
	ldrb r1, [r1, 0x10]
	cmp r0, r1
	bne _0804E3B8
	ldr r4, =gBattleMons
	movs r1, 0x80
	lsls r1, 1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0804E3B8
	ldr r0, =gDisableStructs
	adds r0, 0x50
	ldrb r1, [r0]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0804E3B8
	adds r4, 0xB0
	adds r0, r4, 0
	adds r1, r5, 0
	bl RemoveBattleMonPPBonus
	ldr r0, =gMoveToLearn
	ldrh r1, [r0]
	adds r0, r4, 0
	adds r2, r5, 0
	bl SetBattleMonMoveSlot
	b _0804E3B8
	.pool
_0804E38C:
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _0804E3B8
	.pool
_0804E3AC:
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804E3B8
	movs r0, 0x2
_0804E3B6:
	strb r0, [r2, 0x1F]
_0804E3B8:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk5A

	thumb_func_start atk5B_80256E0
atk5B_80256E0: @ 804E3C8
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gBattleScripting
	ldrb r4, [r5, 0x1F]
	cmp r4, 0
	beq _0804E3E0
	cmp r4, 0x1
	beq _0804E410
	b _0804E4FA
	.pool
_0804E3E0:
	str r4, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gUnknown_085CCABB
	movs r1, 0xC
	bl battle_show_message_maybe
	ldrb r0, [r5, 0x1F]
	adds r0, 0x1
	strb r0, [r5, 0x1F]
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x1]
	movs r0, 0
	bl sub_8056B74
	b _0804E4FA
	.pool
_0804E410:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804E438
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	beq _0804E438
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0
	strb r0, [r4, 0x1]
	bl sub_8056B74
_0804E438:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804E460
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _0804E460
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0x1
	strb r0, [r4, 0x1]
	bl sub_8056B74
_0804E460:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0804E4C4
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	beq _0804E4A4
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
	b _0804E4AC
	.pool
_0804E4A4:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0804E4AC:
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	b _0804E4FA
	.pool
_0804E4C4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804E4FA
	movs r0, 0x5
	bl PlaySE
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
	str r4, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
_0804E4FA:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk5B_80256E0

	thumb_func_start atk5C_hitanimation
atk5C_hitanimation: @ 804E508
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r2, =gActiveBank
	strb r0, [r2]
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	bne _0804E58C
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	beq _0804E55A
	ldr r1, =gBattleMons
	ldrb r2, [r2]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _0804E55A
	ldr r0, =gDisableStructs
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	bne _0804E58C
_0804E55A:
	movs r0, 0
	bl dp01_build_cmdbuf_x29_29_29_29
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	b _0804E592
	.pool
_0804E58C:
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
_0804E592:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end atk5C_hitanimation

	thumb_func_start sub_804E598
sub_804E598: @ 804E598
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r6, r0, 16
	movs r7, 0
	movs r5, 0
	movs r0, 0x80
	lsls r0, 3
	cmp r6, r0
	bne _0804E5D8
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x94
	ldrb r2, [r0]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x4A
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	muls r0, r2
	b _0804E6CA
	.pool
_0804E5D8:
	ldr r0, =gTrainers
	lsls r2, r6, 2
	adds r1, r2, r6
	lsls r1, 3
	adds r4, r1, r0
	ldrb r3, [r4]
	mov r12, r0
	cmp r3, 0x1
	beq _0804E62E
	cmp r3, 0x1
	bgt _0804E5F8
	cmp r3, 0
	beq _0804E602
	b _0804E644
	.pool
_0804E5F8:
	cmp r3, 0x2
	beq _0804E618
	cmp r3, 0x3
	beq _0804E62E
	b _0804E644
_0804E602:
	mov r0, r12
	adds r0, 0x24
	adds r0, r1, r0
	ldr r1, [r0]
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, r1
	subs r0, 0x8
	b _0804E642
_0804E618:
	mov r0, r12
	adds r0, 0x24
	adds r0, r1, r0
	ldr r1, [r0]
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, r1
	subs r0, 0x8
	b _0804E642
_0804E62E:
	mov r0, r12
	adds r0, 0x24
	adds r0, r1, r0
	ldr r1, [r0]
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	subs r0, 0x10
_0804E642:
	ldrb r5, [r0, 0x2]
_0804E644:
	ldr r1, =gUnknown_0831AEB8
	lsls r0, r7, 2
	adds r4, r0, r1
	ldrb r3, [r4]
	ldr r0, =gBattleStruct
	mov r8, r0
	mov r9, r1
	ldr r1, =gBattleTypeFlags
	mov r10, r1
	cmp r3, 0xFF
	beq _0804E67A
	adds r0, r2, r6
	lsls r0, 3
	add r0, r12
	ldrb r1, [r0, 0x1]
	cmp r3, r1
	beq _0804E67A
	adds r2, r0, 0
	adds r0, r4, 0
_0804E66A:
	adds r0, 0x4
	adds r7, 0x1
	ldrb r1, [r0]
	cmp r1, 0xFF
	beq _0804E67A
	ldrb r3, [r2, 0x1]
	cmp r1, r3
	bne _0804E66A
_0804E67A:
	mov r0, r10
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 8
	ands r0, r1
	cmp r0, 0
	bne _0804E6B4
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0804E6B4
	mov r3, r8
	ldr r0, [r3]
	adds r0, 0x4A
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r5, 0
	muls r1, r0
	lsls r0, r7, 2
	add r0, r9
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	b _0804E6C8
	.pool
_0804E6B4:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x4A
	ldrb r0, [r0]
	lsls r0, 2
	adds r1, r5, 0
	muls r1, r0
	lsls r0, r7, 2
	add r0, r9
	ldrb r0, [r0, 0x1]
_0804E6C8:
	muls r0, r1
_0804E6CA:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_804E598

	thumb_func_start atk5D_getmoneyreward
atk5D_getmoneyreward: @ 804E6D8
	push {r4,lr}
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	bl sub_804E598
	adds r4, r0, 0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0804E6FC
	ldr r0, =gTrainerBattleOpponent_B
	ldrh r0, [r0]
	bl sub_804E598
	adds r4, r0
_0804E6FC:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	adds r1, r4, 0
	bl add_money
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x4
	strb r0, [r1, 0x2]
	movs r0, 0x5
	strb r0, [r1, 0x3]
	strb r4, [r1, 0x4]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r4
	lsrs r0, 8
	strb r0, [r1, 0x5]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r4
	lsrs r0, 16
	strb r0, [r1, 0x6]
	lsrs r0, r4, 24
	strb r0, [r1, 0x7]
	movs r0, 0xFF
	strb r0, [r1, 0x8]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk5D_getmoneyreward

	thumb_func_start atk5E_8025A70
atk5E_8025A70: @ 804E764
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r6, =gActiveBank
	strb r0, [r6]
	ldr r5, =gBattleCommunication
	ldrb r0, [r5]
	mov r8, r4
	cmp r0, 0
	beq _0804E794
	cmp r0, 0x1
	beq _0804E7AC
	b _0804E800
	.pool
_0804E794:
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl dp01_build_cmdbuf_x00_a_b_0
	ldrb r0, [r6]
	bl dp01_battle_side_mark_buffer_for_execution
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _0804E800
_0804E7AC:
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804E800
	ldrb r0, [r6]
	lsls r0, 9
	ldr r1, =gBattleBufferB + 4
	adds r0, r1
	mov r12, r0
	movs r2, 0
	adds r4, r6, 0
	movs r5, 0x58
	ldr r6, =gBattleMons + 0x24
	adds r7, r6, 0
	subs r7, 0x18
	mov r3, r12
	adds r3, 0xC
_0804E7CE:
	lsls r1, r2, 1
	ldrb r0, [r4]
	muls r0, r5
	adds r1, r0
	adds r1, r7
	ldrh r0, [r3]
	strh r0, [r1]
	ldrb r0, [r4]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r2, r1
	adds r1, r6
	mov r0, r12
	adds r0, 0x24
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	ble _0804E7CE
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_0804E800:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk5E_8025A70

	thumb_func_start atk5F_8025B24
atk5F_8025B24: @ 804E818
	push {lr}
	ldr r0, =gActiveBank
	ldr r2, =gBankAttacker
	ldrb r3, [r2]
	strb r3, [r0]
	ldr r1, =gBankTarget
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	ldr r2, =gHitMarker
	ldr r1, [r2]
	movs r3, 0x80
	lsls r3, 5
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _0804E854
	ldr r0, =0xffffefff
	ands r1, r0
	b _0804E856
	.pool
_0804E854:
	orrs r1, r3
_0804E856:
	str r1, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk5F_8025B24

	thumb_func_start atk60_increment_gamestat
atk60_increment_gamestat: @ 804E868
	push {lr}
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0804E882
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl IncrementGameStat
_0804E882:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk60_increment_gamestat

	thumb_func_start atk61_8025BA4
atk61_8025BA4: @ 804E898
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x30
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804E94C
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r8, r1
	cmp r0, 0
	bne _0804E8CA
	ldr r0, =gPlayerParty
	mov r8, r0
_0804E8CA:
	movs r7, 0
	add r6, sp, 0x4
	mov r5, sp
_0804E8D0:
	movs r0, 0x64
	muls r0, r7
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _0804E8F4
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _0804E914
_0804E8F4:
	ldr r0, =0x0000ffff
	strh r0, [r5]
	movs r0, 0
	b _0804E926
	.pool
_0804E914:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
_0804E926:
	str r0, [r6]
	adds r6, 0x8
	adds r5, 0x8
	adds r7, 0x1
	cmp r7, 0x5
	ble _0804E8D0
	movs r0, 0
	mov r1, sp
	movs r2, 0x1
	bl dp01_build_cmdbuf_x30_TODO
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_0804E94C:
	add sp, 0x30
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk61_8025BA4

	thumb_func_start atk62_08025C6C
atk62_08025C6C: @ 804E960
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x31_31_31_31
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk62_08025C6C

	thumb_func_start atk63_jumptorandomattack
atk63_jumptorandomattack: @ 804E990
	push {r4,lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0
	beq _0804E9B4
	ldr r0, =gCurrentMove
	ldr r1, =gRandomMove
	ldrh r1, [r1]
	strh r1, [r0]
	b _0804E9C2
	.pool
_0804E9B4:
	ldr r2, =gUnknown_020241EC
	ldr r1, =gCurrentMove
	ldr r0, =gRandomMove
	ldrh r0, [r0]
	strh r0, [r1]
	strh r0, [r2]
	adds r0, r1, 0
_0804E9C2:
	ldr r3, =gUnknown_082D86A8
	ldr r2, =gBattleMoves
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk63_jumptorandomattack

	thumb_func_start atk64_statusanimation
atk64_statusanimation: @ 804E9F4
	push {r4,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804EA5C
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r1, =gStatuses3
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	bne _0804EA54
	ldr r0, =gDisableStructs
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	bne _0804EA54
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0804EA54
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	ldr r2, [r0]
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x1B_aaaa_b
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_0804EA54:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_0804EA5C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk64_statusanimation

	thumb_func_start atk65_status2animation
atk65_status2animation: @ 804EA84
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804EB04
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r5, =gActiveBank
	strb r0, [r5]
	ldr r1, [r4]
	ldrb r3, [r1, 0x2]
	ldrb r0, [r1, 0x3]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r1, 0x5]
	lsls r0, 24
	orrs r3, r0
	ldr r1, =gStatuses3
	ldrb r2, [r5]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	bne _0804EAFC
	ldr r0, =gDisableStructs
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	bne _0804EAFC
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0804EAFC
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r2, [r0]
	ands r2, r3
	movs r0, 0
	movs r1, 0x1
	bl dp01_build_cmdbuf_x1B_aaaa_b
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
_0804EAFC:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x6
	str r0, [r1]
_0804EB04:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk65_status2animation

	thumb_func_start atk66_chosenstatusanimation
atk66_chosenstatusanimation: @ 804EB2C
	push {r4,r5,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _0804EB9E
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r5, =gActiveBank
	strb r0, [r5]
	ldr r4, [r4]
	ldrb r2, [r4, 0x3]
	ldrb r0, [r4, 0x4]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r4, 0x5]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r4, 0x6]
	lsls r0, 24
	orrs r2, r0
	ldr r1, =gStatuses3
	ldrb r3, [r5]
	lsls r0, r3, 2
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x000400c0
	ands r0, r1
	cmp r0, 0
	bne _0804EB96
	ldr r0, =gDisableStructs
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	cmp r0, 0
	bne _0804EB96
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0804EB96
	ldrb r1, [r4, 0x2]
	movs r0, 0
	bl dp01_build_cmdbuf_x1B_aaaa_b
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
_0804EB96:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x7
	str r0, [r1]
_0804EB9E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk66_chosenstatusanimation

	thumb_func_start atk67_8025ECC
atk67_8025ECC: @ 804EBC0
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gBattleCommunication
	ldrb r4, [r5]
	cmp r4, 0
	beq _0804EBD8
	cmp r4, 0x1
	beq _0804EC04
	b _0804EC96
	.pool
_0804EBD8:
	str r4, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gUnknown_085CCABB
	movs r1, 0xC
	bl battle_show_message_maybe
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	strb r4, [r5, 0x1]
	movs r0, 0
	bl sub_8056B74
	b _0804EC96
	.pool
_0804EC04:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804EC2A
	ldrb r0, [r5, 0x1]
	cmp r0, 0
	beq _0804EC2A
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r5, 0x1]
	bl sub_8056BAC
	movs r0, 0
	strb r0, [r5, 0x1]
	bl sub_8056B74
_0804EC2A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804EC52
	ldr r4, =gBattleCommunication
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _0804EC52
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4, 0x1]
	bl sub_8056BAC
	movs r0, 0x1
	strb r0, [r4, 0x1]
	bl sub_8056B74
_0804EC52:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804EC70
	ldr r0, =gBattleCommunication
	movs r4, 0x1
	strb r4, [r0, 0x1]
	b _0804EC7A
	.pool
_0804EC70:
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0804EC96
_0804EC7A:
	movs r0, 0x5
	bl PlaySE
	str r4, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_0804EC96:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk67_8025ECC

	thumb_func_start atk68_80246A0
atk68_80246A0: @ 804ECA4
	push {r4,r5,lr}
	movs r1, 0
	ldr r2, =gNoOfAllBanks
	ldr r5, =gBattlescriptCurrInstr
	ldrb r0, [r2]
	cmp r1, r0
	bge _0804ECC2
	ldr r4, =gUnknown_0202407A
	movs r3, 0xC
_0804ECB6:
	adds r0, r1, r4
	strb r3, [r0]
	adds r1, 0x1
	ldrb r0, [r2]
	cmp r1, r0
	blt _0804ECB6
_0804ECC2:
	ldr r0, [r5]
	adds r0, 0x1
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk68_80246A0

	thumb_func_start atk69_dmg_adjustment2
atk69_dmg_adjustment2: @ 804ECDC
	push {r4-r7,lr}
	ldr r7, =gBattleMons
	ldr r6, =gBankTarget
	ldrb r2, [r6]
	movs r5, 0x58
	adds r0, r2, 0
	muls r0, r5
	adds r1, r0, r7
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0804ED10
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x7]
	ldrb r6, [r0, 0x1A]
	b _0804ED2A
	.pool
_0804ED10:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r7
	ldrh r0, [r0, 0x2E]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r6, r0, 24
_0804ED2A:
	ldr r1, =gUnknown_0202420F
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	strb r0, [r1]
	cmp r4, 0x27
	bne _0804ED68
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r6
	bcs _0804ED68
	ldrb r0, [r5]
	movs r1, 0x27
	bl RecordItemEffectBattle
	ldr r2, =gSpecialStatuses
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
_0804ED68:
	ldr r2, =gBattleMons
	ldr r3, =gBankTarget
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, r2, 0
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 17
	ands r1, r0
	adds r5, r2, 0
	cmp r1, 0
	bne _0804EE38
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x65
	beq _0804EDBA
	ldr r0, =gProtectStructs
	lsls r1, r4, 4
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	blt _0804EDBA
	ldr r0, =gSpecialStatuses
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	beq _0804EE38
_0804EDBA:
	ldrb r0, [r3]
	movs r4, 0x58
	muls r0, r4
	adds r0, r5
	ldrh r1, [r0, 0x28]
	ldr r2, =gBattleMoveDamage
	ldr r0, [r2]
	cmp r1, r0
	bgt _0804EE38
	subs r0, r1, 0x1
	str r0, [r2]
	ldr r1, =gProtectStructs
	ldrb r3, [r3]
	lsls r0, r3, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	cmp r0, 0
	bge _0804EE10
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	b _0804EE38
	.pool
_0804EE10:
	ldr r0, =gSpecialStatuses
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	beq _0804EE38
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gLastUsedItem
	adds r0, r3, 0
	muls r0, r4
	adds r0, r5
	ldrh r0, [r0, 0x2E]
	strh r0, [r1]
_0804EE38:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk69_dmg_adjustment2

	thumb_func_start atk6A_removeitem
atk6A_removeitem: @ 804EE58
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, =gBattlescriptCurrInstr
	ldr r0, [r6]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r5, =gActiveBank
	strb r0, [r5]
	ldr r1, =gBattleStruct
	ldrb r4, [r5]
	lsls r0, r4, 1
	adds r0, 0xB8
	ldr r1, [r1]
	adds r1, r0
	ldr r2, =gBattleMons
	movs r3, 0x58
	adds r0, r4, 0
	muls r0, r3
	adds r0, r2
	ldrh r0, [r0, 0x2E]
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r3
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x2E]
	ldrb r0, [r5]
	muls r0, r3
	adds r2, 0x2E
	adds r0, r2
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x2
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r5]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r6]
	adds r0, 0x2
	str r0, [r6]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk6A_removeitem

	thumb_func_start atk6B_atknameinbuff1
atk6B_atknameinbuff1: @ 804EEC8
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x7
	strb r0, [r1, 0x1]
	ldr r2, =gBankAttacker
	ldrb r0, [r2]
	strb r0, [r1, 0x2]
	ldr r3, =gBattlePartyID
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atk6B_atknameinbuff1

	thumb_func_start atk6C_lvlbox_display
atk6C_lvlbox_display: @ 804EF04
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gBattleScripting
	ldrb r1, [r0, 0x1E]
	adds r4, r0, 0
	cmp r1, 0
	bne _0804EF28
	bl sub_804F498
	cmp r0, 0
	beq _0804EF24
	movs r0, 0x3
	b _0804EF26
	.pool
_0804EF24:
	movs r0, 0x1
_0804EF26:
	strb r0, [r4, 0x1E]
_0804EF28:
	ldrb r0, [r4, 0x1E]
	subs r0, 0x1
	cmp r0, 0x9
	bls _0804EF32
	b _0804F0F2
_0804EF32:
	lsls r0, 2
	ldr r1, =_0804EF40
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804EF40:
	.4byte _0804EF68
	.4byte _0804EF94
	.4byte _0804EFAC
	.4byte _0804F000
	.4byte _0804F014
	.4byte _0804F02C
	.4byte _0804F014
	.4byte _0804F04C
	.4byte _0804F07C
	.4byte _0804F0C0
_0804EF68:
	ldr r1, =gUnknown_02022E1E
	movs r0, 0x60
	strh r0, [r1]
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x2
	bl ShowBg
	bl sub_804F17C
	ldr r1, =gBattleScripting
	movs r0, 0x2
	strb r0, [r1, 0x1E]
	b _0804F0F2
	.pool
_0804EF94:
	bl sub_804F1CC
	lsls r0, 24
	cmp r0, 0
	beq _0804EFA0
	b _0804F0F2
_0804EFA0:
	ldr r1, =gBattleScripting
	movs r0, 0x3
	strb r0, [r1, 0x1E]
	b _0804F0F2
	.pool
_0804EFAC:
	ldr r1, =gUnknown_02022E18
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1A
	movs r2, 0x80
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	movs r0, 0
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x80
	str r0, [sp]
	movs r0, 0x12
	movs r1, 0x7
	movs r2, 0x1D
	movs r3, 0x13
	bl sub_8056A3C
	ldr r1, =gBattleScripting
	movs r0, 0x4
	strb r0, [r1, 0x1E]
	b _0804F0F2
	.pool
_0804F000:
	bl sub_804F100
	movs r0, 0xD
	bl PutWindowTilemap
	movs r0, 0xD
	movs r1, 0x3
	bl CopyWindowToVram
	b _0804F06A
_0804F014:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0804F0F2
	ldr r0, =gUnknown_02022E1A
	strh r1, [r0]
	b _0804F06A
	.pool
_0804F02C:
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	cmp r0, 0
	beq _0804F0F2
	movs r0, 0x5
	bl PlaySE
	bl sub_804F144
	movs r0, 0xD
	movs r1, 0x2
	bl CopyWindowToVram
	b _0804F06A
	.pool
_0804F04C:
	ldr r0, =gMain
	ldrh r0, [r0, 0x2E]
	cmp r0, 0
	beq _0804F0F2
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x81
	str r0, [sp]
	movs r0, 0x12
	movs r1, 0x7
	movs r2, 0x1D
	movs r3, 0x13
	bl sub_8056A3C
_0804F06A:
	ldr r1, =gBattleScripting
	ldrb r0, [r1, 0x1E]
	adds r0, 0x1
	strb r0, [r1, 0x1E]
	b _0804F0F2
	.pool
_0804F07C:
	bl sub_804F344
	lsls r0, 24
	cmp r0, 0
	bne _0804F0F2
	movs r0, 0xE
	bl ClearWindowTilemap
	movs r0, 0xE
	movs r1, 0x1
	bl CopyWindowToVram
	movs r0, 0xD
	bl ClearWindowTilemap
	movs r0, 0xD
	movs r1, 0x1
	bl CopyWindowToVram
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x2
	bl ShowBg
	ldr r1, =gBattleScripting
	movs r0, 0xA
	strb r0, [r1, 0x1E]
	b _0804F0F2
	.pool
_0804F0C0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0804F0F2
	movs r0, 0
	movs r1, 0x7
	movs r2, 0
	bl SetBgAttribute
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_0804F0F2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk6C_lvlbox_display

	thumb_func_start sub_804F100
sub_804F100: @ 804F100
	push {lr}
	sub sp, 0x14
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	add r1, sp, 0x8
	bl sub_81D388C
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r1, [r0, 0x10]
	movs r0, 0xD
	str r0, [sp]
	movs r0, 0xF
	str r0, [sp, 0x4]
	movs r0, 0xD
	add r2, sp, 0x8
	movs r3, 0xE
	bl sub_81D3640
	add sp, 0x14
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804F100

	thumb_func_start sub_804F144
sub_804F144: @ 804F144
	push {lr}
	sub sp, 0x10
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	add r1, sp, 0x4
	bl sub_81D388C
	movs r0, 0xF
	str r0, [sp]
	movs r0, 0xD
	add r1, sp, 0x4
	movs r2, 0xE
	movs r3, 0xD
	bl sub_81D3784
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804F144

	thumb_func_start sub_804F17C
sub_804F17C: @ 804F17C
	push {lr}
	ldr r1, =gUnknown_02022E1E
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02022E1C
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r0, =gUnknown_0831C2C8
	movs r1, 0x60
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_0831C2E8
	movs r0, 0xE
	movs r2, 0
	movs r3, 0
	bl CopyToWindowPixelBuffer
	movs r0, 0xE
	bl PutWindowTilemap
	movs r0, 0xE
	movs r1, 0x3
	bl CopyWindowToVram
	bl sub_804F384
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804F17C

	thumb_func_start sub_804F1CC
sub_804F1CC: @ 804F1CC
	push {r4,r5,lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _0804F1DC
	movs r0, 0x1
	b _0804F216
_0804F1DC:
	ldr r4, =gUnknown_02022E1C
	ldrh r1, [r4]
	movs r5, 0x80
	lsls r5, 2
	cmp r1, r5
	bne _0804F1F0
	movs r0, 0
	b _0804F216
	.pool
_0804F1F0:
	movs r0, 0xD0
	lsls r0, 1
	cmp r1, r0
	bne _0804F1FC
	bl sub_804F220
_0804F1FC:
	ldrh r0, [r4]
	adds r0, 0x8
	strh r0, [r4]
	lsls r0, 16
	ldr r1, =0x01ff0000
	cmp r0, r1
	bls _0804F20C
	strh r5, [r4]
_0804F20C:
	ldrh r1, [r4]
	eors r1, r5
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_0804F216:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_804F1CC

	thumb_func_start sub_804F220
sub_804F220: @ 804F220
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r6, =gBattleStruct
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x38
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	bl GetMonGender
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	muls r0, r5
	adds r0, r4
	ldr r5, =gStringVar4
	adds r1, r5, 0
	bl GetMonNickname
	str r5, [sp]
	mov r2, sp
	movs r1, 0
	movs r0, 0xE
	strb r0, [r2, 0x4]
	mov r0, sp
	strb r1, [r0, 0x5]
	movs r4, 0x20
	strb r4, [r0, 0x6]
	strb r1, [r0, 0x7]
	strb r4, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x10
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r0, 0x10
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	mov r0, sp
	strb r4, [r0, 0xD]
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	movs r0, 0xF9
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0x5
	strb r0, [r5]
	adds r5, 0x1
	adds r4, r5, 0
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	subs r4, r5, r4
	movs r2, 0x4
	subs r2, r4
	lsls r2, 16
	lsrs r2, 16
	movs r1, 0x77
	bl StringFill
	adds r5, r0, 0
	cmp r7, 0xFF
	beq _0804F320
	cmp r7, 0
	bne _0804F300
	movs r1, 0
	movs r2, 0xC
	bl WriteColorChangeControlCode
	adds r5, r0, 0
	movs r1, 0x1
	movs r2, 0xD
	bl WriteColorChangeControlCode
	adds r5, r0, 0
	movs r0, 0xB5
	b _0804F318
	.pool
_0804F300:
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0xE
	bl WriteColorChangeControlCode
	adds r5, r0, 0
	movs r1, 0x1
	movs r2, 0xF
	bl WriteColorChangeControlCode
	adds r5, r0, 0
	movs r0, 0xB6
_0804F318:
	strb r0, [r5]
	adds r5, 0x1
	movs r0, 0xFF
	strb r0, [r5]
_0804F320:
	mov r0, sp
	movs r1, 0xA
	strb r1, [r0, 0x7]
	strb r1, [r0, 0x9]
	movs r1, 0xFF
	movs r2, 0
	bl AddTextPrinter
	movs r0, 0xE
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804F220

	thumb_func_start sub_804F344
sub_804F344: @ 804F344
	push {lr}
	ldr r0, =gUnknown_02022E1C
	ldrh r1, [r0]
	movs r3, 0xD0
	lsls r3, 1
	adds r2, r0, 0
	cmp r1, r3
	bne _0804F35C
	movs r0, 0
	b _0804F380
	.pool
_0804F35C:
	ldrh r0, [r2]
	adds r1, r0, 0
	subs r1, 0x10
	ldr r0, =0x0000019f
	cmp r1, r0
	bgt _0804F370
	strh r3, [r2]
	b _0804F372
	.pool
_0804F370:
	strh r1, [r2]
_0804F372:
	ldrh r1, [r2]
	movs r0, 0xD0
	lsls r0, 1
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
_0804F380:
	pop {r1}
	bx r1
	thumb_func_end sub_804F344

	thumb_func_start sub_804F384
sub_804F384: @ 804F384
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	ldr r0, =gBattleStruct
	mov r8, r0
	ldr r0, [r0]
	ldrb r0, [r0, 0x10]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r1, r8
	ldr r0, [r1]
	ldrb r0, [r0, 0x10]
	muls r0, r6
	adds r0, r5
	movs r1, 0
	bl GetMonData
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_80D2EDC
	str r0, [sp]
	ldr r5, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r5
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	ldr r1, =0xd75a0000
	orrs r0, r1
	str r0, [sp, 0x4]
	adds r0, r4, 0
	bl sub_80D30B0
	str r0, [sp, 0x8]
	add r4, sp, 0x8
	ldr r0, [r4, 0x4]
	ands r0, r5
	ldr r1, =0x0000d75a
	orrs r0, r1
	str r0, [r4, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	adds r0, r4, 0
	bl LoadSpritePalette
	ldr r0, =gUnknown_0831C3C0
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0xA
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldr r0, =gUnknown_02022E1C
	ldrh r0, [r0]
	strh r0, [r1, 0x30]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804F384

	thumb_func_start sub_804F450
sub_804F450: @ 804F450
	push {r4,lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_02022E1C
	ldrh r1, [r2, 0x30]
	ldrh r0, [r0]
	subs r1, r0
	strh r1, [r2, 0x24]
	lsls r1, 16
	cmp r1, 0
	beq _0804F470
	movs r0, 0x1
	strh r0, [r2, 0x2E]
	b _0804F48C
	.pool
_0804F470:
	movs r1, 0x2E
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0804F48C
	adds r0, r2, 0
	bl DestroySprite
	ldr r4, =0x0000d75a
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
_0804F48C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804F450

	thumb_func_start sub_804F498
sub_804F498: @ 804F498
	push {lr}
	ldr r3, =gBattlePartyID
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldrh r1, [r3]
	ldrb r2, [r0, 0x10]
	cmp r1, r2
	beq _0804F4BA
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804F4CC
	ldrh r0, [r3, 0x4]
	cmp r0, r2
	bne _0804F4CC
_0804F4BA:
	movs r0, 0x1
	b _0804F4CE
	.pool
_0804F4CC:
	movs r0, 0
_0804F4CE:
	pop {r1}
	bx r1
	thumb_func_end sub_804F498

	thumb_func_start atk6D_set_sentpokes_values
atk6D_set_sentpokes_values: @ 804F4D4
	push {lr}
	bl sub_803F988
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk6D_set_sentpokes_values

	thumb_func_start atk6E_set_atk_to_player0
atk6E_set_atk_to_player0: @ 804F4EC
	push {lr}
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r1, =gBankAttacker
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk6E_set_atk_to_player0

	thumb_func_start atk6F_set_visible
atk6F_set_visible: @ 804F50C
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r0, [r5]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x33_a_33_33
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk6F_set_visible

	thumb_func_start atk70_record_ability
atk70_record_ability: @ 804F540
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldrb r0, [r1]
	ldr r1, =gLastUsedAbility
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk70_record_ability

	thumb_func_start sub_804F574
sub_804F574: @ 804F574
	ldr r2, =gBattleTextBuff2
	movs r0, 0xFD
	strb r0, [r2]
	movs r0, 0x2
	strb r0, [r2, 0x1]
	ldr r0, =gMoveToLearn
	ldrh r1, [r0]
	strb r1, [r2, 0x2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r2, 0x3]
	movs r0, 0xFF
	strb r0, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end sub_804F574

	thumb_func_start atk71_buffer_move_to_learn
atk71_buffer_move_to_learn: @ 804F59C
	push {lr}
	bl sub_804F574
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk71_buffer_move_to_learn

	thumb_func_start atk72_jump_if_can_run_frombattle
atk72_jump_if_can_run_frombattle: @ 804F5B4
	push {lr}
	ldr r0, =gUnknown_0202420D
	ldrb r0, [r0]
	bl sub_803EC20
	lsls r0, 24
	cmp r0, 0
	beq _0804F5E8
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
	b _0804F5F0
	.pool
_0804F5E8:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_0804F5F0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk72_jump_if_can_run_frombattle

	thumb_func_start atk73_hp_thresholds
atk73_hp_thresholds: @ 804F5F8
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r4, [r0]
	movs r6, 0x1
	ands r4, r6
	cmp r4, 0
	bne _0804F68E
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gActiveBank
	strb r0, [r1]
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gBattleMons
	movs r1, 0x58
	muls r1, r0
	adds r1, r2
	ldrh r5, [r1, 0x28]
	movs r0, 0x64
	muls r0, r5
	ldrh r1, [r1, 0x2C]
	bl __divsi3
	cmp r0, 0
	bne _0804F636
	movs r0, 0x1
_0804F636:
	cmp r0, 0x45
	bgt _0804F63E
	cmp r5, 0
	bne _0804F65C
_0804F63E:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xB1
	strb r4, [r0]
	b _0804F68E
	.pool
_0804F65C:
	cmp r0, 0x27
	ble _0804F670
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xB1
	strb r6, [r0]
	b _0804F68E
	.pool
_0804F670:
	cmp r0, 0x9
	ble _0804F684
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xB1
	movs r1, 0x2
	b _0804F68C
	.pool
_0804F684:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xB1
	movs r1, 0x3
_0804F68C:
	strb r1, [r0]
_0804F68E:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk73_hp_thresholds

	thumb_func_start atk74_hp_thresholds2
atk74_hp_thresholds2: @ 804F6A4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gBattleTypeFlags
	ldr r7, [r0]
	movs r0, 0x1
	mov r8, r0
	ands r7, r0
	cmp r7, 0
	bne _0804F73E
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	adds r4, r0, 0
	ldr r0, =gActiveBank
	strb r4, [r0]
	movs r0, 0x1
	eors r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gBattleStruct
	ldr r6, [r1]
	lsrs r0, 23
	adds r0, r6
	adds r0, 0xA8
	ldrb r5, [r0]
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r4
	adds r0, r1
	ldrh r4, [r0, 0x28]
	subs r1, r5, r4
	movs r0, 0x64
	muls r0, r1
	adds r1, r5, 0
	bl __divsi3
	adds r1, r0, 0
	cmp r4, r5
	bcc _0804F71C
	adds r0, r6, 0
	adds r0, 0xB1
	strb r7, [r0]
	b _0804F73E
	.pool
_0804F71C:
	cmp r0, 0x1D
	bgt _0804F72A
	adds r0, r6, 0
	adds r0, 0xB1
	mov r1, r8
	strb r1, [r0]
	b _0804F73E
_0804F72A:
	cmp r1, 0x45
	bgt _0804F736
	adds r1, r6, 0
	adds r1, 0xB1
	movs r0, 0x2
	b _0804F73C
_0804F736:
	adds r1, r6, 0
	adds r1, 0xB1
	movs r0, 0x3
_0804F73C:
	strb r0, [r1]
_0804F73E:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk74_hp_thresholds2

	thumb_func_start atk75_8026A58
atk75_8026A58: @ 804F754
	push {lr}
	sub sp, 0x4
	ldr r2, =gUnknown_020244B8
	ldr r1, =gBankAttacker
	ldrb r0, [r1]
	strb r0, [r2]
	ldr r2, =gBattlePartyID
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r1, =gLastUsedItem
	ldrh r1, [r1]
	lsls r2, 24
	lsrs r2, 24
	movs r3, 0x1
	str r3, [sp]
	movs r3, 0
	bl ExecuteTableBasedItemEffect
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk75_8026A58

	thumb_func_start atk76_various
atk76_various: @ 804F7AC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldr r0, [r4]
	ldrb r0, [r0, 0x2]
	cmp r0, 0x1A
	bls _0804F7CA
	b _0804FD70
_0804F7CA:
	lsls r0, 2
	ldr r1, =_0804F7E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0804F7E0:
	.4byte _0804F84C
	.4byte _0804F85C
	.4byte _0804F8BC
	.4byte _0804F8CC
	.4byte _0804F8E4
	.4byte _0804F920
	.4byte _0804F958
	.4byte _0804F9E0
	.4byte _0804FA20
	.4byte _0804FACC
	.4byte _0804FAE8
	.4byte _0804FB3C
	.4byte _0804FB94
	.4byte _0804FC18
	.4byte _0804FC2C
	.4byte _0804FC32
	.4byte _0804FC38
	.4byte _0804FC60
	.4byte _0804FC6A
	.4byte _0804FC78
	.4byte _0804FC8C
	.4byte _0804FCC4
	.4byte _0804FCD8
	.4byte _0804FCF0
	.4byte _0804FD1C
	.4byte _0804FD30
	.4byte _0804FD5C
_0804F84C:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl CancelMultiTurnMoves
	b _0804FD70
	.pool
_0804F85C:
	ldr r1, =gBankAttacker
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	strb r0, [r1]
	ldrb r0, [r1]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSideTimers
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _0804F8A8
	ldr r1, =gBattleMons
	ldrb r2, [r2, 0x9]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _0804F8A8
	strb r2, [r4]
	b _0804FD70
	.pool
_0804F8A8:
	ldr r0, =gBankTarget
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	strb r1, [r0]
	b _0804FD70
	.pool
_0804F8BC:
	bl sub_803BB88
	ldr r1, =gBattleCommunication
	strb r0, [r1]
	b _0804FD70
	.pool
_0804F8CC:
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	movs r1, 0
	bl GetMoveTarget
	ldr r1, =gBankTarget
	strb r0, [r1]
	b _0804FD70
	.pool
_0804F8E4:
	ldr r2, =gHitMarker
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	lsls r0, 28
	ldr r2, [r2]
	ands r2, r0
	cmp r2, 0
	beq _0804F914
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1]
	b _0804FD70
	.pool
_0804F914:
	ldr r0, =gBattleCommunication
	strb r2, [r0]
	b _0804FD70
	.pool
_0804F920:
	ldr r4, =gSpecialStatuses
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	b _0804FD70
	.pool
_0804F958:
	ldr r4, =gBattlePartyID
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldrh r3, [r4]
	ldrb r2, [r0, 0x10]
	adds r6, r1, 0
	cmp r3, r2
	beq _0804F974
	ldrh r0, [r4, 0x4]
	cmp r0, r2
	beq _0804F970
	b _0804FD70
_0804F970:
	cmp r3, r0
	bne _0804F988
_0804F974:
	ldr r1, =gActiveBank
	movs r0, 0
	b _0804F98C
	.pool
_0804F988:
	ldr r1, =gActiveBank
	movs r0, 0x2
_0804F98C:
	strb r0, [r1]
	adds r5, r1, 0
	ldrb r2, [r5]
	lsls r0, r2, 1
	adds r0, 0xC8
	ldr r1, [r6]
	adds r4, r1, r0
	movs r3, 0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r1, 0xC
	adds r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _0804F9CC
	adds r6, r5, 0
	movs r5, 0x58
	adds r2, r1, 0
_0804F9B4:
	adds r3, 0x1
	cmp r3, 0x3
	bgt _0804F9CC
	lsls r1, r3, 1
	ldrb r0, [r6]
	muls r0, r5
	adds r1, r0
	adds r1, r2
	ldrh r0, [r1]
	ldrh r1, [r4]
	cmp r0, r1
	bne _0804F9B4
_0804F9CC:
	cmp r3, 0x4
	beq _0804F9D2
	b _0804FD70
_0804F9D2:
	movs r0, 0
	strh r0, [r4]
	b _0804FD70
	.pool
_0804F9E0:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0xB
	ands r0, r1
	cmp r0, 0x8
	beq _0804F9EE
	b _0804FD70
_0804F9EE:
	ldr r1, =gBattleMons
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	bne _0804F9F8
	b _0804FD70
_0804F9F8:
	adds r0, r1, 0
	adds r0, 0x80
	ldrh r0, [r0]
	cmp r0, 0
	bne _0804FA04
	b _0804FD70
_0804FA04:
	ldr r0, =gHitMarker
	ldr r1, [r0]
	ldr r2, =0xffbfffff
	ands r1, r2
	str r1, [r0]
	b _0804FD70
	.pool
_0804FA20:
	ldr r2, =gBattleCommunication
	mov r8, r2
	movs r0, 0
	strb r0, [r2]
	ldr r1, =gBattleScripting
	ldr r6, =gActiveBank
	ldrb r0, [r2, 0x1]
	strb r0, [r6]
	strb r0, [r1, 0x17]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r7, r0, 0
	adds r7, 0x92
	ldrb r3, [r7]
	ldr r1, =gBitTable
	ldrb r2, [r6]
	lsls r0, r2, 2
	adds r0, r1
	ldr r5, [r0]
	adds r0, r3, 0
	ands r0, r5
	cmp r0, 0
	beq _0804FA50
	b _0804FD70
_0804FA50:
	ldr r4, =gBattleMons
	movs r0, 0x58
	mov r12, r0
	mov r1, r12
	muls r1, r2
	adds r2, r1, 0
	adds r1, r2, r4
	ldrh r0, [r1, 0x2C]
	lsrs r0, 1
	ldrh r1, [r1, 0x28]
	cmp r0, r1
	bcs _0804FA6A
	b _0804FD70
_0804FA6A:
	cmp r1, 0
	bne _0804FA70
	b _0804FD70
_0804FA70:
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _0804FA82
	b _0804FD70
_0804FA82:
	orrs r3, r5
	strb r3, [r7]
	movs r0, 0x1
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r6]
	mov r1, r12
	muls r1, r0
	adds r0, r1, 0
	adds r1, r4, 0
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	bl GetNatureFromPersonality
	ldr r1, =gUnknown_0831C4F8
	lsls r0, 24
	lsrs r0, 24
	adds r0, r1
	ldrb r0, [r0]
	mov r2, r8
	strb r0, [r2, 0x5]
	b _0804FD70
	.pool
_0804FACC:
	ldr r4, =gBattleCommunication
	adds r0, r4, 0
	bl sub_81A5258
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _0804FADE
	b _0804FD78
_0804FADE:
	strb r3, [r4, 0x1]
	b _0804FD70
	.pool
_0804FAE8:
	ldr r0, =gBattleMons
	adds r0, 0x80
	movs r1, 0
	strh r1, [r0]
	ldr r2, =gHitMarker
	ldr r3, =gBitTable
	ldr r1, [r3, 0x4]
	lsls r1, 28
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, =gBattleStruct
	ldr r2, [r0]
	ldr r0, =0x000002a1
	adds r2, r0
	ldr r0, =gBattlePartyID
	ldrh r0, [r0, 0x2]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gDisableStructs
	adds r1, 0x34
	ldrb r0, [r1]
	movs r2, 0x2
	b _0804FBF4
	.pool
_0804FB3C:
	ldr r1, =gBattleMons
	movs r0, 0
	strh r0, [r1, 0x28]
	ldr r2, =gHitMarker
	ldr r3, =gBitTable
	ldr r1, [r3]
	lsls r1, 28
	ldr r0, [r2]
	orrs r0, r1
	movs r1, 0x80
	lsls r1, 15
	orrs r0, r1
	str r0, [r2]
	ldr r0, =gBattleStruct
	ldr r2, [r0]
	movs r1, 0xA8
	lsls r1, 2
	adds r2, r1
	ldr r0, =gBattlePartyID
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, =gDisableStructs
	ldrb r0, [r2, 0x18]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x18]
	b _0804FD70
	.pool
_0804FB94:
	ldr r0, =gBattleMons
	movs r1, 0
	strh r1, [r0, 0x28]
	adds r0, 0x80
	strh r1, [r0]
	ldr r2, =gHitMarker
	ldr r3, =gBitTable
	ldr r0, [r3]
	lsls r0, 28
	ldr r1, [r2]
	orrs r1, r0
	ldr r0, [r3, 0x4]
	lsls r0, 28
	orrs r1, r0
	movs r0, 0x80
	lsls r0, 15
	orrs r1, r0
	str r1, [r2]
	ldr r5, =gBattleStruct
	ldr r2, [r5]
	movs r0, 0xA8
	lsls r0, 2
	adds r2, r0
	ldr r4, =gBattlePartyID
	ldrh r0, [r4]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r5]
	ldr r1, =0x000002a1
	adds r2, r1
	ldrh r0, [r4, 0x2]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gDisableStructs
	ldrb r0, [r1, 0x18]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1, 0x18]
	adds r1, 0x34
	ldrb r0, [r1]
_0804FBF4:
	orrs r0, r2
	strb r0, [r1]
	b _0804FD70
	.pool
_0804FC18:
	movs r0, 0
	bl sub_8033E10
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804FD70
	.pool
_0804FC2C:
	bl sub_81A5BF8
	b _0804FD70
_0804FC32:
	bl sub_81A5D44
	b _0804FD70
_0804FC38:
	ldr r1, =gUnknown_085CD1C8
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl StrCpyDecodeToDisplayedStringBattle
	ldr r0, =gDisplayedStringBattle
	movs r1, 0x16
	bl battle_show_message_maybe
	b _0804FD70
	.pool
_0804FC60:
	movs r0, 0x16
	bl IsTextPrinterActive
	lsls r0, 16
	b _0804FD24
_0804FC6A:
	bl IsCryFinished
	lsls r0, 24
	cmp r0, 0
	bne _0804FC76
	b _0804FD78
_0804FC76:
	b _0804FD70
_0804FC78:
	ldr r4, =gActiveBank
	movs r0, 0x1
	strb r0, [r4]
	ldr r0, =gBattleMons
	adds r0, 0x58
	b _0804FCA2
	.pool
_0804FC8C:
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r0, 0x3
	bls _0804FD70
	ldr r4, =gActiveBank
	movs r0, 0x3
	strb r0, [r4]
	ldr r0, =gBattleMons
	movs r2, 0x84
	lsls r2, 1
	adds r0, r2
_0804FCA2:
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _0804FD70
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x06_a
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804FD70
	.pool
_0804FCC4:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x55
	bl m4aMPlayVolumeControl
	b _0804FD70
	.pool
_0804FCD8:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	b _0804FD70
	.pool
_0804FCF0:
	ldr r0, =gBattleStruct
	ldr r2, [r0]
	ldr r0, =0x000002a2
	adds r2, r0
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804FD70
	.pool
_0804FD1C:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl sub_805725C
_0804FD24:
	cmp r0, 0
	bne _0804FD78
	b _0804FD70
	.pool
_0804FD30:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0804FD50
	ldr r1, =gBattleOutcome
	movs r0, 0x5
	strb r0, [r1]
	b _0804FD70
	.pool
_0804FD50:
	ldr r1, =gBattleOutcome
	movs r0, 0xA
	strb r0, [r1]
	b _0804FD70
	.pool
_0804FD5C:
	movs r1, 0xCE
	lsls r1, 1
	movs r0, 0
	movs r2, 0x1
	bl sub_8034300
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
_0804FD70:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x3
	str r0, [r1]
_0804FD78:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk76_various

	thumb_func_start atk77_setprotect
atk77_setprotect: @ 804FD8C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0x1
	ldr r2, =gUnknown_02024260
	ldr r1, =gBankAttacker
	ldrb r3, [r1]
	lsls r0, r3, 1
	adds r0, r2
	ldrh r0, [r0]
	mov r8, r1
	ldr r7, =gDisableStructs
	cmp r0, 0xB6
	beq _0804FDBC
	cmp r0, 0xC5
	beq _0804FDBC
	cmp r0, 0xCB
	beq _0804FDBC
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r7
	movs r1, 0
	strb r1, [r0, 0x8]
_0804FDBC:
	ldr r0, =gUnknown_02024082
	ldrb r1, [r0]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	bne _0804FDCC
	movs r6, 0
_0804FDCC:
	ldr r2, =sProtectSuccessRates
	mov r5, r8
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r4, [r0, 0x8]
	lsls r4, 1
	adds r4, r2
	bl Random
	ldrh r1, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r1, r0
	bcc _0804FE80
	cmp r6, 0
	beq _0804FE80
	ldr r4, =gBattleMoves
	ldr r3, =gCurrentMove
	ldrh r0, [r3]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1]
	cmp r0, 0x6F
	bne _0804FE1C
	ldr r0, =gProtectStructs
	ldrb r1, [r5]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
_0804FE1C:
	ldrh r0, [r3]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1]
	cmp r0, 0x74
	bne _0804FE42
	ldr r0, =gProtectStructs
	ldrb r1, [r5]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r1]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
_0804FE42:
	mov r1, r8
	ldrb r0, [r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r0, [r1, 0x8]
	adds r0, 0x1
	strb r0, [r1, 0x8]
	b _0804FEA2
	.pool
_0804FE80:
	ldr r2, =gDisableStructs
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x8]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_0804FEA2:
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
	thumb_func_end atk77_setprotect

	thumb_func_start atk78_faintifabilitynotdamp
atk78_faintifabilitynotdamp: @ 804FEC8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gBattleExecBuffer
	ldr r2, [r0]
	cmp r2, 0
	bne _0804FFCC
	ldr r1, =gBankTarget
	strb r2, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r3, [r0]
	adds r5, r1, 0
	mov r8, r0
	ldr r6, =gBattleMons
	cmp r2, r3
	bcs _0804FF14
	adds r0, r6, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _0804FF14
	adds r2, r3, 0
	adds r4, r6, 0
	movs r3, 0x58
_0804FEF8:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r2
	bcs _0804FF14
	ldrb r0, [r5]
	muls r0, r3
	adds r0, r4
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _0804FEF8
_0804FF14:
	ldrb r0, [r5]
	mov r1, r8
	ldrb r1, [r1]
	cmp r0, r1
	bne _0804FFB0
	ldr r4, =gActiveBank
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	strb r0, [r4]
	ldr r2, =gBattleMoveDamage
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r0, r6
	ldrh r0, [r0, 0x28]
	str r0, [r2]
	ldr r1, =0x00007fff
	movs r0, 0
	bl dp01_build_cmdbuf_x18_0_aa_health_bar_update
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	movs r0, 0
	strb r0, [r5]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, 0
	beq _0804FFCC
	adds r3, r5, 0
	ldrb r5, [r7]
	ldr r7, =gBitTable
	adds r4, r0, 0
	ldr r6, =gAbsentBankFlags
_0804FF60:
	ldrb r2, [r3]
	cmp r2, r5
	beq _0804FF76
	ldrb r0, [r6]
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r7
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	beq _0804FFCC
_0804FF76:
	adds r0, r2, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	bcc _0804FF60
	b _0804FFCC
	.pool
_0804FFB0:
	ldr r1, =gLastUsedAbility
	movs r0, 0x6
	strb r0, [r1]
	ldrb r0, [r5]
	movs r1, 0x58
	muls r1, r0
	adds r1, r6
	adds r1, 0x20
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB560
	str r0, [r1]
_0804FFCC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk78_faintifabilitynotdamp

	thumb_func_start atk79_setatkhptozero
atk79_setatkhptozero: @ 804FFE4
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gBattleExecBuffer
	ldr r3, [r0]
	cmp r3, 0
	bne _08050028
	ldr r4, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, =gBattleMons
	ldrb r0, [r4]
	movs r2, 0x58
	muls r0, r2
	adds r0, r1
	strh r3, [r0, 0x28]
	ldrb r0, [r4]
	muls r0, r2
	adds r1, 0x28
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2A
	movs r2, 0
	movs r3, 0x2
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08050028:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk79_setatkhptozero

	thumb_func_start atk7A_jumpwhiletargetvalid
atk7A_jumpwhiletargetvalid: @ 8050044
	push {r4-r7,lr}
	ldr r3, =gBattlescriptCurrInstr
	ldr r2, [r3]
	ldrb r4, [r2, 0x1]
	ldrb r0, [r2, 0x2]
	lsls r0, 8
	orrs r4, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	orrs r4, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 24
	orrs r4, r0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	adds r7, r3, 0
	cmp r0, 0
	beq _080500DC
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r2, =gBankAttacker
	lsls r1, 24
	lsrs r1, 24
	adds r3, r0, 0
	ldr r6, =gAbsentBankFlags
	ldr r5, =gBitTable
	ldr r0, =gNoOfAllBanks
	mov r12, r0
	ldrb r0, [r2]
	cmp r1, r0
	bne _0805009A
_0805008A:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r2]
	cmp r0, r1
	beq _0805008A
_0805009A:
	ldrb r0, [r6]
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _0805008A
	ldrb r0, [r3]
	mov r2, r12
	ldrb r2, [r2]
	cmp r0, r2
	bcc _080500D8
	ldr r0, [r7]
	adds r0, 0x5
	str r0, [r7]
	b _080500E0
	.pool
_080500D8:
	str r4, [r7]
	b _080500E0
_080500DC:
	adds r0, r2, 0x5
	str r0, [r3]
_080500E0:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk7A_jumpwhiletargetvalid

	thumb_func_start atk7B_healhalfHP_if_possible
atk7B_healhalfHP_if_possible: @ 80500E8
	push {r4-r6,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r1, [r4]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r2, r0
	ldrb r0, [r1, 0x5]
	ldr r3, =gBankTarget
	cmp r0, 0x1
	bne _08050110
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r3]
_08050110:
	ldr r1, =gBattleMoveDamage
	ldr r6, =gBattleMons
	ldrb r0, [r3]
	movs r5, 0x58
	muls r0, r5
	adds r0, r6
	ldrh r0, [r0, 0x2C]
	lsrs r0, 1
	str r0, [r1]
	cmp r0, 0
	bne _0805012A
	movs r0, 0x1
	str r0, [r1]
_0805012A:
	ldr r0, [r1]
	negs r0, r0
	str r0, [r1]
	ldrb r0, [r3]
	muls r0, r5
	adds r0, r6
	ldrh r1, [r0, 0x28]
	ldrh r0, [r0, 0x2C]
	cmp r1, r0
	bne _08050158
	str r2, [r4]
	b _0805015E
	.pool
_08050158:
	ldr r0, [r4]
	adds r0, 0x6
	str r0, [r4]
_0805015E:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk7B_healhalfHP_if_possible

	thumb_func_start atk7C_8025508
atk7C_8025508: @ 8050164
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r2, =gNoOfAllBanks
	ldr r0, =gBankAttacker
	mov r10, r0
	movs r1, 0
	add r0, sp, 0x4
_0805017A:
	strh r1, [r0]
	subs r0, 0x2
	cmp r0, sp
	bge _0805017A
	movs r1, 0
	mov r8, r1
	movs r5, 0
	ldrb r1, [r2]
	cmp r5, r1
	bge _080501D0
	ldr r0, =gBankAttacker
	ldrb r6, [r0]
	ldr r2, =0x0000ffff
	mov r9, r2
	lsls r4, r6, 3
	mov r2, sp
	ldr r0, =gBattleStruct
	mov r12, r0
	adds r7, r1, 0
_080501A0:
	cmp r5, r6
	beq _080501C8
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4, r0
	adds r1, r0, 0
	adds r1, 0xE0
	ldrb r3, [r1]
	adds r0, 0xE1
	ldrb r0, [r0]
	lsls r0, 8
	orrs r3, r0
	cmp r3, 0
	beq _080501C8
	cmp r3, r9
	beq _080501C8
	strh r3, [r2]
	adds r2, 0x2
	movs r0, 0x1
	add r8, r0
_080501C8:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, r7
	blt _080501A0
_080501D0:
	mov r1, r10
	ldrb r0, [r1]
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	lsls r0, 1
	adds r0, r1
	adds r1, r0, 0
	adds r1, 0x98
	ldrb r3, [r1]
	adds r0, 0x99
	ldrb r0, [r0]
	lsls r0, 8
	orrs r3, r0
	cmp r3, 0
	beq _08050220
	ldr r0, =0x0000ffff
	cmp r3, r0
	beq _08050220
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
	ldr r4, =gCurrentMove
	strh r3, [r4]
	b _0805024A
	.pool
_08050220:
	mov r0, r8
	cmp r0, 0
	beq _08050290
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r1, r8
	bl __modsi3
	adds r5, r0, 0
	ldr r4, =gCurrentMove
	lsls r0, r5, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
_0805024A:
	ldrh r0, [r4]
	movs r1, 0
	bl GetMoveTarget
	ldr r1, =gBankTarget
	strb r0, [r1]
	ldr r5, =gBattlescriptCurrInstr
	ldr r3, =gUnknown_082D86A8
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
	str r0, [r5]
	b _080502AE
	.pool
_08050290:
	ldr r2, =gSpecialStatuses
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_080502AE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk7C_8025508

	thumb_func_start atk7D_set_rain
atk7D_set_rain: @ 80502C8
	push {lr}
	ldr r2, =gBattleWeather
	ldrh r0, [r2]
	movs r1, 0x7
	ands r1, r0
	cmp r1, 0
	beq _080502F4
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	b _08050304
	.pool
_080502F4:
	movs r0, 0x1
	strh r0, [r2]
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x5]
	ldr r0, =gUnknown_020243D0
	adds r0, 0x28
	movs r1, 0x5
	strb r1, [r0]
_08050304:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk7D_set_rain

	thumb_func_start atk7E_setreflect
atk7E_setreflect: @ 805031C
	push {r4-r6,lr}
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	bl GetBankIdentity
	ldr r4, =gSideAffecting
	movs r5, 0x1
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r1, [r1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _0805035C
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0
	b _080503D0
	.pool
_0805035C:
	ldrb r0, [r6]
	bl GetBankIdentity
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r6]
	bl GetBankIdentity
	ldr r4, =gSideTimers
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x5
	strb r1, [r0]
	ldrb r0, [r6]
	bl GetBankIdentity
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r6]
	strb r1, [r0, 0x1]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ands r0, r5
	cmp r0, 0
	beq _080503CC
	movs r0, 0x1
	bl CountAliveMonsInBattle
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x2
	bne _080503CC
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x5]
	b _080503D2
	.pool
_080503CC:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
_080503D0:
	strb r0, [r1, 0x5]
_080503D2:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk7E_setreflect

	thumb_func_start atk7F_setseeded
atk7F_setseeded: @ 80503E8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r7, =gBattleMoveFlags
	ldrb r5, [r7]
	movs r0, 0x29
	ands r0, r5
	cmp r0, 0
	bne _0805041A
	ldr r0, =gStatuses3
	mov r9, r0
	ldr r1, =gBankTarget
	mov r8, r1
	ldrb r4, [r1]
	lsls r0, r4, 2
	mov r2, r9
	adds r6, r0, r2
	ldr r2, [r6]
	movs r0, 0x4
	mov r12, r0
	adds r3, r2, 0
	ands r3, r0
	cmp r3, 0
	beq _08050438
_0805041A:
	movs r0, 0x1
	orrs r0, r5
	strb r0, [r7]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _08050488
	.pool
_08050438:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r4
	adds r1, r0, r1
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0xC
	beq _08050454
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _0805046C
_08050454:
	movs r0, 0x1
	orrs r0, r5
	strb r0, [r7]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	b _08050488
	.pool
_0805046C:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	orrs r2, r0
	str r2, [r6]
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, 2
	add r1, r9
	ldr r0, [r1]
	mov r2, r12
	orrs r0, r2
	str r0, [r1]
	ldr r0, =gBattleCommunication
	strb r3, [r0, 0x5]
_08050488:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk7F_setseeded

	thumb_func_start atk80_manipulatedamage
atk80_manipulatedamage: @ 80504A8
	push {r4,lr}
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	ldrb r2, [r0, 0x1]
	adds r4, r1, 0
	cmp r2, 0x1
	beq _080504D8
	cmp r2, 0x1
	bgt _080504C4
	cmp r2, 0
	beq _080504CA
	b _08050518
	.pool
_080504C4:
	cmp r2, 0x2
	beq _08050510
	b _08050518
_080504CA:
	ldr r1, =gBattleMoveDamage
	ldr r0, [r1]
	negs r0, r0
	b _08050516
	.pool
_080504D8:
	ldr r3, =gBattleMoveDamage
	ldr r0, [r3]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	str r0, [r3]
	cmp r0, 0
	bne _080504EA
	str r2, [r3]
_080504EA:
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x2C]
	lsrs r1, r0, 1
	ldr r0, [r3]
	cmp r1, r0
	bge _08050518
	str r1, [r3]
	b _08050518
	.pool
_08050510:
	ldr r1, =gBattleMoveDamage
	ldr r0, [r1]
	lsls r0, 1
_08050516:
	str r0, [r1]
_08050518:
	ldr r0, [r4]
	adds r0, 0x2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk80_manipulatedamage

	thumb_func_start atk81_setrest
atk81_setrest: @ 8050528
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r0, =gBattlescriptCurrInstr
	mov r12, r0
	ldr r1, [r0]
	ldrb r6, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r6, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r6, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r6, r0
	ldr r5, =gActiveBank
	ldr r2, =gBankTarget
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r2]
	strb r0, [r5]
	ldr r4, =gBattleMoveDamage
	ldr r1, =gBattleMons
	ldrb r0, [r2]
	movs r3, 0x58
	muls r0, r3
	adds r0, r1
	ldrh r0, [r0, 0x2C]
	negs r0, r0
	str r0, [r4]
	ldrb r0, [r2]
	adds r4, r0, 0
	muls r4, r3
	adds r0, r4, r1
	ldrh r3, [r0, 0x28]
	adds r7, r5, 0
	adds r5, r2, 0
	adds r2, r1, 0
	ldrh r0, [r0, 0x2C]
	cmp r3, r0
	bne _08050598
	mov r0, r12
	str r6, [r0]
	b _080505E8
	.pool
_08050598:
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, 0xF8
	ands r1, r0
	cmp r1, 0
	beq _080505B4
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _080505B8
	.pool
_080505B4:
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x5]
_080505B8:
	ldrb r0, [r5]
	movs r3, 0x58
	muls r0, r3
	adds r2, 0x4C
	adds r0, r2
	movs r1, 0x3
	str r1, [r0]
	ldrb r0, [r7]
	muls r0, r3
	adds r0, r2
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r7]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080505E8:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk81_setrest

	thumb_func_start atk82_jumpifnotfirstturn
atk82_jumpifnotfirstturn: @ 80505F8
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r4, [r5]
	ldrb r3, [r4, 0x1]
	ldrb r0, [r4, 0x2]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r4, 0x4]
	lsls r0, 24
	orrs r3, r0
	ldr r2, =gDisableStructs
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	beq _08050638
	adds r0, r4, 0x5
	str r0, [r5]
	b _0805063A
	.pool
_08050638:
	str r3, [r5]
_0805063A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end atk82_jumpifnotfirstturn

	thumb_func_start atk83_nop
atk83_nop: @ 8050640
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atk83_nop

	thumb_func_start sub_8050650
sub_8050650: @ 8050650
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	mov r8, r0
	cmp r2, r1
	bge _080506C4
	ldr r0, =gBattleMons
	mov r12, r0
	movs r0, 0x58
	muls r0, r3
	add r0, r12
	adds r5, r0, 0
	adds r5, 0x20
	adds r4, r1, 0
	movs r3, 0
	ldr r6, =gBattleScripting
	ldr r7, =gBattleCommunication
_0805067C:
	mov r0, r12
	adds r0, 0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x70
	ands r0, r1
	cmp r0, 0
	beq _080506BC
	ldrb r0, [r5]
	cmp r0, 0x2B
	beq _080506BC
	movs r3, 0
	strb r2, [r6, 0x17]
	ldr r1, =gBankTarget
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _080506DC
	cmp r0, r2
	beq _080506D0
	movs r0, 0x1
	strb r0, [r7, 0x5]
	b _080506C4
	.pool
_080506BC:
	adds r3, 0x58
	adds r2, 0x1
	cmp r2, r4
	blt _0805067C
_080506C4:
	mov r1, r8
	ldrb r1, [r1]
	cmp r2, r1
	beq _080506E0
	movs r0, 0x1
	b _080506E2
_080506D0:
	ldr r0, =gBattleCommunication
	strb r3, [r0, 0x5]
	b _080506C4
	.pool
_080506DC:
	strb r2, [r1]
	b _080506C4
_080506E0:
	movs r0, 0
_080506E2:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8050650

	thumb_func_start atk84_jump_if_cant_sleep
atk84_jump_if_cant_sleep: @ 80506EC
	push {r4-r6,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r1, [r5]
	ldrb r4, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r4, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r4, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r4, r0
	ldr r6, =gBankTarget
	ldrb r0, [r6]
	bl sub_8050650
	lsls r0, 24
	cmp r0, 0
	beq _08050720
	str r4, [r5]
	b _08050762
	.pool
_08050720:
	ldr r1, =gBattleMons
	ldrb r3, [r6]
	movs r0, 0x58
	muls r0, r3
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	adds r1, r0, 0
	cmp r1, 0xF
	beq _08050738
	cmp r1, 0x48
	bne _0805075C
_08050738:
	ldr r2, =gLastUsedAbility
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	str r4, [r5]
	ldrb r1, [r2]
	adds r0, r3, 0
	bl RecordAbilityBattle
	b _08050762
	.pool
_0805075C:
	ldr r0, [r5]
	adds r0, 0x5
	str r0, [r5]
_08050762:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk84_jump_if_cant_sleep

	thumb_func_start atk85_stockpile
atk85_stockpile: @ 8050768
	push {r4,r5,lr}
	ldr r5, =gDisableStructs
	ldr r4, =gBankAttacker
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r5
	ldrb r0, [r1, 0x9]
	cmp r0, 0x3
	bne _080507A0
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _080507CA
	.pool
_080507A0:
	adds r0, 0x1
	movs r3, 0
	strb r0, [r1, 0x9]
	ldr r2, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r2]
	movs r0, 0x1
	strb r0, [r2, 0x1]
	strb r0, [r2, 0x2]
	strb r0, [r2, 0x3]
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r0, [r0, 0x9]
	strb r0, [r2, 0x4]
	movs r0, 0xFF
	strb r0, [r2, 0x5]
	ldr r0, =gBattleCommunication
	strb r3, [r0, 0x5]
_080507CA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk85_stockpile

	thumb_func_start atk86_stockpiletobasedamage
atk86_stockpiletobasedamage: @ 80507E4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r3, =gBattlescriptCurrInstr
	ldr r1, [r3]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r2, r0
	ldr r7, =gDisableStructs
	ldr r6, =gBankAttacker
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	bne _08050828
	str r2, [r3]
	b _080508CA
	.pool
_08050828:
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x6]
	cmp r0, 0x1
	beq _080508B0
	ldr r0, =gBattleMoveDamage
	mov r8, r0
	ldr r4, =gSideAffecting
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	bl GetBankIdentity
	movs r1, 0x1
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r3, [r1]
	ldrb r0, [r6]
	movs r4, 0x58
	muls r0, r4
	ldr r2, =gBattleMons
	adds r0, r2
	ldrb r1, [r5]
	muls r1, r4
	adds r1, r2
	ldr r2, =gCurrentMove
	ldrh r2, [r2]
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	ldrb r4, [r6]
	str r4, [sp, 0x8]
	ldrb r4, [r5]
	str r4, [sp, 0xC]
	bl CalculateBaseDamage
	ldrb r2, [r6]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r7
	ldrb r1, [r1, 0x9]
	adds r3, r0, 0
	muls r3, r1
	mov r1, r8
	str r3, [r1]
	ldr r2, =gBattleScripting
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r0, [r0, 0x9]
	strb r0, [r2, 0x18]
	ldr r1, =gProtectStructs
	ldrb r0, [r6]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 28
	cmp r0, 0
	bge _080508B0
	lsls r0, r3, 4
	subs r0, r3
	movs r1, 0xA
	bl __divsi3
	mov r1, r8
	str r0, [r1]
_080508B0:
	ldr r2, =gDisableStructs
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080508CA:
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk86_stockpiletobasedamage

	thumb_func_start atk87_stockpiletohpheal
atk87_stockpiletohpheal: @ 8050904
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r7, =gBattlescriptCurrInstr
	ldr r1, [r7]
	ldrb r2, [r1, 0x1]
	ldrb r0, [r1, 0x2]
	lsls r0, 8
	orrs r2, r0
	ldrb r0, [r1, 0x3]
	lsls r0, 16
	orrs r2, r0
	ldrb r0, [r1, 0x4]
	lsls r0, 24
	orrs r2, r0
	ldr r0, =gDisableStructs
	mov r8, r0
	ldr r6, =gBankAttacker
	ldrb r3, [r6]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	mov r1, r8
	adds r4, r0, r1
	ldrb r1, [r4, 0x9]
	cmp r1, 0
	bne _08050954
	str r2, [r7]
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x5]
	b _080509D0
	.pool
_08050954:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r3
	adds r1, r0, r1
	ldrh r0, [r1, 0x2C]
	ldrh r3, [r1, 0x28]
	cmp r0, r3
	bne _08050984
	movs r0, 0
	strb r0, [r4, 0x9]
	str r2, [r7]
	ldr r1, =gBankTarget
	ldrb r0, [r6]
	strb r0, [r1]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _080509D0
	.pool
_08050984:
	ldr r5, =gBattleMoveDamage
	ldrh r0, [r1, 0x2C]
	ldrb r1, [r4, 0x9]
	movs r2, 0x3
	subs r2, r1
	movs r4, 0x1
	adds r1, r4, 0
	lsls r1, r2
	bl __divsi3
	str r0, [r5]
	cmp r0, 0
	bne _080509A0
	str r4, [r5]
_080509A0:
	ldr r0, [r5]
	negs r0, r0
	str r0, [r5]
	ldr r3, =gBattleScripting
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r0, [r0, 0x9]
	movs r2, 0
	strb r0, [r3, 0x18]
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r8
	strb r2, [r0, 0x9]
	ldr r0, [r7]
	adds r0, 0x5
	str r0, [r7]
	ldr r1, =gBankTarget
	ldrb r0, [r6]
	strb r0, [r1]
_080509D0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk87_stockpiletohpheal

	thumb_func_start atk88_negativedamage
atk88_negativedamage: @ 80509E8
	push {lr}
	ldr r2, =gBattleMoveDamage
	ldr r0, =gUnknown_020241F4
	ldr r0, [r0]
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	negs r0, r0
	str r0, [r2]
	cmp r0, 0
	bne _08050A04
	movs r0, 0x1
	negs r0, r0
	str r0, [r2]
_08050A04:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk88_negativedamage

	thumb_func_start sub_8050A1C
sub_8050A1C: @ 8050A1C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r8, r3
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0
	mov r9, r0
	mov r10, r0
	movs r0, 0x40
	ands r0, r5
	cmp r0, 0
	beq _08050A50
	ldr r0, =gActiveBank
	ldr r1, =gBankAttacker
	b _08050A54
	.pool
_08050A50:
	ldr r0, =gActiveBank
	ldr r1, =gBankTarget
_08050A54:
	ldrb r1, [r1]
	strb r1, [r0]
	movs r0, 0xBF
	ands r5, r0
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	beq _08050A6E
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_08050A6E:
	movs r0, 0x7F
	ands r5, r0
	movs r0, 0x20
	ands r0, r5
	cmp r0, 0
	beq _08050A84
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
_08050A84:
	movs r0, 0xDF
	ands r5, r0
	ldr r1, =gBattleTextBuff1
	movs r4, 0
	movs r2, 0xFD
	strb r2, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	strb r7, [r1, 0x2]
	movs r3, 0x1
	negs r3, r3
	mov r12, r3
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	lsls r0, r6, 24
	cmp r0, 0
	blt _08050AA8
	b _08050D8C
_08050AA8:
	ldr r4, =gSideTimers
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	bl GetBankIdentity
	movs r1, 0x1
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08050B48
	mov r2, r9
	cmp r2, 0
	bne _08050B48
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xAE
	beq _08050B78
	cmp r5, 0x1
	bne _08050B68
	ldr r4, =gSpecialStatuses
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq _08050B10
	ldr r0, =gBattlescriptCurrInstr
	mov r4, r8
	str r4, [r0]
	b _08050B68
	.pool
_08050B10:
	mov r0, r8
	bl b_movescr_stack_push
	ldr r1, =gBattleScripting
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAE03
	str r0, [r1]
	ldrb r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _08050B68
	.pool
_08050B48:
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xAE
	beq _08050B78
	mov r0, r10
	cmp r0, 0x1
	beq _08050B78
	movs r0, 0
	bl sub_80464AC
	lsls r0, 24
	cmp r0, 0
	beq _08050B78
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D9F1C
	str r0, [r1]
_08050B68:
	movs r0, 0x1
	b _08050E80
	.pool
_08050B78:
	ldr r2, =gBattleMons
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	movs r4, 0x58
	adds r0, r3, 0
	muls r0, r4
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	mov r10, r2
	cmp r0, 0x1D
	beq _08050B94
	cmp r0, 0x49
	bne _08050C2C
_08050B94:
	mov r0, r9
	cmp r0, 0
	bne _08050C2C
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xAE
	beq _08050C2C
	cmp r5, 0x1
	bne _08050B68
	ldr r4, =gSpecialStatuses
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _08050BD4
	ldr r0, =gBattlescriptCurrInstr
	mov r1, r8
	str r1, [r0]
	b _08050B68
	.pool
_08050BD4:
	mov r0, r8
	bl b_movescr_stack_push
	ldr r1, =gBattleScripting
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB5C7
	str r0, [r1]
	ldr r1, =gLastUsedAbility
	ldrb r0, [r2]
	movs r3, 0x58
	muls r0, r3
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _08050B68
	.pool
_08050C2C:
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	movs r4, 0x58
	muls r0, r4
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x33
	bne _08050C8C
	mov r2, r9
	cmp r2, 0
	bne _08050C8C
	cmp r7, 0x6
	bne _08050C8C
	cmp r5, 0x1
	bne _08050B68
	mov r0, r8
	bl b_movescr_stack_push
	ldr r1, =gBattleScripting
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB62F
	str r0, [r1]
	ldr r1, =gLastUsedAbility
	ldrb r0, [r3]
	muls r0, r4
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r3]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	b _08050B68
	.pool
_08050C8C:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r4, 0x58
	muls r0, r4
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x34
	bne _08050CF0
	mov r0, r9
	cmp r0, 0
	bne _08050CF0
	cmp r7, 0x1
	bne _08050CF0
	cmp r5, 0x1
	beq _08050CAE
	b _08050B68
_08050CAE:
	mov r0, r8
	bl b_movescr_stack_push
	ldr r1, =gBattleScripting
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB62F
	str r0, [r1]
	ldr r1, =gLastUsedAbility
	ldrb r0, [r2]
	muls r0, r4
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	b _08050B68
	.pool
_08050CF0:
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x13
	bne _08050D08
	cmp r5, 0
	bne _08050D08
	b _08050B68
_08050D08:
	lsls r0, r6, 24
	asrs r0, 28
	movs r1, 0x7
	ands r0, r1
	negs r0, r0
	lsls r0, 24
	ldr r3, =gBattleTextBuff2
	movs r4, 0
	movs r1, 0xFD
	strb r1, [r3]
	movs r2, 0x1
	lsrs r6, r0, 24
	asrs r0, 24
	subs r1, 0xFF
	cmp r0, r1
	bne _08050D32
	strb r4, [r3, 0x1]
	movs r0, 0xD3
	strb r0, [r3, 0x2]
	strb r4, [r3, 0x3]
	movs r2, 0x4
_08050D32:
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, 0x1
	adds r1, r2, r3
	movs r0, 0xD4
	strb r0, [r1]
	adds r2, 0x1
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, 0x1
	adds r1, r2, r3
	movs r0, 0xFF
	strb r0, [r1]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r0, r7, r0
	mov r1, r10
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	beq _08050DE2
	movs r1, 0
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	ldr r3, =gBattleCommunication
	mov r8, r3
	cmp r0, r2
	bne _08050D76
	movs r1, 0x1
_08050D76:
	mov r4, r8
	strb r1, [r4, 0x5]
	b _08050E10
	.pool
_08050D8C:
	asrs r6, r0, 28
	movs r0, 0x7
	ands r6, r0
	ldr r3, =gBattleTextBuff2
	strb r2, [r3]
	movs r2, 0x1
	cmp r6, 0x2
	bne _08050DA6
	strb r4, [r3, 0x1]
	movs r0, 0xD1
	strb r0, [r3, 0x2]
	strb r4, [r3, 0x3]
	movs r2, 0x4
_08050DA6:
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, 0x1
	adds r1, r2, r3
	movs r0, 0xD2
	strb r0, [r1]
	adds r2, 0x1
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, 0x1
	adds r1, r2, r3
	ldrb r0, [r1]
	mov r2, r12
	orrs r0, r2
	strb r0, [r1]
	ldr r2, =gBattleMons
	ldr r4, =gActiveBank
	ldrb r3, [r4]
	movs r0, 0x58
	muls r0, r3
	adds r0, r7, r0
	adds r1, r2, 0
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	mov r10, r2
	cmp r0, 0xC
	bne _08050DFC
_08050DE2:
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	mov r8, r1
	b _08050E10
	.pool
_08050DFC:
	movs r1, 0
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	ldr r2, =gBattleCommunication
	mov r8, r2
	cmp r0, r3
	bne _08050E0C
	movs r1, 0x1
_08050E0C:
	mov r3, r8
	strb r1, [r3, 0x5]
_08050E10:
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	movs r4, 0x58
	adds r1, r0, 0
	muls r1, r4
	adds r1, r7, r1
	mov r3, r10
	adds r3, 0x18
	adds r1, r3
	lsls r0, r6, 24
	asrs r0, 24
	ldrb r6, [r1]
	adds r0, r6
	strb r0, [r1]
	ldrb r0, [r2]
	muls r0, r4
	adds r0, r7, r0
	adds r1, r0, r3
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0
	bge _08050E40
	movs r0, 0
	strb r0, [r1]
_08050E40:
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	muls r0, r4
	adds r0, r7, r0
	adds r1, r0, r3
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0xC
	ble _08050E56
	movs r0, 0xC
	strb r0, [r1]
_08050E56:
	mov r2, r8
	ldrb r0, [r2, 0x5]
	cmp r0, 0x2
	bne _08050E7E
	movs r3, 0x1
	ands r3, r5
	cmp r3, 0
	beq _08050E70
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
_08050E70:
	mov r4, r8
	ldrb r0, [r4, 0x5]
	cmp r0, 0x2
	bne _08050E7E
	cmp r3, 0
	bne _08050E7E
	b _08050B68
_08050E7E:
	movs r0, 0
_08050E80:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8050A1C

	thumb_func_start atk89_statbuffchange
atk89_statbuffchange: @ 8050EA0
	push {r4,r5,lr}
	ldr r5, =gBattlescriptCurrInstr
	ldr r2, [r5]
	ldrb r3, [r2, 0x2]
	ldrb r0, [r2, 0x3]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r2, 0x4]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r2, 0x5]
	lsls r0, 24
	orrs r3, r0
	ldr r0, =gBattleScripting
	ldrb r4, [r0, 0x1A]
	movs r0, 0xF0
	ands r0, r4
	lsls r0, 24
	asrs r0, 24
	movs r1, 0xF
	ands r1, r4
	ldrb r2, [r2, 0x1]
	bl sub_8050A1C
	lsls r0, 24
	cmp r0, 0
	bne _08050EDC
	ldr r0, [r5]
	adds r0, 0x6
	str r0, [r5]
_08050EDC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk89_statbuffchange

	thumb_func_start atk8A_normalisebuffs
atk8A_normalisebuffs: @ 8050EEC
	push {r4-r7,lr}
	movs r2, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	ldr r0, =gBattlescriptCurrInstr
	mov r12, r0
	cmp r2, r1
	bge _08050F24
	ldr r0, =gBattleMons
	movs r4, 0x6
	adds r5, r1, 0
	movs r7, 0x58
	adds r6, r0, 0
	adds r6, 0x18
_08050F08:
	adds r3, r2, 0x1
	movs r1, 0x7
	adds r0, r2, 0
	muls r0, r7
	adds r0, r6
	adds r0, 0x7
_08050F14:
	strb r4, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _08050F14
	adds r2, r3, 0
	cmp r2, r5
	blt _08050F08
_08050F24:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk8A_normalisebuffs

	thumb_func_start atk8B_setbide
atk8B_setbide: @ 8050F40
	push {r4,r5,lr}
	ldr r4, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	movs r5, 0x58
	adds r2, r0, 0
	muls r2, r5
	adds r4, 0x50
	adds r2, r4
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 5
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gUnknown_02024268
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r1
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	movs r2, 0
	strh r1, [r0]
	ldr r1, =gUnknown_020241F8
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r1
	str r2, [r0]
	ldrb r0, [r3]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r4
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 2
	orrs r0, r2
	str r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk8B_setbide

	thumb_func_start atk8C_confuseifrepeatingattackends
atk8C_confuseifrepeatingattackends: @ 8050FB0
	push {lr}
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 4
	ands r0, r1
	cmp r0, 0
	bne _08050FD2
	ldr r1, =gBattleCommunication
	movs r0, 0x75
	strb r0, [r1, 0x3]
_08050FD2:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk8C_confuseifrepeatingattackends

	thumb_func_start atk8D_setmultihit_counter
atk8D_setmultihit_counter: @ 8050FF0
	push {r4,r5,lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	cmp r1, 0
	beq _0805100C
	ldr r0, =gUnknown_02024212
	strb r1, [r0]
	b _08051026
	.pool
_0805100C:
	ldr r4, =gUnknown_02024212
	bl Random
	movs r5, 0x3
	ands r0, r5
	strb r0, [r4]
	cmp r0, 0x1
	bls _08051022
	bl Random
	ands r0, r5
_08051022:
	adds r0, 0x2
	strb r0, [r4]
_08051026:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk8D_setmultihit_counter

	thumb_func_start atk8E_prepare_multihit
atk8E_prepare_multihit: @ 805103C
	ldr r1, =gBattleScripting
	movs r2, 0
	movs r0, 0xFD
	strb r0, [r1, 0x8]
	movs r0, 0x1
	strb r0, [r1, 0x9]
	strb r0, [r1, 0xA]
	strb r0, [r1, 0xB]
	strb r2, [r1, 0xC]
	movs r0, 0xFF
	strb r0, [r1, 0xD]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atk8E_prepare_multihit

	thumb_func_start sub_8051064
sub_8051064: @ 8051064
	push {r4-r7,lr}
	ldr r6, =gBattleMons
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	movs r5, 0x58
	adds r1, r0, 0
	muls r1, r5
	adds r1, r6
	adds r1, 0x2A
	ldr r4, =gBankTarget
	ldrb r3, [r4]
	adds r0, r3, 0
	muls r0, r5
	adds r0, r6
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bcc _080510AC
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r1, r3, r1
	adds r1, 0x58
	ldr r2, =gBattlePartyID
	lsls r0, r3, 1
	b _08051108
	.pool
_080510AC:
	bl Random
	movs r3, 0xFF
	ands r3, r0
	ldrb r0, [r7]
	muls r0, r5
	adds r0, r6
	adds r0, 0x2A
	ldrb r2, [r0]
	ldrb r4, [r4]
	adds r0, r4, 0
	muls r0, r5
	adds r0, r6
	adds r0, 0x2A
	ldrb r1, [r0]
	adds r2, r1
	adds r0, r3, 0
	muls r0, r2
	asrs r0, 8
	adds r0, 0x1
	lsrs r1, 2
	cmp r0, r1
	bhi _080510FC
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
	movs r0, 0
	b _08051116
	.pool
_080510FC:
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r1, r4, r1
	adds r1, 0x58
	ldr r2, =gBattlePartyID
	lsls r0, r4, 1
_08051108:
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DADD8
	str r0, [r1]
	movs r0, 0x1
_08051116:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8051064

	thumb_func_start atk8F_forcerandomswitch
atk8F_forcerandomswitch: @ 805112C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	movs r0, 0
	str r0, [sp, 0x4]
	ldr r5, =gBattleTypeFlags
	ldr r0, [r5]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0805114A
	b _08051410
_0805114A:
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	str r1, [sp]
	cmp r0, 0
	bne _08051160
	ldr r0, =gPlayerParty
	str r0, [sp]
_08051160:
	ldr r2, [r5]
	movs r1, 0x81
	lsls r1, 1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	beq _08051182
	ldr r1, =0x02000100
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	beq _08051182
	movs r0, 0x80
	lsls r0, 15
	ands r0, r2
	cmp r0, 0
	beq _080511C8
_08051182:
	ldr r2, =gBankTarget
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	adds r1, r2, 0
	cmp r0, 0
	beq _080511AC
	movs r0, 0x3
	mov r9, r0
	movs r0, 0x6
	b _080511B2
	.pool
_080511AC:
	movs r0, 0
	mov r9, r0
	movs r0, 0x3
_080511B2:
	mov r8, r0
	movs r0, 0x3
	mov r10, r0
	movs r0, 0x1
	str r0, [sp, 0x8]
	ldr r2, =gBattlePartyID
	ldrb r1, [r1]
	b _0805128E
	.pool
_080511C8:
	movs r0, 0x42
	ands r0, r2
	cmp r0, 0x42
	beq _080511DA
	ldr r1, =0x02000040
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	bne _0805121C
_080511DA:
	ldrb r0, [r4]
	bl sub_806D864
	lsls r0, 24
	lsrs r0, 24
	bl sub_806D82C
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bne _080511FC
	movs r1, 0x3
	mov r9, r1
	movs r0, 0x6
	b _08051202
	.pool
_080511FC:
	movs r1, 0
	mov r9, r1
	movs r0, 0x3
_08051202:
	mov r8, r0
	movs r1, 0x3
	mov r10, r1
	movs r0, 0x1
	str r0, [sp, 0x8]
	ldr r2, =gBattlePartyID
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	b _0805128E
	.pool
_0805121C:
	movs r0, 0x80
	lsls r0, 8
	ands r0, r2
	cmp r0, 0
	beq _08051274
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08051240
	movs r1, 0
	mov r9, r1
	movs r0, 0x6
	mov r8, r0
	mov r10, r0
	movs r1, 0x2
	b _08051260
_08051240:
	ldrb r1, [r4]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08051252
	movs r0, 0x3
	mov r9, r0
	movs r1, 0x6
	b _08051258
_08051252:
	movs r0, 0
	mov r9, r0
	movs r1, 0x3
_08051258:
	mov r8, r1
	movs r0, 0x3
	mov r10, r0
	movs r1, 0x1
_08051260:
	str r1, [sp, 0x8]
	ldr r2, =gBattlePartyID
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	b _0805128E
	.pool
_08051274:
	movs r0, 0x1
	ands r2, r0
	cmp r2, 0
	beq _080512A4
	movs r0, 0
	mov r9, r0
	movs r1, 0x6
	mov r8, r1
	mov r10, r1
	movs r0, 0x2
	str r0, [sp, 0x8]
	ldr r2, =gBattlePartyID
	ldrb r1, [r4]
_0805128E:
	lsls r0, r1, 1
	adds r0, r2
	ldrh r7, [r0]
	movs r0, 0x2
	eors r1, r0
	lsls r1, 1
	adds r1, r2
	ldrh r5, [r1]
	b _080512BE
	.pool
_080512A4:
	movs r1, 0
	mov r9, r1
	movs r0, 0x6
	mov r8, r0
	mov r10, r0
	movs r1, 0x1
	str r1, [sp, 0x8]
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r5, [r0]
	adds r7, r5, 0
_080512BE:
	mov r6, r9
	cmp r6, r8
	bge _080512FC
_080512C4:
	movs r0, 0x64
	muls r0, r6
	ldr r1, [sp]
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _080512F6
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _080512F6
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _080512F6
	ldr r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x4]
_080512F6:
	adds r6, 0x1
	cmp r6, r8
	blt _080512C4
_080512FC:
	ldr r1, [sp, 0x4]
	ldr r0, [sp, 0x8]
	cmp r1, r0
	bgt _08051328
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
	b _08051414
	.pool
_08051328:
	bl sub_8051064
	lsls r0, 24
	cmp r0, 0
	beq _08051378
_08051332:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	mov r1, r10
	bl __modsi3
	adds r6, r0, 0
	add r6, r9
	cmp r6, r7
	beq _08051332
	cmp r6, r5
	beq _08051332
	movs r0, 0x64
	muls r0, r6
	ldr r1, [sp]
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _08051332
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0x1
	beq _08051332
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08051332
_08051378:
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x5C
	strb r6, [r0]
	bl sub_81B1250
	lsls r0, 24
	cmp r0, 0
	bne _08051396
	ldrb r0, [r4]
	bl sub_803BDA0
_08051396:
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r1, 0x81
	lsls r1, 1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	beq _080513C0
	movs r0, 0x42
	ands r0, r2
	cmp r0, 0x42
	beq _080513C0
	ldr r1, =0x02000100
	adds r0, r2, 0
	ands r0, r1
	cmp r0, r1
	beq _080513C0
	ldr r0, =0x02000040
	ands r2, r0
	cmp r2, r0
	bne _080513DE
_080513C0:
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	lsls r4, r6, 24
	lsrs r4, 24
	adds r1, r4, 0
	movs r2, 0
	bl sub_81B8E80
	ldrb r1, [r5]
	movs r0, 0x2
	eors r0, r1
	adds r1, r4, 0
	movs r2, 0x1
	bl sub_81B8E80
_080513DE:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _08051414
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	lsls r1, r6, 24
	lsrs r1, 24
	bl sub_80571DC
	b _08051414
	.pool
_08051410:
	bl sub_8051064
_08051414:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk8F_forcerandomswitch

	thumb_func_start atk90_conversion_type_change
atk90_conversion_type_change: @ 8051424
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r6, 0
	ldr r2, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0xC
	adds r0, r1
	ldrh r0, [r0]
	mov r8, r2
	cmp r0, 0
	beq _08051466
	movs r5, 0x58
	adds r2, r1, 0
_0805144C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bhi _08051466
	lsls r1, r6, 1
	ldrb r0, [r3]
	muls r0, r5
	adds r1, r0
	adds r1, r2
	ldrh r0, [r1]
	cmp r0, 0
	bne _0805144C
_08051466:
	movs r3, 0
	cmp r3, r6
	bcs _080514E8
	ldr r0, =gBattleMoves
	mov r10, r0
	ldr r5, =gBattleMons
	mov r12, r5
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	movs r4, 0x58
	adds r5, r0, 0
	muls r5, r4
	movs r0, 0xC
	add r0, r12
	mov r9, r0
_08051484:
	lsls r0, r3, 1
	adds r0, r5
	add r0, r9
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	add r0, r10
	ldrb r2, [r0, 0x2]
	cmp r2, 0x9
	bne _080514C6
	mov r0, r8
	adds r1, r5, r0
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x7
	beq _080514B2
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _080514C4
_080514B2:
	movs r2, 0x7
	b _080514C6
	.pool
_080514C4:
	movs r2, 0
_080514C6:
	ldrb r0, [r7]
	muls r0, r4
	add r0, r12
	adds r1, r0, 0
	adds r1, 0x21
	ldrb r1, [r1]
	cmp r2, r1
	beq _080514DE
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r2, r0
	bne _080514E8
_080514DE:
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r6
	bcc _08051484
_080514E8:
	cmp r3, r6
	bne _0805150C
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
	b _080515B0
	.pool
_0805150C:
	movs r7, 0x3
	ldr r5, =gBattleMoves
	mov r9, r5
_08051512:
	bl Random
	adds r3, r0, 0
	ands r3, r7
	cmp r3, r6
	bcs _08051512
	ldr r4, =gBattleMons
	lsls r1, r3, 1
	ldr r3, =gBankAttacker
	ldrb r2, [r3]
	movs r0, 0x58
	adds r5, r2, 0
	muls r5, r0
	adds r1, r5
	adds r0, r4, 0
	adds r0, 0xC
	adds r1, r0
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	add r0, r9
	ldrb r2, [r0, 0x2]
	mov r8, r4
	adds r4, r3, 0
	cmp r2, 0x9
	bne _08051572
	mov r0, r8
	adds r2, r5, r0
	adds r0, r2, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x7
	beq _08051560
	adds r0, r2, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x7
	bne _08051570
_08051560:
	movs r2, 0x7
	b _08051572
	.pool
_08051570:
	movs r2, 0
_08051572:
	ldrb r0, [r4]
	movs r3, 0x58
	muls r0, r3
	add r0, r8
	adds r1, r0, 0
	adds r1, 0x21
	ldrb r5, [r1]
	cmp r2, r5
	beq _08051512
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r2, r0
	beq _08051512
	strb r2, [r1]
	ldrb r0, [r4]
	muls r0, r3
	add r0, r8
	adds r0, 0x22
	strb r2, [r0]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x3
	strb r0, [r1, 0x1]
	strb r2, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_080515B0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk90_conversion_type_change

	thumb_func_start atk91_givepaydaymoney
atk91_givepaydaymoney: @ 80515C8
	push {r4,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	bne _08051650
	ldr r1, =gUnknown_0202432E
	ldrh r0, [r1]
	cmp r0, 0
	beq _08051650
	adds r1, r0, 0
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x4A
	ldrb r0, [r0]
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r1, 0x92
	lsls r1, 3
	adds r0, r1
	adds r1, r4, 0
	bl add_money
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x1
	strb r0, [r1, 0x1]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	movs r0, 0x5
	strb r0, [r1, 0x3]
	strb r4, [r1, 0x4]
	movs r0, 0xFF
	lsls r0, 8
	ands r4, r0
	lsrs r4, 8
	strb r4, [r1, 0x5]
	movs r0, 0xFF
	strb r0, [r1, 0x6]
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	adds r0, 0x1
	bl b_movescr_stack_push
	ldr r0, =gUnknown_082DB307
	str r0, [r4]
	b _08051658
	.pool
_08051650:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
_08051658:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk91_givepaydaymoney

	thumb_func_start atk92_setlightscreen
atk92_setlightscreen: @ 8051664
	push {r4-r6,lr}
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	bl GetBankIdentity
	ldr r4, =gSideAffecting
	movs r6, 0x1
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r1, [r1]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080516A4
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0
	b _08051718
	.pool
_080516A4:
	ldrb r0, [r5]
	bl GetBankIdentity
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r5]
	bl GetBankIdentity
	ldr r4, =gSideTimers
	adds r1, r6, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x5
	strb r1, [r0, 0x2]
	ldrb r0, [r5]
	bl GetBankIdentity
	adds r1, r6, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r5]
	strb r1, [r0, 0x3]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ands r0, r6
	cmp r0, 0
	beq _08051714
	movs r0, 0x1
	bl CountAliveMonsInBattle
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08051714
	ldr r1, =gBattleCommunication
	movs r0, 0x4
	b _08051718
	.pool
_08051714:
	ldr r1, =gBattleCommunication
	movs r0, 0x3
_08051718:
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk92_setlightscreen

	thumb_func_start atk93_ko_move
atk93_ko_move: @ 8051730
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r7, =gBattleMons
	ldr r6, =gBankTarget
	ldrb r2, [r6]
	movs r5, 0x58
	adds r0, r2, 0
	muls r0, r5
	adds r1, r0, r7
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _08051768
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x7]
	ldrb r6, [r0, 0x1A]
	b _08051782
	.pool
_08051768:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r7
	ldrh r0, [r0, 0x2E]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r6, r0, 24
_08051782:
	ldr r1, =gUnknown_0202420F
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	strb r0, [r1]
	cmp r4, 0x27
	bne _080517C0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r6
	bcs _080517C0
	ldrb r0, [r5]
	movs r1, 0x27
	bl RecordItemEffectBattle
	ldr r2, =gSpecialStatuses
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
_080517C0:
	ldr r1, =gBattleMons
	ldr r2, =gBankTarget
	ldrb r3, [r2]
	movs r6, 0x58
	adds r0, r3, 0
	muls r0, r6
	adds r5, r0, r1
	adds r0, r5, 0
	adds r0, 0x20
	ldrb r4, [r0]
	mov r8, r1
	mov r9, r2
	cmp r4, 0x5
	bne _0805181C
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gLastUsedAbility
	strb r4, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB552
	str r0, [r1]
	mov r1, r9
	ldrb r0, [r1]
	movs r1, 0x5
	bl RecordAbilityBattle
	b _08051A70
	.pool
_0805181C:
	ldr r1, =gStatuses3
	lsls r0, r3, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x18
	ands r0, r1
	cmp r0, 0
	bne _080518A0
	ldr r1, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	muls r0, r6
	add r0, r8
	adds r0, 0x2A
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r1, 0x2A
	ldrb r1, [r1]
	subs r0, r1
	ldrb r2, [r2, 0x3]
	adds r0, r2
	lsls r0, 16
	lsrs r4, r0, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, 0x1
	cmp r0, r4
	blt _08051870
	b _08051A08
_08051870:
	ldrb r0, [r7]
	adds r1, r0, 0
	muls r1, r6
	add r1, r8
	adds r1, 0x2A
	mov r2, r9
	ldrb r0, [r2]
	muls r0, r6
	add r0, r8
	adds r0, 0x2A
	ldrb r1, [r1]
	movs r4, 0x1
	ldrb r0, [r0]
	cmp r1, r0
	bcs _08051936
	b _08051A08
	.pool
_080518A0:
	ldr r1, =gDisableStructs
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldr r1, =gBankAttacker
	ldrb r0, [r0, 0x15]
	adds r7, r1, 0
	ldrb r3, [r7]
	cmp r0, r3
	bne _080518CA
	ldrb r0, [r7]
	muls r0, r6
	add r0, r8
	adds r0, 0x2A
	adds r1, r5, 0
	adds r1, 0x2A
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08051942
_080518CA:
	ldr r1, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	ldr r6, =gBattleMons
	ldrb r0, [r7]
	movs r5, 0x58
	muls r0, r5
	adds r0, r6
	adds r0, 0x2A
	ldrb r1, [r0]
	ldr r0, =gBankTarget
	mov r8, r0
	ldrb r0, [r0]
	muls r0, r5
	adds r0, r6
	adds r0, 0x2A
	ldrb r0, [r0]
	subs r1, r0
	ldrb r2, [r2, 0x3]
	adds r1, r2
	lsls r1, 16
	lsrs r4, r1, 16
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, 0x1
	cmp r0, r4
	bge _08051934
	ldrb r0, [r7]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r6
	adds r1, 0x2A
	mov r2, r8
	ldrb r0, [r2]
	muls r0, r5
	adds r0, r6
	adds r0, 0x2A
	ldrb r1, [r1]
	movs r4, 0x1
	ldrb r0, [r0]
	cmp r1, r0
	bcs _08051936
_08051934:
	movs r4, 0
_08051936:
	ldr r3, =gBattleMons
	mov r8, r3
	ldr r0, =gBankTarget
	mov r9, r0
	cmp r4, 0
	beq _08051A08
_08051942:
	ldr r0, =gProtectStructs
	mov r1, r9
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 30
	cmp r0, 0
	bge _08051990
	ldr r1, =gBattleMoveDamage
	movs r0, 0x58
	muls r0, r2
	add r0, r8
	ldrh r0, [r0, 0x28]
	subs r0, 0x1
	str r0, [r1]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x40
	b _080519EE
	.pool
_08051990:
	ldr r0, =gSpecialStatuses
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	lsrs r0, 7
	cmp r0, 0
	beq _080519DC
	ldr r1, =gBattleMoveDamage
	movs r3, 0x58
	adds r0, r2, 0
	muls r0, r3
	add r0, r8
	ldrh r0, [r0, 0x28]
	subs r0, 0x1
	str r0, [r1]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gLastUsedItem
	mov r2, r9
	ldrb r0, [r2]
	muls r0, r3
	add r0, r8
	ldrh r0, [r0, 0x2E]
	strh r0, [r1]
	b _080519F2
	.pool
_080519DC:
	ldr r1, =gBattleMoveDamage
	movs r0, 0x58
	muls r0, r2
	add r0, r8
	ldrh r0, [r0, 0x28]
	str r0, [r1]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x10
_080519EE:
	orrs r0, r1
	strb r0, [r2]
_080519F2:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08051A70
	.pool
_08051A08:
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r3, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	movs r2, 0x58
	adds r1, r0, 0
	muls r1, r2
	adds r1, r3
	adds r1, 0x2A
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	muls r0, r2
	adds r0, r3
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bcc _08051A50
	ldr r1, =gBattleCommunication
	movs r0, 0
	b _08051A54
	.pool
_08051A50:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
_08051A54:
	strb r0, [r1, 0x5]
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
_08051A70:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk93_ko_move

	thumb_func_start atk94_gethalfcurrentenemyhp
atk94_gethalfcurrentenemyhp: @ 8051A84
	push {lr}
	ldr r3, =gBattleMoveDamage
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x28]
	lsrs r0, 1
	str r0, [r3]
	cmp r0, 0
	bne _08051AA2
	movs r0, 0x1
	str r0, [r3]
_08051AA2:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk94_gethalfcurrentenemyhp

	thumb_func_start atk95_setsandstorm
atk95_setsandstorm: @ 8051AC0
	push {lr}
	ldr r2, =gBattleWeather
	ldrh r1, [r2]
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _08051AEC
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	b _08051AFE
	.pool
_08051AEC:
	movs r0, 0x8
	strh r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x3
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_020243D0
	adds r0, 0x28
	movs r1, 0x5
	strb r1, [r0]
_08051AFE:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk95_setsandstorm

	thumb_func_start atk96_weatherdamage
atk96_weatherdamage: @ 8051B18
	push {r4,r5,lr}
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
	beq _08051B36
	b _08051C48
_08051B36:
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _08051B4C
	b _08051C48
_08051B4C:
	ldr r2, =gBattleWeather
	ldrh r1, [r2]
	movs r0, 0x18
	ands r0, r1
	adds r4, r2, 0
	ldr r5, =gBankAttacker
	cmp r0, 0
	beq _08051BDA
	ldr r0, =gBattleMons
	ldrb r2, [r5]
	movs r1, 0x58
	muls r1, r2
	adds r3, r1, r0
	adds r0, r3, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _08051BD4
	cmp r0, 0x8
	beq _08051BD4
	cmp r0, 0x4
	beq _08051BD4
	adds r0, r3, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _08051BD4
	cmp r0, 0x8
	beq _08051BD4
	cmp r0, 0x4
	beq _08051BD4
	adds r0, r3, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x8
	beq _08051BD4
	ldr r0, =gStatuses3
	lsls r1, r2, 2
	adds r1, r0
	ldr r1, [r1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08051BD4
	movs r0, 0x80
	lsls r0, 11
	ands r1, r0
	cmp r1, 0
	bne _08051BD4
	ldr r1, =gBattleMoveDamage
	ldrh r0, [r3, 0x2C]
	lsrs r0, 4
	str r0, [r1]
	cmp r0, 0
	bne _08051BDA
	movs r0, 0x1
	b _08051BD8
	.pool
_08051BD4:
	ldr r1, =gBattleMoveDamage
	movs r0, 0
_08051BD8:
	str r0, [r1]
_08051BDA:
	ldrh r1, [r4]
	movs r4, 0x80
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _08051C50
	ldr r1, =gBattleMons
	ldrb r3, [r5]
	movs r0, 0x58
	muls r0, r3
	adds r2, r0, r1
	adds r0, r2, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0xF
	beq _08051C3C
	adds r0, r2, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0xF
	beq _08051C3C
	ldr r0, =gStatuses3
	lsls r1, r3, 2
	adds r1, r0
	ldr r1, [r1]
	adds r0, r1, 0
	ands r0, r4
	cmp r0, 0
	bne _08051C3C
	movs r0, 0x80
	lsls r0, 11
	ands r1, r0
	cmp r1, 0
	bne _08051C3C
	ldr r1, =gBattleMoveDamage
	ldrh r0, [r2, 0x2C]
	lsrs r0, 4
	str r0, [r1]
	cmp r0, 0
	bne _08051C50
	movs r0, 0x1
	str r0, [r1]
	b _08051C50
	.pool
_08051C3C:
	ldr r1, =gBattleMoveDamage
	movs r0, 0
	str r0, [r1]
	b _08051C50
	.pool
_08051C48:
	ldr r1, =gBattleMoveDamage
	movs r0, 0
	str r0, [r1]
	ldr r5, =gBankAttacker
_08051C50:
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08051C6A
	ldr r1, =gBattleMoveDamage
	movs r0, 0
	str r0, [r1]
_08051C6A:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk96_weatherdamage

	thumb_func_start atk97_try_infatuation
atk97_try_infatuation: @ 8051C90
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08051CC8
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	b _08051CD8
	.pool
_08051CC8:
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
_08051CD8:
	adds r5, r1, r0
	ldr r4, =gBankTarget
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08051D0C
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	b _08051D1C
	.pool
_08051D0C:
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
_08051D1C:
	adds r4, r1, r0
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	adds r0, r5, 0
	movs r1, 0
	bl GetMonData
	mov r9, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	adds r7, r0, 0
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	movs r6, 0x58
	muls r0, r6
	ldr r1, =gBattleMons
	adds r0, r1
	adds r0, 0x20
	ldrb r2, [r0]
	cmp r2, 0xC
	bne _08051D94
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB5F5
	str r0, [r1]
	ldr r0, =gLastUsedAbility
	strb r2, [r0]
	ldrb r0, [r5]
	movs r1, 0xC
	bl RecordAbilityBattle
	b _08051E2C
	.pool
_08051D94:
	mov r0, r10
	mov r1, r9
	bl GetGenderFromSpeciesAndPersonality
	adds r4, r0, 0
	mov r0, r8
	adds r1, r7, 0
	bl GetGenderFromSpeciesAndPersonality
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	beq _08051DE4
	ldrb r0, [r5]
	muls r0, r6
	ldr r4, =gBattleMons
	adds r4, 0x50
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0xF0
	lsls r1, 12
	ands r0, r1
	cmp r0, 0
	bne _08051DE4
	mov r0, r10
	mov r1, r9
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08051DE4
	mov r0, r8
	adds r1, r7, 0
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08051E08
_08051DE4:
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
	b _08051E2C
	.pool
_08051E08:
	ldrb r0, [r5]
	adds r2, r0, 0
	muls r2, r6
	adds r2, r4
	ldr r1, =gBitTable
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 16
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
_08051E2C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk97_try_infatuation

	thumb_func_start atk98_status_icon_update
atk98_status_icon_update: @ 8051E48
	push {r4-r7,lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _08051F34
	ldr r5, =gBattlescriptCurrInstr
	ldr r1, [r5]
	ldrb r0, [r1, 0x1]
	cmp r0, 0x4
	beq _08051EA0
	bl get_battle_side_of_something
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r3, =gBattleMons
	ldrb r1, [r4]
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	adds r0, r3, 0
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r1, [r0]
	adds r3, 0x50
	adds r2, r3
	ldr r2, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x1A_aaaa_bbbb
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	b _08051F34
	.pool
_08051EA0:
	ldr r4, =gActiveBank
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	strb r0, [r4]
	ldr r6, =gAbsentBankFlags
	ldrb r1, [r6]
	ldr r7, =gBitTable
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r7
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08051EDC
	ldr r3, =gBattleMons
	movs r0, 0x58
	muls r2, r0
	adds r0, r3, 0
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r1, [r0]
	adds r3, 0x50
	adds r2, r3
	ldr r2, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x1A_aaaa_bbbb
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_08051EDC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08051F2C
	ldrb r0, [r5]
	bl GetBankIdentity
	movs r1, 0x2
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	strb r0, [r4]
	ldrb r1, [r6]
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r7
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08051F2C
	ldr r3, =gBattleMons
	movs r0, 0x58
	muls r2, r0
	adds r0, r3, 0
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r1, [r0]
	adds r3, 0x50
	adds r2, r3
	ldr r2, [r2]
	movs r0, 0
	bl dp01_build_cmdbuf_x1A_aaaa_bbbb
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_08051F2C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
_08051F34:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk98_status_icon_update

	thumb_func_start atk99_setmist
atk99_setmist: @ 8051F58
	push {r4-r6,lr}
	ldr r6, =gSideTimers
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankIdentity
	movs r5, 0x1
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x4]
	cmp r0, 0
	beq _08051F98
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2]
	ldr r0, =gBattleCommunication
	strb r5, [r0, 0x5]
	b _08051FE6
	.pool
_08051F98:
	ldrb r0, [r4]
	bl GetBankIdentity
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	strb r1, [r0, 0x4]
	ldrb r0, [r4]
	bl GetBankIdentity
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r4]
	strb r1, [r0, 0x5]
	ldrb r0, [r4]
	bl GetBankIdentity
	ldr r2, =gSideAffecting
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r3, 0x80
	lsls r3, 1
	adds r0, r3, 0
	movs r3, 0
	orrs r0, r2
	strh r0, [r1]
	ldr r0, =gBattleCommunication
	strb r3, [r0, 0x5]
_08051FE6:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk99_setmist

	thumb_func_start atk9A_set_focusenergy
atk9A_set_focusenergy: @ 8052000
	push {lr}
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	movs r3, 0x80
	lsls r3, 13
	adds r2, r1, 0
	ands r2, r3
	cmp r2, 0
	beq _08052040
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _08052048
	.pool
_08052040:
	orrs r1, r3
	str r1, [r0]
	ldr r0, =gBattleCommunication
	strb r2, [r0, 0x5]
_08052048:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk9A_set_focusenergy

	thumb_func_start atk9B_transformdataexecution
atk9B_transformdataexecution: @ 805205C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, =gUnknown_020241EC
	ldr r2, =0x0000ffff
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r7, =gBattleMons
	ldr r0, =gBankTarget
	mov r12, r0
	ldrb r1, [r0]
	movs r6, 0x58
	adds r0, r1, 0
	muls r0, r6
	adds r5, r7, 0
	adds r5, 0x50
	adds r0, r5
	ldr r0, [r0]
	movs r4, 0x80
	lsls r4, 14
	ands r0, r4
	cmp r0, 0
	bne _080520A2
	ldr r0, =gStatuses3
	lsls r1, 2
	adds r1, r0
	ldr r2, [r1]
	ldr r0, =0x000400c0
	ands r2, r0
	cmp r2, 0
	beq _080520D8
_080520A2:
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	b _080521EC
	.pool
_080520D8:
	ldr r3, =gBankAttacker
	ldrb r0, [r3]
	adds r1, r0, 0
	muls r1, r6
	adds r1, r5
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r4, =gDisableStructs
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	strh r2, [r0, 0x4]
	ldrb r0, [r3]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0xB]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0xB]
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	mov r2, r12
	ldrb r1, [r2]
	muls r1, r6
	adds r2, r7, 0
	adds r2, 0x48
	adds r1, r2
	ldr r1, [r1]
	str r1, [r0]
	ldrb r0, [r3]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r2, [r1, 0x18]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1, 0x18]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x6
	strb r0, [r1, 0x1]
	mov r2, r12
	ldrb r0, [r2]
	muls r0, r6
	adds r0, r7
	ldrh r0, [r0]
	strb r0, [r1, 0x2]
	ldrb r0, [r2]
	muls r0, r6
	adds r0, r7
	ldrh r0, [r0]
	lsrs r0, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldrb r0, [r3]
	muls r0, r6
	adds r5, r0, r7
	ldrb r0, [r2]
	muls r0, r6
	adds r2, r0, r7
	movs r4, 0
	adds r6, r3, 0
	ldr r0, =gActiveBank
	mov r8, r0
_08052170:
	adds r0, r5, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x23
	bls _08052170
	movs r4, 0
	ldr r7, =gBattleMoves
	ldr r3, =gBattleMons + 0xC
	adds r5, r3, 0
	adds r5, 0x18
_08052188:
	lsls r1, r4, 1
	ldrb r2, [r6]
	movs r0, 0x58
	muls r2, r0
	adds r1, r2
	adds r1, r3
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r1, [r0, 0x4]
	cmp r1, 0x4
	bhi _080521C4
	adds r0, r4, r2
	adds r0, r5
	b _080521CA
	.pool
_080521C4:
	adds r0, r4, r2
	adds r0, r5
	movs r1, 0x5
_080521CA:
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x3
	ble _08052188
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	movs r0, 0
	movs r1, 0x2
	bl dp01_build_cmdbuf_x38_a
	mov r2, r8
	ldrb r0, [r2]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattleCommunication
	movs r0, 0
_080521EC:
	strb r0, [r1, 0x5]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk9B_transformdataexecution

	thumb_func_start atk9C_set_substitute
atk9C_set_substitute: @ 80521FC
	push {r4-r7,lr}
	ldr r7, =gBattleMons
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	movs r5, 0x58
	muls r0, r5
	adds r3, r0, r7
	ldrh r0, [r3, 0x2C]
	lsrs r1, r0, 2
	adds r2, r1, 0
	cmp r1, 0
	bne _08052216
	movs r2, 0x1
_08052216:
	ldrh r0, [r3, 0x28]
	cmp r0, r2
	bhi _0805223C
	ldr r1, =gBattleMoveDamage
	movs r0, 0
	str r0, [r1]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _08052290
	.pool
_0805223C:
	ldr r4, =gBattleMoveDamage
	str r1, [r4]
	cmp r1, 0
	bne _08052248
	movs r0, 0x1
	str r0, [r4]
_08052248:
	ldrb r0, [r6]
	adds r2, r0, 0
	muls r2, r5
	adds r3, r7, 0
	adds r3, 0x50
	adds r2, r3
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 17
	orrs r0, r1
	str r0, [r2]
	ldrb r0, [r6]
	adds r1, r0, 0
	muls r1, r5
	adds r1, r3
	ldr r0, [r1]
	ldr r2, =0xffff1fff
	ands r0, r2
	str r0, [r1]
	ldr r2, =gDisableStructs
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r4]
	movs r2, 0
	strb r1, [r0, 0xA]
	ldr r0, =gBattleCommunication
	strb r2, [r0, 0x5]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [r2]
_08052290:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk9C_set_substitute

	thumb_func_start sub_80522B8
sub_80522B8: @ 80522B8
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r3, 0
	ldr r0, =gUnknown_0831C3E0
	ldrh r1, [r0]
	ldr r4, =0x0000fffe
	adds r5, r0, 0
	cmp r1, r4
	beq _080522E0
	cmp r1, r2
	beq _080522E0
	adds r1, r5, 0
_080522D2:
	adds r1, 0x2
	adds r3, 0x1
	ldrh r0, [r1]
	cmp r0, r4
	beq _080522E0
	cmp r0, r2
	bne _080522D2
_080522E0:
	lsls r0, r3, 1
	adds r0, r5
	ldrh r1, [r0]
	ldr r0, =0x0000fffe
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80522B8

	thumb_func_start atk9D_copyattack
atk9D_copyattack: @ 8052300
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_020241EC
	ldr r1, =0x0000ffff
	adds r7, r1, 0
	strh r7, [r0]
	ldr r5, =gLastUsedMovesByBanks
	ldr r6, =gBankTarget
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	bl sub_80522B8
	lsls r0, 24
	cmp r0, 0
	bne _0805235A
	ldr r3, =gBattleMons
	ldr r2, =gBankAttacker
	ldrb r1, [r2]
	movs r0, 0x58
	adds r4, r1, 0
	muls r4, r0
	adds r0, r3, 0
	adds r0, 0x50
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 14
	ands r1, r0
	mov r12, r3
	mov r9, r2
	cmp r1, 0
	bne _0805235A
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r5
	ldrh r1, [r0]
	cmp r1, 0
	beq _0805235A
	cmp r1, r7
	bne _08052394
_0805235A:
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
	b _080524CC
	.pool
_08052394:
	movs r2, 0
	mov r3, r12
	adds r3, 0xC
	adds r0, r4, r3
	ldrh r0, [r0]
	ldr r4, =gBattlescriptCurrInstr
	mov r10, r4
	cmp r0, r1
	beq _080523CE
	mov r8, r3
	adds r7, r5, 0
	adds r5, r6, 0
	mov r4, r9
	movs r3, 0x58
_080523B0:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080523CE
	lsls r1, r2, 1
	ldrb r0, [r4]
	muls r0, r3
	adds r1, r0
	add r1, r8
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r7
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080523B0
_080523CE:
	cmp r2, 0x4
	bne _080524B0
	ldr r5, =gCurrMovePos
	ldrb r1, [r5]
	lsls r1, 1
	mov r2, r9
	ldrb r0, [r2]
	movs r6, 0x58
	muls r0, r6
	adds r1, r0
	mov r0, r12
	adds r0, 0xC
	adds r1, r0
	ldr r2, =gLastUsedMovesByBanks
	ldr r3, =gBankTarget
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r4, =gBattleMoves
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r4, [r0, 0x4]
	cmp r4, 0x4
	bhi _08052438
	mov r1, r9
	ldrb r0, [r1]
	muls r0, r6
	ldrb r1, [r5]
	adds r0, r1
	mov r1, r12
	adds r1, 0x24
	adds r0, r1
	strb r4, [r0]
	b _0805244C
	.pool
_08052438:
	mov r4, r9
	ldrb r0, [r4]
	muls r0, r6
	ldrb r1, [r5]
	adds r0, r1
	mov r1, r12
	adds r1, 0x24
	adds r0, r1
	movs r1, 0x5
	strb r1, [r0]
_0805244C:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
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
	ldr r1, =gDisableStructs
	mov r2, r9
	ldrb r0, [r2]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r2, r1
	ldrb r4, [r2, 0x18]
	lsrs r3, r4, 4
	ldr r1, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	orrs r1, r3
	lsls r1, 4
	movs r0, 0xF
	ands r0, r4
	orrs r0, r1
	strb r0, [r2, 0x18]
	mov r4, r10
	ldr r0, [r4]
	adds r0, 0x5
	str r0, [r4]
	b _080524CC
	.pool
_080524B0:
	mov r0, r10
	ldr r2, [r0]
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
	mov r2, r10
	str r1, [r2]
_080524CC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end atk9D_copyattack

	thumb_func_start atk9E_metronome
atk9E_metronome: @ 80524DC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r7, =gCurrentMove
	movs r6, 0xB1
	lsls r6, 1
	ldr r5, =gUnknown_0831C3E0
	ldr r0, =gBattlescriptCurrInstr
	mov r8, r0
_080524EE:
	bl Random
	ldr r2, =0x000001ff
	adds r1, r2, 0
	ands r0, r1
	adds r0, 0x1
	strh r0, [r7]
	cmp r0, r6
	bhi _080524EE
	movs r0, 0x3
_08052502:
	subs r0, 0x1
	cmp r0, 0
	bge _08052502
	ldr r4, =gCurrentMove
	ldrh r2, [r4]
	ldr r3, =0x0000ffff
	subs r0, r5, 0x2
_08052510:
	adds r0, 0x2
	ldrh r1, [r0]
	cmp r1, r2
	beq _0805251C
	cmp r1, r3
	bne _08052510
_0805251C:
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _080524EE
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0xfffffbff
	ands r0, r1
	str r0, [r2]
	ldr r3, =gUnknown_082D86A8
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
	mov r1, r8
	str r0, [r1]
	ldrh r0, [r4]
	movs r1, 0
	bl GetMoveTarget
	ldr r1, =gBankTarget
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk9E_metronome

	thumb_func_start atk9F_dmgtolevel
atk9F_dmgtolevel: @ 8052584
	ldr r3, =gBattleMoveDamage
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x2A
	ldrb r0, [r0]
	str r0, [r3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end atk9F_dmgtolevel

	thumb_func_start atkA0_psywavedamageeffect
atkA0_psywavedamageeffect: @ 80525B4
	push {r4,lr}
	movs r4, 0xF
_080525B8:
	bl Random
	adds r3, r4, 0
	ands r3, r0
	cmp r3, 0xA
	bgt _080525B8
	lsls r0, r3, 2
	adds r0, r3
	lsls r3, r0, 1
	ldr r4, =gBattleMoveDamage
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r0, 0x2A
	ldrb r1, [r0]
	adds r0, r3, 0
	adds r0, 0x32
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	str r0, [r4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA0_psywavedamageeffect

	thumb_func_start atkA1_counterdamagecalculator
atkA1_counterdamagecalculator: @ 8052608
	push {r4-r6,lr}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gProtectStructs
	ldrb r0, [r4]
	lsls r0, 4
	adds r0, r5
	ldrb r0, [r0, 0xC]
	bl GetBankSide
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r0, r5, 0x4
	adds r0, r1, r0
	ldr r3, [r0]
	cmp r3, 0
	beq _080526BC
	cmp r6, r2
	beq _080526BC
	ldr r6, =gBattleMons
	adds r0, r1, r5
	ldrb r0, [r0, 0xC]
	movs r4, 0x58
	muls r0, r4
	adds r0, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _080526BC
	ldr r1, =gBattleMoveDamage
	lsls r0, r3, 1
	str r0, [r1]
	ldr r1, =gSideTimers
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _08052690
	ldrb r1, [r1, 0x9]
	adds r0, r1, 0
	muls r0, r4
	adds r0, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08052690
	ldr r0, =gBankTarget
	strb r1, [r0]
	b _080526A0
	.pool
_08052690:
	ldr r2, =gBankTarget
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0xC]
	strb r0, [r2]
_080526A0:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _080526EC
	.pool
_080526BC:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
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
_080526EC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA1_counterdamagecalculator

	thumb_func_start atkA2_mirrorcoatdamagecalculator
atkA2_mirrorcoatdamagecalculator: @ 8052700
	push {r4-r6,lr}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r5, =gProtectStructs
	ldrb r0, [r4]
	lsls r0, 4
	adds r0, r5
	ldrb r0, [r0, 0xD]
	bl GetBankSide
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r3, [r0]
	cmp r3, 0
	beq _080527B4
	cmp r6, r2
	beq _080527B4
	ldr r6, =gBattleMons
	adds r0, r1, r5
	ldrb r0, [r0, 0xD]
	movs r4, 0x58
	muls r0, r4
	adds r0, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _080527B4
	ldr r1, =gBattleMoveDamage
	lsls r0, r3, 1
	str r0, [r1]
	ldr r1, =gSideTimers
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x8]
	cmp r0, 0
	beq _08052788
	ldrb r1, [r1, 0x9]
	adds r0, r1, 0
	muls r0, r4
	adds r0, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08052788
	ldr r0, =gBankTarget
	strb r1, [r0]
	b _08052798
	.pool
_08052788:
	ldr r2, =gBankTarget
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0xD]
	strb r0, [r2]
_08052798:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _080527E4
	.pool
_080527B4:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
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
_080527E4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA2_mirrorcoatdamagecalculator

	thumb_func_start atkA3_disablelastusedattack
atkA3_disablelastusedattack: @ 80527F8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r4, 0
	ldr r2, =gBattleMons
	ldr r3, =gBankTarget
	ldrb r1, [r3]
	movs r0, 0x58
	muls r0, r1
	adds r7, r2, 0
	adds r7, 0xC
	adds r0, r7
	ldr r5, =gLastUsedMovesByBanks
	lsls r1, 1
	adds r1, r5
	ldrh r0, [r0]
	mov r9, r2
	adds r6, r3, 0
	ldr r2, =gDisableStructs
	mov r8, r2
	ldrh r1, [r1]
	cmp r0, r1
	beq _0805284C
	mov r12, r6
	movs r3, 0x58
_0805282C:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0805284C
	lsls r2, r4, 1
	mov r0, r12
	ldrb r1, [r0]
	adds r0, r1, 0
	muls r0, r3
	adds r2, r0
	adds r2, r7
	lsls r1, 1
	adds r1, r5
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0805282C
_0805284C:
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r8
	ldrh r0, [r0, 0x4]
	cmp r0, 0
	bne _08052910
	cmp r4, 0x4
	beq _08052910
	movs r5, 0x58
	adds r0, r1, 0
	muls r0, r5
	adds r0, r4, r0
	mov r1, r9
	adds r1, 0x24
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08052910
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	lsls r2, r4, 1
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r2, r0
	mov r3, r9
	adds r3, 0xC
	adds r0, r3
	ldrh r0, [r0]
	strb r0, [r1, 0x2]
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r2, r0
	adds r0, r3
	ldrh r0, [r0]
	lsrs r0, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r8
	muls r1, r5
	adds r2, r1
	adds r2, r3
	ldrh r1, [r2]
	strh r1, [r0, 0x4]
	bl Random
	ldrb r2, [r6]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	add r1, r8
	movs r2, 0x3
	ands r2, r0
	adds r2, 0x2
	ldrb r3, [r1, 0xB]
	movs r0, 0x10
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0xB]
	ldrb r0, [r6]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	add r1, r8
	ldrb r3, [r1, 0xB]
	lsls r2, r3, 28
	lsrs r2, 24
	movs r0, 0xF
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0xB]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _0805292A
	.pool
_08052910:
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
_0805292A:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA3_disablelastusedattack

	thumb_func_start atkA4_setencore
atkA4_setencore: @ 805293C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r5, 0
	ldr r3, =gBattleMons
	ldr r4, =gBankTarget
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r6, r3, 0
	adds r6, 0xC
	adds r0, r6
	ldr r2, =gLastUsedMovesByBanks
	lsls r1, 1
	adds r1, r2
	ldrh r0, [r0]
	mov r10, r3
	mov r8, r2
	ldr r2, =gDisableStructs
	mov r9, r2
	ldrh r1, [r1]
	cmp r0, r1
	beq _08052996
	mov r12, r4
	adds r7, r6, 0
	mov r6, r8
	movs r3, 0x58
_08052976:
	adds r5, 0x1
	cmp r5, 0x3
	bgt _08052996
	lsls r2, r5, 1
	mov r0, r12
	ldrb r1, [r0]
	adds r0, r1, 0
	muls r0, r3
	adds r2, r0
	adds r2, r7
	lsls r1, 1
	adds r1, r6
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08052976
_08052996:
	ldrb r0, [r4]
	lsls r0, 1
	add r0, r8
	ldrh r2, [r0]
	cmp r2, 0xA5
	beq _080529AA
	cmp r2, 0xE3
	beq _080529AA
	cmp r2, 0x77
	bne _080529AC
_080529AA:
	movs r5, 0x4
_080529AC:
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	mov r2, r9
	adds r3, r0, r2
	ldrh r0, [r3, 0x6]
	cmp r0, 0
	bne _08052A44
	cmp r5, 0x4
	beq _08052A44
	movs r0, 0x58
	adds r2, r1, 0
	muls r2, r0
	adds r0, r5, r2
	mov r1, r10
	adds r1, 0x24
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08052A44
	lsls r0, r5, 1
	adds r0, r2
	subs r1, 0x18
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r3, 0x6]
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r9
	strb r5, [r0, 0xC]
	bl Random
	ldrb r2, [r4]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	add r1, r9
	movs r2, 0x3
	ands r2, r0
	adds r2, 0x3
	ldrb r3, [r1, 0xE]
	movs r0, 0x10
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0xE]
	ldrb r0, [r4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	add r1, r9
	ldrb r3, [r1, 0xE]
	lsls r2, r3, 28
	lsrs r2, 24
	movs r0, 0xF
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0xE]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08052A5E
	.pool
_08052A44:
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
_08052A5E:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA4_setencore

	thumb_func_start atkA5_painsplitdmgcalc
atkA5_painsplitdmgcalc: @ 8052A70
	push {r4-r7,lr}
	ldr r6, =gBattleMons
	ldr r0, =gBankTarget
	mov r12, r0
	ldrb r0, [r0]
	movs r7, 0x58
	adds r2, r0, 0
	muls r2, r7
	adds r0, r6, 0
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne _08052B10
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	muls r0, r7
	adds r0, r6
	ldrh r3, [r0, 0x28]
	adds r0, r2, r6
	ldrh r1, [r0, 0x28]
	adds r3, r1
	asrs r3, 1
	ldr r4, =gBattleMoveDamage
	subs r1, r3
	str r1, [r4]
	ldr r2, =gBattleScripting
	strb r1, [r2]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	asrs r0, 8
	strb r0, [r2, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	asrs r0, 16
	strb r0, [r2, 0x2]
	lsrs r1, 24
	strb r1, [r2, 0x3]
	ldrb r0, [r5]
	muls r0, r7
	adds r0, r6
	ldrh r0, [r0, 0x28]
	subs r0, r3
	str r0, [r4]
	ldr r2, =gSpecialStatuses
	mov r0, r12
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r0, r2
	ldr r1, =0x0000ffff
	str r1, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08052B2A
	.pool
_08052B10:
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
_08052B2A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA5_painsplitdmgcalc

	thumb_func_start atkA6_settypetorandomresistance
atkA6_settypetorandomresistance: @ 8052B34
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r1, =gUnknown_02024250
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	lsls r0, 1
	adds r2, r0, r1
	ldrh r1, [r2]
	cmp r1, 0
	beq _08052B7E
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _08052B7E
	ldrh r0, [r2]
	bl sub_8052F48
	lsls r0, 24
	cmp r0, 0
	beq _08052C1C
	ldr r1, =gBattleMons
	ldr r2, =gUnknown_02024270
	ldrb r0, [r4]
	adds r0, r2
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 5
	ands r0, r1
	cmp r0, 0
	beq _08052C1C
_08052B7E:
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
	b _08052D08
	.pool
_08052BB4:
	mov r0, r12
	strb r5, [r0]
	mov r1, r10
	ldrb r0, [r1]
	muls r0, r2
	adds r0, r7
	adds r0, 0x22
	strb r5, [r0]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x3
	strb r0, [r1, 0x1]
	strb r5, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r1, =gBattlescriptCurrInstr
	b _08052C0A
	.pool
_08052BE0:
	mov r0, r8
	adds r0, 0x1
	adds r0, r3
	ldrb r2, [r0]
	strb r2, [r4]
	mov r4, r10
	ldrb r0, [r4]
	muls r0, r6
	ldr r7, =gBattleMons
	adds r0, r7
	adds r0, 0x22
	strb r2, [r0]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x3
	strb r0, [r1, 0x1]
	strb r2, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	mov r1, r12
_08052C0A:
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08052D08
	.pool
_08052C1C:
	movs r4, 0
	mov r8, r4
	movs r7, 0x7F
	mov r9, r7
_08052C24:
	bl Random
	mov r4, r9
	ands r4, r0
	cmp r4, 0x70
	bhi _08052C24
	lsls r0, r4, 1
	adds r4, r0, r4
	ldr r6, =gUnknown_0831ACE8
	adds r3, r4, r6
	ldr r1, =gUnknown_02024258
	ldr r2, =gBankAttacker
	ldrb r5, [r2]
	lsls r0, r5, 1
	adds r0, r1
	ldrb r1, [r3]
	mov r10, r2
	ldrh r0, [r0]
	cmp r1, r0
	bne _08052C80
	adds r0, r4, 0x2
	adds r0, r6
	ldrb r0, [r0]
	cmp r0, 0x5
	bhi _08052C80
	ldr r7, =gBattleMons
	movs r2, 0x58
	adds r0, r5, 0
	muls r0, r2
	adds r3, r0, r7
	movs r0, 0x21
	adds r0, r3
	mov r12, r0
	adds r0, r4, 0x1
	adds r0, r6
	ldrb r5, [r0]
	mov r1, r12
	ldrb r0, [r1]
	adds r1, r5, 0
	cmp r0, r1
	beq _08052C80
	adds r0, r3, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, r1
	bne _08052BB4
_08052C80:
	movs r7, 0x1
	add r8, r7
	ldr r0, =0x000003e7
	cmp r8, r0
	ble _08052C24
	movs r0, 0
	mov r8, r0
	ldr r1, =gBattlescriptCurrInstr
	mov r12, r1
	ldr r3, =gUnknown_0831ACE8
	adds r0, r4, 0x1
	adds r0, r3
	mov r9, r0
	adds r5, r3, 0
_08052C9C:
	ldrb r1, [r5]
	cmp r1, 0xFF
	bgt _08052CA6
	cmp r1, 0xFE
	bge _08052CE0
_08052CA6:
	mov r4, r10
	ldrb r2, [r4]
	lsls r0, r2, 1
	ldr r7, =gUnknown_02024258
	adds r0, r7
	ldrh r0, [r0]
	cmp r1, r0
	bne _08052CE0
	ldrb r0, [r5, 0x2]
	cmp r0, 0x5
	bhi _08052CE0
	movs r6, 0x58
	adds r0, r2, 0
	muls r0, r6
	ldr r1, =gBattleMons
	adds r2, r0, r1
	adds r4, r2, 0
	adds r4, 0x21
	ldrb r0, [r4]
	mov r7, r9
	ldrb r1, [r7]
	cmp r0, r1
	beq _08052CE0
	adds r0, r2, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, r1
	beq _08052CE0
	b _08052BE0
_08052CE0:
	adds r5, 0x3
	movs r0, 0x3
	add r8, r0
	ldr r0, =0x0000014f
	cmp r8, r0
	bls _08052C9C
	mov r1, r12
	ldr r2, [r1]
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
	mov r4, r12
	str r1, [r4]
_08052D08:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA6_settypetorandomresistance

	thumb_func_start atkA7_setalwayshitflag
atkA7_setalwayshitflag: @ 8052D34
	push {r4,lr}
	ldr r4, =gStatuses3
	ldr r3, =gBankTarget
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r4
	ldr r0, [r1]
	movs r2, 0x19
	negs r2, r2
	ands r0, r2
	str r0, [r1]
	ldrb r1, [r3]
	lsls r1, 2
	adds r1, r4
	ldr r0, [r1]
	movs r2, 0x10
	orrs r0, r2
	str r0, [r1]
	ldr r2, =gDisableStructs
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gBankAttacker
	ldrb r1, [r1]
	strb r1, [r0, 0x15]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA7_setalwayshitflag

	thumb_func_start atkA8_copymovepermanently
atkA8_copymovepermanently: @ 8052D8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	ldr r0, =gUnknown_020241EC
	ldr r1, =0x0000ffff
	adds r5, r1, 0
	strh r5, [r0]
	ldr r3, =gBattleMons
	ldr r2, =gBankAttacker
	ldrb r1, [r2]
	movs r0, 0x58
	adds r4, r1, 0
	muls r4, r0
	adds r0, r3, 0
	adds r0, 0x50
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 14
	ands r1, r0
	mov r12, r3
	mov r10, r2
	cmp r1, 0
	beq _08052DC4
	b _08052F18
_08052DC4:
	ldr r0, =gUnknown_02024240
	ldr r2, =gBankTarget
	ldrb r1, [r2]
	lsls r1, 1
	adds r1, r0
	ldrh r1, [r1]
	mov r9, r0
	mov r8, r2
	cmp r1, 0xA5
	bne _08052DDA
	b _08052F18
_08052DDA:
	cmp r1, 0
	bne _08052DE0
	b _08052F18
_08052DE0:
	cmp r1, r5
	bne _08052DE6
	b _08052F18
_08052DE6:
	cmp r1, 0xA6
	bne _08052DEC
	b _08052F18
_08052DEC:
	movs r7, 0
	mov r5, r9
	mov r0, r12
	adds r0, 0xC
	adds r1, r4, r0
	mov r3, r8
_08052DF8:
	ldrh r2, [r1]
	cmp r2, 0xA6
	beq _08052E0A
	ldrb r0, [r3]
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	cmp r2, r0
	beq _08052E12
_08052E0A:
	adds r1, 0x2
	adds r7, 0x1
	cmp r7, 0x3
	ble _08052DF8
_08052E12:
	cmp r7, 0x4
	beq _08052E18
	b _08052F18
_08052E18:
	ldr r4, =gCurrMovePos
	ldrb r1, [r4]
	lsls r1, 1
	mov r2, r10
	ldrb r0, [r2]
	movs r3, 0x58
	muls r0, r3
	adds r1, r0
	mov r6, r12
	adds r6, 0xC
	adds r1, r6
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	strh r0, [r1]
	mov r1, r10
	ldrb r0, [r1]
	adds r2, r0, 0
	muls r2, r3
	ldrb r4, [r4]
	adds r2, r4
	mov r5, r12
	adds r5, 0x24
	adds r2, r5
	ldr r4, =gBattleMoves
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, 1
	add r0, r9
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x4]
	strb r0, [r2]
	ldr r1, =gActiveBank
	mov r2, r10
	ldrb r0, [r2]
	strb r0, [r1]
	movs r7, 0
	ldrb r0, [r2]
	muls r0, r3
	adds r4, r0, r5
	adds r3, r0, 0
	add r2, sp, 0x4
	add r5, sp, 0xC
_08052E7A:
	adds r0, r3, r6
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, r5, r7
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, 0x1
	adds r3, 0x2
	adds r2, 0x2
	adds r7, 0x1
	cmp r7, 0x3
	ble _08052E7A
	add r2, sp, 0x4
	mov r0, r10
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	add r0, r12
	adds r0, 0x3B
	ldrb r0, [r0]
	strb r0, [r2, 0xC]
	str r2, [sp]
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	movs r3, 0x10
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	ldr r3, =gUnknown_02024240
	ldr r2, =gBankTarget
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	strb r0, [r1, 0x2]
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	lsrs r0, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x5
	str r0, [r1]
	b _08052F32
	.pool
_08052F18:
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
_08052F32:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkA8_copymovepermanently

	thumb_func_start sub_8052F48
sub_8052F48: @ 8052F48
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
	thumb_func_end sub_8052F48

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

	thumb_func_start move_weather_interaction
move_weather_interaction: @ 8052FAC
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
	thumb_func_end move_weather_interaction

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
	bl sub_8052F48
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

	thumb_func_start b_feature_update_destiny_bond
b_feature_update_destiny_bond: @ 8053180
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
	thumb_func_end b_feature_update_destiny_bond

	thumb_func_start atkAB_DestinyBondFlagUpdate
atkAB_DestinyBondFlagUpdate: @ 80531E0
	push {lr}
	bl b_feature_update_destiny_bond
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl GetBankByPlayerAI
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
	bl GetBankByPlayerAI
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
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
	ldr r1, =gUnknown_02024268
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
	ldr r0, =gUnknown_02024212
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
	bl GetBankByPlayerAI
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
	ldr r0, =gUnknown_02024274
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
	ldr r0, =gUnknown_020243D0
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
	bl b_movescr_stack_push_cursor
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
	bl b_movescr_stack_push_cursor
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
	bl b_movescr_stack_push_cursor
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
	ldr r0, =gUnknown_020243D0
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
	ldr r0, =gUnknown_020243D0
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
	bl dp01_build_cmdbuf_x18_0_aa_health_bar_update
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
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
	ldr r3, =gUnknown_082D86A8
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
	bl b_movescr_stack_push
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl GetBankByPlayerAI
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
	ldr r0, =gUnknown_020243D0
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
	ldr r0, =gUnknown_082DB63F
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldr r1, =gBankAttacker
	ldrb r0, [r1]
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r7]
	bl dp01_battle_side_mark_buffer_for_execution
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
	ldr r1, =gUnknown_020243D0
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
	ldr r0, =gUnknown_020243D0
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
	bl sub_80C0630
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
	ldr r0, =gUnknown_0831C3E0
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
	ldr r0, =gUnknown_02024082
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
	ldr r0, =gUnknown_02024082
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
	bl get_battle_side_of_something
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl get_battle_side_of_something
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
	bl dp01_build_cmdbuf_x34_a_bb_aka_battle_anim
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl castform_switch
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08055E8E
	ldr r0, =gUnknown_082DB4A9
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r7]
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl GetBankByPlayerAI
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
	ldr r1, =gUnknown_02024274
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
	ldr r1, =gUnknown_0202420E
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
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl pokedex_flag_operation
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
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl dp01_battle_side_mark_buffer_for_execution
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
	bl pokedex_flag_operation
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
	bl SetPokedexFlag
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
	ldr r0, =sub_8038420
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

	thumb_func_start sub_8056B74
sub_8056B74: @ 8056B74
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
	thumb_func_end sub_8056B74

	thumb_func_start sub_8056BAC
sub_8056BAC: @ 8056BAC
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
	thumb_func_end sub_8056BAC

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
	ldr r0, =gUnknown_085CCABB
	movs r1, 0xC
	bl battle_show_message_maybe
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	strb r4, [r1, 0x1]
	movs r0, 0
	bl sub_8056B74
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
	bl sub_8056BAC
	movs r0, 0
	strb r0, [r4, 0x1]
	bl sub_8056B74
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
	bl sub_8056BAC
	movs r0, 0x1
	strb r0, [r4, 0x1]
	bl sub_8056B74
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
	ldr r0, =sub_8038420
	str r0, [sp, 0x4]
	movs r0, 0x2
	adds r2, r6, 0
	adds r3, r5, 0
	bl do_choose_name_or_words_screen
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08056E62
	.pool
_08056DD4:
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
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
	ldr r1, =gUnknown_02024082
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
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	movs r0, 0
	bl dp01_build_cmdbuf_x09_9_9_9
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8056EF8

    
	.align 2, 0 @ Don't pad with nop.
