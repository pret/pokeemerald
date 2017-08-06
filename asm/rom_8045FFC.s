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
	ldr r0, =gUnknown_0202433A
	ldrb r0, [r0]
	cmp r0, 0
	beq _08046020
	ldr r1, =gUnknown_02024083
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
	bl AtkCanceller_UnableToUseMove
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
	ldr r0, =gUnknown_020241E8
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
	ldr r0, =gUnknown_0202437C
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
	ldr r4, =gUnknown_0202420A
	movs r0, 0x1F
	strb r0, [r4]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB53E
	str r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	ldrb r1, [r4]
	bl b_history__record_ability_usage_of_player
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
	ldr r1, =gUnknown_02024474
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

	thumb_func_start atk40_801DBA0
atk40_801DBA0: @ 804643C
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
	thumb_func_end atk40_801DBA0

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
	ldr r0, =gUnknown_0202449C
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
	ldr r1, =gUnknown_0831C0F4
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
	bl itemid_get_quality
	lsls r0, 24
	lsrs r2, r0, 24
_08046944:
	ldr r0, =gStringBank
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
	ldr r0, =gUnknown_02024068
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
	ldr r0, =gUnknown_02024068
	ldr r0, [r0]
	cmp r0, 0
	beq _08046A54
	b _08046BEE
_08046A54:
	ldr r1, =gUnknown_0202437C
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
	ldr r3, =gUnknown_020241E8
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
	bl EmitSetAttributes
	mov r7, r9
	ldrb r0, [r7]
	bl MarkBufferBankForExecution
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
	ldr r1, =gStringBank
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
	ldr r2, =gUnknown_0831C128
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

	thumb_func_start atk05_cmd5
atk05_cmd5: @ 8046D8C
	push {r4-r7,lr}
	sub sp, 0x10
	ldr r4, =gSideAffecting
	ldr r5, =gBankTarget
	ldrb r0, [r5]
	bl battle_get_per_side_status
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
	ldr r4, =gUnknown_02024400
	ldrh r4, [r4]
	str r4, [sp]
	ldr r4, =gUnknown_0202449C
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
	ldr r0, =gUnknown_02024474
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
	thumb_func_end atk05_cmd5

	thumb_func_start sub_8046E7C
sub_8046E7C: @ 8046E7C
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
	bl battle_get_per_side_status
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
	ldr r6, =gUnknown_02024400
	ldrh r4, [r6]
	str r4, [sp]
	ldr r4, =gUnknown_0202449C
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
	ldr r0, =gUnknown_02024474
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
	thumb_func_end sub_8046E7C

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

	thumb_func_start sub_8047038
sub_8047038: @ 8047038
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
	ldr r0, =gUnknown_0202449C
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
	ldr r3, =gUnknown_0202420A
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
	bl b_history__record_ability_usage_of_player
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
	ldr r3, =gUnknown_0202420A
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
	bl b_history__record_ability_usage_of_player
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
	thumb_func_end sub_8047038

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
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202420A
	strb r1, [r0]
	ldr r0, =gBattleCommunication
	mov r1, r12
	strb r1, [r0, 0x6]
	ldrb r0, [r3]
	movs r1, 0x1A
	bl b_history__record_ability_usage_of_player
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
	ldr r0, =gUnknown_0202420A
	strb r4, [r0]
	ldr r1, =gBattleCommunication
	movs r0, 0x3
	strb r0, [r1, 0x6]
	mov r1, r8
	ldrb r0, [r1]
	movs r1, 0x19
	bl b_history__record_ability_usage_of_player
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

	thumb_func_start move_effectiveness_something
move_effectiveness_something: @ 80475E4
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
	thumb_func_end move_effectiveness_something

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

	thumb_func_start atk07_cmd7
atk07_cmd7: @ 80478F4
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
	bl itemid_get_quality
	lsls r0, 24
	lsrs r6, r0, 24
_08047976:
	ldr r1, =gStringBank
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
	bl b_history__record_item_x12_of_player
	ldr r2, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	thumb_func_end atk07_cmd7

	thumb_func_start atk08_cmd8
atk08_cmd8: @ 8047AA4
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
	bl itemid_get_quality
	lsls r0, 24
	lsrs r6, r0, 24
_08047B26:
	ldr r1, =gStringBank
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
	bl b_history__record_item_x12_of_player
	ldr r2, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	thumb_func_end atk08_cmd8

	thumb_func_start atk09_attackanimation
atk09_attackanimation: @ 8047C30
	push {r4-r7,lr}
	sub sp, 0x10
	ldr r0, =gUnknown_02024068
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
	ldr r1, =gUnknown_02024474
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
	ldr r0, =gUnknown_02024474
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
	ldr r5, =gUnknown_02024474
	ldrb r2, [r5, 0x18]
	ldr r0, =gUnknown_020244E0
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
	bl MarkBufferBankForExecution
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

	thumb_func_start sub_8047DC8
sub_8047DC8: @ 8047DC8
	push {lr}
	ldr r0, =gUnknown_02024068
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
	thumb_func_end sub_8047DC8

	thumb_func_start atk0B_graphicalhpupdate
atk0B_graphicalhpupdate: @ 8047DE8
	push {r4,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08047EA2
	ldr r0, =gBattleMoveDamage
	ldr r0, [r0]
	cmp r0, 0
	ble _08047EA2
	ldr r0, =gUnknown_03005D10
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
	thumb_func_end atk0B_graphicalhpupdate

	thumb_func_start atk0C_datahpupdate
atk0C_datahpupdate: @ 8047EC4
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02024068
	ldr r0, [r0]
	cmp r0, 0
	beq _08047ED2
	b _080482A2
_08047ED2:
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	ldr r0, =gTakenDmg
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
	ldr r1, =gTakenDmgBanks
	ldrb r0, [r5]
	adds r0, r1
	ldr r1, =gBankAttacker
	b _080480DC
	.pool
_080480D4:
	ldr r1, =gTakenDmgBanks
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
	ldr r2, =gUnknown_0202437C
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
	ldr r1, =gUnknown_020240AC
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x2A
	movs r2, 0
	movs r3, 0x2
	bl EmitSetAttributes
	ldrb r0, [r5]
	bl MarkBufferBankForExecution
	b _0804829A
	.pool
_08048274:
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldr r2, =gUnknown_0202437C
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
	ldr r0, =gUnknown_02024068
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

	thumb_func_start atk0E_missmessage
atk0E_missmessage: @ 8048310
	push {r4,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
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
	thumb_func_end atk0E_missmessage

	thumb_func_start atk0F_resultmessage
atk0F_resultmessage: @ 80483E0
	push {r4-r7,lr}
	movs r3, 0
	ldr r0, =gUnknown_02024068
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
	ldr r1, =gStringBank
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
	ldr r1, =gStringBank
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
	ldr r0, =gUnknown_02024068
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

	thumb_func_start atk11_printstring2
atk11_printstring2: @ 80485D0
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
	bl MarkBufferBankForExecution
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
	thumb_func_end atk11_printstring2

	thumb_func_start atk12_waitmessage
atk12_waitmessage: @ 8048614
	push {r4-r6,lr}
	ldr r0, =gUnknown_02024068
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
	ldr r0, =gUnknown_02024068
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

	thumb_func_start atk14_printfromtable2
atk14_printfromtable2: @ 80486C4
	push {r4-r6,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	thumb_func_end atk14_printfromtable2

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

	thumb_func_start SetMoveEffect
SetMoveEffect: @ 8048760
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
	ldr r2, =gEffectBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, 0xBF
	ands r0, r3
	adds r3, r1, 0
	strb r0, [r3, 0x3]
	movs r7, 0x40
	ldr r1, =gUnknown_02024474
	ldr r0, =gBankTarget
	b _080487C4
	.pool
_080487B8:
	ldr r2, =gEffectBank
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, =gUnknown_02024474
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
	bl battle_get_per_side_status
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
	ldr r2, =gEffectBank
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
	ldr r1, =gUnknown_0831C134
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
	ldr r0, =gUnknown_0202420A
	strb r1, [r0]
	mov r3, r9
	ldrb r0, [r3]
	movs r1, 0x11
	bl b_history__record_ability_usage_of_player
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
	ldr r0, =gUnknown_0202420A
	strb r1, [r0]
	mov r3, r9
	ldrb r0, [r3]
	movs r1, 0x29
	bl b_history__record_ability_usage_of_player
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
	ldr r0, =gEffectBank
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
	ldr r0, =gUnknown_0202420A
	strb r2, [r0]
	mov r4, r9
	ldrb r0, [r4]
	movs r1, 0x7
	bl b_history__record_ability_usage_of_player
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
	ldr r1, =gUnknown_0831C134
	ldr r0, =gBattleCommunication
	ldrb r0, [r0, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r3, [r0]
	cmp r3, 0x7
	bne _08048E50
	bl Random
	ldr r2, =gBattleMons
	ldr r1, =gEffectBank
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
	ldr r0, =gEffectBank
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
	ldr r1, =gUnknown_0831C224
	ldr r5, =gBattleCommunication
	ldrb r0, [r5, 0x3]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r4, =gActiveBank
	ldr r1, =gEffectBank
	ldrb r0, [r1]
	strb r0, [r4]
	ldrb r1, [r1]
	movs r0, 0x58
	muls r0, r1
	ldr r1, =gUnknown_020240D0
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl EmitSetAttributes
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
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
	ldr r0, =gUnknown_0202449C
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
	ldr r2, =gUnknown_0831C134
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
	ldr r1, =gUnknown_0831C224
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
	ldr r0, =gUnknown_0202420A
	strb r1, [r0]
	mov r1, r9
	ldrb r0, [r1]
	movs r1, 0x27
	bl b_history__record_ability_usage_of_player
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
	ldr r1, =gUnknown_0831C134
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
	ldr r1, =gUnknown_0831C224
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
	bl battle_get_per_side_status
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
	ldr r1, =gUnknown_0831C224
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
	bl SetMoveEffect
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
	ldr r2, =gUnknown_0202449C
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
	ldr r1, =gUnknown_0831C224
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
	ldr r1, =gUnknown_0831C224
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
	ldr r2, =gUnknown_02024474
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
	ldr r2, =gUnknown_02024474
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
	ldr r2, =gUnknown_02024474
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
	ldr r2, =gUnknown_02024474
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
	ldr r0, =gWishFutureKnock
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
	ldr r1, =gUnknown_0202420A
	ldrb r0, [r7]
	muls r0, r5
	add r0, r8
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	ldrb r1, [r1]
	bl b_history__record_ability_usage_of_player
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
	ldr r5, =gUnknown_0202449C
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
	bl EmitSetAttributes
	mov r2, r10
	ldrb r0, [r2]
	bl MarkBufferBankForExecution
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
	bl EmitSetAttributes
	ldrb r0, [r7]
	bl MarkBufferBankForExecution
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
	bl EmitSetAttributes
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
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
	ldr r1, =gUnknown_0831C224
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
	ldr r0, =gUnknown_0202420A
	strb r2, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB63F
	str r0, [r1]
	ldrb r0, [r4]
	movs r1, 0x3C
	bl b_history__record_ability_usage_of_player
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
	ldr r2, =gWishFutureKnock
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
	ldr r2, =gUnknown_0202449C
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
	thumb_func_end SetMoveEffect

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
	bl SetMoveEffect
	b _08049AA2
	.pool
_08049A90:
	movs r0, 0
	movs r1, 0
	bl SetMoveEffect
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
	ldr r0, =gUnknown_02024474
	strb r1, [r0, 0x16]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk15_seteffectwithchancetarget

	thumb_func_start sub_8049AC0
sub_8049AC0: @ 8049AC0
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl SetMoveEffect
	pop {r0}
	bx r0
	thumb_func_end sub_8049AC0

	thumb_func_start sub_8049AD0
sub_8049AD0: @ 8049AD0
	push {lr}
	movs r0, 0
	movs r1, 0
	bl SetMoveEffect
	pop {r0}
	bx r0
	thumb_func_end sub_8049AD0

	thumb_func_start sub_8049AE0
sub_8049AE0: @ 8049AE0
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
	ldr r1, =gUnknown_0831C134
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
	ldr r0, =gUnknown_02024474
	strb r2, [r0, 0x16]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8049AE0

	thumb_func_start atk19_faintpokemon
atk19_faintpokemon: @ 8049B5C
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
	ldr r1, =gUnknown_03005D10
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
	ldr r4, =gUnknown_03005D10
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
	ldr r0, =gUnknown_0202449C
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
	bl EmitSetAttributes
	ldrb r0, [r5]
	bl MarkBufferBankForExecution
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
	thumb_func_end atk19_faintpokemon

	thumb_func_start sub_8049E40
sub_8049E40: @ 8049E40
	push {r4,r5,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
_08049E6A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8049E40

	thumb_func_start sub_8049E7C
sub_8049E7C: @ 8049E7C
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02024068
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
	bl EmitSetAttributes
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
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
	thumb_func_end sub_8049E7C

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

	thumb_func_start atk1D_jumpifsecondarystatus
atk1D_jumpifsecondarystatus: @ 8049F7C
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
	thumb_func_end atk1D_jumpifsecondarystatus

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
	ldr r1, =gUnknown_0202420A
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
	ldr r1, =gUnknown_0202420A
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
	ldr r0, =gUnknown_0202420A
	strb r1, [r0]
	str r7, [r6]
	ldrb r1, [r0]
	adds r0, r4, 0
_0804A0B0:
	bl b_history__record_ability_usage_of_player
	ldr r0, =gUnknown_02024474
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

	thumb_func_start sub_804A0DC
sub_804A0DC: @ 804A0DC
	push {r4-r6,lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r4, [r0, 0x1]
	cmp r4, 0x1
	bne _0804A0FC
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl battle_get_per_side_status
	b _0804A106
	.pool
_0804A0FC:
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	bl battle_get_per_side_status
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
	thumb_func_end sub_804A0DC

	thumb_func_start sub_804A154
sub_804A154: @ 804A154
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
	thumb_func_end sub_804A154

	thumb_func_start atk21_jumpifspecialstatusflag
atk21_jumpifspecialstatusflag: @ 804A24C
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
	thumb_func_end atk21_jumpifspecialstatusflag

	thumb_func_start sub_804A2D0
sub_804A2D0: @ 804A2D0
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
	thumb_func_end sub_804A2D0

	thumb_func_start sub_804A32C
sub_804A32C: @ 804A32C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r6, 0
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0x50
	mov r9, r0
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gBank1
	strb r0, [r1]
	ldr r2, =gUnknown_020243FE
	movs r1, 0x2
	ands r1, r0
	lsls r1, 24
	lsrs r1, 25
	adds r1, r2
	ldrb r1, [r1]
	mov r8, r1
	ldr r0, =gUnknown_02024474
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
	ldr r4, =gBank1
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
	ldr r1, =gUnknown_02024474
	ldrb r0, [r1, 0x1C]
	adds r0, 0x1
	strb r0, [r1, 0x1C]
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gBank1
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
	ldr r1, =gUnknown_02024474
	ldrb r0, [r1, 0x1C]
	adds r0, 0x1
	movs r2, 0
	strb r0, [r1, 0x1C]
	ldr r1, =gUnknown_0202449C
	ldr r0, [r1]
	strb r2, [r0, 0x10]
	ldr r0, [r1]
	adds r0, 0x53
	mov r4, r8
	strb r4, [r0]
_0804A52E:
	ldr r0, =gUnknown_02024068
	ldr r0, [r0]
	cmp r0, 0
	beq _0804A538
	b _0804ACB2
_0804A538:
	ldr r0, =gUnknown_0202449C
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
	ldr r5, =gUnknown_0202449C
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
	ldr r1, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
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
	bl song_play_for_text
	ldr r1, [r5]
	ldrb r0, [r1, 0x12]
	adds r0, 0x1
	strb r0, [r1, 0x12]
_0804A616:
	ldr r5, =gUnknown_0202449C
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
	ldr r4, =gUnknown_0202449C
	ldr r0, [r4]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl sub_806E8A8
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
	ldr r1, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202449C
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
	ldr r6, =gUnknown_0202449C
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
	ldr r1, =gUnknown_02022F68
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
	ldr r1, =gUnknown_02022F78
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
	ldr r1, =gBank1
	ldrb r2, [r1]
	movs r1, 0x58
	muls r1, r2
	adds r1, r3
	ldrh r1, [r1]
	bl sub_806DADC
_0804A824:
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	adds r1, 0x53
	ldrb r0, [r1]
	lsrs r0, 1
	strb r0, [r1]
	b _0804A92A
	.pool
_0804A850:
	ldr r0, =gUnknown_02024068
	ldr r2, [r0]
	cmp r2, 0
	beq _0804A85A
	b _0804ACB2
_0804A85A:
	ldr r1, =gBattleBufferB
	ldr r7, =gUnknown_0202449C
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
	ldr r4, =gBattleStruct
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
	bl MarkBufferBankForExecution
_0804A92A:
	ldr r1, =gUnknown_02024474
	ldrb r0, [r1, 0x1C]
	adds r0, 0x1
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804A954:
	ldr r0, =gUnknown_02024068
	ldr r0, [r0]
	cmp r0, 0
	beq _0804A95E
	b _0804ACB2
_0804A95E:
	ldr r1, =gActiveBank
	ldr r0, =gUnknown_0202449C
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
	ldr r4, =gUnknown_0202449C
	mov r9, r4
	ldr r2, [r4]
	ldrb r0, [r2, 0x10]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r4, =gUnknown_02022F68
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
	bl happiness_algorithm
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
	ldr r7, =gUnknown_0202449C
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
	ldr r1, =gUnknown_02024474
	movs r0, 0x5
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC40:
	ldr r0, =gBattleMoveDamage
	ldr r0, [r0]
	cmp r0, 0
	beq _0804AC58
	ldr r1, =gUnknown_02024474
	movs r0, 0x3
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC58:
	ldr r2, =gUnknown_0202449C
	ldr r1, [r2]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
	ldr r0, [r2]
	ldrb r0, [r0, 0x10]
	cmp r0, 0x5
	bhi _0804AC7C
	ldr r1, =gUnknown_02024474
	movs r0, 0x2
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC7C:
	ldr r1, =gUnknown_02024474
	movs r0, 0x6
	strb r0, [r1, 0x1C]
	b _0804ACB2
	.pool
_0804AC88:
	ldr r0, =gUnknown_02024068
	ldr r5, [r0]
	cmp r5, 0
	bne _0804ACB2
	ldr r4, =gBattleMons
	ldr r2, =gBank1
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
	thumb_func_end sub_804A32C

	thumb_func_start sub_804ACD0
sub_804ACD0: @ 804ACD0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r0, =gUnknown_02024068
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
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202433A
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
	ldr r0, =gUnknown_0202449C
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
	ldr r2, =gUnknown_0202433A
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
	ldr r1, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	thumb_func_end sub_804ACD0

	thumb_func_start sub_804AF30
sub_804AF30: @ 804AF30
	ldr r1, =gBattleMoveFlags
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gUnknown_02024474
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

	thumb_func_start atk25_cmd25
atk25_cmd25: @ 804AF70
	push {lr}
	bl sub_804AF30
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk25_cmd25

	thumb_func_start atk26_80225F0_storebyteforjump
atk26_80225F0_storebyteforjump: @ 804AF88
	ldr r3, =gUnknown_02024212
	ldr r2, =gBattlescriptCurrInstr
	ldr r0, [r2]
	ldrb r1, [r0, 0x1]
	strb r1, [r3]
	adds r0, 0x2
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end atk26_80225F0_storebyteforjump

	thumb_func_start atk27_cmd27
atk27_cmd27: @ 804AFA0
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
	thumb_func_end atk27_cmd27

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

	thumb_func_start sub_804B0A8
sub_804B0A8: @ 804B0A8
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
	thumb_func_end sub_804B0A8

	thumb_func_start sub_804B150
sub_804B150: @ 804B150
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
	thumb_func_end sub_804B150

	thumb_func_start sub_804B204
sub_804B204: @ 804B204
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
	thumb_func_end sub_804B204

	thumb_func_start sub_804B28C
sub_804B28C: @ 804B28C
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
	thumb_func_end sub_804B28C

	thumb_func_start sub_804B310
sub_804B310: @ 804B310
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
	thumb_func_end sub_804B310

	thumb_func_start sub_804B338
sub_804B338: @ 804B338
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
	thumb_func_end sub_804B338

	thumb_func_start sub_804B364
sub_804B364: @ 804B364
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
	thumb_func_end sub_804B364

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

	thumb_func_start atk32_memcpy_with_offset
atk32_memcpy_with_offset: @ 804B3E4
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
	thumb_func_end atk32_memcpy_with_offset

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
	ldr r0, =gUnknown_02024068
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

	thumb_func_start sub_804B5E0
sub_804B5E0: @ 804B5E0
	push {lr}
	ldr r0, =gUnknown_02024068
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
	thumb_func_end sub_804B5E0

	thumb_func_start atk3B_8022C68
atk3B_8022C68: @ 804B600
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
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk3B_8022C68

	thumb_func_start atk3C_return
atk3C_return: @ 804B658
	push {lr}
	bl b_movescr_stack_pop_cursor
	pop {r0}
	bx r0
	thumb_func_end atk3C_return

	thumb_func_start sub_804B664
sub_804B664: @ 804B664
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
	ldr r1, =gUnknown_02024083
	movs r0, 0xB
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804B664

	thumb_func_start atk3E_end2
atk3E_end2: @ 804B6A4
	ldr r1, =gActiveBank
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_02024083
	movs r0, 0xB
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end atk3E_end2

	thumb_func_start atk3F_end3
atk3F_end3: @ 804B6BC
	push {lr}
	bl b_movescr_stack_pop_cursor
	ldr r3, =gBattleStruct
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

	thumb_func_start sub_804B784
sub_804B784: @ 804B784
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
	thumb_func_end sub_804B784

	thumb_func_start sub_804B7D0
sub_804B7D0: @ 804B7D0
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x54
	movs r1, 0x1
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_804B7D0

	thumb_func_start atk46_cmd46
atk46_cmd46: @ 804B7EC
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x7
_0804B8A8:
	str r0, [r5]
_0804B8AA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end atk46_cmd46

	thumb_func_start sub_804B8B0
sub_804B8B0: @ 804B8B0
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	ldr r0, [r6]
_0804B972:
	adds r0, 0xA
	str r0, [r6]
_0804B976:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_804B8B0

	thumb_func_start sub_804B97C
sub_804B97C: @ 804B97C
	push {r4,lr}
	movs r3, 0
	ldr r1, =gUnknown_02024474
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
	thumb_func_end sub_804B97C

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
	ldr r0, =gBattleMons+0x18
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
	bl battle_get_per_side_status
	mov r1, r10
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSideTimer
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
	ldr r6, =gBattleMons+0x18
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
	ldr r4, =gUnknown_02024474
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
	bl MarkBufferBankForExecution
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

	thumb_func_start sub_804BBCC
sub_804BBCC: @ 804BBCC
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
	ldr r1, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
	b _0804C15A
	.pool
_0804BC80:
	ldr r4, =gActiveBank
	strb r2, [r4]
	movs r0, 0
	movs r1, 0
	bl dp01_build_cmdbuf_x33_a_33_33
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
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
	ldr r0, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
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
	ldr r2, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	bl EmitSetAttributes
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
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
	ldr r0, =gUnknown_02024474
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
	ldr r7, =gUnknown_0202449C
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
	bl ItemBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _0804C184
	movs r2, 0x1
	mov r10, r2
	ldr r3, =gUnknown_02024474
	mov r12, r3
	b _0804C570
	.pool
_0804C0A8:
	movs r0, 0x4
	movs r1, 0
	movs r2, 0
	bl ItemBattleEffects
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
	bl MarkBufferBankForExecution
	ldr r0, =gStatuses3
	ldrb r2, [r5]
	lsls r2, 2
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xfffbff3f
	ands r0, r1
	str r0, [r2]
	ldr r2, =gUnknown_0202437C
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
	ldr r1, =gUnknown_02024474
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	b _0804C5BA
	.pool
_0804C184:
	ldr r1, =gUnknown_02024474
	ldrb r0, [r1, 0x14]
	adds r0, 0x1
	strb r0, [r1, 0x14]
	mov r12, r1
	b _0804C570
	.pool
_0804C194:
	ldr r0, =gUnknown_0202437C
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
	ldr r1, =gUnknown_020240D4
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
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gLastUsedMove
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
	ldr r1, =gLastUsedMove
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
	ldr r6, =gUnknown_0202449C
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
	bl battle_get_per_side_status
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
	ldr r2, =gUnknown_02024474
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
	thumb_func_end sub_804BBCC

	thumb_func_start atk4A_damagecalc2
atk4A_damagecalc2: @ 804C5F4
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
	ldr r3, =gUnknown_0202420A
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
	bl b_history__record_ability_usage_of_player
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
	ldr r3, =gUnknown_0202420A
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
	bl b_history__record_ability_usage_of_player
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
	thumb_func_end atk4A_damagecalc2

	thumb_func_start atk4B_cmd4b
atk4B_cmd4b: @ 804C844
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
	bl MarkBufferBankForExecution
_0804C872:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk4B_cmd4b

	thumb_func_start atk4C_switch1
atk4C_switch1: @ 804C894
	push {r4,r5,lr}
	ldr r0, =gUnknown_02024068
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
	ldr r1, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
_0804C8E4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk4C_switch1

	thumb_func_start sub_804C904
sub_804C904: @ 804C904
	push {r4-r7,lr}
	sub sp, 0x58
	ldr r0, =gUnknown_02024068
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
	bl sub_806B694
	ldrb r1, [r6]
	muls r1, r7
	adds r1, r4
	adds r1, 0x20
	strb r0, [r1]
	ldrb r0, [r6]
	bl GetBankSide
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gWishFutureKnock
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
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_02024474
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
	thumb_func_end sub_804C904

	thumb_func_start atk4E_switch3
atk4E_switch3: @ 804CAE8
	push {r4-r6,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	thumb_func_end atk4E_switch3

	thumb_func_start atk4F_jumpifcannotswitch
atk4F_jumpifcannotswitch: @ 804CBB0
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
	thumb_func_end atk4F_jumpifcannotswitch

	thumb_func_start sub_804CF10
sub_804CF10: @ 804CF10
	push {r4,r5,lr}
	sub sp, 0x4
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r4, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	b _0804D098
	.pool
_0804D054:
	ldr r5, =gUnknown_0202437C
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	b _0804D170
	.pool
_0804D120:
	ldr r6, =gUnknown_0202437C
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D15C
	ldr r0, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	b _0804D22E
	.pool
_0804D1D8:
	ldr r6, =gUnknown_0202437C
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D214
	ldr r0, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	b _0804D2E4
	.pool
_0804D290:
	ldr r6, =gUnknown_0202437C
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D2CC
	ldr r0, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	b _0804D3A2
	.pool
_0804D34C:
	ldr r6, =gUnknown_0202437C
	ldrb r0, [r4]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D388
	ldr r0, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
_0804D3A2:
	ldr r1, =gUnknown_0202437C
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
	bl MarkBufferBankForExecution
_0804D3FA:
	ldr r1, =gUnknown_0202437C
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	b _0804D52A
	.pool
_0804D4F8:
	ldr r4, =gUnknown_0202437C
	ldrb r0, [r6]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D52A
	ldr r0, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
	b _0804D5DA
	.pool
_0804D5A8:
	ldr r4, =gUnknown_0202437C
	ldrb r0, [r5]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 25
	cmp r0, 0
	blt _0804D5DA
	ldr r0, =gUnknown_0202449C
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
	ldr r1, =gBank1
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
	ldr r1, =gUnknown_0202437C
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
	ldr r3, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
	ldr r0, [r6]
	adds r0, 0x6
	str r0, [r6]
	ldrb r0, [r4]
	bl battle_get_per_side_status
	lsls r0, 24
	cmp r0, 0
	bne _0804D760
	ldr r1, =gUnknown_03005D10
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
	bl MarkBufferBankForExecution
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
	bl battle_get_per_side_status
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
	bl MarkBufferBankForExecution
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

	thumb_func_start atk51_cmd51
atk51_cmd51: @ 804D820
	push {r4-r7,lr}
	ldr r0, =gUnknown_02024068
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
	ldr r5, =gUnknown_0202449C
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
	ldr r4, =gUnknown_0202449C
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
	ldr r1, =gUnknown_0202449C
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
	ldr r2, =gUnknown_02022F68
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
	thumb_func_end atk51_cmd51

	thumb_func_start atk52_cmd52
atk52_cmd52: @ 804DAAC
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
	ldr r2, =gUnknown_0202437C
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
	ldr r2, =gSideTimer
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
	ldr r0, =gUnknown_02024474
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
	bl ItemBattleEffects
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
	ldr r6, =gUnknown_0202449C
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
	ldr r1, =gBank1
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
	thumb_func_end atk52_cmd52

	thumb_func_start sub_804DDA8
sub_804DDA8: @ 804DDA8
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804DDA8

	thumb_func_start atk54_802511C
atk54_802511C: @ 804DDD8
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
	bl MarkBufferBankForExecution
	ldr r0, [r4]
	adds r0, 0x3
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk54_802511C

	thumb_func_start sub_804DE14
sub_804DE14: @ 804DE14
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
	bl MarkBufferBankForExecution
	ldr r0, [r4]
	adds r0, 0x3
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804DE14

	thumb_func_start atk56_8025194
atk56_8025194: @ 804DE50
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk56_8025194

	thumb_func_start atk57_80251C4_flee
atk57_80251C4_flee: @ 804DE80
	push {r4,lr}
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r4, =gActiveBank
	strb r0, [r4]
	ldr r0, =gUnknown_0202433A
	ldrb r1, [r0]
	movs r0, 0
	bl dp01_build_cmdbuf_x37_a
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
	thumb_func_end atk57_80251C4_flee

	thumb_func_start atk58_cmd58
atk58_cmd58: @ 804DEB8
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk58_cmd58

	thumb_func_start atk59_8025230
atk59_8025230: @ 804DEEC
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
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r2, 0x9]
	bl sub_8069318
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000fffe
	cmp r5, r0
	bne _0804DF56
	adds r7, r5, 0
_0804DF3A:
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	bl sub_8069318
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
	ldr r1, =gUnknown_0202449C
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
	bl sub_80691B0
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
	ldr r1, =gUnknown_0202449C
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
	bl sub_80691B0
_0804E014:
	ldr r0, =gBattlescriptCurrInstr
	str r6, [r0]
_0804E018:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk59_8025230

	thumb_func_start sub_804E038
sub_804E038: @ 804E038
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r0, =gActiveBank
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
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
	bl audio_play
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
	bl audio_play
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
	bl audio_play
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
	bl audio_play
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
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	ldrb r1, [r1, 0x10]
	ldr r2, =gUnknown_020244E9
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_80A92F8
	ldr r4, =gUnknown_020244E2
	ldrh r4, [r4]
	str r4, [sp]
	bl sub_81BFA38
_0804E192:
	ldr r1, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
	movs r0, 0x5
	strb r0, [r1, 0x1F]
	b _0804E3B8
	.pool
_0804E224:
	ldr r6, =gUnknown_0202449C
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
	bl sub_806E804
	cmp r0, 0
	beq _0804E274
	ldr r0, =0x0000013f
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	bl b_std_message
	ldr r1, =gUnknown_02024474
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
	ldr r1, =gUnknown_02022F68
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
	bl sub_806B9A8
	ldr r0, [r6]
	ldrb r0, [r0, 0x10]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r7
	ldr r7, =gUnknown_020244E2
	ldrh r1, [r7]
	adds r2, r5, 0
	bl sub_80691F4
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
	bl sub_806B9E4
	ldrh r1, [r7]
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8069234
_0804E30A:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0804E3B8
	ldr r2, =gBattlePartyID
	ldr r0, =gUnknown_0202449C
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
	bl sub_806B9E4
	ldr r0, =gUnknown_020244E2
	ldrh r1, [r0]
	adds r0, r4, 0
	adds r2, r5, 0
	bl sub_8069234
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
	ldr r0, =gUnknown_02024068
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
	thumb_func_end sub_804E038

	thumb_func_start atk5B_80256E0
atk5B_80256E0: @ 804E3C8
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gUnknown_02024474
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
	bl audio_play
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
	bl audio_play
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
	bl audio_play
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
	bl audio_play
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

	thumb_func_start atk5C_cmd5c
atk5C_cmd5c: @ 804E508
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
	bl MarkBufferBankForExecution
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
	thumb_func_end atk5C_cmd5c

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
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x94
	ldrb r2, [r0]
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202449C
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

	thumb_func_start sub_804E6D8
sub_804E6D8: @ 804E6D8
	push {r4,lr}
	ldr r0, =gUnknown_02038BCA
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
	ldr r0, =gUnknown_02038BCC
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
	thumb_func_end sub_804E6D8

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
	bl MarkBufferBankForExecution
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _0804E800
_0804E7AC:
	ldr r0, =gUnknown_02024068
	ldr r0, [r0]
	cmp r0, 0
	bne _0804E800
	ldrb r0, [r6]
	lsls r0, 9
	ldr r1, =gUnknown_02023868
	adds r0, r1
	mov r12, r0
	movs r2, 0
	adds r4, r6, 0
	movs r5, 0x58
	ldr r6, =gBattleMons+0x24
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

	thumb_func_start atk60_cmd60
atk60_cmd60: @ 804E868
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
	bl sav12_xor_increment
_0804E882:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x2
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk60_cmd60

	thumb_func_start atk61_8025BA4
atk61_8025BA4: @ 804E898
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x30
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk62_08025C6C

	thumb_func_start atk63_jumptoattack
atk63_jumptoattack: @ 804E990
	push {r4,lr}
	ldr r0, =gBattlescriptCurrInstr
	ldr r1, [r0]
	ldrb r1, [r1, 0x1]
	adds r4, r0, 0
	cmp r1, 0
	beq _0804E9B4
	ldr r0, =gCurrentMove
	ldr r1, =gUnknown_020241EE
	ldrh r1, [r1]
	strh r1, [r0]
	b _0804E9C2
	.pool
_0804E9B4:
	ldr r2, =gUnknown_020241EC
	ldr r1, =gCurrentMove
	ldr r0, =gUnknown_020241EE
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
	thumb_func_end atk63_jumptoattack

	thumb_func_start atk64_statusanimation
atk64_statusanimation: @ 804E9F4
	push {r4,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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

	thumb_func_start atk65_8025D90
atk65_8025D90: @ 804EA84
	push {r4,r5,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	thumb_func_end atk65_8025D90

	thumb_func_start atk66_8025E38
atk66_8025E38: @ 804EB2C
	push {r4,r5,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	thumb_func_end atk66_8025E38

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
	bl audio_play
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
	bl audio_play
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
	bl audio_play
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

	thumb_func_start sub_804ECA4
sub_804ECA4: @ 804ECA4
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
	thumb_func_end sub_804ECA4

	thumb_func_start atk69_8025FE0
atk69_8025FE0: @ 804ECDC
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
	bl itemid_get_quality
	lsls r0, 24
	lsrs r6, r0, 24
_0804ED2A:
	ldr r1, =gStringBank
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
	bl b_history__record_item_x12_of_player
	ldr r2, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202437C
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
	thumb_func_end atk69_8025FE0

	thumb_func_start atk6A_stash_item_for_side
atk6A_stash_item_for_side: @ 804EE58
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, =gBattlescriptCurrInstr
	ldr r0, [r6]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r5, =gActiveBank
	strb r0, [r5]
	ldr r1, =gUnknown_0202449C
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
	bl EmitSetAttributes
	ldrb r0, [r5]
	bl MarkBufferBankForExecution
	ldr r0, [r6]
	adds r0, 0x2
	str r0, [r6]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk6A_stash_item_for_side

	thumb_func_start atk6B_end_battle_80261CC
atk6B_end_battle_80261CC: @ 804EEC8
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
	thumb_func_end atk6B_end_battle_80261CC

	thumb_func_start atk6C_8026208
atk6C_8026208: @ 804EF04
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
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
	bl audio_play
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
	bl audio_play
	movs r0, 0x81
	str r0, [sp]
	movs r0, 0x12
	movs r1, 0x7
	movs r2, 0x1D
	movs r3, 0x13
	bl sub_8056A3C
_0804F06A:
	ldr r1, =gUnknown_02024474
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
	ldr r1, =gUnknown_02024474
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
	thumb_func_end atk6C_8026208

	thumb_func_start sub_804F100
sub_804F100: @ 804F100
	push {lr}
	sub sp, 0x14
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	add r1, sp, 0x8
	bl sub_81D388C
	ldr r0, =gBattleStruct
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
	ldr r0, =gUnknown_0202449C
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
	ldr r6, =gUnknown_0202449C
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
	bl pokemon_get_gender
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
	ldr r0, =gUnknown_0202449C
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
	bl LoadObjectPic
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	ldr r0, =gUnknown_0831C3C0
	movs r1, 0x80
	lsls r1, 1
	movs r2, 0xA
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02020630
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
	bl RemoveObjectAndFreeTiles
	ldr r4, =0x0000d75a
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
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
	ldr r0, =gUnknown_0202449C
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

	thumb_func_start sub_804F4D4
sub_804F4D4: @ 804F4D4
	push {lr}
	bl sub_803F988
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_804F4D4

	thumb_func_start atk6E_state0_side_becomes_attacker
atk6E_state0_side_becomes_attacker: @ 804F4EC
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
	thumb_func_end atk6E_state0_side_becomes_attacker

	thumb_func_start atk6F_8026810
atk6F_8026810: @ 804F50C
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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk6F_8026810

	thumb_func_start atk70_record_ability_usage_of_side
atk70_record_ability_usage_of_side: @ 804F540
	push {r4,lr}
	ldr r4, =gBattlescriptCurrInstr
	ldr r0, [r4]
	ldrb r0, [r0, 0x1]
	bl get_battle_side_of_something
	ldr r1, =gActiveBank
	strb r0, [r1]
	ldrb r0, [r1]
	ldr r1, =gUnknown_0202420A
	ldrb r1, [r1]
	bl b_history__record_ability_usage_of_player
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk70_record_ability_usage_of_side

	thumb_func_start sub_804F574
sub_804F574: @ 804F574
	ldr r2, =gUnknown_02022F68
	movs r0, 0xFD
	strb r0, [r2]
	movs r0, 0x2
	strb r0, [r2, 0x1]
	ldr r0, =gUnknown_020244E2
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

	thumb_func_start atk71_80268A0
atk71_80268A0: @ 804F59C
	push {lr}
	bl sub_804F574
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atk71_80268A0

	thumb_func_start atk72_flee
atk72_flee: @ 804F5B4
	push {lr}
	ldr r0, =gBank1
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
	thumb_func_end atk72_flee

	thumb_func_start atk73_cmd73
atk73_cmd73: @ 804F5F8
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
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0xB1
	strb r4, [r0]
	b _0804F68E
	.pool
_0804F65C:
	cmp r0, 0x27
	ble _0804F670
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0xB1
	strb r6, [r0]
	b _0804F68E
	.pool
_0804F670:
	cmp r0, 0x9
	ble _0804F684
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0xB1
	movs r1, 0x2
	b _0804F68C
	.pool
_0804F684:
	ldr r0, =gUnknown_0202449C
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
	thumb_func_end atk73_cmd73

	thumb_func_start atk74_hp_tresholds_2
atk74_hp_tresholds_2: @ 804F6A4
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
	ldr r1, =gUnknown_0202449C
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
	thumb_func_end atk74_hp_tresholds_2

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

	thumb_func_start sub_804F7AC
sub_804F7AC: @ 804F7AC
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
	ldr r2, =gSideTimer
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
	ldr r4, =gUnknown_0202437C
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
	ldr r1, =gUnknown_0202449C
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
	ldr r1, =gUnknown_02024474
	ldr r6, =gActiveBank
	ldrb r0, [r2, 0x1]
	strb r0, [r6]
	strb r0, [r1, 0x17]
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202449C
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
	ldr r5, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
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
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
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
	bl sub_80A3678
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
	bl MarkBufferBankForExecution
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
	ldr r0, =gUnknown_0202449C
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
	ldr r1, =gUnknown_0202433A
	movs r0, 0x5
	strb r0, [r1]
	b _0804FD70
	.pool
_0804FD50:
	ldr r1, =gUnknown_0202433A
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
	bl MarkBufferBankForExecution
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
	thumb_func_end sub_804F7AC

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
	ldr r2, =gUnknown_0831C3D8
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
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	ldr r1, =gUnknown_0202420A
	movs r0, 0x6
	strb r0, [r1]
	ldrb r0, [r5]
	movs r1, 0x58
	muls r1, r0
	adds r1, r6
	adds r1, 0x20
	ldrb r1, [r1]
	bl b_history__record_ability_usage_of_player
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

	thumb_func_start atk79_setuserhptozero
atk79_setuserhptozero: @ 804FFE4
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_02024068
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
	bl EmitSetAttributes
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
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
	thumb_func_end atk79_setuserhptozero

	thumb_func_start sub_8050044
sub_8050044: @ 8050044
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
	thumb_func_end sub_8050044

	thumb_func_start sub_80500E8
sub_80500E8: @ 80500E8
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
	thumb_func_end sub_80500E8

	thumb_func_start sub_8050164
sub_8050164: @ 8050164
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
	ldr r0, =gUnknown_0202449C
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
	ldr r2, =gUnknown_0202449C
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
	ldr r2, =gUnknown_0202437C
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
	thumb_func_end sub_8050164

	thumb_func_start sub_80502C8
sub_80502C8: @ 80502C8
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
	ldr r0, =gWishFutureKnock
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
	thumb_func_end sub_80502C8

	thumb_func_start atk7E_setreflect
atk7E_setreflect: @ 805031C
	push {r4-r6,lr}
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	bl battle_get_per_side_status
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
	bl battle_get_per_side_status
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r6]
	bl battle_get_per_side_status
	ldr r4, =gSideTimer
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x5
	strb r1, [r0]
	ldrb r0, [r6]
	bl battle_get_per_side_status
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
	bl sub_8069DEC
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

	thumb_func_start sub_80503E8
sub_80503E8: @ 80503E8
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
	thumb_func_end sub_80503E8

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
	bl EmitSetAttributes
	ldrb r0, [r7]
	bl MarkBufferBankForExecution
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

	thumb_func_start sub_8050640
sub_8050640: @ 8050640
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8050640

	thumb_func_start UproarWakeUpCheck
UproarWakeUpCheck: @ 8050650
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
	ldr r6, =gUnknown_02024474
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
	thumb_func_end UproarWakeUpCheck

	thumb_func_start sub_80506EC
sub_80506EC: @ 80506EC
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
	bl UproarWakeUpCheck
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
	ldr r2, =gUnknown_0202420A
	strb r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	str r4, [r5]
	ldrb r1, [r2]
	adds r0, r3, 0
	bl b_history__record_ability_usage_of_player
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
	thumb_func_end sub_80506EC

	thumb_func_start sub_8050768
sub_8050768: @ 8050768
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
	thumb_func_end sub_8050768

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
	bl battle_get_per_side_status
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
	ldr r2, =gUnknown_02024474
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

	thumb_func_start atk87_stockpiletohprecovery
atk87_stockpiletohprecovery: @ 8050904
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
	ldr r3, =gUnknown_02024474
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
	thumb_func_end atk87_stockpiletohprecovery

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
	ldr r4, =gSideTimer
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	bl battle_get_per_side_status
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
	ldr r4, =gUnknown_0202437C
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
	ldr r1, =gUnknown_02024474
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
	ldr r4, =gUnknown_0202437C
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
	ldr r1, =gUnknown_02024474
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB5C7
	str r0, [r1]
	ldr r1, =gUnknown_0202420A
	ldrb r0, [r2]
	movs r3, 0x58
	muls r0, r3
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	ldrb r1, [r1]
	bl b_history__record_ability_usage_of_player
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
	ldr r1, =gUnknown_02024474
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB62F
	str r0, [r1]
	ldr r1, =gUnknown_0202420A
	ldrb r0, [r3]
	muls r0, r4
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r3]
	ldrb r1, [r1]
	bl b_history__record_ability_usage_of_player
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
	ldr r1, =gUnknown_02024474
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	strb r0, [r1, 0x17]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB62F
	str r0, [r1]
	ldr r1, =gUnknown_0202420A
	ldrb r0, [r2]
	muls r0, r4
	add r0, r10
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	ldrb r1, [r1]
	bl b_history__record_ability_usage_of_player
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
	ldr r3, =gUnknown_02022F68
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
	ldr r3, =gUnknown_02022F68
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
	ldr r0, =gUnknown_02024474
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
	ldr r1, =gTakenDmg
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

	thumb_func_start atk8D_setloopcounter
atk8D_setloopcounter: @ 8050FF0
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
	thumb_func_end atk8D_setloopcounter

	thumb_func_start atk8E_cmd8e
atk8E_cmd8e: @ 805103C
	ldr r1, =gUnknown_02024474
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
	thumb_func_end atk8E_cmd8e

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
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_0202449C
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

	thumb_func_start sub_805112C
sub_805112C: @ 805112C
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
	ldr r1, =gUnknown_0202449C
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
	thumb_func_end sub_805112C

	thumb_func_start sub_8051424
sub_8051424: @ 8051424
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
	thumb_func_end sub_8051424

	thumb_func_start atk91_givemoney
atk91_givemoney: @ 80515C8
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
	ldr r0, =gUnknown_0202449C
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
	thumb_func_end atk91_givemoney

	thumb_func_start atk92_setlightscreen
atk92_setlightscreen: @ 8051664
	push {r4-r6,lr}
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	bl battle_get_per_side_status
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
	bl battle_get_per_side_status
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r0, [r1]
	movs r2, 0x2
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r5]
	bl battle_get_per_side_status
	ldr r4, =gSideTimer
	adds r1, r6, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x5
	strb r1, [r0, 0x2]
	ldrb r0, [r5]
	bl battle_get_per_side_status
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
	bl sub_8069DEC
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
	bl itemid_get_quality
	lsls r0, 24
	lsrs r6, r0, 24
_08051782:
	ldr r1, =gStringBank
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
	bl b_history__record_item_x12_of_player
	ldr r2, =gUnknown_0202437C
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
	ldr r0, =gUnknown_0202420A
	strb r4, [r0]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB552
	str r0, [r1]
	mov r1, r9
	ldrb r0, [r1]
	movs r1, 0x5
	bl b_history__record_ability_usage_of_player
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
	ldr r0, =gUnknown_0202437C
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

	thumb_func_start sub_8051AC0
sub_8051AC0: @ 8051AC0
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
	ldr r0, =gWishFutureKnock
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
	thumb_func_end sub_8051AC0

	thumb_func_start sub_8051B18
sub_8051B18: @ 8051B18
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
	thumb_func_end sub_8051B18

	thumb_func_start atk97_tryinfatuatetarget
atk97_tryinfatuatetarget: @ 8051C90
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
	ldr r0, =gUnknown_0202420A
	strb r2, [r0]
	ldrb r0, [r5]
	movs r1, 0xC
	bl b_history__record_ability_usage_of_player
	b _08051E2C
	.pool
_08051D94:
	mov r0, r10
	mov r1, r9
	bl pokemon_species_get_gender_info
	adds r4, r0, 0
	mov r0, r8
	adds r1, r7, 0
	bl pokemon_species_get_gender_info
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
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08051DE4
	mov r0, r8
	adds r1, r7, 0
	bl pokemon_species_get_gender_info
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
	thumb_func_end atk97_tryinfatuatetarget

	thumb_func_start sub_8051E48
sub_8051E48: @ 8051E48
	push {r4-r7,lr}
	ldr r0, =gUnknown_02024068
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
	bl MarkBufferBankForExecution
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
	bl MarkBufferBankForExecution
_08051EDC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08051F2C
	ldrb r0, [r5]
	bl battle_get_per_side_status
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
	bl MarkBufferBankForExecution
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
	thumb_func_end sub_8051E48

	thumb_func_start atk99_setmisteffect
atk99_setmisteffect: @ 8051F58
	push {r4-r6,lr}
	ldr r6, =gSideTimer
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl battle_get_per_side_status
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
	bl battle_get_per_side_status
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	strb r1, [r0, 0x4]
	ldrb r0, [r4]
	bl battle_get_per_side_status
	adds r1, r5, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r4]
	strb r1, [r0, 0x5]
	ldrb r0, [r4]
	bl battle_get_per_side_status
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
	thumb_func_end atk99_setmisteffect

	thumb_func_start atk9A_setincreasedcriticalchance
atk9A_setincreasedcriticalchance: @ 8052000
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
	thumb_func_end atk9A_setincreasedcriticalchance

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
	ldr r3, =gBattleMons+0xC
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
	bl MarkBufferBankForExecution
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

	thumb_func_start sub_80521FC
sub_80521FC: @ 80521FC
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
	thumb_func_end sub_80521FC

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
	ldr r5, =gLastUsedMove
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
	ldr r5, =gUnknown_020241E8
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
	ldr r2, =gLastUsedMove
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

	thumb_func_start sub_80524DC
sub_80524DC: @ 80524DC
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
	thumb_func_end sub_80524DC

	thumb_func_start atk9F_nightshadedamageeffect
atk9F_nightshadedamageeffect: @ 8052584
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
	thumb_func_end atk9F_nightshadedamageeffect

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
	ldr r1, =gSideTimer
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
	ldr r2, =gUnknown_0202437C
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
	ldr r1, =gSideTimer
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
	ldr r2, =gUnknown_0202437C
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
	ldr r5, =gLastUsedMove
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
	ldr r2, =gLastUsedMove
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

	thumb_func_start sub_8052A70
sub_8052A70: @ 8052A70
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
	ldr r2, =gUnknown_02024474
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
	ldr r2, =gUnknown_0202437C
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
	thumb_func_end sub_8052A70

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
	ldr r4, =gUnknown_020241E8
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
	bl EmitSetAttributes
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl MarkBufferBankForExecution
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

	thumb_func_start sub_8053018
sub_8053018: @ 8053018
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
	ldr r7, =gBattleMons+0xC
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
	ldr r4, =gUnknown_020241EE
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
	ldr r0, =gUnknown_020241E8
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
	thumb_func_end sub_8053018

	thumb_func_start atkAA_destinybondeffect
atkAA_destinybondeffect: @ 8053150
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
	thumb_func_end atkAA_destinybondeffect

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

	thumb_func_start atkAB_802A458
atkAB_802A458: @ 80531E0
	push {lr}
	bl b_feature_update_destiny_bond
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkAB_802A458

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
	ldr r2, =gUnknown_02024400
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

	thumb_func_start atkAD_reducepprandom
atkAD_reducepprandom: @ 8053260
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, =gLastUsedMove
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
	ldr r2, =gLastUsedMove
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
	ldr r4, =gUnknown_02022F68
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
	bl EmitSetAttributes
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
	thumb_func_end atkAD_reducepprandom

	thumb_func_start atkAE_clearstatusifnotsoundproofed
atkAE_clearstatusifnotsoundproofed: @ 8053438
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
	bl b_history__record_ability_usage_of_player
	ldrb r0, [r6, 0x5]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r6, 0x5]
_080534D4:
	ldr r7, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl battle_get_per_side_status
	movs r2, 0x2
	mov r9, r2
	mov r1, r9
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	ldr r1, =gUnknown_02024474
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
	bl b_history__record_ability_usage_of_player
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
	bl sub_806B694
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
	bl battle_get_per_side_status
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
	bl EmitSetAttributes
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
	thumb_func_end atkAE_clearstatusifnotsoundproofed

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

	thumb_func_start atkB0_setspikes
atkB0_setspikes: @ 80537A0
	push {r4,lr}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSideTimer
	lsls r2, r0, 1
	adds r0, r2, r0
	lsls r0, 2
	adds r3, r0, r1
	ldrb r0, [r3, 0xA]
	cmp r0, 0x3
	bne _08053804
	ldr r2, =gUnknown_0202437C
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
	thumb_func_end atkB0_setspikes

	thumb_func_start atkB1_setforesight
atkB1_setforesight: @ 805382C
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
	thumb_func_end atkB1_setforesight

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
	ldr r3, =gUnknown_02024400
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

	thumb_func_start atkB4_jumpifconfusedandattackmaxed
atkB4_jumpifconfusedandattackmaxed: @ 8053A90
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
	thumb_func_end atkB4_jumpifconfusedandattackmaxed

	thumb_func_start sub_8053AF8
sub_8053AF8: @ 8053AF8
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
	ldr r3, =gUnknown_02024400
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
	thumb_func_end sub_8053AF8

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
	ldr r4, =gUnknown_02024400
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
	ldr r4, =gUnknown_02024400
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
	ldr r1, =gUnknown_02024400
	movs r0, 0x28
	strh r0, [r1]
	b _08053C8E
	.pool
_08053C4C:
	cmp r4, 0xB1
	bgt _08053C5C
	ldr r1, =gUnknown_02024400
	movs r0, 0x50
	strh r0, [r1]
	b _08053C8E
	.pool
_08053C5C:
	cmp r4, 0xCB
	bgt _08053C6C
	ldr r1, =gUnknown_02024400
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

	thumb_func_start atkB8_setsafeguard
atkB8_setsafeguard: @ 8053CFC
	push {r4-r7,lr}
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	bl battle_get_per_side_status
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
	bl battle_get_per_side_status
	adds r1, r6, 0
	ands r1, r0
	lsls r1, 1
	adds r1, r4
	ldrh r0, [r1]
	movs r2, 0x20
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r7]
	bl battle_get_per_side_status
	ldr r5, =gSideTimer
	adds r1, r6, 0
	ands r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r4, 0x5
	strb r4, [r0, 0x6]
	ldrb r0, [r7]
	bl battle_get_per_side_status
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
	thumb_func_end atkB8_setsafeguard

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
	ldr r1, =gUnknown_02024400
	movs r0, 0xA
	strh r0, [r1]
	movs r3, 0x4
	b _08053E3C
	.pool
_08053DD0:
	cmp r3, 0xE
	bgt _08053DE4
	ldr r1, =gUnknown_02024400
	movs r0, 0x1E
	strh r0, [r1]
	movs r3, 0x5
	b _08053E3C
	.pool
_08053DE4:
	cmp r3, 0x22
	bgt _08053DF8
	ldr r1, =gUnknown_02024400
	movs r0, 0x32
	strh r0, [r1]
	movs r3, 0x6
	b _08053E3C
	.pool
_08053DF8:
	cmp r3, 0x40
	bgt _08053E0C
	ldr r1, =gUnknown_02024400
	movs r0, 0x46
	strh r0, [r1]
	movs r3, 0x7
	b _08053E3C
	.pool
_08053E0C:
	cmp r3, 0x54
	bgt _08053E20
	ldr r1, =gUnknown_02024400
	movs r0, 0x5A
	strh r0, [r1]
	movs r3, 0x8
	b _08053E3C
	.pool
_08053E20:
	cmp r3, 0x5E
	bgt _08053E34
	ldr r1, =gUnknown_02024400
	movs r0, 0x6E
	strh r0, [r1]
	movs r3, 0x9
	b _08053E3C
	.pool
_08053E34:
	ldr r1, =gUnknown_02024400
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

	thumb_func_start atkBA_802B140
atkBA_802B140: @ 8053EC8
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
	ldr r0, =gUnknown_0202449C
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
	ldr r7, =gUnknown_020241E8
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
	ldr r7, =gUnknown_0202449C
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
	ldr r1, =gUnknown_02024474
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
	thumb_func_end atkBA_802B140

	thumb_func_start sub_805405C
sub_805405C: @ 805405C
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
	thumb_func_end sub_805405C

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
	ldr r3, =gBattleMons+0x18
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
	ldr r1, =gUnknown_02024474
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
	ldr r1, =gUnknown_0202449C
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
	ldr r2, =gSideTimer
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

	thumb_func_start atkBF_setcurled
atkBF_setcurled: @ 80542C8
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
	thumb_func_end atkBF_setcurled

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

	thumb_func_start sub_8054400
sub_8054400: @ 8054400
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
	ldr r5, =gUnknown_02024400
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	movs r1, 0x3F
	bl __divsi3
	adds r0, 0x1E
	strh r0, [r5]
	ldr r6, =gUnknown_0202449C
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
	thumb_func_end sub_8054400

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
	bl battle_get_per_side_status
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
	bl battle_get_per_side_status
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

	thumb_func_start atkC4_802B910
atkC4_802B910: @ 80546E4
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
	thumb_func_end atkC4_802B910

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

	thumb_func_start sub_8054A48
sub_8054A48: @ 8054A48
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
	thumb_func_end sub_8054A48

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
	ldr r5, =gSideTimer
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
	bl EmitSetAttributes
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

	thumb_func_start atkD1_sethelpinghand
atkD1_sethelpinghand: @ 8054E0C
	push {r4,lr}
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl battle_get_per_side_status
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
	thumb_func_end atkD1_sethelpinghand

	thumb_func_start sub_8054EB4
sub_8054EB4: @ 8054EB4
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
	ldr r0, =gUnknown_082DB63F
	str r0, [r1]
	ldr r1, =gUnknown_0202420A
	ldrb r0, [r7]
	muls r0, r5
	add r0, r8
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	ldrb r1, [r1]
	bl b_history__record_ability_usage_of_player
	b _08055132
	.pool
_08055010:
	ldr r3, =gUnknown_0202449C
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
	bl EmitSetAttributes
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
	bl EmitSetAttributes
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
	ldr r1, =gUnknown_02022F68
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
	thumb_func_end sub_8054EB4

	thumb_func_start sub_8055148
sub_8055148: @ 8055148
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
	ldr r1, =gUnknown_0202420A
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
	thumb_func_end sub_8055148

	thumb_func_start atkD4_802C408
atkD4_802C408: @ 80551C0
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
	thumb_func_end atkD4_802C408

	thumb_func_start sub_8055294
sub_8055294: @ 8055294
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
	thumb_func_end sub_8055294

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
	ldr r1, =gUnknown_02024474
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

	thumb_func_start sub_805534C
sub_805534C: @ 805534C
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
	thumb_func_end sub_805534C

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
	ldr r4, =gUnknown_02024400
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
	ldr r0, =gUnknown_02024400
	adds r1, r5, 0x1
	lsls r1, 1
	adds r1, r6
	ldrh r1, [r1]
	strh r1, [r0]
	b _08055702
	.pool
_080556FC:
	ldr r1, =gUnknown_02024400
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
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0x18
	str r0, [sp, 0x4]
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl battle_get_per_side_status
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
	ldr r4, =gUnknown_020241EE
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
	ldr r2, =gUnknown_0202437C
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
	ldr r2, =gUnknown_0202437C
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

	thumb_func_start atkE1_802CBE4
atkE1_802CBE4: @ 805599C
	push {r4-r6,lr}
	ldr r4, =gUnknown_02024474
	ldr r0, =gUnknown_0202449C
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
	thumb_func_end atkE1_802CBE4

	thumb_func_start atkE2_cmde2
atkE2_cmde2: @ 8055A78
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
	ldr r0, =gUnknown_0202449C
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
	bl EmitSetAttributes
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
	thumb_func_end atkE2_cmde2

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

	thumb_func_start sub_8055B48
sub_8055B48: @ 8055B48
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
	thumb_func_end sub_8055B48

	thumb_func_start atkE5_pickupitemcalculation
atkE5_pickupitemcalculation: @ 8055C00
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
	bl pokemon_setattr
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
	bl pokemon_setattr
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
	bl pokemon_setattr
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
	thumb_func_end atkE5_pickupitemcalculation

	thumb_func_start atkE6_castform_transform
atkE6_castform_transform: @ 8055DFC
	push {r4,lr}
	ldr r4, =gActiveBank
	ldr r0, =gUnknown_02024474
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
	ldr r3, =gUnknown_0202449C
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
	bl MarkBufferBankForExecution
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE6_castform_transform

	thumb_func_start atkE7_castform_switch
atkE7_castform_switch: @ 8055E64
	push {r4,lr}
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, [r1]
	adds r0, 0x1
	str r0, [r1]
	ldr r0, =gUnknown_02024474
	ldrb r0, [r0, 0x17]
	bl CastformDataTypeChange
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08055E8E
	ldr r0, =gUnknown_082DB4A9
	bl b_push_move_exec
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0x7F
	subs r1, r4, 0x1
	strb r1, [r0]
_08055E8E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end atkE7_castform_switch

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

	thumb_func_start atkE9_seteffectbyweather
atkE9_seteffectbyweather: @ 8055F5C
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
	ldr r1, =gUnknown_02024474
	movs r0, 0x2
	strb r0, [r1, 0xE]
_08055F9A:
	ldrh r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08055FB8
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	movs r0, 0x8B
	b _08055FFA
	.pool
_08055FB8:
	movs r0, 0x18
	ands r0, r1
	cmp r0, 0
	beq _08055FCC
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	movs r0, 0x85
	b _08055FFA
	.pool
_08055FCC:
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _08055FE0
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	movs r0, 0x8A
	b _08055FFA
	.pool
_08055FE0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08055FF4
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	movs r0, 0x8F
	b _08055FFA
	.pool
_08055FF4:
	ldr r0, =gUnknown_0202449C
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
	thumb_func_end atkE9_seteffectbyweather

	thumb_func_start atkEA_recycleitem
atkEA_recycleitem: @ 8056014
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r7, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r7]
	ldr r1, =gUnknown_0202449C
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
	bl EmitSetAttributes
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
	ldr r5, =gUnknown_0831C483
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

	thumb_func_start atkEC_802D2A0
atkEC_802D2A0: @ 805616C
	push {r4-r6,lr}
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	bl battle_get_per_side_status
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
	ldr r0, =gUnknown_02024474
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
	thumb_func_end atkEC_802D2A0

	thumb_func_start atkED_802D364
atkED_802D364: @ 8056230
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
	ldr r1, =gUnknown_02024474
	ldrb r0, [r1, 0x17]
	strb r0, [r2]
	strb r0, [r3]
	b _0805626A
	.pool
_08056264:
	ldr r1, =gUnknown_02024474
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
	thumb_func_end atkED_802D364

	thumb_func_start atkEE_removereflectlightscreen
atkEE_removereflectlightscreen: @ 8056284
	push {r4,lr}
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSideTimer
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
	ldr r1, =gUnknown_02024474
	movs r0, 0x1
	strb r0, [r1, 0x18]
	strb r0, [r1, 0x19]
	b _080562EA
	.pool
_080562E4:
	ldr r0, =gUnknown_02024474
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
	thumb_func_end atkEE_removereflectlightscreen

	thumb_func_start sub_8056300
sub_8056300: @ 8056300
	push {r4-r6,lr}
	movs r4, 0
	ldr r0, =gUnknown_02024068
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
	ldr r0, =gUnknown_0202449C
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
	ldr r0, =gUnknown_03005D10
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
	ldr r1, =gUnknown_0831C48D
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
	ldr r0, =gUnknown_03005D10
	ldrb r1, [r0, 0x5]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0, 0x5]
	b _08056564
	.pool
_08056550:
	ldr r0, =gUnknown_03005D10
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
	bl pokemon_setattr
	bl calc_player_party_count
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
	bl pokemon_setattr
	bl calc_player_party_count
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
	thumb_func_end sub_8056300

	thumb_func_start atkF0_catch_pokemon
atkF0_catch_pokemon: @ 80566A8
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
	bl pokemon_catch
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
	ldr r5, =gUnknown_03005D10
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
	thumb_func_end atkF0_catch_pokemon

	thumb_func_start atkF1_802D95C
atkF1_802D95C: @ 8056850
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
	thumb_func_end atkF1_802D95C

	thumb_func_start sub_80568CC
sub_80568CC: @ 80568CC
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
	thumb_func_end sub_80568CC

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

	thumb_func_start atkF3_receive_new_pokemon_maybe
atkF3_receive_new_pokemon_maybe: @ 8056BEC
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
	bl audio_play
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
	bl audio_play
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
	bl audio_play
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
	bl audio_play
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
	ldr r1, =gUnknown_0202449C
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
	bl pokemon_get_gender
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
	ldr r2, =gUnknown_0202449C
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
	ldr r1, =gUnknown_0202449C
	ldr r2, [r1]
	adds r2, 0x6D
	movs r1, 0x2
	bl pokemon_setattr
	b _08056E48
	.pool
_08056E2C:
	bl calc_player_party_count
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
	thumb_func_end atkF3_receive_new_pokemon_maybe

	thumb_func_start sub_8056E78
sub_8056E78: @ 8056E78
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
	thumb_func_end sub_8056E78

	thumb_func_start atkF5_reset_attacker_bd_x4C
atkF5_reset_attacker_bd_x4C: @ 8056EA8
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
	thumb_func_end atkF5_reset_attacker_bd_x4C

	thumb_func_start sub_8056ED0
sub_8056ED0: @ 8056ED0
	ldr r1, =gUnknown_02024083
	movs r0, 0xC
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8056ED0

	thumb_func_start sub_8056EDC
sub_8056EDC: @ 8056EDC
	ldr r1, =gUnknown_02024083
	movs r0, 0xC
	strb r0, [r1]
	ldr r1, =gUnknown_02024082
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8056EDC

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
	bl MarkBufferBankForExecution
	ldr r0, [r5]
	adds r0, 0x2
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8056EF8

	thumb_func_start sub_8056F28
sub_8056F28: @ 8056F28
	push {r4-r6,lr}
	ldr r5, =gBattleStruct
	ldr r6, =gBattleTypeFlags
	ldr r0, [r6]
	movs r1, 0x80
	lsls r1, 19
	ands r0, r1
	cmp r0, 0
	beq _08056F3E
	bl sub_81D55D0
_08056F3E:
	ldr r4, =gUnknown_0202449C
	movs r0, 0xA9
	lsls r0, 2
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x20
	bl AllocZeroed
	str r0, [r5]
	movs r0, 0xA0
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1]
	movs r0, 0x10
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1, 0x4]
	movs r0, 0x24
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1, 0x8]
	movs r0, 0x24
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1, 0xC]
	movs r0, 0xC
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1, 0x10]
	movs r0, 0x1C
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1, 0x14]
	movs r0, 0x54
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1, 0x18]
	movs r0, 0x24
	bl AllocZeroed
	ldr r1, [r5]
	str r0, [r1, 0x1C]
	ldr r4, =gUnknown_020244A0
	movs r5, 0x80
	lsls r5, 5
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4]
	ldr r4, =gUnknown_020244A4
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4]
	ldr r4, =gUnknown_0202305C
	movs r0, 0x80
	lsls r0, 6
	bl AllocZeroed
	str r0, [r4]
	ldr r4, =gUnknown_02023060
	adds r0, r5, 0
	bl AllocZeroed
	str r0, [r4]
	ldr r0, [r6]
	movs r1, 0x80
	lsls r1, 20
	ands r0, r1
	cmp r0, 0
	beq _08056FFA
	ldr r0, =0x00004054
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gSaveBlock1Ptr
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 5
	ldr r0, =0x00001a9c
	adds r1, r0
	ldr r0, [r2]
	adds r0, r1
	bl create_enemy_party
_08056FFA:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8056F28

	thumb_func_start sub_8057028
sub_8057028: @ 8057028
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 19
	ands r0, r1
	cmp r0, 0
	beq _0805703C
	bl sub_81D5694
_0805703C:
	ldr r6, =gBattleStruct
	ldr r0, [r6]
	cmp r0, 0
	beq _080570D0
	ldr r4, =gUnknown_0202449C
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	ldr r0, [r6]
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	str r5, [r0]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r6]
	str r5, [r0, 0x4]
	ldr r0, [r0, 0x8]
	bl Free
	ldr r0, [r6]
	str r5, [r0, 0x8]
	ldr r0, [r0, 0xC]
	bl Free
	ldr r0, [r6]
	str r5, [r0, 0xC]
	ldr r0, [r0, 0x10]
	bl Free
	ldr r0, [r6]
	str r5, [r0, 0x10]
	ldr r0, [r0, 0x14]
	bl Free
	ldr r0, [r6]
	str r5, [r0, 0x14]
	ldr r0, [r0, 0x18]
	bl Free
	ldr r0, [r6]
	str r5, [r0, 0x18]
	ldr r0, [r0, 0x1C]
	bl Free
	ldr r0, [r6]
	str r5, [r0, 0x1C]
	bl Free
	str r5, [r6]
	ldr r4, =gUnknown_020244A0
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_020244A4
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_0202305C
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r4, =gUnknown_02023060
	ldr r0, [r4]
	bl Free
	str r5, [r4]
_080570D0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8057028

	thumb_func_start sub_80570F4
sub_80570F4: @ 80570F4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08057140
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x3
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gBattleMons
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	adds r1, r2
	adds r1, 0x2A
	muls r0, r4
	adds r0, r2
	adds r0, 0x2A
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls _0805714A
	adds r4, r3, 0
	b _0805714A
	.pool
_08057140:
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r4, r0, 24
_0805714A:
	ldr r2, =gBattleMons
	movs r1, 0x58
	adds r0, r4, 0
	muls r0, r1
	adds r0, r2
	adds r3, r0, 0
	adds r3, 0x2A
	adds r0, r5, 0
	muls r0, r1
	adds r0, r2
	adds r1, r0, 0
	adds r1, 0x2A
	ldrb r0, [r3]
	ldrb r2, [r1]
	cmp r0, r2
	bls _080571B8
	ldrb r1, [r1]
	subs r0, r1
	cmp r0, 0x1D
	ble _08057198
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x8
	bl happiness_algorithm
	b _080571CE
	.pool
_08057198:
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x6
	bl happiness_algorithm
	b _080571CE
	.pool
_080571B8:
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x6
	bl happiness_algorithm
_080571CE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80570F4

	thumb_func_start sub_80571DC
sub_80571DC: @ 80571DC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08057248
	movs r2, 0
	ldr r6, =gBattlePartyID
	lsls r3, r4, 1
	ldr r5, =gUnknown_0203CF00
	ldr r4, =gUnknown_0202449C
_080571FE:
	adds r0, r2, r5
	ldr r1, [r4]
	adds r1, r2, r1
	adds r1, 0x60
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x2
	ble _080571FE
	adds r0, r3, r6
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r7, 0
	bl pokemon_order_func
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_81B8FB0
	movs r2, 0
	ldr r4, =gUnknown_0202449C
	ldr r3, =gUnknown_0203CF00
_08057236:
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, 0x60
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x2
	ble _08057236
_08057248:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80571DC

	thumb_func_start sub_805725C
sub_805725C: @ 805725C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	mov r8, r0
	ldr r1, =gBattleCommunication
	mov r10, r1
	b _08057284
	.pool
_0805727C:
	mov r2, r8
	cmp r2, 0
	beq _08057284
	b _08057406
_08057284:
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _0805728E
	b _08057390
_0805728E:
	cmp r0, 0x1
	ble _08057294
	b _080573FC
_08057294:
	cmp r0, 0
	beq _0805729A
	b _080573FC
_0805729A:
	ldr r6, =gBattleMons
	movs r0, 0x58
	mov r5, r9
	muls r5, r0
	adds r0, r6, 0
	adds r0, 0x4C
	adds r4, r5, r0
	ldr r0, [r4]
	movs r7, 0x7
	ands r0, r7
	cmp r0, 0
	beq _08057372
	mov r0, r9
	bl UproarWakeUpCheck
	lsls r0, 24
	cmp r0, 0
	beq _080572FC
	ldr r0, [r4]
	movs r1, 0x8
	negs r1, r1
	ands r0, r1
	str r0, [r4]
	adds r2, r6, 0
	adds r2, 0x50
	adds r2, r5, r2
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	bl b_movescr_stack_push_cursor
	movs r0, 0x1
	mov r2, r10
	strb r0, [r2, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =BattleScript_MoveUsedWokeUp
	str r0, [r1]
	movs r0, 0x2
	mov r8, r0
	b _08057372
	.pool
_080572FC:
	adds r0, r5, r6
	adds r0, 0x20
	ldrb r0, [r0]
	movs r2, 0x1
	cmp r0, 0x30
	bne _0805730A
	movs r2, 0x2
_0805730A:
	ldr r1, [r4]
	adds r0, r1, 0
	ands r0, r7
	cmp r0, r2
	bcs _0805731E
	movs r0, 0x8
	negs r0, r0
	ands r1, r0
	str r1, [r4]
	b _08057322
_0805731E:
	subs r0, r1, r2
	str r0, [r4]
_08057322:
	ldr r2, =gBattleMons
	movs r0, 0x58
	mov r1, r9
	muls r1, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r4, [r0]
	movs r0, 0x7
	ands r4, r0
	cmp r4, 0
	beq _08057354
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =BattleScript_MoveUsedIsAsleep
	str r0, [r1]
	movs r1, 0x2
	mov r8, r1
	b _08057372
	.pool
_08057354:
	adds r2, 0x50
	adds r2, r1, r2
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =BattleScript_MoveUsedWokeUp
	str r0, [r1]
	movs r2, 0x2
	mov r8, r2
_08057372:
	ldr r1, =gBattleCommunication
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r10, r1
	b _080573FC
	.pool
_08057390:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	adds r1, 0x4C
	adds r4, r0, r1
	ldr r0, [r4]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080573F4
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _080573D4
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =BattleScript_MoveUsedIsFrozen
	str r0, [r1]
	b _080573EC
	.pool
_080573D4:
	ldr r0, [r4]
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	str r0, [r4]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =BattleScript_MoveUsedUnfroze
	str r0, [r1]
	mov r0, r10
	strb r5, [r0, 0x5]
_080573EC:
	movs r1, 0x2
	mov r8, r1
	ldr r2, =gBattleCommunication
	mov r10, r2
_080573F4:
	mov r1, r10
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080573FC:
	mov r2, r10
	ldrb r0, [r2]
	cmp r0, 0x2
	beq _08057406
	b _0805727C
_08057406:
	mov r0, r8
	cmp r0, 0x2
	bne _08057430
	ldr r4, =gActiveBank
	mov r1, r9
	strb r1, [r4]
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	ldr r1, =gUnknown_020240D0
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl EmitSetAttributes
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
_08057430:
	mov r0, r8
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_805725C

	thumb_func_start nullsub_21
nullsub_21: @ 8057458
	bx lr
	thumb_func_end nullsub_21

	thumb_func_start sub_805745C
sub_805745C: @ 805745C
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl1
	str r1, [r0]
	ldr r0, =gUnknown_020244B9
	movs r1, 0
	strb r1, [r0]
	ldr r0, =gUnknown_020244CC
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_805745C

	thumb_func_start dp01_tbl1_exec_completed
dp01_tbl1_exec_completed: @ 805748C
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_03005D60
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl1
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080574E0
	bl link_get_multiplayer_id
	mov r1, sp
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	mov r2, sp
	bl dp01_prepare_buffer_wireless_probably
	ldr r1, =gUnknown_02023064
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r1
	movs r1, 0x38
	strb r1, [r0]
	b _080574F2
	.pool
_080574E0:
	ldr r2, =gUnknown_02024068
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_080574F2:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_tbl1_exec_completed

	thumb_func_start bx_exec_buffer_A_ch0_tbl1
bx_exec_buffer_A_ch0_tbl1: @ 8057504
	push {lr}
	ldr r2, =gUnknown_02024068
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08057550
	ldr r0, =gUnknown_02023064
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _0805754C
	ldr r0, =gUnknown_0831C514
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _08057550
	.pool
_0805754C:
	bl dp01_tbl1_exec_completed
_08057550:
	pop {r0}
	bx r0
	thumb_func_end bx_exec_buffer_A_ch0_tbl1

	thumb_func_start bx_0802E404
bx_0802E404: @ 8057554
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08057576
	bl dp01_tbl1_exec_completed
_08057576:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_0802E404

	thumb_func_start sub_8057588
sub_8057588: @ 8057588
	push {r4-r7,lr}
	ldr r3, =gUnknown_02023064
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r2, r0, 9
	adds r1, r3, 0x2
	adds r1, r2, r1
	ldrb r5, [r1]
	adds r3, 0x3
	adds r2, r3
	ldrb r1, [r2]
	lsls r1, 8
	orrs r5, r1
	movs r1, 0x1
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	beq _080575EC
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne _080575EC
	ldr r1, =gUnknown_020244CC
	ldrb r0, [r1]
	adds r0, 0x1
	b _080575F0
	.pool
_080575EC:
	ldr r1, =gUnknown_020244CC
	movs r0, 0
_080575F0:
	strb r0, [r1]
	ldr r0, =gMain
	ldrh r2, [r0, 0x2E]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _08057658
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020244AC
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08057640
	cmp r0, 0x1
	bgt _08057630
	cmp r0, 0
	beq _0805763A
	b _080577C2
	.pool
_08057630:
	cmp r0, 0x2
	beq _08057646
	cmp r0, 0x3
	beq _0805764C
	b _080577C2
_0805763A:
	movs r0, 0x1
	movs r1, 0
	b _080577BC
_08057640:
	movs r0, 0x1
	movs r1, 0x1
	b _080577BC
_08057646:
	movs r0, 0x1
	movs r1, 0x2
	b _080577BC
_0805764C:
	movs r0, 0x1
	movs r1, 0x3
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _080577C2
_08057658:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _08057698
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08057674
	b _080577E8
_08057674:
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	b _08057732
	.pool
_08057698:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _080576D8
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080576B4
	b _080577E8
_080576B4:
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	b _08057732
	.pool
_080576D8:
	movs r7, 0x40
	adds r0, r7, 0
	ands r0, r2
	cmp r0, 0
	beq _08057700
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080577E8
	b _0805771A
	.pool
_08057700:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _0805774C
	ldr r5, =gUnknown_020244AC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080577E8
_0805771A:
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_8059CF8
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x2
_08057732:
	eors r0, r2
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	b _080577E8
	.pool
_0805774C:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _0805775A
	ldrb r0, [r1]
	cmp r0, 0x3B
	bls _080577DC
_0805775A:
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	ands r0, r3
	cmp r0, 0
	beq _080577E8
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _080577E8
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _080577E8
	ldr r0, [r4]
	ands r0, r7
	cmp r0, 0
	bne _080577E8
	ldr r0, =gUnknown_02023064
	ldrb r1, [r6]
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x1
	bne _080577B2
	cmp r5, 0xC
	bhi _080577E8
	adds r0, r5, 0
	movs r1, 0x1
	bl bag_add_item
_080577B2:
	movs r0, 0x5
	bl audio_play
	movs r0, 0x1
	movs r1, 0xC
_080577BC:
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
_080577C2:
	bl dp01_tbl1_exec_completed
	b _080577E8
	.pool
_080577DC:
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	beq _080577E8
	bl sub_8073314
_080577E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8057588

	thumb_func_start sub_80577F0
sub_80577F0: @ 80577F0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	ldrb r0, [r4]
	movs r1, 0
	bl dp11b_obj_free
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057824
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80577F0

	thumb_func_start sub_8057824
sub_8057824: @ 8057824
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_0831C5F8
	mov r0, sp
	movs r2, 0x4
	bl memcpy
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	movs r1, 0x1
	movs r2, 0xF
	movs r3, 0x1
	bl dp11b_obj_instanciate
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r0, 0
	beq _08057866
_0805784A:
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	cmp r4, r0
	beq _0805785C
	lsls r0, r4, 24
	lsrs r0, 24
	movs r1, 0x1
	bl dp11b_obj_free
_0805785C:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0805784A
_08057866:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	beq _0805789C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne _0805789C
	ldr r1, =gUnknown_020244CC
	ldrb r0, [r1]
	adds r0, 0x1
	b _080578A0
	.pool
_0805789C:
	ldr r1, =gUnknown_020244CC
	movs r0, 0
_080578A0:
	strb r0, [r1]
	ldrh r2, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _08057910
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	ldr r1, =gUnknown_020244B0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r2, [r0]
	ldrb r0, [r4]
	lsls r0, 8
	orrs r2, r0
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	bl dp01_tbl1_exec_completed
	b _08057BC8
	.pool
_08057910:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _0805791E
	ldrb r0, [r1]
	cmp r0, 0x3B
	bls _0805798C
_0805791E:
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r5, =gUnknown_03005D74
	ldrb r0, [r5]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
	ldrb r0, [r4]
	movs r1, 0x1
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x7
	movs r3, 0x1
	bl dp11b_obj_instanciate
	ldrb r0, [r5]
	movs r1, 0x1
	bl dp11b_obj_free
	b _08057BC8
	.pool
_0805798C:
	movs r0, 0x60
	ands r0, r2
	cmp r0, 0
	bne _08057996
	b _08057AB0
_08057996:
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r3, =gUnknown_03005D74
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	adds r5, r3, 0
_080579B8:
	ldrb r0, [r5]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	mov r0, sp
	b _080579E2
	.pool
_080579D8:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080579E8
	mov r2, sp
	adds r0, r2, r4
_080579E2:
	ldrb r0, [r0]
	cmp r1, r0
	bne _080579D8
_080579E8:
	subs r4, 0x1
	cmp r4, 0
	bge _080579F0
	movs r4, 0x4
_080579F0:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetBankByPlayerAI
	strb r0, [r5]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	beq _080579E8
	movs r4, 0
	ldrb r0, [r5]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08057A6E
	cmp r0, 0x1
	bgt _08057A28
	cmp r0, 0
	beq _08057A32
	b _08057A70
	.pool
_08057A28:
	cmp r0, 0x2
	beq _08057A32
	cmp r0, 0x3
	beq _08057A6E
	b _08057A70
_08057A32:
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	ldrb r1, [r5]
	cmp r0, r1
	bne _08057A6E
	ldr r1, =gBattlePartyID
	ldrb r2, [r2]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gUnknown_020244B0
	adds r2, r1
	ldrb r1, [r2]
	adds r1, 0xD
	bl GetMonData
	ldr r2, =gBattleMoves
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x6]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08057A70
_08057A6E:
	adds r4, 0x1
_08057A70:
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	ldr r0, =gUnknown_03005D74
	cmp r1, 0
	beq _08057A88
	movs r4, 0
_08057A88:
	cmp r4, 0
	beq _080579B8
	b _08057BB0
	.pool
_08057AB0:
	movs r0, 0x90
	ands r0, r2
	cmp r0, 0
	bne _08057ABA
	b _08057BC8
_08057ABA:
	movs r0, 0x5
	bl audio_play
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r3, =gUnknown_03005D74
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039B2C
	str r1, [r0]
	adds r5, r3, 0
_08057ADC:
	ldrb r0, [r5]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r1, r0, 24
	movs r4, 0
	mov r0, sp
	b _08057B06
	.pool
_08057AFC:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _08057B0C
	mov r2, sp
	adds r0, r2, r4
_08057B06:
	ldrb r0, [r0]
	cmp r1, r0
	bne _08057AFC
_08057B0C:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08057B14
	movs r4, 0
_08057B14:
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	bl GetBankByPlayerAI
	strb r0, [r5]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	beq _08057B0C
	movs r4, 0
	ldrb r0, [r5]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08057B92
	cmp r0, 0x1
	bgt _08057B4C
	cmp r0, 0
	beq _08057B56
	b _08057B94
	.pool
_08057B4C:
	cmp r0, 0x2
	beq _08057B56
	cmp r0, 0x3
	beq _08057B92
	b _08057B94
_08057B56:
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	ldrb r1, [r5]
	cmp r0, r1
	bne _08057B92
	ldr r1, =gBattlePartyID
	ldrb r2, [r2]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gUnknown_020244B0
	adds r2, r1
	ldrb r1, [r2]
	adds r1, 0xD
	bl GetMonData
	ldr r2, =gBattleMoves
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x6]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08057B94
_08057B92:
	adds r4, 0x1
_08057B94:
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	ldr r0, =gUnknown_03005D74
	cmp r1, 0
	beq _08057BAC
	movs r4, 0
_08057BAC:
	cmp r4, 0
	beq _08057ADC
_08057BB0:
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039AD8
	str r1, [r0]
_08057BC8:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8057824

	thumb_func_start sub_8057BFC
sub_8057BFC: @ 8057BFC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	ldr r1, =gUnknown_02023068
	adds r6, r0, r1
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0xF0
	ands r0, r1
	adds r7, r3, 0
	cmp r0, 0
	beq _08057C44
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne _08057C44
	ldr r1, =gUnknown_020244CC
	ldrb r0, [r1]
	adds r0, 0x1
	b _08057C48
	.pool
_08057C44:
	ldr r1, =gUnknown_020244CC
	movs r0, 0
_08057C48:
	strb r0, [r1]
	ldrh r2, [r2, 0x2E]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	bne _08057C58
	b _08057E04
_08057C58:
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020244B0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, 0xAE
	bne _08057C98
	ldrb r0, [r6, 0x12]
	movs r4, 0
	cmp r0, 0x7
	beq _08057CA6
	ldrb r1, [r6, 0x13]
	movs r0, 0x7
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	asrs r4, r0, 31
	movs r0, 0x10
	ands r4, r0
	b _08057CA6
	.pool
_08057C98:
	ldr r2, =gBattleMoves
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r4, [r0, 0x6]
_08057CA6:
	movs r0, 0x10
	ands r0, r4
	cmp r0, 0
	beq _08057CC4
	ldr r0, =gUnknown_03005D74
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	strb r1, [r0]
	b _08057CDE
	.pool
_08057CC4:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl battle_get_per_side_status
	adds r1, r0, 0
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	bl GetBankByPlayerAI
	ldr r1, =gUnknown_03005D74
	strb r0, [r1]
_08057CDE:
	ldr r5, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r2, r3, 9
	adds r1, r5, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r7, r0, 0
	cmp r1, 0
	bne _08057D18
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq _08057D5A
	adds r0, r5, 0x2
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, 0
	bne _08057D5A
	movs r0, 0x1
	add r8, r0
	b _08057D5A
	.pool
_08057D18:
	movs r0, 0x7D
	ands r0, r4
	cmp r0, 0
	bne _08057D24
	movs r0, 0x1
	add r8, r0
_08057D24:
	ldr r0, =gUnknown_020244B0
	adds r0, r3, r0
	adds r1, r6, 0
	adds r1, 0x8
	ldrb r0, [r0]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08057D62
	movs r0, 0x12
	ands r0, r4
	cmp r0, 0
	bne _08057D5A
	movs r0, 0
	bl sub_8069DEC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _08057D5A
	ldrb r0, [r7]
	bl sub_8069F34
	ldr r1, =gUnknown_03005D74
	strb r0, [r1]
	movs r0, 0
	mov r8, r0
_08057D5A:
	ldr r7, =gActiveBank
	mov r0, r8
	cmp r0, 0
	bne _08057D80
_08057D62:
	ldr r1, =gUnknown_020244B0
	ldrb r0, [r7]
	adds r0, r1
	ldrb r2, [r0]
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	lsls r0, 8
	orrs r2, r0
	b _08057E1C
	.pool
_08057D80:
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057824
	str r1, [r0]
	movs r0, 0x12
	ands r4, r0
	cmp r4, 0
	beq _08057DA8
	ldr r1, =gUnknown_03005D74
	ldrb r0, [r7]
	b _08057DD8
	.pool
_08057DA8:
	movs r0, 0x1
	bl GetBankByPlayerAI
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08057DD0
	movs r0, 0x3
	b _08057DD2
	.pool
_08057DD0:
	movs r0, 0x1
_08057DD2:
	bl GetBankByPlayerAI
	ldr r1, =gUnknown_03005D74
_08057DD8:
	strb r0, [r1]
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039AD8
	b _08057F9C
	.pool
_08057E04:
	movs r6, 0x2
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	bne _08057E14
	ldrb r0, [r1]
	cmp r0, 0x3B
	bls _08057E30
_08057E14:
	movs r0, 0x5
	bl audio_play
	ldr r2, =0x0000ffff
_08057E1C:
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	bl dp01_tbl1_exec_completed
	b _08057F9E
	.pool
_08057E30:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _08057E60
	ldr r4, =gUnknown_020244B0
	ldrb r0, [r7]
	adds r2, r0, r4
	ldrb r1, [r2]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08057E4A
	b _08057F9E
_08057E4A:
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	movs r2, 0x1
	eors r0, r2
	b _08057F08
	.pool
_08057E60:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	beq _08057EA4
	ldr r4, =gUnknown_020244B0
	ldrb r0, [r7]
	adds r3, r0, r4
	ldrb r2, [r3]
	movs r6, 0x1
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _08057E7C
	b _08057F9E
_08057E7C:
	ldr r1, =gUnknown_03005D78
	adds r0, r6, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08057E8A
	b _08057F9E
_08057E8A:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	eors r0, r6
	b _08057F08
	.pool
_08057EA4:
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _08057ED4
	ldr r4, =gUnknown_020244B0
	ldrb r0, [r7]
	adds r2, r0, r4
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08057F9E
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	movs r2, 0x2
	eors r0, r2
	b _08057F08
	.pool
_08057ED4:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _08057F30
	ldr r4, =gUnknown_020244B0
	ldrb r0, [r7]
	adds r3, r0, r4
	ldrb r2, [r3]
	movs r5, 0x2
	adds r0, r6, 0
	ands r0, r2
	cmp r0, 0
	bne _08057F9E
	ldr r1, =gUnknown_03005D78
	adds r0, r5, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08057F9E
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r7]
	adds r1, r4
	ldrb r0, [r1]
	eors r0, r5
_08057F08:
	strb r0, [r1]
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	bl sub_8059B3C
	bl sub_8059BB0
	b _08057F9E
	.pool
_08057F30:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	beq _08057F9E
	ldr r0, =gUnknown_03005D78
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _08057F9E
	ldr r0, =gBattleTypeFlags
	ldr r5, [r0]
	ands r5, r6
	cmp r5, 0
	bne _08057F9E
	ldr r4, =gUnknown_020244B0
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	ldrb r0, [r7]
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08057F78
	ldr r0, =gUnknown_03005D74
	strb r5, [r0]
	b _08057F80
	.pool
_08057F78:
	ldr r1, =gUnknown_03005D74
	adds r0, 0x1
	strb r0, [r1]
	adds r0, r1, 0
_08057F80:
	ldrb r0, [r0]
	movs r1, 0x1B
	bl battle_menu_cursor_related_2
	ldr r0, =gUnknown_085CCACA
	movs r1, 0xB
	bl battle_show_message_maybe
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058138
_08057F9C:
	str r1, [r0]
_08057F9E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8057BFC

	thumb_func_start sub_8057FBC
sub_8057FBC: @ 8057FBC
	push {r4-r7,lr}
	movs r7, 0
	ldr r4, =gMain
	ldrh r1, [r4, 0x2E]
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08057FD6
	movs r0, 0x5
	bl audio_play
	movs r7, 0x1
_08057FD6:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08057FF8
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_02022E14
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gUnknown_02022E16
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	movs r7, 0xFF
_08057FF8:
	ldrh r1, [r4, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08058038
	ldr r5, =gUnknown_020244B0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r2, r0, r5
	ldrb r1, [r2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08058038
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x1
	eors r0, r2
	strb r0, [r1]
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_08058038:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08058086
	ldr r5, =gUnknown_020244B0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r3, r0, r5
	ldrb r2, [r3]
	movs r6, 0x1
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _08058086
	ldr r1, =gUnknown_03005D78
	adds r0, r6, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08058086
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	eors r0, r6
	strb r0, [r1]
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_08058086:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080580C8
	ldr r5, =gUnknown_020244B0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r2, r0, r5
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080580C8
	ldrb r0, [r2]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	movs r2, 0x2
	eors r0, r2
	strb r0, [r1]
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_080580C8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08058116
	ldr r5, =gUnknown_020244B0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r3, r0, r5
	ldrb r2, [r3]
	movs r6, 0x2
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _08058116
	ldr r1, =gUnknown_03005D78
	adds r0, r6, 0
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08058116
	ldrb r0, [r3]
	bl battle_menu_cursor_related
	ldrb r1, [r4]
	adds r1, r5
	ldrb r0, [r1]
	eors r0, r6
	strb r0, [r1]
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
_08058116:
	adds r0, r7, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8057FBC

	thumb_func_start sub_8058138
sub_8058138: @ 8058138
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x5
	ands r0, r1
	cmp r0, 0
	bne _08058152
	b _08058500
_08058152:
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_020244B0
	mov r10, r0
	ldr r1, =gActiveBank
	mov r8, r1
	ldrb r1, [r1]
	adds r2, r1, r0
	ldr r5, =gUnknown_03005D74
	ldrb r0, [r2]
	ldrb r3, [r5]
	cmp r0, r3
	bne _08058170
	b _080584A8
_08058170:
	lsls r1, 9
	ldr r0, =gUnknown_02023068
	adds r1, r0
	mov r9, r1
	ldrb r1, [r2]
	lsls r1, 1
	add r1, r9
	ldrh r6, [r1]
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, 1
	add r0, r9
	strh r6, [r0]
	mov r1, r8
	ldrb r0, [r1]
	add r0, r10
	ldrb r1, [r0]
	mov r7, r9
	adds r7, 0x8
	adds r1, r7, r1
	ldrb r6, [r1]
	ldrb r0, [r5]
	adds r0, r7, r0
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r5]
	adds r0, r7, r0
	strb r6, [r0]
	mov r2, r8
	ldrb r0, [r2]
	add r0, r10
	ldrb r1, [r0]
	mov r2, r9
	adds r2, 0xC
	adds r1, r2, r1
	ldrb r6, [r1]
	ldrb r0, [r5]
	adds r0, r2, r0
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r5]
	adds r2, r0
	strb r6, [r2]
	mov r3, r8
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r2, =gDisableStructs
	adds r6, r0, r2
	ldrb r4, [r6, 0x18]
	lsls r3, r4, 24
	lsrs r2, r3, 28
	ldr r0, =gBitTable
	mov r12, r0
	add r1, r10
	ldrb r0, [r1]
	lsls r0, 2
	add r0, r12
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	beq _0805822A
	lsrs r1, r3, 28
	bics r1, r0
	lsls r1, 4
	movs r2, 0xF
	adds r0, r2, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r6, 0x18]
	mov r1, r8
	ldrb r0, [r1]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	ldr r3, =gDisableStructs
	adds r1, r3
	ldrb r4, [r1, 0x18]
	lsrs r3, r4, 4
	ldrb r0, [r5]
	lsls r0, 2
	add r0, r12
	ldr r0, [r0]
	orrs r0, r3
	lsls r0, 4
	ands r2, r4
	orrs r2, r0
	strb r2, [r1, 0x18]
_0805822A:
	bl sub_8059AAC
	movs r6, 0
	mov r12, r7
	mov r5, sp
	adds r5, 0x18
	str r5, [sp, 0x1C]
	ldr r2, =gBattleMons
	mov r0, r8
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	adds r4, r0, 0
	adds r4, 0x3B
	mov r7, r8
	mov r10, r2
	movs r5, 0x3
_0805824E:
	mov r1, sp
	adds r3, r1, r6
	ldrb r1, [r4]
	lsls r2, r6, 1
	adds r0, r5, 0
	lsls r0, r2
	ands r1, r0
	asrs r1, r2
	strb r1, [r3]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805824E
	ldr r1, =gUnknown_020244B0
	ldrb r0, [r7]
	adds r0, r1
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
	ldr r2, [sp, 0x1C]
	strb r0, [r2]
	ldrb r0, [r7]
	adds r0, r1
	ldrb r0, [r0]
	mov r3, sp
	adds r2, r3, r0
	ldr r1, =gUnknown_03005D74
	ldrb r0, [r1]
	add r0, sp
	ldrb r0, [r0]
	movs r3, 0
	strb r0, [r2]
	ldrb r0, [r1]
	mov r5, sp
	adds r1, r5, r0
	ldr r2, [sp, 0x1C]
	ldrb r0, [r2]
	strb r0, [r1]
	strb r3, [r2]
	movs r6, 0
	ldr r2, [sp, 0x1C]
_0805829E:
	mov r3, sp
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r6, 1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805829E
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	add r0, r10
	adds r0, 0x3B
	ldr r5, [sp, 0x1C]
	ldrb r1, [r5]
	strb r1, [r0]
	movs r6, 0
	adds r4, r7, 0
	movs r3, 0x58
	movs r0, 0x24
	add r0, r10
	mov r8, r0
	mov r2, r9
	mov r7, r10
	adds r7, 0xC
	mov r5, r12
_080582D8:
	lsls r1, r6, 1
	ldrb r0, [r4]
	muls r0, r3
	adds r1, r0
	adds r1, r7
	ldrh r0, [r2]
	strh r0, [r1]
	ldrb r0, [r4]
	adds r1, r0, 0
	muls r1, r3
	adds r1, r6, r1
	add r1, r8
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _080582D8
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	movs r0, 0x58
	muls r0, r1
	mov r1, r10
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	beq _0805831A
	b _080584A8
_0805831A:
	movs r6, 0
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x20]
	add r3, sp, 0xC
	mov r10, r3
	ldr r5, =gBattlePartyID
	mov r9, r5
	mov r8, r2
	movs r7, 0x64
	ldr r5, =gPlayerParty
	adds r4, r1, 0
_08058332:
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r5
	adds r1, r6, 0
	adds r1, 0xD
	bl GetMonData
	strh r0, [r4]
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, 1
	add r0, r9
	ldrh r0, [r0]
	muls r0, r7
	adds r0, r5
	adds r1, r6, 0
	adds r1, 0x11
	bl GetMonData
	mov r3, r10
	adds r1, r3, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08058332
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	ldr r5, [sp, 0x1C]
	strb r0, [r5]
	movs r6, 0
	movs r5, 0x3
	ldr r4, [sp, 0x1C]
_08058392:
	mov r0, sp
	adds r3, r0, r6
	lsls r2, r6, 1
	adds r1, r5, 0
	lsls r1, r2
	ldrb r0, [r4]
	ands r0, r1
	asrs r0, r2
	strb r0, [r3]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08058392
	ldr r4, =gUnknown_020244B0
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	adds r0, r4
	ldrb r1, [r0]
	lsls r1, 1
	ldr r2, [sp, 0x20]
	adds r1, r2, r1
	ldrh r6, [r1]
	ldr r2, =gUnknown_03005D74
	ldrb r0, [r2]
	lsls r0, 1
	ldr r5, [sp, 0x20]
	adds r0, r5, r0
	ldrh r0, [r0]
	movs r5, 0
	strh r0, [r1]
	ldrb r0, [r2]
	lsls r0, 1
	ldr r1, [sp, 0x20]
	adds r0, r1, r0
	strh r6, [r0]
	ldrb r0, [r3]
	adds r0, r4
	ldrb r1, [r0]
	add r1, r10
	ldrb r6, [r1]
	ldrb r0, [r2]
	add r0, r10
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	add r0, r10
	strb r6, [r0]
	ldrb r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	add r0, sp
	ldrb r0, [r0]
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldrb r0, [r3]
	adds r0, r4
	ldrb r0, [r0]
	mov r3, sp
	adds r1, r3, r0
	ldrb r0, [r2]
	add r0, sp
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	adds r1, r3, r0
	ldr r2, [sp, 0x1C]
	ldrb r0, [r2]
	strb r0, [r1]
	strb r5, [r2]
	movs r6, 0
	ldr r2, [sp, 0x1C]
_0805841E:
	mov r3, sp
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r6, 1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805841E
	movs r6, 0
	ldr r5, =gBattlePartyID
	mov r10, r5
	ldr r0, =gActiveBank
	mov r9, r0
	movs r1, 0x64
	mov r8, r1
	ldr r7, =gPlayerParty
	ldr r5, [sp, 0x20]
	adds r5, 0x8
	ldr r4, [sp, 0x20]
_0805844A:
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 1
	add r0, r10
	ldrh r0, [r0]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	adds r0, r7
	adds r1, r6, 0
	adds r1, 0xD
	adds r2, r4, 0
	bl pokemon_setattr
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	add r0, r10
	ldrh r0, [r0]
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r0, r7
	adds r1, r6, 0
	adds r1, 0x11
	adds r2, r5, 0
	bl pokemon_setattr
	adds r5, 0x1
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805844A
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	ldr r2, [sp, 0x1C]
	bl pokemon_setattr
_080584A8:
	ldr r1, =gUnknown_03005D60
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
	ldr r3, =gUnknown_020244B0
	ldrb r0, [r2]
	adds r0, r3
	ldr r1, =gUnknown_03005D74
	ldrb r1, [r1]
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, r3
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	b _08058532
	.pool
_08058500:
	movs r0, 0x6
	ands r0, r1
	cmp r0, 0
	beq _08058554
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	bl battle_menu_cursor_related
	ldr r1, =gUnknown_020244B0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
_08058532:
	bl sub_8059B18
	bl sub_8059B3C
	bl sub_8059BB0
	b _080586E8
	.pool
_08058554:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080585A4
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _0805856A
	b _080586E8
_0805856A:
	ldr r0, =gUnknown_020244B0
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r5, [r1]
	cmp r2, r5
	bne _08058590
_08058578:
	ldrb r0, [r1]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	b _08058596
	.pool
_08058590:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
_08058596:
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	movs r1, 0x1
	b _0805862C
	.pool
_080585A4:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080585E8
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _080585BA
	b _080586E8
_080585BA:
	ldr r1, =gUnknown_03005D78
	movs r0, 0x1
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcc _080585C8
	b _080586E8
_080585C8:
	ldr r0, =gUnknown_020244B0
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r0, [r1]
	cmp r2, r0
	beq _08058578
	b _08058590
	.pool
_080585E8:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0805865C
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	beq _080586E8
	ldr r0, =gUnknown_020244B0
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r5, [r1]
	cmp r2, r5
	bne _08058620
	ldrb r0, [r1]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	b _08058626
	.pool
_08058620:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
_08058626:
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	movs r1, 0x2
_0805862C:
	eors r0, r1
	strb r0, [r4]
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020244B0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080586CA
	ldrb r0, [r4]
	movs r1, 0x1B
	bl battle_menu_cursor_related_2
	b _080586E8
	.pool
_0805865C:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080586E8
	ldr r3, =gUnknown_03005D74
	ldrb r2, [r3]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _080586E8
	ldr r1, =gUnknown_03005D78
	movs r0, 0x2
	eors r0, r2
	ldrb r1, [r1]
	cmp r0, r1
	bcs _080586E8
	ldr r0, =gUnknown_020244B0
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	adds r1, r0
	ldrb r0, [r1]
	cmp r2, r0
	bne _080586A4
	ldrb r0, [r1]
	movs r1, 0x1D
	bl battle_menu_cursor_related_2
	b _080586AA
	.pool
_080586A4:
	ldrb r0, [r3]
	bl battle_menu_cursor_related
_080586AA:
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	movs r1, 0x2
	eors r0, r1
	strb r0, [r4]
	movs r0, 0x5
	bl audio_play
	ldr r1, =gUnknown_020244B0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	bne _080586E0
_080586CA:
	adds r0, r1, 0
	movs r1, 0
	bl battle_menu_cursor_related_2
	b _080586E8
	.pool
_080586E0:
	ldrb r0, [r4]
	movs r1, 0x1B
	bl battle_menu_cursor_related_2
_080586E8:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8058138

	thumb_func_start sub_80586F8
sub_80586F8: @ 80586F8
	push {lr}
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805875C
	ldr r0, =gUnknown_03003124
	ldrb r0, [r0]
	cmp r0, 0
	bne _08058798
	movs r0, 0x5A
	bl m4aSongNumStop
	ldr r3, =gMain
	ldr r0, =0x00000439
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, =sub_8038D64
	bl SetMainCallback2
	ldr r0, =gUnknown_0202433A
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08058738
	bl sub_817E3F4
_08058738:
	bl FreeAllWindowBuffers
	b _08058798
	.pool
_0805875C:
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08058798
	movs r0, 0x5A
	bl m4aSongNumStop
	ldr r3, =gMain
	ldr r0, =0x00000439
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, =sub_8038D64
	bl SetMainCallback2
	ldr r0, =gUnknown_0202433A
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08058794
	bl sub_817E3F4
_08058794:
	bl FreeAllWindowBuffers
_08058798:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80586F8

	thumb_func_start sub_80587B0
sub_80587B0: @ 80587B0
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08058832
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08058810
	bl sub_800A520
	lsls r0, 24
	cmp r0, 0
	beq _08058832
	ldr r0, =gLinkVSyncDisabled
	ldrb r0, [r0]
	cmp r0, 0
	bne _080587F0
	bl sub_800AC34
	b _080587F4
	.pool
_080587F0:
	bl sub_800ADF8
_080587F4:
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80586F8
	str r1, [r0]
	b _08058832
	.pool
_08058810:
	movs r0, 0x5A
	bl m4aSongNumStop
	ldr r2, =gMain
	ldr r0, =0x00000439
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r2, 0x8]
	bl SetMainCallback2
_08058832:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80587B0

	thumb_func_start sub_8058844
sub_8058844: @ 8058844
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08058868
	bl dp01_tbl1_exec_completed
_08058868:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058844

	thumb_func_start sub_805887C
sub_805887C: @ 805887C
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _080588A0
	bl dp01_tbl1_exec_completed
_080588A0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805887C

	thumb_func_start bx_802F7A0
bx_802F7A0: @ 80588B4
	push {r4-r6,lr}
	ldr r6, =gUnknown_02020630
	ldr r5, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08058908
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl nullsub_25
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl obj_free_rotscale_entry
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl RemoveObjectAndFreeTiles
	bl dp01_tbl1_exec_completed
_08058908:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_802F7A0

	thumb_func_start sub_8058924
sub_8058924: @ 8058924
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r1, [r4]
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x9]
	subs r0, 0x1
	strb r0, [r1, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _0805895C
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl dp01_tbl1_exec_completed
_0805895C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058924

	thumb_func_start sub_805896C
sub_805896C: @ 805896C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r7, 0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058998
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _080589D0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080589D0
_08058998:
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_03005D70
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	mov r10, r3
	cmp r1, r0
	bne _08058A0A
	b _08058A0E
	.pool
_080589D0:
	ldr r3, =gUnknown_02020630
	ldr r6, =gUnknown_03005D70
	ldr r2, =gActiveBank
	ldrb r4, [r2]
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r3, 0
	adds r5, 0x1C
	adds r0, r5
	ldr r3, [r0]
	ldr r0, =DummyObjectCallback
	mov r10, r2
	cmp r3, r0
	bne _08058A0A
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	cmp r0, r3
	bne _08058A0A
	movs r7, 0x1
_08058A0A:
	cmp r7, 0
	beq _08058B08
_08058A0E:
	ldr r0, =gUnknown_020244D0
	mov r9, r0
	ldr r0, [r0]
	mov r6, r10
	ldrb r2, [r6]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r3
	ldrb r1, [r4, 0x1]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08058B08
	movs r1, 0x2
	mov r8, r1
	mov r1, r8
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08058B08
	ldrb r1, [r4]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4]
	mov r2, r9
	ldr r0, [r2]
	ldrb r2, [r6]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	mov r0, r9
	ldr r2, [r0]
	ldrb r0, [r6]
	mov r1, r8
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	mov r1, r9
	ldr r2, [r1]
	ldrb r0, [r6]
	mov r1, r8
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	ands r4, r1
	strb r4, [r0, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	ldr r7, =gBattlePartyID
	ldrb r1, [r6]
	lsls r0, r1, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	bl sub_805E990
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058AE4
	ldrb r0, [r6]
	mov r1, r8
	eors r1, r0
	lsls r0, r1, 1
	adds r0, r7
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	bl sub_805E990
_08058AE4:
	mov r2, r9
	ldr r0, [r2]
	mov r2, r10
	ldrb r1, [r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x9]
	ldr r1, =gUnknown_03005D60
	mov r2, r10
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058924
	str r1, [r0]
_08058B08:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805896C

	thumb_func_start sub_8058B40
sub_8058B40: @ 8058B40
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r0, 0
	mov r9, r0
	mov r8, r0
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r5, 0x88
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08058B80
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08058B80:
	ldr r1, [r4]
	ldrb r0, [r7]
	movs r6, 0x2
	adds r2, r6, 0
	eors r2, r0
	ldr r1, [r1, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08058BB2
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08058BB2:
	ldr r0, [r4]
	ldrb r2, [r7]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r3
	ldrb r1, [r4]
	movs r5, 0x8
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08058C82
	adds r1, r6, 0
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08058C82
	ldrb r1, [r4, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08058C68
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058C38
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08058C38
	ldr r4, =gUnknown_03005D70
	ldrb r0, [r7]
	adds r1, r6, 0
	eors r1, r0
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r7]
	eors r0, r6
	bl sub_8076918
	ldrb r0, [r7]
	eors r0, r6
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_08058C38:
	ldr r5, =gUnknown_03005D70
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
_08058C68:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x1]
_08058C82:
	ldr r5, =gUnknown_020244D0
	ldr r0, [r5]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	bne _08058D32
	movs r1, 0x2
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08058D32
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _08058D32
	ldr r0, [r5]
	ldrb r1, [r4]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08058D14
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _08058D08
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	b _08058D14
	.pool
_08058D08:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_08058D14:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r0, 0x1
	mov r9, r0
_08058D32:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058D52
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058DAC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08058DAC
_08058D52:
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_03005D7C
	ldr r1, =gActiveBank
	ldrb r4, [r1]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r3, [r0]
	ldr r0, =DummyObjectCallback
	cmp r3, r0
	bne _08058E0A
	ldr r0, =gUnknown_020241E4
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r3
	bne _08058E0A
	b _08058E06
	.pool
_08058DAC:
	ldr r2, =gUnknown_02020630
	ldr r7, =gUnknown_03005D7C
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	adds r0, r3, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r4, [r0]
	ldr r0, =DummyObjectCallback
	cmp r4, r0
	bne _08058E0A
	ldr r6, =gUnknown_020241E4
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r5, [r0]
	cmp r5, r4
	bne _08058E0A
	movs r0, 0x2
	eors r3, r0
	adds r0, r3, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r4, [r0]
	cmp r4, r5
	bne _08058E0A
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _08058E0A
_08058E06:
	movs r0, 0x1
	mov r8, r0
_08058E0A:
	mov r0, r9
	cmp r0, 0
	beq _08058EAA
	mov r0, r8
	cmp r0, 0
	beq _08058EAA
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08058E48
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08058E48
	ldr r2, =gUnknown_03005D7C
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x2
	eors r0, r1
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	bl RemoveObjectAndFreeTiles
_08058E48:
	ldr r1, =gUnknown_03005D7C
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	bl RemoveObjectAndFreeTiles
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r1, [r2, 0x9]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x9]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805896C
	str r1, [r0]
_08058EAA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058B40

	thumb_func_start sub_8058EDC
sub_8058EDC: @ 8058EDC
	push {r4-r6,lr}
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_03005D70
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r4, [r0]
	ldr r0, =DummyObjectCallback
	cmp r4, r0
	bne _08058F94
	ldr r5, =gUnknown_020244D0
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08058F94
	ldr r0, =gUnknown_020241E4
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _08058F94
	adds r0, r3, 0
	bl sub_805E408
	ldr r0, [r5]
	ldrb r2, [r6]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r5]
	ldrb r2, [r6]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	ldr r0, [r5]
	ldrb r2, [r6]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08058F88
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
_08058F88:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8058FC0
	str r0, [r1]
_08058F94:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058EDC

	thumb_func_start sub_8058FC0
sub_8058FC0: @ 8058FC0
	push {r4,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805900E
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _0805900E
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	ldr r2, =gBattlePartyID
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	bl dp01_tbl1_exec_completed
_0805900E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8058FC0

	thumb_func_start sub_805902C
sub_805902C: @ 805902C
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	bne _0805905E
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_0805905E:
	ldr r4, =gUnknown_02020630
	ldr r0, =gUnknown_03005D7C
	ldrb r2, [r5]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r3, r0, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r3, r0
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _080590D2
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080590D2
	adds r0, r3, r4
	bl RemoveObjectAndFreeTiles
	ldr r4, =gUnknown_03005D70
	ldrb r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r5]
	bl sub_8076918
	ldrb r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058EDC
	str r1, [r0]
_080590D2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805902C

	thumb_func_start c3_0802FDF4
c3_0802FDF4: @ 8059100
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _08059122
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	adds r0, r4, 0
	bl DestroyTask
_08059122:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_0802FDF4

	thumb_func_start bx_t1_healthbar_update
bx_t1_healthbar_update: @ 8059130
	push {r4-r6,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r6, =gUnknown_03005D70
	adds r1, r0, r6
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	bl sub_80729D0
	lsls r4, 16
	asrs r1, r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08059178
	ldrb r0, [r5]
	adds r0, r6
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _08059192
	.pool
_08059178:
	ldr r2, =gBattlePartyID
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	bl dp01_tbl1_exec_completed
_08059192:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_t1_healthbar_update

	thumb_func_start sub_80591A0
sub_80591A0: @ 80591A0
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080591B2
	bl dp01_tbl1_exec_completed
_080591B2:
	pop {r0}
	bx r0
	thumb_func_end sub_80591A0

	thumb_func_start sub_80591B8
sub_80591B8: @ 80591B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	mov r8, r0
	ldrb r0, [r0, 0x8]
	mov r10, r0
	mov r1, r8
	ldrb r7, [r1, 0xC]
	str r7, [sp, 0x8]
	ldrh r2, [r1, 0xA]
	str r2, [sp, 0xC]
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _080591FE
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r10, r0
	bne _080591FE
	b _08059314
_080591FE:
	movs r0, 0x64
	mov r1, r10
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r6, r1, r0
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x4]
	ldr r3, =gExperienceTables
	adds r4, 0x1
	lsls r4, 2
	ldr r2, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x13]
	movs r1, 0xCA
	lsls r1, 1
	muls r1, r2
	adds r4, r1
	adds r4, r3
	ldr r2, [r4]
	str r2, [sp]
	ldr r3, [sp, 0xC]
	lsls r1, r3, 16
	asrs r1, 16
	adds r0, r1
	cmp r0, r2
	bcc _080592EC
	adds r0, r6, 0
	movs r1, 0x19
	mov r2, sp
	bl pokemon_setattr
	adds r0, r6, 0
	bl pokemon_calc_effective_stats
	ldr r2, [sp]
	add r0, sp, 0x4
	ldrh r0, [r0]
	subs r2, r0
	ldr r0, [sp, 0xC]
	subs r2, r0, r2
	ldr r4, =gActiveBank
	ldrb r5, [r4]
	strb r7, [r4]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xB
	bl dp01_build_cmdbuf_x21_a_bb
	strb r5, [r4]
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080592D4
	ldr r2, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r2
	mov r1, r10
	ldrh r0, [r0]
	cmp r1, r0
	beq _080592B2
	movs r0, 0x2
	eors r7, r0
	lsls r0, r7, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r1, r0
	bne _080592D4
_080592B2:
	ldr r0, =sub_8059544
	b _08059316
	.pool
_080592D4:
	ldr r0, =gTasks
	mov r2, r9
	lsls r1, r2, 2
	add r1, r9
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_805965C
	b _08059318
	.pool
_080592EC:
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r6, 0
	movs r1, 0x19
	bl pokemon_setattr
	ldr r1, =gUnknown_03005D60
	ldr r3, [sp, 0x8]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, =sub_80591A0
	str r1, [r0]
	mov r0, r9
	bl DestroyTask
	b _0805931A
	.pool
_08059314:
	ldr r0, =sub_8059330
_08059316:
	mov r1, r8
_08059318:
	str r0, [r1]
_0805931A:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80591B8

	thumb_func_start sub_8059330
sub_8059330: @ 8059330
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	mov r8, r2
	add r8, r0
	mov r0, r8
	lsls r0, 3
	mov r8, r0
	add r8, r1
	mov r2, r8
	ldrb r1, [r2, 0x8]
	movs r0, 0xA
	ldrsh r2, [r2, r0]
	mov r9, r2
	mov r2, r8
	ldrb r2, [r2, 0xC]
	mov r10, r2
	movs r0, 0x64
	adds r6, r1, 0
	muls r6, r0
	ldr r0, =gPlayerParty
	adds r6, r0
	adds r0, r6, 0
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	movs r1, 0x19
	bl GetMonData
	adds r3, r0, 0
	ldr r6, =gExperienceTables
	lsls r1, r4, 2
	ldr r2, =gBaseStats
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r2
	ldrb r2, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r2
	adds r1, r0
	adds r1, r6
	ldr r1, [r1]
	subs r3, r1
	adds r4, 0x1
	lsls r4, 2
	adds r4, r0
	adds r4, r6
	ldr r2, [r4]
	subs r2, r1
	ldr r0, =gUnknown_03005D70
	add r0, r10
	ldrb r1, [r0]
	mov r0, r9
	negs r0, r0
	str r0, [sp]
	mov r0, r10
	bl sub_807294C
	movs r0, 0x21
	bl audio_play
	ldr r0, =sub_8059400
	mov r1, r8
	str r0, [r1]
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059330

	thumb_func_start sub_8059400
sub_8059400: @ 8059400
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r6, r0, r1
	ldrh r1, [r6, 0x1C]
	movs r2, 0x1C
	ldrsh r0, [r6, r2]
	cmp r0, 0xC
	bgt _08059430
	adds r0, r1, 0x1
	strh r0, [r6, 0x1C]
	b _0805952C
	.pool
_08059430:
	ldrb r0, [r6, 0x8]
	mov r9, r0
	ldrh r2, [r6, 0xA]
	mov r10, r2
	ldrb r7, [r6, 0xC]
	ldr r5, =gUnknown_03005D70
	adds r5, r7, r5
	ldrb r1, [r5]
	adds r0, r7, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5]
	bl sub_80729D0
	lsls r4, 16
	asrs r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r4, r0
	bne _0805952C
	movs r0, 0x21
	bl m4aSongNumStop
	movs r0, 0x64
	mov r1, r9
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r3, =gExperienceTables
	adds r4, 0x1
	lsls r4, 2
	ldr r2, =gBaseStats
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r1, [r1, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r1
	adds r4, r0
	adds r4, r3
	ldr r1, [r4]
	str r1, [sp]
	mov r2, r10
	lsls r0, r2, 16
	asrs r4, r0, 16
	ldr r0, [sp, 0x4]
	adds r0, r4
	cmp r0, r1
	blt _08059510
	adds r0, r5, 0
	movs r1, 0x19
	mov r2, sp
	bl pokemon_setattr
	adds r0, r5, 0
	bl pokemon_calc_effective_stats
	ldr r2, [sp]
	add r0, sp, 0x4
	ldrh r0, [r0]
	subs r2, r0
	subs r2, r4, r2
	ldr r4, =gActiveBank
	ldrb r5, [r4]
	strb r7, [r4]
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xB
	bl dp01_build_cmdbuf_x21_a_bb
	strb r5, [r4]
	ldr r0, =sub_8059544
	str r0, [r6]
	b _0805952C
	.pool
_08059510:
	str r0, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r5, 0
	movs r1, 0x19
	bl pokemon_setattr
	ldr r1, =gUnknown_03005D60
	lsls r0, r7, 2
	adds r0, r1
	ldr r1, =sub_80591A0
	str r1, [r0]
	mov r0, r8
	bl DestroyTask
_0805952C:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059400

	thumb_func_start sub_8059544
sub_8059544: @ 8059544
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrb r4, [r0, 0xC]
	ldrb r6, [r0, 0x8]
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08059578
	ldr r1, =gBattlePartyID
	movs r0, 0x2
	adds r2, r4, 0
	eors r2, r0
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r6, r0
	bne _08059578
	adds r4, r2, 0
_08059578:
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r4, 0
	movs r3, 0
	bl move_anim_start_t4
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80595A4
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059544

	thumb_func_start sub_80595A4
sub_80595A4: @ 80595A4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r2, r0, r1
	ldrb r5, [r2, 0xC]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08059646
	ldrb r4, [r2, 0x8]
	movs r0, 0x64
	adds r1, r4, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	adds r0, r7, 0
	movs r1, 0x38
	bl GetMonData
	bl battle_type_is_double
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08059624
	ldr r1, =gBattlePartyID
	movs r0, 0x2
	adds r2, r5, 0
	eors r2, r0
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _08059624
	ldr r0, =gUnknown_03005D70
	adds r0, r2, r0
	ldrb r0, [r0]
	adds r1, r7, 0
	movs r2, 0
	bl healthbar_draw_field_maybe
	b _08059638
	.pool
_08059624:
	ldr r0, =gUnknown_03005D70
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x64
	muls r1, r4
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
_08059638:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_805965C
	str r0, [r1]
_08059646:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80595A4

	thumb_func_start sub_805965C
sub_805965C: @ 805965C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	ldrb r1, [r4, 0x8]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	bl GetMonData
	ldrb r0, [r4, 0xC]
	ldr r1, =gUnknown_03005D60
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80591A0
	str r1, [r0]
	adds r0, r5, 0
	bl DestroyTask
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805965C

	thumb_func_start sub_80596A8
sub_80596A8: @ 80596A8
	push {r4-r6,lr}
	ldr r6, =gUnknown_02020630
	ldr r5, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r3, 0x22
	ldrsh r1, [r0, r3]
	movs r3, 0x26
	ldrsh r0, [r0, r3]
	adds r1, r0
	cmp r1, 0xA0
	ble _08059724
	ldr r1, =gBattlePartyID
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl nullsub_24
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl rotscale_free_entry
	ldrb r0, [r4]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl RemoveObjectAndFreeTiles
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl1_exec_completed
_08059724:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80596A8

	thumb_func_start sub_8059744
sub_8059744: @ 8059744
	push {r4-r6,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08059798
	ldr r5, =gUnknown_020241E4
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl RemoveObjectAndFreeTiles
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl1_exec_completed
_08059798:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059744

	thumb_func_start sub_80597B4
sub_80597B4: @ 80597B4
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _080597C6
	bl dp01_tbl1_exec_completed
_080597C6:
	pop {r0}
	bx r0
	thumb_func_end sub_80597B4

	thumb_func_start sub_80597CC
sub_80597CC: @ 80597CC
	push {r4,lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0805980A
	ldr r1, =gUnknown_03005D60
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8059828
	str r1, [r0]
	ldr r3, =gTasks
	ldr r1, =gUnknown_03005D7C
	ldrb r0, [r2]
	adds r0, r1
	ldrb r0, [r0]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r3
	ldrb r4, [r1, 0x8]
	bl DestroyTask
	bl FreeAllWindowBuffers
	adds r0, r4, 0
	bl sub_81B89AC
_0805980A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80597CC

	thumb_func_start sub_8059828
sub_8059828: @ 8059828
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	bne _08059898
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08059898
	ldr r0, =gUnknown_0203CEE8
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08059870
	ldr r0, =gUnknown_0203CEE9
	ldrb r1, [r0]
	ldr r2, =gUnknown_0203CF00
	movs r0, 0x1
	bl dp01_build_cmdbuf_x22_a_three_bytes
	b _0805987A
	.pool
_08059870:
	movs r0, 0x1
	movs r1, 0x6
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
_0805987A:
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _08059894
	bl b_link_standby_message
_08059894:
	bl dp01_tbl1_exec_completed
_08059898:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059828

	thumb_func_start sub_80598A4
sub_80598A4: @ 80598A4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080598CC
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80598E0
	str r1, [r0]
	bl nullsub_35
	bl FreeAllWindowBuffers
	bl sub_81AABB0
_080598CC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80598A4

	thumb_func_start sub_80598E0
sub_80598E0: @ 80598E0
	push {lr}
	ldr r0, =gMain
	ldr r1, [r0, 0x4]
	ldr r0, =sub_8038420
	cmp r1, r0
	bne _08059906
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08059906
	ldr r0, =gUnknown_0203CE7C
	ldrh r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl dp01_tbl1_exec_completed
_08059906:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80598E0

	thumb_func_start bx_wait_t1
bx_wait_t1: @ 805991C
	push {lr}
	ldr r0, =gUnknown_020244B9
	ldrb r0, [r0]
	cmp r0, 0
	beq _08059942
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08059946
_08059942:
	bl dp01_tbl1_exec_completed
_08059946:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_wait_t1

	thumb_func_start bx_blink_t1
bx_blink_t1: @ 8059958
	push {r4,lr}
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gUnknown_02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	bne _080599A4
	movs r3, 0
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_020244B9
	strb r3, [r0]
	bl dp01_tbl1_exec_completed
	b _080599CE
	.pool
_080599A4:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080599C8
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_080599C8:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_080599CE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bx_blink_t1

	thumb_func_start sub_80599D4
sub_80599D4: @ 80599D4
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08059A02
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	cmp r0, 0
	beq _08059A02
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	bl sub_8056BAC
	movs r0, 0
	strb r0, [r4]
	movs r0, 0
	bl sub_8056B74
_08059A02:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08059A2C
	ldr r4, =gUnknown_03005D74
	ldrb r0, [r4]
	cmp r0, 0
	bne _08059A2C
	movs r0, 0x5
	bl audio_play
	ldrb r0, [r4]
	bl sub_8056BAC
	movs r0, 0x1
	strb r0, [r4]
	movs r0, 0x1
	bl sub_8056B74
_08059A2C:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08059A7A
	str r2, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	movs r0, 0x5
	bl audio_play
	ldr r0, =gUnknown_03005D74
	ldrb r0, [r0]
	cmp r0, 0
	beq _08059A6C
	movs r0, 0x1
	movs r1, 0xE
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08059A76
	.pool
_08059A6C:
	movs r0, 0x1
	movs r1, 0xD
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
_08059A76:
	bl dp01_tbl1_exec_completed
_08059A7A:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08059AA0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	movs r0, 0x5
	bl audio_play
	bl dp01_tbl1_exec_completed
_08059AA0:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80599D4

	thumb_func_start sub_8059AAC
sub_8059AAC: @ 8059AAC
	push {r4-r7,lr}
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 9
	ldr r3, =gUnknown_02023068
	ldr r2, =gUnknown_03005D78
	movs r0, 0
	strb r0, [r2]
	movs r5, 0
	ldr r7, =gUnknown_02022E2C
	adds r4, r1, r3
	adds r6, r2, 0
_08059AC4:
	lsls r0, r5, 24
	lsrs r0, 24
	bl battle_menu_cursor_related
	ldrh r1, [r4]
	movs r0, 0xD
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	adds r0, r7, 0
	bl StringCopy
	adds r1, r5, 0x3
	lsls r1, 24
	lsrs r1, 24
	adds r0, r7, 0
	bl battle_show_message_maybe
	ldrh r0, [r4]
	cmp r0, 0
	beq _08059AF4
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
_08059AF4:
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _08059AC4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059AAC

	thumb_func_start sub_8059B18
sub_8059B18: @ 8059B18
	push {r4,lr}
	ldr r4, =gUnknown_02022E2C
	ldr r1, =gUnknown_085CCA6F
	adds r0, r4, 0
	bl StringCopy
	adds r0, r4, 0
	movs r1, 0x7
	bl battle_show_message_maybe
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059B18

	thumb_func_start sub_8059B3C
sub_8059B3C: @ 8059B3C
	push {r4-r7,lr}
	ldr r5, =gUnknown_02023064
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	lsls r0, 9
	adds r1, r5, 0x2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08059B98
	bl sub_814FBAC
	ldrb r1, [r7]
	lsls r4, r1, 9
	adds r0, r5, 0x4
	adds r4, r0
	ldr r6, =gUnknown_02022E2C
	ldr r5, =gUnknown_020244B0
	adds r1, r5
	adds r0, r4, 0
	adds r0, 0x8
	ldrb r1, [r1]
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	movs r1, 0xBA
	strb r1, [r0]
	adds r0, 0x1
	ldrb r1, [r7]
	adds r1, r5
	adds r4, 0xC
	ldrb r1, [r1]
	adds r4, r1
	ldrb r1, [r4]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	movs r1, 0x9
	bl battle_show_message_maybe
_08059B98:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059B3C

	thumb_func_start sub_8059BB0
sub_8059BB0: @ 8059BB0
	push {r4-r6,lr}
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r4, 9
	ldr r0, =gUnknown_02023068
	adds r4, r0
	ldr r6, =gUnknown_02022E2C
	ldr r1, =gUnknown_085CCA73
	adds r0, r6, 0
	bl StringCopy
	movs r1, 0xFC
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x6
	strb r1, [r0]
	adds r0, 0x1
	movs r1, 0x1
	strb r1, [r0]
	adds r0, 0x1
	ldr r3, =gBattleMoves
	ldr r2, =gUnknown_020244B0
	ldrb r1, [r5]
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 1
	adds r4, r1
	ldrh r2, [r4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1, 0x2]
	lsls r1, r2, 3
	subs r1, r2
	ldr r2, =gTypeNames
	adds r1, r2
	bl StringCopy
	adds r0, r6, 0
	movs r1, 0xA
	bl battle_show_message_maybe
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059BB0

	thumb_func_start battle_menu_cursor_related_2
battle_menu_cursor_related_2: @ 8059C28
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r1, 24
	lsrs r1, 24
	add r2, sp, 0xC
	adds r0, r1, 0x1
	strh r0, [r2]
	adds r0, r2, 0
	adds r1, 0x2
	strh r1, [r0, 0x2]
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	lsls r2, r0, 3
	adds r2, r0
	adds r2, 0x1
	movs r0, 0x2
	ands r3, r0
	adds r3, 0x37
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	thumb_func_end battle_menu_cursor_related_2

	thumb_func_start battle_menu_cursor_related
battle_menu_cursor_related: @ 8059C70
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	ldr r1, =0x00001016
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	lsls r2, r0, 3
	adds r2, r0
	adds r2, 0x1
	movs r0, 0x2
	ands r3, r0
	adds r3, 0x37
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end battle_menu_cursor_related

	thumb_func_start sub_8059CB4
sub_8059CB4: @ 8059CB4
	push {r4,lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	movs r4, 0x1
	strh r4, [r0]
	movs r1, 0x2
	strh r1, [r0, 0x2]
	adds r0, r3, 0
	ands r0, r4
	lsls r2, r0, 3
	subs r2, r0
	adds r2, 0x10
	lsls r2, 24
	lsrs r2, 24
	ands r3, r1
	adds r3, 0x23
	str r4, [sp]
	str r1, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8059CB4

	thumb_func_start sub_8059CF8
sub_8059CF8: @ 8059CF8
	push {lr}
	sub sp, 0x10
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	add r0, sp, 0xC
	ldr r1, =0x00001016
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	lsls r2, r0, 3
	subs r2, r0
	adds r2, 0x10
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0x2
	ands r3, r0
	adds r3, 0x23
	str r1, [sp]
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	add r1, sp, 0xC
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059CF8

	thumb_func_start sub_8059D40
sub_8059D40: @ 8059D40
	push {lr}
	ldr r0, =sub_80A92F8
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059D40

	thumb_func_start sub_8059D50
sub_8059D50: @ 8059D50
	push {lr}
	ldr r0, =sub_80A92F8
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059D50

	thumb_func_start sub_8059D60
sub_8059D60: @ 8059D60
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08059D82
	bl dp01_tbl1_exec_completed
_08059D82:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8059D60

	thumb_func_start bx_8030B2C
bx_8030B2C: @ 8059D90
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08059DB2
	bl dp01_tbl1_exec_completed
_08059DB2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_8030B2C

	thumb_func_start b_link_standby_message
b_link_standby_message: @ 8059DC0
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _08059DE0
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r0, =gUnknown_085CCA29
	movs r1, 0
	bl battle_show_message_maybe
_08059DE0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_link_standby_message

	thumb_func_start dp01t_00_1_getattr
dp01t_00_1_getattr: @ 8059DF4
	push {r4-r6,lr}
	sub sp, 0x100
	movs r6, 0
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08059E2C
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl dp01_getattr_by_ch1_for_player_pokemon_
	adds r6, r0, 0
	b _08059E4E
	.pool
_08059E2C:
	ldrb r4, [r1]
	movs r5, 0
_08059E30:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08059E46
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl dp01_getattr_by_ch1_for_player_pokemon_
	adds r6, r0
_08059E46:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _08059E30
_08059E4E:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl dp01_tbl1_exec_completed
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_1_getattr

	thumb_func_start dp01_getattr_by_ch1_for_player_pokemon_
dp01_getattr_by_ch1_for_player_pokemon_: @ 8059E68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x90
	adds r7, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r2, =gUnknown_02023064
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3B
	bls _08059E92
	bl _0805A5FE
_08059E92:
	lsls r0, 2
	ldr r1, =_08059EA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08059EA8:
	.4byte _08059F98
	.4byte _0805A1BC
	.4byte _0805A1CC
	.4byte _0805A1DC
	.4byte _0805A244
	.4byte _0805A244
	.4byte _0805A244
	.4byte _0805A244
	.4byte _0805A260
	.4byte _0805A29C
	.4byte _0805A29C
	.4byte _0805A29C
	.4byte _0805A29C
	.4byte _0805A5FE
	.4byte _0805A5FE
	.4byte _0805A5FE
	.4byte _0805A5FE
	.4byte _0805A2B8
	.4byte _0805A2C8
	.4byte _0805A2F8
	.4byte _0805A308
	.4byte _0805A318
	.4byte _0805A328
	.4byte _0805A338
	.4byte _0805A348
	.4byte _0805A358
	.4byte _0805A368
	.4byte _0805A378
	.4byte _0805A388
	.4byte _0805A398
	.4byte _0805A3A8
	.4byte _0805A3B8
	.4byte _0805A408
	.4byte _0805A418
	.4byte _0805A428
	.4byte _0805A438
	.4byte _0805A448
	.4byte _0805A458
	.4byte _0805A468
	.4byte _0805A478
	.4byte _0805A488
	.4byte _0805A4BC
	.4byte _0805A4CC
	.4byte _0805A4DC
	.4byte _0805A4EC
	.4byte _0805A4FC
	.4byte _0805A50C
	.4byte _0805A51C
	.4byte _0805A52C
	.4byte _0805A54C
	.4byte _0805A55C
	.4byte _0805A56C
	.4byte _0805A57C
	.4byte _0805A58C
	.4byte _0805A59C
	.4byte _0805A5AC
	.4byte _0805A5BC
	.4byte _0805A5CC
	.4byte _0805A5DC
	.4byte _0805A5EC
_08059F98:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2E]
	movs r6, 0
	add r0, sp, 0x24
	mov r9, r0
	movs r1, 0x3B
	add r1, sp
	mov r10, r1
	mov r2, sp
	adds r2, 0x2B
	str r2, [sp, 0x80]
	mov r0, sp
	adds r0, 0x2A
	str r0, [sp, 0x7C]
	mov r1, sp
	adds r1, 0x68
	str r1, [sp, 0x8C]
	adds r2, 0x5
	str r2, [sp, 0x84]
	adds r0, 0x12
	str r0, [sp, 0x88]
	mov r8, r4
	add r4, sp, 0xC
_08059FE4:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r8
	bl GetMonData
	strh r0, [r4]
	adds r1, r6, 0
	adds r1, 0x11
	mov r0, r8
	bl GetMonData
	mov r2, r9
	adds r1, r2, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08059FE4
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	mov r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	mov r3, sp
	movs r5, 0x1F
	ands r0, r5
	ldrb r2, [r3, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	mov r3, sp
	movs r6, 0x1F
	ands r0, r6
	lsls r0, 5
	ldrh r2, [r3, 0x14]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 2
	ldrb r2, [r3, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [sp, 0x14]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	mov r3, sp
	ands r0, r6
	lsls r0, 4
	ldrh r2, [r3, 0x16]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 1
	ldrb r2, [r3, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x48]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	str r0, [sp, 0x4C]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x7C]
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	mov r3, sp
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r3, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	mov r3, sp
	lsls r0, 7
	ldrb r2, [r3, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x54]
	adds r0, r4, 0
	movs r1, 0x2
	ldr r2, [sp, 0x8C]
	bl GetMonData
	ldr r0, [sp, 0x84]
	ldr r1, [sp, 0x8C]
	bl StringCopy10
	adds r0, r4, 0
	movs r1, 0x7
	ldr r2, [sp, 0x88]
	bl GetMonData
	mov r2, sp
	movs r6, 0
_0805A19C:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _0805A19C
	b _0805A5FE
	.pool
_0805A1BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	b _0805A536
	.pool
_0805A1CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	b _0805A536
	.pool
_0805A1DC:
	movs r6, 0
	add r2, sp, 0x58
	mov r9, r2
	add r0, sp, 0x60
	mov r10, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	mov r8, r9
_0805A1F2:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r4, 0
	bl GetMonData
	mov r2, r10
	adds r1, r2, r6
	strb r0, [r1]
	movs r0, 0x2
	add r8, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805A1F2
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1, 0xC]
	mov r2, r9
	movs r6, 0
_0805A230:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _0805A230
	b _0805A5FE
	.pool
_0805A244:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x9
	b _0805A536
	.pool
_0805A260:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gPlayerParty
	mov r8, r2
_0805A26C:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _0805A26C
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _0805A5FE
	.pool
_0805A29C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x8
	b _0805A5F6
	.pool
_0805A2B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1
	b _0805A2D2
	.pool
_0805A2C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x19
_0805A2D2:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	movs r6, 0x3
	b _0805A5FE
	.pool
_0805A2F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1A
	b _0805A5F6
	.pool
_0805A308:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1B
	b _0805A5F6
	.pool
_0805A318:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1C
	b _0805A5F6
	.pool
_0805A328:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1D
	b _0805A5F6
	.pool
_0805A338:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1E
	b _0805A5F6
	.pool
_0805A348:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1F
	b _0805A5F6
	.pool
_0805A358:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x20
	b _0805A5F6
	.pool
_0805A368:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x22
	b _0805A5F6
	.pool
_0805A378:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x23
	b _0805A5F6
	.pool
_0805A388:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x24
	b _0805A5F6
	.pool
_0805A398:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x25
	b _0805A5F6
	.pool
_0805A3A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x26
	b _0805A5F6
	.pool
_0805A3B8:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	strb r0, [r7, 0x1]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	strb r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	strb r0, [r7, 0x3]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	strb r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	strb r0, [r7, 0x5]
	movs r6, 0x6
	b _0805A5FE
	.pool
_0805A408:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x27
	b _0805A5F6
	.pool
_0805A418:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x28
	b _0805A5F6
	.pool
_0805A428:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x29
	b _0805A5F6
	.pool
_0805A438:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2A
	b _0805A5F6
	.pool
_0805A448:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2B
	b _0805A5F6
	.pool
_0805A458:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2C
	b _0805A5F6
	.pool
_0805A468:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	b _0805A492
	.pool
_0805A478:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x9
	b _0805A536
	.pool
_0805A488:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x37
_0805A492:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	lsrs r0, r1, 24
	strb r0, [r7, 0x3]
	movs r6, 0x4
	b _0805A5FE
	.pool
_0805A4BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x38
	b _0805A5F6
	.pool
_0805A4CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x39
	b _0805A536
	.pool
_0805A4DC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	b _0805A536
	.pool
_0805A4EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3B
	b _0805A536
	.pool
_0805A4FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3C
	b _0805A536
	.pool
_0805A50C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3D
	b _0805A536
	.pool
_0805A51C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3E
	b _0805A536
	.pool
_0805A52C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3F
_0805A536:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _0805A5FE
	.pool
_0805A54C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x16
	b _0805A5F6
	.pool
_0805A55C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x17
	b _0805A5F6
	.pool
_0805A56C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x18
	b _0805A5F6
	.pool
_0805A57C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x21
	b _0805A5F6
	.pool
_0805A58C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2F
	b _0805A5F6
	.pool
_0805A59C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x30
	b _0805A5F6
	.pool
_0805A5AC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x32
	b _0805A5F6
	.pool
_0805A5BC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x33
	b _0805A5F6
	.pool
_0805A5CC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x34
	b _0805A5F6
	.pool
_0805A5DC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x35
	b _0805A5F6
	.pool
_0805A5EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x36
_0805A5F6:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_0805A5FE:
	adds r0, r6, 0
	add sp, 0x90
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end dp01_getattr_by_ch1_for_player_pokemon_

	thumb_func_start sub_805A614
sub_805A614: @ 805A614
	push {r4-r7,lr}
	sub sp, 0x58
	ldr r2, =gBattlePartyID
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	adds r4, r2, 0
	muls r4, r0
	ldr r3, =gUnknown_02023064
	lsls r1, 9
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r2, [r0]
	ldr r0, =gPlayerParty
	adds r0, r2, r0
	adds r6, r4, r0
	mov r0, sp
	adds r4, r0, r2
	movs r2, 0
	adds r0, r3, 0x2
	adds r1, r0
	adds r7, r5, 0
	mov r12, r3
	ldrb r1, [r1]
	cmp r2, r1
	bcs _0805A66A
	adds r3, r0, 0
_0805A650:
	adds r1, r4, r2
	adds r0, r6, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r5]
	lsls r0, 9
	adds r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0805A650
_0805A66A:
	ldrb r0, [r7]
	lsls r0, 9
	mov r1, r12
	adds r1, 0x2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl dp01_tbl1_exec_completed
	add sp, 0x58
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805A614

	thumb_func_start dp01t_02_1_setattr
dp01t_02_1_setattr: @ 805A69C
	push {r4,r5,lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805A6CC
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl dp01_setattr_by_ch1_for_player_pokemon
	b _0805A6EA
	.pool
_0805A6CC:
	ldrb r4, [r1]
	movs r5, 0
_0805A6D0:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0805A6DE
	adds r0, r5, 0
	bl dp01_setattr_by_ch1_for_player_pokemon
_0805A6DE:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _0805A6D0
_0805A6EA:
	bl dp01_tbl1_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_02_1_setattr

	thumb_func_start dp01_setattr_by_ch1_for_player_pokemon
dp01_setattr_by_ch1_for_player_pokemon: @ 805A6F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r2, =gUnknown_02023067
	adds r3, r0, r2
	adds r6, r3, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r7, r2, 0
	cmp r0, 0x3B
	bls _0805A720
	bl _0805B0BA
_0805A720:
	lsls r0, 2
	ldr r1, =_0805A738
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0805A738:
	.4byte _0805A828
	.4byte _0805A9C0
	.4byte _0805A9E0
	.4byte _0805AA00
	.4byte _0805AA58
	.4byte _0805AA58
	.4byte _0805AA58
	.4byte _0805AA58
	.4byte _0805AA80
	.4byte _0805AAE4
	.4byte _0805AAE4
	.4byte _0805AAE4
	.4byte _0805AAE4
	.4byte _0805B0BA
	.4byte _0805B0BA
	.4byte _0805B0BA
	.4byte _0805B0BA
	.4byte _0805AB14
	.4byte _0805AB34
	.4byte _0805AB54
	.4byte _0805AB74
	.4byte _0805AB94
	.4byte _0805ABB4
	.4byte _0805ABD4
	.4byte _0805ABF4
	.4byte _0805AC14
	.4byte _0805AC34
	.4byte _0805AC54
	.4byte _0805AC74
	.4byte _0805AC94
	.4byte _0805ACB4
	.4byte _0805ACD4
	.4byte _0805AD44
	.4byte _0805AD64
	.4byte _0805AD84
	.4byte _0805ADA4
	.4byte _0805ADC4
	.4byte _0805ADE4
	.4byte _0805AE04
	.4byte _0805AE24
	.4byte _0805AE44
	.4byte _0805AE64
	.4byte _0805AE84
	.4byte _0805AEA4
	.4byte _0805AEC4
	.4byte _0805AEE4
	.4byte _0805AF04
	.4byte _0805AF24
	.4byte _0805AF44
	.4byte _0805AF64
	.4byte _0805AF84
	.4byte _0805AFA4
	.4byte _0805AFC4
	.4byte _0805AFE4
	.4byte _0805B004
	.4byte _0805B024
	.4byte _0805B044
	.4byte _0805B064
	.4byte _0805B084
	.4byte _0805B0A4
_0805A828:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	adds r2, r6, 0
	bl pokemon_setattr
	adds r2, r6, 0
	adds r2, 0x2E
	adds r0, r4, 0
	movs r1, 0xC
	bl pokemon_setattr
	movs r0, 0
	mov r8, r0
	movs r0, 0x3B
	adds r0, r6
	mov r10, r0
	adds r0, r6, 0
	adds r0, 0x2B
	str r0, [sp, 0x20]
	adds r0, 0x19
	str r0, [sp, 0x28]
	adds r0, 0x4
	str r0, [sp, 0x2C]
	adds r0, 0x4
	str r0, [sp, 0x30]
	subs r0, 0x22
	str r0, [sp, 0x1C]
	subs r0, 0x2
	str r0, [sp, 0x18]
	adds r0, 0x4
	str r0, [sp, 0x24]
	adds r0, r6, 0x2
	str r0, [sp, 0x4]
	adds r0, r6, 0x4
	str r0, [sp, 0x8]
	adds r0, r6, 0x6
	str r0, [sp, 0xC]
	adds r0, 0x2
	str r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x14]
	mov r9, r4
	adds r7, r6, 0
	adds r7, 0x24
	adds r4, r6, 0
	adds r4, 0xC
_0805A88E:
	mov r1, r8
	adds r1, 0xD
	mov r0, r9
	adds r2, r4, 0
	bl pokemon_setattr
	mov r1, r8
	adds r1, 0x11
	mov r0, r9
	adds r2, r7, 0
	bl pokemon_setattr
	adds r7, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _0805A88E
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	mov r2, r10
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x20
	ldr r2, [sp, 0x20]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x19
	ldr r2, [sp, 0x28]
	bl pokemon_setattr
	ldrb r0, [r6, 0x14]
	lsls r0, 27
	lsrs r0, 27
	mov r1, sp
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrh r0, [r6, 0x14]
	lsls r0, 22
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x28
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrb r0, [r6, 0x15]
	lsls r0, 25
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x29
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldr r0, [r6, 0x14]
	lsls r0, 12
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2A
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrh r0, [r6, 0x16]
	lsls r0, 23
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2B
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrb r0, [r6, 0x17]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2C
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0
	ldr r2, [sp, 0x2C]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x37
	ldr r2, [sp, 0x30]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x38
	ldr r2, [sp, 0x1C]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x39
	ldr r2, [sp, 0x18]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3A
	ldr r2, [sp, 0x24]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3B
	ldr r2, [sp, 0x4]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3C
	ldr r2, [sp, 0x8]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3D
	ldr r2, [sp, 0xC]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3E
	ldr r2, [sp, 0x10]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3F
	ldr r2, [sp, 0x14]
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805A9C0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0xB
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805A9E0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0xC
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AA00:
	movs r0, 0
	mov r8, r0
	movs r0, 0xC
	adds r0, r3
	mov r9, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	adds r6, r3, 0
	adds r6, 0x8
	adds r4, r3, 0
_0805AA1A:
	mov r1, r8
	adds r1, 0xD
	adds r0, r7, 0
	adds r2, r4, 0
	bl pokemon_setattr
	mov r1, r8
	adds r1, 0x11
	adds r0, r7, 0
	adds r2, r6, 0
	bl pokemon_setattr
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _0805AA1A
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AA58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r3, =gUnknown_02023064
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x9
	b _0805AAFC
	.pool
_0805AA80:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	lsls r2, 9
	adds r2, r7
	adds r0, r4, 0
	movs r1, 0x11
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x12
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x14
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AAE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r3, =gUnknown_02023064
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x8
_0805AAFC:
	adds r3, 0x3
	adds r2, r3
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AB14:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AB34:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x19
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AB54:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1A
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AB74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1B
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AB94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1C
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ABB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1D
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ABD4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1E
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ABF4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x1F
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AC14:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x20
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AC34:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x22
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AC54:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x23
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AC74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x24
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AC94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x25
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ACB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x26
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ACD4:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	lsls r2, 9
	adds r2, r7
	adds r0, r4, 0
	movs r1, 0x27
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x28
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x29
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2A
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2B
	bl pokemon_setattr
	ldrb r2, [r5]
	lsls r2, 9
	adds r0, r7, 0x5
	adds r2, r0
	adds r0, r4, 0
	b _0805ADF4
	.pool
_0805AD44:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x27
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AD64:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x28
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AD84:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x29
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ADA4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2A
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ADC4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2B
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805ADE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
_0805ADF4:
	movs r1, 0x2C
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AE04:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AE24:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x9
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AE44:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x37
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AE64:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x38
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AE84:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x39
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AEA4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3A
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AEC4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3B
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AEE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3C
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AF04:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3D
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AF24:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3E
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AF44:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x3F
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AF64:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x16
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AF84:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x17
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AFA4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x18
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AFC4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x21
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805AFE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x2F
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805B004:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x30
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805B024:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x32
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805B044:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x33
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805B064:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x34
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805B084:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x35
	bl pokemon_setattr
	b _0805B0BA
	.pool
_0805B0A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	lsls r2, 9
	adds r2, r7
	movs r1, 0x36
	bl pokemon_setattr
_0805B0BA:
	ldr r2, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_setattr_by_ch1_for_player_pokemon

	thumb_func_start sub_805B0F0
sub_805B0F0: @ 805B0F0
	push {r4-r7,lr}
	ldr r1, =gBattlePartyID
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	adds r3, r1, 0
	muls r3, r0
	ldr r4, =gUnknown_02023064
	lsls r2, 9
	adds r0, r4, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r5, r3, r0
	movs r3, 0
	adds r0, r4, 0x2
	adds r2, r0
	ldrb r2, [r2]
	cmp r3, r2
	bcs _0805B148
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_0805B126:
	adds r1, r5, r3
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, 0x3
	adds r0, r3, r0
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r3, r0
	bcc _0805B126
_0805B148:
	bl dp01_tbl1_exec_completed
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B0F0

	thumb_func_start sub_805B164
sub_805B164: @ 805B164
	push {r4,lr}
	ldr r2, =gBattlePartyID
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805DD7C
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldrb r3, [r4]
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_0802E404
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B164

	thumb_func_start sub_805B1CC
sub_805B1CC: @ 805B1CC
	push {r4-r6,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	ldr r4, =gUnknown_02023064
	lsls r1, r0, 9
	adds r6, r4, 0x2
	adds r1, r6
	ldrb r1, [r1]
	bl sub_805EF84
	ldr r2, =gBattlePartyID
	ldrb r0, [r5]
	lsls r1, r0, 1
	adds r1, r2
	lsls r0, 9
	adds r4, 0x1
	adds r0, r4
	ldrb r0, [r0]
	movs r4, 0
	strh r0, [r1]
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805DD7C
	ldr r1, =gUnknown_020244AC
	ldrb r0, [r5]
	adds r0, r1
	strb r4, [r0]
	ldr r1, =gUnknown_020244B0
	ldrb r0, [r5]
	adds r0, r1
	strb r4, [r0]
	ldrb r0, [r5]
	lsls r1, r0, 9
	adds r1, r6
	ldrb r1, [r1]
	bl sub_805B258
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805902C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B1CC

	thumb_func_start sub_805B258
sub_805B258: @ 805B258
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_805EF84
	ldr r0, =gBattlePartyID
	lsls r2, r6, 1
	adds r2, r0
	ldr r0, =gUnknown_02023064
	lsls r1, r6, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r2]
	ldrh r1, [r2]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =sub_805D714
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gUnknown_03005D7C
	mov r9, r1
	add r9, r6
	mov r1, r9
	strb r0, [r1]
	adds r0, r6, 0
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r10, r0
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r10
	adds r1, r5, 0
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r4, =gUnknown_020241E4
	adds r4, r6, r4
	strb r0, [r4]
	ldr r5, =gUnknown_02020630
	mov r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r4]
	strh r1, [r0, 0x30]
	mov r0, r9
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r6, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r6, r1
	ldrb r1, [r6]
	bl StartObjectImageAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =DummyObjectCallback
	str r1, [r0]
	movs r0, 0
	movs r1, 0xFF
	bl sub_80753E8
	mov r1, r9
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x2E]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B258

	thumb_func_start sub_805B3D4
sub_805B3D4: @ 805B3D4
	push {r4-r6,lr}
	ldr r1, =gUnknown_02023064
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _0805B41C
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	strb r3, [r0, 0x4]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805B464
	str r1, [r0]
	b _0805B452
	.pool
_0805B41C:
	ldr r5, =gUnknown_020241E4
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl RemoveObjectAndFreeTiles
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl1_exec_completed
_0805B452:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B3D4

	thumb_func_start sub_805B464
sub_805B464: @ 805B464
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r4, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	beq _0805B48C
	cmp r0, 0x1
	beq _0805B4BA
	b _0805B4E2
	.pool
_0805B48C:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805B4A6
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0805B4A6:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0805B4E2
_0805B4BA:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805B4E2
	strb r0, [r3, 0x4]
	ldrb r2, [r5]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x1
	bl move_anim_start_t4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8059744
	str r1, [r0]
_0805B4E2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B464

	thumb_func_start sub_805B4F0
sub_805B4F0: @ 805B4F0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805B5B4
	bl link_get_multiplayer_id
	ldr r5, =gUnknown_020229E8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _0805B538
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _0805B558
_0805B538:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x2
	b _0805B5BA
	.pool
_0805B558:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _0805B58A
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _0805B5A0
_0805B58A:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x4
	b _0805B5BA
_0805B5A0:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r4, [r1, 0x13]
	b _0805B5BA
_0805B5B4:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r4, [r0, 0x8]
_0805B5BA:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r2, 0x40
	ands r1, r2
	adds r5, r0, 0
	cmp r1, 0
	beq _0805B63C
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl battle_get_per_side_status
	movs r1, 0x2
	ands r1, r0
	movs r0, 0x20
	mov r9, r0
	cmp r1, 0
	beq _0805B5E0
	movs r1, 0x5A
	mov r9, r1
_0805B5E0:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _0805B618
	ldr r0, =gUnknown_02038BCE
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	beq _0805B618
	movs r0, 0x5A
	mov r9, r0
	ldr r1, =gUnknown_083054E0
	b _0805B642
	.pool
_0805B618:
	ldr r1, =gUnknown_08305D2C
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	subs r0, r1
	lsls r0, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r0, r1
	lsrs r7, r0, 16
	ldr r5, =gBattleTypeFlags
	b _0805B656
	.pool
_0805B63C:
	movs r0, 0x50
	mov r9, r0
	ldr r1, =gUnknown_08305D2C
_0805B642:
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	subs r0, r1
	lsls r0, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r0, r1
	lsrs r7, r0, 16
_0805B656:
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	bne _0805B664
	b _0805B794
_0805B664:
	ldr r0, =gUnknown_02038BCE
	ldrh r1, [r0]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _0805B670
	b _0805B794
_0805B670:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bl sub_806F000
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	adds r0, r5, 0
	bl sub_805DF38
	ldrb r0, [r6]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_806A1C0
	ldr r0, =gUnknown_0202499C
	mov r8, r0
	lsls r4, r7, 16
	asrs r4, 16
	ldrb r0, [r6]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r8
	mov r1, r9
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r4, =gUnknown_020241E4
	ldrb r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r0, =gTrainerFrontPicPaletteTable
	lsls r5, 3
	adds r5, r0
	ldrh r0, [r5, 0x4]
	bl IndexOfObjectPaletteTag
	ldr r5, =gUnknown_02020630
	ldrb r1, [r6]
	adds r1, r4
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r5
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0xF0
	strh r1, [r0, 0x24]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x30
	strh r1, [r0, 0x26]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _0805B82A
	.pool
_0805B794:
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_805DF84
	ldrb r0, [r5]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl template_build_for_pokemon_or_trainer
	ldr r6, =gUnknown_0202499C
	mov r8, r9
	lsls r4, r7, 16
	asrs r4, 16
	ldrb r0, [r5]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	mov r1, r8
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r6, =gUnknown_020241E4
	ldrb r1, [r5]
	adds r1, r6
	strb r0, [r1]
	ldr r4, =gUnknown_02020630
	ldrb r3, [r5]
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0xF0
	strh r1, [r0, 0x24]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
_0805B82A:
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058844
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B4F0

	thumb_func_start dp01t_08_1_8032428
dp01t_08_1_8032428: @ 805B864
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805B920
	bl link_get_multiplayer_id
	ldr r5, =gUnknown_020229E8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _0805B8A6
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _0805B8C4
_0805B8A6:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x2
	b _0805B926
	.pool
_0805B8C4:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _0805B8F6
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _0805B90C
_0805B8F6:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x13]
	adds r4, r0, 0x4
	b _0805B926
_0805B90C:
	bl link_get_multiplayer_id
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r4, [r1, 0x13]
	b _0805B926
_0805B920:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r4, [r0, 0x8]
_0805B926:
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	adds r0, r4, 0
	bl sub_805DF84
	ldrb r0, [r5]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r1, =gUnknown_08305D2C
	lsls r4, 2
	adds r4, r1
	ldrb r1, [r4]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 15
	adds r2, r1
	asrs r2, 16
	movs r1, 0x50
	movs r3, 0x1E
	bl AddObjectToFront
	ldr r6, =gUnknown_020241E4
	ldrb r1, [r5]
	adds r1, r6
	strb r0, [r1]
	ldr r4, =gUnknown_02020630
	ldrb r3, [r5]
	adds r0, r3, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffa0
	strh r1, [r0, 0x24]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x2E]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805887C
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_08_1_8032428

	thumb_func_start sub_805B9F8
sub_805B9F8: @ 805B9F8
	push {r4-r6,lr}
	ldr r5, =gUnknown_020241E4
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x32
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ffd8
	strh r1, [r0, 0x32]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =DummyObjectCallback
	bl oamt_set_x3A_32
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x1
	bl StartObjectImageAnim
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_802F7A0
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805B9F8

	thumb_func_start sub_805BAB8
sub_805BAB8: @ 805BAB8
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r0, [r4, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r3, r1, r0
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	bne _0805BB0C
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805BAEC
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0805BAEC:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	adds r1, 0x1
	strb r1, [r0, 0x4]
	b _0805BB82
	.pool
_0805BB0C:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805BB82
	strb r4, [r3, 0x4]
	ldr r2, =gBattlePartyID
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805E990
	movs r1, 0x40
	negs r1, r1
	movs r0, 0x10
	bl audio_play_and_stuff
	ldr r2, =gUnknown_02020630
	ldr r3, =gUnknown_020241E4
	ldrb r0, [r5]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r4, [r0, 0x30]
	ldrb r0, [r5]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x5
	strh r1, [r0, 0x32]
	ldrb r0, [r5]
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039C00
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80596A8
	str r1, [r0]
_0805BB82:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BAB8

	thumb_func_start sub_805BBA4
sub_805BBA4: @ 805BBA4
	push {lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl dp01_tbl1_exec_completed
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_805BBA4

	thumb_func_start sub_805BBC4
sub_805BBC4: @ 805BBC4
	push {r4,r5,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	movs r0, 0x4
	strb r0, [r1, 0x8]
	ldr r1, =gUnknown_020244B9
	movs r0, 0x1
	strb r0, [r1]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x3
	bl move_anim_start_t4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t1
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BBC4

	thumb_func_start sub_805BC18
sub_805BC18: @ 805BC18
	push {r4,r5,lr}
	ldr r1, =gUnknown_02023064
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	strb r1, [r0, 0x8]
	ldr r1, =gUnknown_020244B9
	movs r0, 0x1
	strb r0, [r1]
	ldrb r4, [r5]
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r4, 0
	movs r3, 0x3
	bl move_anim_start_t4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_wait_t1
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BC18

	thumb_func_start sub_805BC78
sub_805BC78: @ 805BC78
	push {lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805BC96
_0805BC8C:
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805BC8C
_0805BC96:
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BC78

	thumb_func_start dp01t_0F_1_move_anim
dp01t_0F_1_move_anim: @ 805BCA8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _0805BCBE
	b _0805BDE4
_0805BCBE:
	ldr r0, =gUnknown_02023064
	mov r12, r0
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	mov r0, r12
	adds r0, 0x2
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r6, r0
	ldr r0, =gUnknown_02038432
	mov r8, r0
	mov r0, r12
	adds r0, 0x3
	adds r1, r0
	ldrb r0, [r1]
	mov r1, r8
	strb r0, [r1]
	ldr r3, =gUnknown_02038408
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x4
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0x5
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	strh r2, [r3]
	ldr r3, =gUnknown_02038404
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x6
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0x7
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r2, r0
	mov r0, r12
	adds r0, 0x8
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 16
	orrs r2, r0
	mov r0, r12
	adds r0, 0x9
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 24
	orrs r2, r0
	str r2, [r3]
	ldr r2, =gUnknown_0203841A
	ldrb r0, [r5]
	lsls r0, 9
	mov r1, r12
	adds r1, 0xA
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r4, =gUnknown_0203841C
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0xC
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0xD
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	strh r2, [r4]
	ldr r7, =gUnknown_02038400
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x10
	adds r1, r0
	str r1, [r7]
	ldr r2, =gUnknown_020244BC
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r1]
	str r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_805DB8C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _0805BDBC
	bl dp01_tbl1_exec_completed
	b _0805BDE4
	.pool
_0805BDBC:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x4]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_move_anim_1
	str r1, [r0]
	ldrh r1, [r4]
	ldr r2, [r7]
	adds r0, r6, 0
	bl sub_817E0FC
_0805BDE4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_0F_1_move_anim

	thumb_func_start bx_move_anim_1
bx_move_anim_1: @ 805BDFC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r2, =gUnknown_02023064
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	lsls r1, r3, 9
	adds r0, r2, 0x1
	mov r10, r0
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, r2, 0x2
	mov r9, r5
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	adds r2, 0xB
	adds r1, r2
	ldrb r1, [r1]
	mov r8, r1
	ldr r7, =gUnknown_020244D0
	ldr r5, [r7]
	ldr r1, [r5, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	cmp r2, 0x1
	beq _0805BE94
	cmp r2, 0x1
	bgt _0805BE54
	cmp r2, 0
	beq _0805BE5E
	b _0805BF70
	.pool
_0805BE54:
	cmp r2, 0x2
	beq _0805BEBE
	cmp r2, 0x3
	beq _0805BF34
	b _0805BF70
_0805BE5E:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _0805BE80
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_0805BE80:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0805BF70
_0805BE94:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805BF70
	movs r0, 0
	bl sub_805EB9C
	adds r0, r4, 0
	bl move_anim_start_t1
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0, 0x4]
	b _0805BF70
_0805BEBE:
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805BF70
	movs r0, 0x1
	bl sub_805EB9C
	ldr r0, [r7]
	ldrb r2, [r6]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805BF0C
	mov r0, r8
	cmp r0, 0x1
	bhi _0805BF0C
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r0, [r0]
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_0805BF0C:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x4]
	b _0805BF70
	.pool
_0805BF34:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _0805BF70
	bl sub_805E394
	ldrb r0, [r6]
	lsls r2, r0, 9
	mov r3, r10
	adds r1, r2, r3
	ldrb r1, [r1]
	add r2, r9
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	bl sub_805E94C
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r4, [r0, 0x4]
	bl dp01_tbl1_exec_completed
_0805BF70:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end bx_move_anim_1

	thumb_func_start sub_805BF80
sub_805BF80: @ 805BF80
	push {r4,r5,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r4, 9
	ldr r0, =gUnknown_02023066
	adds r4, r0
	ldrh r0, [r4]
	bl battle_pick_message
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80597B4
	str r1, [r0]
	ldrh r0, [r4]
	bl sub_817C95C
	ldrb r0, [r5]
	ldrh r1, [r4]
	bl sub_81A57E4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805BF80

	thumb_func_start dp01t_11_1_message_for_player_only
dp01t_11_1_message_for_player_only: @ 805BFE0
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805BFFC
	bl sub_805BF80
	b _0805C000
	.pool
_0805BFFC:
	bl dp01_tbl1_exec_completed
_0805C000:
	pop {r0}
	bx r0
	thumb_func_end dp01t_11_1_message_for_player_only

	thumb_func_start sub_805C004
sub_805C004: @ 805C004
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0805C02A
	ldr r0, =gUnknown_02022E14
	strh r1, [r0]
	ldr r1, =gUnknown_02022E16
	movs r0, 0xA0
	strh r0, [r1]
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057588
	str r1, [r0]
_0805C02A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C004

	thumb_func_start dp01t_12_6_battle_menu
dp01t_12_6_battle_menu: @ 805C044
	push {r4,lr}
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805C004
	str r1, [r0]
	bl sub_817F2A8
	ldr r0, =gUnknown_085CCA3A
	movs r1, 0x2
	bl battle_show_message_maybe
	movs r4, 0
_0805C062:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_8059CF8
	adds r4, 0x1
	cmp r4, 0x3
	ble _0805C062
	ldr r1, =gUnknown_020244AC
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_8059CB4
	ldr r0, =gUnknown_085CC9F3
	bl get_battle_strings_
	ldr r0, =gUnknown_02022E2C
	movs r1, 0x1
	bl battle_show_message_maybe
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_12_6_battle_menu

	thumb_func_start sub_805C0B0
sub_805C0B0: @ 805C0B0
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0805C108
	str r0, [sp]
	movs r0, 0x18
	movs r1, 0x8
	movs r2, 0x1D
	movs r3, 0xD
	bl sub_8056A3C
	ldr r0, =gUnknown_085CCABB
	movs r1, 0xC
	bl battle_show_message_maybe
	ldr r1, =gUnknown_03005D74
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	bl sub_8056B74
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80599D4
	str r1, [r0]
	b _0805C10C
	.pool
_0805C108:
	bl dp01_tbl1_exec_completed
_0805C10C:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_805C0B0

	thumb_func_start sub_805C114
sub_805C114: @ 805C114
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _0805C13E
	ldr r0, =gUnknown_02022E14
	strh r1, [r0]
	ldr r1, =gUnknown_02022E16
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8057BFC
	str r1, [r0]
_0805C13E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C114

	thumb_func_start sub_805C158
sub_805C158: @ 805C158
	push {lr}
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r1, r0
	movs r0, 0xA6
	lsls r0, 2
	adds r1, r0
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _0805C194
	ldr r1, =gUnknown_0203BD30
	ldr r0, =gRngValue
	ldr r0, [r0]
	str r0, [r1]
	bl sub_805D19C
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	bl dp01_tbl1_exec_completed
_0805C194:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C158

	thumb_func_start dp01t_14_5_move_menu_pokedude
dp01t_14_5_move_menu_pokedude: @ 805C1A8
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0805C1EC
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	movs r1, 0xA6
	lsls r1, 2
	adds r0, r1
	movs r1, 0x8
	strb r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805C158
	b _0805C1FC
	.pool
_0805C1EC:
	bl sub_805C210
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805C114
_0805C1FC:
	str r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_14_5_move_menu_pokedude

	thumb_func_start sub_805C210
sub_805C210: @ 805C210
	push {lr}
	bl sub_8059AAC
	ldr r1, =gUnknown_03005D74
	movs r0, 0xFF
	strb r0, [r1]
	ldr r1, =gUnknown_020244B0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl battle_menu_cursor_related_2
	bl sub_8059B18
	bl sub_8059B3C
	bl sub_8059BB0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C210

	thumb_func_start sub_805C248
sub_805C248: @ 805C248
	push {r4,r5,lr}
	sub sp, 0x4
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gUnknown_03005D60
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80598A4
	str r1, [r0]
	ldr r1, =gUnknown_020244B8
	ldrb r0, [r2]
	strb r0, [r1]
	movs r3, 0
	ldr r5, =gUnknown_0203CF00
	ldr r4, =gUnknown_02023064
_0805C276:
	adds r0, r3, r5
	ldrb r1, [r2]
	lsls r1, 9
	adds r1, 0x1
	adds r1, r3, r1
	adds r1, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x2
	ble _0805C276
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C248

	thumb_func_start sub_805C2AC
sub_805C2AC: @ 805C2AC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r3, 0
	ldr r0, =gUnknown_0203CF00
	mov r12, r0
	ldr r1, =gUnknown_02023064
	mov r8, r1
	ldr r2, =gActiveBank
	ldr r7, =gBattleTypeFlags
	mov r6, r12
	mov r5, r8
	adds r4, r2, 0
_0805C2C8:
	adds r0, r3, r6
	ldrb r1, [r4]
	lsls r1, 9
	adds r1, 0x4
	adds r1, r3, r1
	adds r1, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, 0x1
	cmp r3, 0x2
	ble _0805C2C8
	ldr r0, [r7]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _0805C330
	ldrb r3, [r2]
	lsls r0, r3, 9
	mov r1, r8
	adds r1, 0x1
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x2
	beq _0805C330
	ldr r1, =gBattlePartyID
	lsls r0, r3, 1
	adds r0, r1
	ldrb r1, [r0]
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x1
	mov r2, r12
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl dp01_tbl1_exec_completed
	b _0805C3BC
	.pool
_0805C330:
	ldr r0, =TaskDummy
	movs r1, 0xFF
	bl CreateTask
	ldr r3, =gUnknown_03005D7C
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	adds r1, r3
	movs r2, 0
	mov r8, r2
	strb r0, [r1]
	ldr r5, =gTasks
	ldrb r2, [r4]
	adds r3, r2, r3
	ldrb r0, [r3]
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r5
	ldr r5, =gUnknown_02023064
	lsls r2, 9
	adds r6, r5, 0x1
	adds r2, r6
	ldrb r2, [r2]
	movs r0, 0xF
	ands r0, r2
	strh r0, [r1, 0x8]
	ldr r3, =gUnknown_0202449C
	ldr r1, [r3]
	adds r1, 0x49
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r6
	ldrb r0, [r0]
	lsrs r0, 4
	strb r0, [r1]
	ldr r2, [r3]
	adds r2, 0x8B
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, r5, 0x2
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, [r3]
	adds r1, 0xB0
	ldrb r0, [r4]
	lsls r0, 9
	adds r5, 0x3
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
	mov r1, r8
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80597CC
	str r1, [r0]
	ldr r1, =gUnknown_020244B8
	ldrb r0, [r4]
	strb r0, [r1]
_0805C3BC:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C2AC

	thumb_func_start sub_805C3EC
sub_805C3EC: @ 805C3EC
	push {lr}
	sub sp, 0x4
	bl sub_805EA60
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r1, 0x2
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	bl dp01_tbl1_exec_completed
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_805C3EC

	thumb_func_start sub_805C410
sub_805C410: @ 805C410
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	bl load_gfxc_health_bar
	ldr r3, =gUnknown_02023064
	ldr r0, =gActiveBank
	mov r9, r0
	ldrb r1, [r0]
	lsls r1, 9
	adds r0, r3, 0x2
	adds r0, r1, r0
	ldrb r2, [r0]
	adds r3, 0x3
	adds r1, r3
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	lsls r2, 16
	asrs r7, r2, 16
	cmp r7, 0
	ble _0805C44A
	ldr r1, =gUnknown_0203CD70
	ldr r0, [r1]
	adds r0, r7
	str r0, [r1]
_0805C44A:
	ldr r0, =0x00007fff
	cmp r7, r0
	beq _0805C4B4
	ldr r6, =gBattlePartyID
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gPlayerParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	mov r8, r0
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	mov r2, r8
	bl sub_807294C
	b _0805C4F2
	.pool
_0805C4B4:
	ldr r1, =gBattlePartyID
	mov r2, r9
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	adds r2, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r4, =gUnknown_03005D70
	adds r1, r0, r4
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_807294C
	mov r2, r9
	ldrb r0, [r2]
	adds r0, r4
	ldrb r0, [r0]
	movs r1, 0
	movs r2, 0
	bl heathbar_draw_hp
_0805C4F2:
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t1_healthbar_update
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C410

	thumb_func_start sub_805C528
sub_805C528: @ 805C528
	push {r4-r7,lr}
	ldr r5, =gUnknown_02023064
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	lsls r0, 9
	adds r1, r5, 0x1
	adds r0, r1
	ldrb r7, [r0]
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	cmp r0, 0x63
	bls _0805C560
	bl dp01_tbl1_exec_completed
	b _0805C5AC
	.pool
_0805C560:
	movs r0, 0x1
	bl load_gfxc_health_bar
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	ldrb r1, [r6]
	lsls r1, 9
	adds r0, r5, 0x2
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r0, r5, 0x3
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	ldr r0, =sub_80591B8
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r7, [r1, 0x8]
	strh r4, [r1, 0xA]
	ldrb r0, [r6]
	strh r0, [r1, 0xC]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_21
	str r1, [r0]
_0805C5AC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C528

	thumb_func_start sub_805C5C4
sub_805C5C4: @ 805C5C4
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0805C618
	ldr r0, =gUnknown_03005D70
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0x9
	bl healthbar_draw_field_maybe
	ldrb r2, [r4]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8059D60
	str r1, [r0]
_0805C618:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C5C4

	thumb_func_start sub_805C63C
sub_805C63C: @ 805C63C
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0805C68C
	ldr r4, =gUnknown_02023064
	ldrb r3, [r5]
	lsls r3, 9
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	adds r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	adds r2, r4, 0x4
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 16
	orrs r1, r2
	adds r4, 0x5
	adds r3, r4
	ldrb r2, [r3]
	lsls r2, 24
	orrs r1, r2
	bl move_anim_start_t2_for_situation
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8059D60
	str r1, [r0]
_0805C68C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C63C

	thumb_func_start sub_805C6A4
sub_805C6A4: @ 805C6A4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	ldr r0, =gBattlePartyID
	mov r8, r0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0x37
	bl GetMonData
	ldr r2, =gUnknown_02023064
	ldrb r1, [r4]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	eors r0, r1
	mov r1, sp
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r0, 1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0x37
	mov r2, sp
	bl pokemon_setattr
	bl dp01_tbl1_exec_completed
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C6A4

	thumb_func_start sub_805C710
sub_805C710: @ 805C710
	push {lr}
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_805C710

	thumb_func_start sub_805C71C
sub_805C71C: @ 805C71C
	push {r4,r5,lr}
	ldr r3, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r2, 9
	adds r0, r3, 0x1
	adds r0, r2, r0
	ldrb r5, [r0]
	adds r0, r3, 0x2
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r5, r0
	adds r0, r3, 0x3
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, 16
	orrs r5, r0
	adds r0, r3, 0x4
	adds r0, r2, r0
	ldrb r4, [r0]
	lsls r4, 24
	adds r0, r3, 0x5
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r0, r3, 0x6
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	adds r3, 0x7
	adds r2, r3
	orrs r5, r4
	lsrs r4, r1, 16
	movs r0, 0x80
	lsls r0, 5
	cmp r4, r0
	bhi _0805C78C
	ldr r0, =0x040000d4
	str r2, [r0]
	str r5, [r0, 0x4]
	lsrs r1, 17
	movs r2, 0x80
	lsls r2, 24
	orrs r1, r2
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	b _0805C7B8
	.pool
_0805C78C:
	ldr r3, =0x040000d4
	str r2, [r3]
	str r5, [r3, 0x4]
	ldr r0, =0x80000800
	str r0, [r3, 0x8]
	ldr r0, [r3, 0x8]
	movs r0, 0x80
	lsls r0, 5
	adds r2, r0
	adds r5, r0
	ldr r1, =0xfffff000
	adds r4, r1
	cmp r4, r0
	bhi _0805C78C
	str r2, [r3]
	str r5, [r3, 0x4]
	lsrs r0, r4, 1
	movs r1, 0x80
	lsls r1, 24
	orrs r0, r1
	str r0, [r3, 0x8]
	ldr r0, [r3, 0x8]
_0805C7B8:
	bl dp01_tbl1_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C71C

	thumb_func_start sub_805C7D0
sub_805C7D0: @ 805C7D0
	push {lr}
	ldr r2, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl song_play_for_text
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C7D0

	thumb_func_start sub_805C800
sub_805C800: @ 805C800
	push {lr}
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_805C800

	thumb_func_start sub_805C80C
sub_805C80C: @ 805C80C
	push {lr}
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_805C80C

	thumb_func_start sub_805C820
sub_805C820: @ 805C820
	push {lr}
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_805C820

	thumb_func_start sub_805C834
sub_805C834: @ 805C834
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl dp01_build_cmdbuf_x23_aa_0
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_805C834

	thumb_func_start sub_805C848
sub_805C848: @ 805C848
	push {lr}
	movs r0, 0x1
	movs r1, 0
	bl dp01_build_cmdbuf_x24_aa_0
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_805C848

	thumb_func_start sub_805C85C
sub_805C85C: @ 805C85C
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C85C

	thumb_func_start sub_805C878
sub_805C878: @ 805C878
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x7F
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C878

	thumb_func_start sub_805C8B0
sub_805C8B0: @ 805C8B0
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C8B0

	thumb_func_start sub_805C8C8
sub_805C8C8: @ 805C8C8
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, [r3]
	lsls r1, 24
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 7
	ldrb r2, [r3]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C8C8

	thumb_func_start dp01t_29_1_blink
dp01t_29_1_blink: @ 805C8F0
	push {r4,lr}
	ldr r3, =gUnknown_02020630
	ldr r2, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _0805C924
	bl dp01_tbl1_exec_completed
	b _0805C94E
	.pool
_0805C924:
	ldr r1, =gUnknown_020244B9
	movs r0, 0x1
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x30]
	ldrb r0, [r4]
	bl sub_80769F4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_blink_t1
	str r1, [r0]
_0805C94E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_29_1_blink

	thumb_func_start sub_805C960
sub_805C960: @ 805C960
	push {lr}
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_805C960

	thumb_func_start sub_805C96C
sub_805C96C: @ 805C96C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _0805C980
	movs r3, 0xC0
_0805C980:
	ldr r2, =gUnknown_02023064
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	lsls r1, r3, 24
	asrs r1, 24
	bl audio_play_and_stuff
	bl dp01_tbl1_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805C96C

	thumb_func_start sub_805C9B0
sub_805C9B0: @ 805C9B0
	push {r4,r5,lr}
	ldr r4, =gUnknown_02023064
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805C9EC
	bl sub_805EA60
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, r4, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl song_play_for_text
	b _0805CA00
	.pool
_0805C9EC:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl fanfare_play
_0805CA00:
	bl dp01_tbl1_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_805C9B0

	thumb_func_start sub_805CA0C
sub_805CA0C: @ 805CA0C
	push {lr}
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	negs r1, r1
	movs r2, 0x5
	bl sub_80A32E4
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CA0C

	thumb_func_start dp01t_2E_1_battle_intro
dp01t_2E_1_battle_intro: @ 805CA4C
	push {lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl battle_intro_launch
	ldr r2, =gUnknown_020243FC
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_1_battle_intro

	thumb_func_start dp01t_2F_1_pokemon_enter
dp01t_2F_1_pokemon_enter: @ 805CA80
	push {r4-r7,lr}
	ldr r6, =gUnknown_020241E4
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gUnknown_02020630
	adds r0, r5
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x32
	strh r1, [r0, 0x2E]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ffd8
	strh r1, [r0, 0x32]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r2, [r7]
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x38]
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =sub_805CC00
	bl oamt_set_x3A_32
	ldrb r0, [r7]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x1
	bl StartObjectImageAnim
	ldr r0, =0x0000d6f8
	bl AllocObjectPalette
	adds r4, r0, 0
	lsls r4, 24
	ldr r1, =gTrainerBackPicPaletteTable
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0]
	lsrs r4, 20
	movs r2, 0x80
	lsls r2, 1
	adds r1, r4, r2
	movs r2, 0x20
	bl LoadCompressedPalette
	ldrb r0, [r7]
	adds r0, r6
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r4
	strb r0, [r1, 0x5]
	ldr r0, =task05_08033660
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r7]
	strh r0, [r1, 0x8]
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805CBA2
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_0805CBA2:
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_21
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2F_1_pokemon_enter

	thumb_func_start sub_805CC00
sub_805CC00: @ 805CC00
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0x38]
	lsls r4, 24
	lsrs r4, 24
	bl obj_free_rotscale_entry
	ldrb r0, [r5, 0x5]
	lsrs r0, 4
	bl GetObjectPaletteTagBySlot
	lsls r0, 16
	lsrs r0, 16
	bl FreeObjectPaletteByTag
	adds r0, r5, 0
	bl RemoveObjectAndFreeTiles
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	bl sub_805DD7C
	ldr r0, =gUnknown_020241E4
	adds r4, r0
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	movs r1, 0
	bl StartObjectImageAnim
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CC00

	thumb_func_start task05_08033660
task05_08033660: @ 805CC68
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r1, =gTasks
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0xA]
	movs r3, 0xA
	ldrsh r0, [r1, r3]
	cmp r0, 0x1E
	bgt _0805CC94
	adds r0, r2, 0x1
	strh r0, [r1, 0xA]
	b _0805CD50
	.pool
_0805CC94:
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldrh r0, [r1, 0x8]
	strb r0, [r7]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805CCB4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0805CCE4
_0805CCB4:
	ldr r0, =gUnknown_02023064
	ldrb r1, [r7]
	lsls r2, r1, 9
	adds r0, 0x1
	adds r2, r0
	ldr r0, =gBattlePartyID
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strb r0, [r2]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_805B258
	b _0805CD38
	.pool
_0805CCE4:
	ldr r4, =gUnknown_02023064
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r4, 0x1
	adds r1, r4
	ldr r5, =gBattlePartyID
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_805B258
	ldrb r0, [r7]
	movs r6, 0x2
	eors r0, r6
	strb r0, [r7]
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r1, r4
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r1, [r7]
	lsls r0, r1, 1
	adds r0, r5
	ldrh r2, [r0]
	movs r0, 0x64
	muls r0, r2
	ldr r2, =gPlayerParty
	adds r0, r2
	bl sub_805DD7C
	ldrb r0, [r7]
	movs r1, 0
	bl sub_805B258
	ldrb r0, [r7]
	eors r0, r6
	strb r0, [r7]
_0805CD38:
	ldr r1, =gUnknown_03005D60
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8058B40
	str r1, [r0]
	mov r3, r9
	strb r3, [r2]
	mov r0, r8
	bl DestroyTask
_0805CD50:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task05_08033660

	thumb_func_start sub_805CD74
sub_805CD74: @ 805CD74
	push {r4-r6,lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805CDA4
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805CDA4
	bl dp01_tbl1_exec_completed
	b _0805CE18
	.pool
_0805CDA4:
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r3, r0, 9
	ldr r4, =gUnknown_02023068
	adds r1, r3, r4
	subs r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	subs r4, 0x2
	adds r3, r4
	ldrb r3, [r3]
	bl sub_80735DC
	ldr r2, =gUnknown_020244B4
	ldrb r1, [r5]
	adds r1, r2
	movs r3, 0
	strb r0, [r1]
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x5]
	ldrb r2, [r5]
	lsls r0, r2, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805CE0C
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_0805CE0C:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_805CE38
	str r0, [r1]
_0805CE18:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CD74

	thumb_func_start sub_805CE38
sub_805CE38: @ 805CE38
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	adds r2, r1, 0x1
	strb r2, [r0, 0x5]
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x5C
	bls _0805CE70
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl dp01_tbl1_exec_completed
_0805CE70:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CE38

	thumb_func_start sub_805CE80
sub_805CE80: @ 805CE80
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	ldr r1, [r1, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805CEB2
	ldr r2, =gTasks
	ldr r0, =gUnknown_020244B4
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_8073C30
	str r1, [r0]
_0805CEB2:
	bl dp01_tbl1_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CE80

	thumb_func_start sub_805CED0
sub_805CED0: @ 805CED0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	ldrb r0, [r4]
	movs r1, 0
	bl dp11b_obj_free
	bl dp01_tbl1_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CED0

	thumb_func_start dp01t_33_1_enemy_move
dp01t_33_1_enemy_move: @ 805CEF4
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _0805CF3A
	ldr r3, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldr r0, =gUnknown_02023064
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	adds r2, 0x3E
	movs r0, 0x1
	ldrb r1, [r1]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4]
	bl sub_805E408
_0805CF3A:
	bl dp01_tbl1_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_33_1_enemy_move

	thumb_func_start sub_805CF54
sub_805CF54: @ 805CF54
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _0805CFB6
	ldr r4, =gUnknown_02023064
	ldrb r2, [r5]
	lsls r1, r2, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	adds r0, r4, 0x2
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r4, 0x3
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 8
	orrs r3, r0
	str r3, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	adds r3, r6, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _0805CFA4
	bl dp01_tbl1_exec_completed
	b _0805CFB0
	.pool
_0805CFA4:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_8030B2C
	str r0, [r1]
_0805CFB0:
	adds r0, r6, 0
	bl sub_817E32C
_0805CFB6:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805CF54

	thumb_func_start dp01t_35_1_link_standby_message_and_free_vram
dp01t_35_1_link_standby_message_and_free_vram: @ 805CFC8
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	ldr r4, =gUnknown_02023066
	adds r0, r4
	bl sub_81851A8
	ldrb r0, [r5]
	lsls r0, 9
	subs r4, 0x1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _0805D002
	cmp r0, 0x1
	bgt _0805CFF8
	cmp r0, 0
	beq _0805CFFE
	b _0805D020
	.pool
_0805CFF8:
	cmp r0, 0x2
	beq _0805D01C
	b _0805D020
_0805CFFE:
	bl b_link_standby_message
_0805D002:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0x1
	bl dp11b_obj_free
	ldrb r0, [r4]
	movs r1, 0
	bl dp11b_obj_free
	b _0805D020
	.pool
_0805D01C:
	bl b_link_standby_message
_0805D020:
	bl dp01_tbl1_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_35_1_link_standby_message_and_free_vram

	thumb_func_start sub_805D02C
sub_805D02C: @ 805D02C
	push {r4,lr}
	ldr r1, =gUnknown_02023064
	ldr r4, =gActiveBank
	ldrb r3, [r4]
	lsls r0, r3, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r2, [r0]
	cmp r2, 0x1
	beq _0805D074
	cmp r2, 0x1
	bgt _0805D054
	cmp r2, 0
	beq _0805D05A
	b _0805D084
	.pool
_0805D054:
	cmp r2, 0x2
	beq _0805D07C
	b _0805D084
_0805D05A:
	ldr r0, =gUnknown_020244AC
	adds r0, r3, r0
	strb r2, [r0]
	ldr r1, =gUnknown_020244B0
	ldrb r0, [r4]
	adds r0, r1
	strb r2, [r0]
	b _0805D084
	.pool
_0805D074:
	ldr r0, =gUnknown_020244AC
	b _0805D07E
	.pool
_0805D07C:
	ldr r0, =gUnknown_020244B0
_0805D07E:
	adds r0, r3, r0
	movs r1, 0
	strb r1, [r0]
_0805D084:
	bl dp01_tbl1_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D02C

	thumb_func_start sub_805D094
sub_805D094: @ 805D094
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	ldr r4, =gUnknown_02023068
	adds r0, r4
	bl sub_81851A8
	ldr r2, =gUnknown_0202433A
	ldrb r0, [r5]
	lsls r0, 9
	subs r1, r4, 0x3
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldrb r0, [r5]
	lsls r0, 9
	subs r4, 0x2
	adds r0, r4
	ldrb r0, [r0]
	ldr r1, =0x00000ca9
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x5
	bl sub_80A2F50
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl dp01_tbl1_exec_completed
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80587B0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D094

	thumb_func_start nullsub_22
nullsub_22: @ 805D114
	bx lr
	thumb_func_end nullsub_22

	thumb_func_start dp11_init
dp11_init: @ 805D118
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	movs r0, 0x10
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x10
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
	movs r0, 0x30
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x4]
	movs r0, 0x10
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0x8]
	movs r0, 0x50
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp11_init

	thumb_func_start dp11_free
dp11_free: @ 805D158
	push {r4,r5,lr}
	ldr r5, =gUnknown_020244D0
	ldr r0, [r5]
	cmp r0, 0
	beq _0805D192
	ldr r0, [r0, 0xC]
	bl Free
	ldr r0, [r5]
	movs r4, 0
	str r4, [r0, 0xC]
	ldr r0, [r0, 0x8]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x8]
	ldr r0, [r0, 0x4]
	bl Free
	ldr r0, [r5]
	str r4, [r0, 0x4]
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	str r4, [r0]
	bl Free
	str r4, [r5]
_0805D192:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp11_free

	thumb_func_start sub_805D19C
sub_805D19C: @ 805D19C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0x1
	negs r0, r0
	mov r9, r0
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r2, r0, 9
	ldr r1, =gUnknown_02023068
	adds r2, r1
	mov r10, r2
	movs r1, 0
	movs r2, 0xFF
	bl CheckMoveLimitations
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, 0x92
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	negs r0, r1
	orrs r0, r1
	asrs r4, r0, 31
	movs r0, 0x2
	ands r4, r0
	adds r6, r4, 0
	adds r5, r4, 0x2
	b _0805D20E
	.pool
_0805D20C:
	adds r4, 0x1
_0805D20E:
	cmp r4, r5
	bge _0805D234
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	ldr r1, =gUnknown_020240CC
	adds r0, r1
	ldr r0, [r0]
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 22
	adds r0, r4, r0
	ldr r2, =gUnknown_0831C494
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, r7
	ble _0805D20C
_0805D234:
	subs r7, r4, r6
	cmp r4, r5
	bne _0805D23C
	movs r7, 0x2
_0805D23C:
	movs r6, 0
	movs r4, 0
	mov r1, r10
	ldrh r0, [r1]
	cmp r0, 0
	beq _0805D27C
	mov r5, r10
_0805D24A:
	ldrh r0, [r5]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r7, r0
	bne _0805D26E
	mov r0, r10
	adds r0, 0x8
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805D26E
	ldr r0, =gBitTable
	lsls r1, r4, 2
	adds r1, r0
	ldr r0, [r1]
	orrs r6, r0
_0805D26E:
	adds r5, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0805D27C
	ldrh r0, [r5]
	cmp r0, 0
	bne _0805D24A
_0805D27C:
	cmp r6, 0
	beq _0805D2AC
	ldr r3, =gUnknown_0202449C
	ldr r1, [r3]
	adds r1, 0x92
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r3]
	adds r1, 0x92
	lsls r0, r6, 4
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	lsls r0, r6, 24
	lsrs r0, 24
	bl BattleAI_SetupAIData
	bl sub_8130BA4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0805D2AC:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0805D2B6
	b _0805D40C
_0805D2B6:
	mov r2, r8
	cmp r2, 0xF
	bne _0805D2BE
	b _0805D3EA
_0805D2BE:
	movs r5, 0
	movs r6, 0
	ldr r7, =gBitTable
	mov r4, r10
_0805D2C6:
	ldrh r0, [r4]
	bl sub_805D4A8
	lsls r0, 24
	cmp r0, 0
	bne _0805D2DE
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _0805D2DE
	adds r5, 0x1
_0805D2DE:
	ldrh r0, [r4]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805D2F8
	ldr r0, [r7]
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	bne _0805D2F8
	adds r5, 0x10
_0805D2F8:
	ldrh r0, [r4]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0805D316
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _0805D316
	movs r2, 0x80
	lsls r2, 1
	adds r5, r2
_0805D316:
	adds r7, 0x4
	adds r4, 0x2
	ldr r0, =gBitTable
	adds r0, 0xC
	cmp r7, r0
	ble _0805D2C6
	movs r1, 0xF
	ands r1, r5
	cmp r1, 0x1
	ble _0805D32C
	adds r6, 0x1
_0805D32C:
	movs r0, 0xF0
	ands r0, r5
	cmp r0, 0x1F
	ble _0805D336
	adds r6, 0x1
_0805D336:
	ldr r2, =0x000001ff
	cmp r0, r2
	ble _0805D33E
	adds r6, 0x1
_0805D33E:
	cmp r6, 0x1
	bgt _0805D346
	cmp r6, 0
	bne _0805D388
_0805D346:
	ldr r5, =gBitTable
_0805D348:
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r4, r1, 16
	lsls r0, r4, 2
	adds r0, r5
	ldr r0, [r0]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _0805D366
	mov r9, r4
_0805D366:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0805D348
	b _0805D3D4
	.pool
_0805D388:
	cmp r1, 0x1
	ble _0805D38E
	movs r6, 0
_0805D38E:
	cmp r0, 0x1F
	ble _0805D394
	movs r6, 0x1
_0805D394:
	cmp r0, r2
	ble _0805D39A
	movs r6, 0x2
_0805D39A:
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r4, r1, 16
	ldr r1, =gBitTable
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, 0
	bne _0805D3CC
	lsls r0, r4, 1
	add r0, r10
	ldrh r0, [r0]
	bl sub_805D4A8
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bne _0805D3CC
	mov r9, r4
_0805D3CC:
	movs r0, 0x1
	negs r0, r0
	cmp r9, r0
	beq _0805D39A
_0805D3D4:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x31
	bls _0805D40C
_0805D3EA:
	ldr r2, =gProtectStructs
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r1, 4
	adds r1, r2
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	movs r0, 0
	b _0805D496
	.pool
_0805D40C:
	mov r1, r9
	lsls r0, r1, 1
	mov r2, r10
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, 0xAE
	bne _0805D434
	ldrb r0, [r2, 0x12]
	movs r5, 0
	cmp r0, 0x7
	beq _0805D442
	ldrb r1, [r2, 0x13]
	movs r0, 0x7
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	asrs r5, r0, 31
	movs r0, 0x10
	ands r5, r0
	b _0805D442
_0805D434:
	ldr r2, =gBattleMoves
	ldrh r1, [r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r5, [r0, 0x6]
_0805D442:
	movs r0, 0x10
	ands r0, r5
	cmp r0, 0
	beq _0805D45C
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 8
	b _0805D48A
	.pool
_0805D45C:
	cmp r5, 0
	bne _0805D470
	bl sub_805D5F4
	lsls r0, 16
	lsrs r0, 16
	mov r2, r9
	orrs r2, r0
	mov r9, r2
	b _0805D490
_0805D470:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl battle_get_per_side_status
	adds r1, r0, 0
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 16
_0805D48A:
	mov r1, r9
	orrs r1, r0
	mov r9, r1
_0805D490:
	mov r2, r9
	lsls r0, r2, 16
	lsrs r0, 16
_0805D496:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_805D19C

	thumb_func_start sub_805D4A8
sub_805D4A8: @ 805D4A8
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gBattleMoves
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x6]
	adds r3, r1, 0
	cmp r0, 0x40
	bls _0805D4C2
	b _0805D5EE
_0805D4C2:
	lsls r0, 2
	ldr r1, =_0805D4D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0805D4D4:
	.4byte _0805D5D8
	.4byte _0805D5E6
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EA
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5D8
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5EE
	.4byte _0805D5E6
_0805D5D8:
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0805D5EE
_0805D5E6:
	movs r0, 0x2
	b _0805D5F0
_0805D5EA:
	movs r0, 0x1
	b _0805D5F0
_0805D5EE:
	movs r0, 0
_0805D5F0:
	pop {r1}
	bx r1
	thumb_func_end sub_805D4A8

	thumb_func_start sub_805D5F4
sub_805D5F4: @ 805D5F4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805D6FA
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805D630
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x3
	b _0805D63E
	.pool
_0805D630:
	movs r0, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x2
_0805D63E:
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r1, =gBattleMons
	movs r2, 0x58
	mov r0, r8
	muls r0, r2
	adds r5, r0, r1
	adds r0, r7, 0
	muls r0, r2
	adds r6, r0, r1
	ldrh r0, [r5, 0x28]
	ldrh r3, [r6, 0x28]
	cmp r0, r3
	bne _0805D680
	bl Random
	adds r3, r0, 0
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	movs r1, 0x2
	ands r1, r3
	adds r0, r1
	b _0805D702
	.pool
_0805D680:
	ldr r4, =gUnknown_0831C604
	ldr r0, =gActiveBank
	mov r9, r0
	ldrb r0, [r0]
	muls r0, r2
	adds r1, 0x48
	adds r0, r1
	ldr r0, [r0]
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	adds r0, r4
	ldrb r4, [r0]
	cmp r4, 0x1
	beq _0805D6CC
	cmp r4, 0x1
	bgt _0805D6B4
	cmp r4, 0
	beq _0805D6BA
	b _0805D6FA
	.pool
_0805D6B4:
	cmp r4, 0x2
	beq _0805D6DE
	b _0805D6FA
_0805D6BA:
	ldrh r0, [r5, 0x28]
	ldrh r6, [r6, 0x28]
	cmp r0, r6
	bls _0805D6C8
	mov r1, r8
	lsls r0, r1, 8
	b _0805D704
_0805D6C8:
	lsls r0, r7, 8
	b _0805D704
_0805D6CC:
	ldrh r0, [r5, 0x28]
	ldrh r6, [r6, 0x28]
	cmp r0, r6
	bcs _0805D6DA
	mov r3, r8
	lsls r0, r3, 8
	b _0805D704
_0805D6DA:
	lsls r0, r7, 8
	b _0805D704
_0805D6DE:
	bl Random
	adds r3, r0, 0
	mov r0, r9
	ldrb r1, [r0]
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	ands r4, r3
	adds r0, r4
	lsls r0, 24
	lsrs r0, 16
	b _0805D704
_0805D6FA:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
_0805D702:
	lsls r0, 8
_0805D704:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_805D5F4

	thumb_func_start sub_805D714
sub_805D714: @ 805D714
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r3, [r0]
	lsls r0, r3, 26
	cmp r0, 0
	bge _0805D766
	adds r0, r1, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _0805D766
	adds r2, r1, 0
	adds r2, 0x2C
	ldrb r1, [r2]
	lsls r0, r1, 25
	cmp r0, 0
	bge _0805D75C
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	b _0805D766
	.pool
_0805D75C:
	lsls r0, r3, 27
	cmp r0, 0
	bge _0805D766
	ldr r0, =DummyObjectCallback
	str r0, [r4, 0x1C]
_0805D766:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D714

	thumb_func_start sub_805D770
sub_805D770: @ 805D770
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	adds r3, r4, 0
	adds r3, 0x2C
	ldrb r0, [r3]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r3]
	ldr r0, =DummyObjectCallback
	str r0, [r4, 0x1C]
	cmp r1, 0
	bne _0805D798
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
	b _0805D7A0
	.pool
_0805D798:
	adds r0, r4, 0
	movs r1, 0x1
	bl StartObjectRotScalAnim
_0805D7A0:
	adds r0, r4, 0
	bl AnimateObject
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_805D770

	thumb_func_start sub_805D7AC
sub_805D7AC: @ 805D7AC
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_020243FC
	ldrh r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0805D7E4
	ldrh r0, [r2, 0x2E]
	ldrh r1, [r2, 0x24]
	adds r0, r1
	strh r0, [r2, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _0805D7E4
	movs r1, 0x26
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0805D7E0
	ldr r0, =sub_805D7EC
	b _0805D7E2
	.pool
_0805D7E0:
	ldr r0, =DummyObjectCallback
_0805D7E2:
	str r0, [r2, 0x1C]
_0805D7E4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D7AC

	thumb_func_start sub_805D7EC
sub_805D7EC: @ 805D7EC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x26]
	subs r0, 0x2
	strh r0, [r1, 0x26]
	lsls r0, 16
	cmp r0, 0
	bne _0805D800
	ldr r0, =DummyObjectCallback
	str r0, [r1, 0x1C]
_0805D800:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805D7EC

	thumb_func_start move_anim_start_t2_for_situation
move_anim_start_t2_for_situation: @ 805D808
	push {r4-r6,lr}
	adds r4, r1, 0
	lsls r0, 24
	ldr r6, =gUnknown_020244D0
	ldr r1, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r3, [r1, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1]
	movs r3, 0x10
	orrs r2, r3
	strb r2, [r1]
	cmp r0, 0
	bne _0805D888
	cmp r4, 0x20
	bne _0805D844
	ldrb r0, [r5]
	movs r1, 0x6
	bl move_anim_start_t2
	b _0805D902
	.pool
_0805D844:
	cmp r4, 0x8
	beq _0805D850
	movs r0, 0x80
	ands r0, r4
	cmp r0, 0
	beq _0805D85A
_0805D850:
	ldrb r0, [r5]
	movs r1, 0
	bl move_anim_start_t2
	b _0805D902
_0805D85A:
	cmp r4, 0x10
	bne _0805D868
	ldrb r0, [r5]
	movs r1, 0x2
	bl move_anim_start_t2
	b _0805D902
_0805D868:
	movs r0, 0x7
	ands r0, r4
	cmp r0, 0
	beq _0805D87A
	ldrb r0, [r5]
	movs r1, 0x4
	bl move_anim_start_t2
	b _0805D902
_0805D87A:
	cmp r4, 0x40
	bne _0805D8EA
	ldrb r0, [r5]
	movs r1, 0x5
	bl move_anim_start_t2
	b _0805D902
_0805D888:
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r4
	cmp r0, 0
	beq _0805D89C
	ldrb r0, [r5]
	movs r1, 0x3
	bl move_anim_start_t2
	b _0805D902
_0805D89C:
	movs r0, 0x7
	ands r0, r4
	cmp r0, 0
	beq _0805D8AE
	ldrb r0, [r5]
	movs r1, 0x1
	bl move_anim_start_t2
	b _0805D902
_0805D8AE:
	movs r0, 0x80
	lsls r0, 21
	ands r0, r4
	cmp r0, 0
	beq _0805D8C2
	ldrb r0, [r5]
	movs r1, 0x7
	bl move_anim_start_t2
	b _0805D902
_0805D8C2:
	movs r0, 0x80
	lsls r0, 20
	ands r0, r4
	cmp r0, 0
	beq _0805D8D6
	ldrb r0, [r5]
	movs r1, 0x8
	bl move_anim_start_t2
	b _0805D902
_0805D8D6:
	movs r0, 0xE0
	lsls r0, 8
	ands r0, r4
	cmp r0, 0
	beq _0805D8EA
	ldrb r0, [r5]
	movs r1, 0x9
	bl move_anim_start_t2
	b _0805D902
_0805D8EA:
	ldr r0, [r6]
	ldrb r2, [r5]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_0805D902:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end move_anim_start_t2_for_situation

	thumb_func_start move_anim_start_t3
move_anim_start_t3: @ 805D908
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r4, 16
	lsrs r7, r4, 16
	cmp r5, 0
	bne _0805D950
	movs r0, 0x80
	ands r0, r7
	cmp r0, 0
	beq _0805D950
	ldr r0, =gUnknown_020244E4
	adds r0, r6, r0
	movs r2, 0x7F
	adds r1, r7, 0
	ands r1, r2
	strb r1, [r0]
	movs r0, 0x1
	b _0805DA1E
	.pool
_0805D950:
	ldr r0, =gUnknown_020244D0
	mov r9, r0
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r4, r6, 2
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r2, 0x4
	mov r8, r2
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0805D9CC
	adds r0, r5, 0
	bl sub_805DAA0
	lsls r0, 24
	cmp r0, 0
	bne _0805D980
	movs r0, 0x1
	b _0805DA1E
	.pool
_0805D980:
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0]
	adds r0, r4, r0
	ldrb r1, [r0]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _0805D9CC
	cmp r5, 0x2
	bne _0805D9CC
	ldr r1, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	adds r0, r6, r0
	ldrb r2, [r0]
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _0805D9CC
	adds r0, r6, 0
	movs r1, 0x1
	bl refresh_graphics_maybe
	adds r0, r6, 0
	bl sub_805E974
	movs r0, 0x1
	b _0805DA1E
	.pool
_0805D9CC:
	ldr r0, =gUnknown_02038436
	mov r2, r10
	strb r2, [r0]
	ldr r0, =gUnknown_02038437
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	strh r7, [r0]
	ldr r0, =gUnknown_082C9320
	adds r1, r5, 0
	movs r2, 0
	bl move_something
	ldr r0, =task0A_0803415C
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r6, [r1, 0x8]
	ldr r0, [r4]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
	movs r0, 0
_0805DA1E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end move_anim_start_t3

	thumb_func_start task0A_0803415C
task0A_0803415C: @ 805DA48
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805DA8A
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	ldr r2, [r2, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_0805DA8A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task0A_0803415C

	thumb_func_start sub_805DAA0
sub_805DAA0: @ 805DAA0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD
	bgt _0805DAB4
	cmp r0, 0xA
	bge _0805DAB8
	cmp r0, 0x2
	beq _0805DAB8
	b _0805DABC
_0805DAB4:
	cmp r0, 0x11
	bne _0805DABC
_0805DAB8:
	movs r0, 0x1
	b _0805DABE
_0805DABC:
	movs r0, 0
_0805DABE:
	pop {r1}
	bx r1
	thumb_func_end sub_805DAA0

	thumb_func_start move_anim_start_t4
move_anim_start_t4: @ 805DAC4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_02038436
	strb r1, [r0]
	ldr r0, =gUnknown_02038437
	strb r2, [r0]
	ldr r0, =gUnknown_082C937C
	adds r1, r3, 0
	movs r2, 0
	bl move_something
	ldr r0, =task0A_08034248
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	movs r2, 0x8
	ldrsh r1, [r1, r2]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end move_anim_start_t4

	thumb_func_start task0A_08034248
task0A_08034248: @ 805DB34
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805DB76
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0x8
	ldrsh r0, [r0, r1]
	ldr r2, [r2, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl DestroyTask
_0805DB76:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task0A_08034248

	thumb_func_start sub_805DB8C
sub_805DB8C: @ 805DB8C
	movs r0, 0
	bx lr
	thumb_func_end sub_805DB8C

	thumb_func_start mplay_80342A4
mplay_80342A4: @ 805DB90
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	bl mplay_has_finished_maybe
	lsls r0, 24
	cmp r0, 0
	beq _0805DBD8
	ldr r2, =gUnknown_020244D0
	ldr r0, [r2]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	adds r1, 0x1
	strb r1, [r0, 0x8]
	ldr r2, [r2]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x8]
	cmp r0, 0x1D
	bls _0805DBDC
	ldr r0, =gMPlay_SE1
	bl m4aMPlayStop
	ldr r0, =gMPlay_SE2
	bl m4aMPlayStop
_0805DBD8:
	cmp r5, 0
	beq _0805DBF0
_0805DBDC:
	movs r0, 0x1
	b _0805DC02
	.pool
_0805DBF0:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	strb r5, [r0, 0x8]
	movs r0, 0
_0805DC02:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end mplay_80342A4

	thumb_func_start sub_805DC0C
sub_805DC0C: @ 805DC0C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0
	bl GetMonData
	str r0, [sp]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	adds r2, r1, r0
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	bne _0805DC50
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r6, [sp]
	b _0805DC58
	.pool
_0805DC50:
	ldrh r5, [r2, 0x2]
	ldr r0, =gUnknown_020244BC
	adds r0, r1, r0
	ldr r6, [r0]
_0805DC58:
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	mov r10, r0
	mov r0, r8
	bl battle_get_per_side_status
	lsls r0, 24
	lsls r2, r5, 3
	ldr r1, =gMonFrontPicTable
	adds r2, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
	mov r3, r8
	lsls r2, r3, 4
	movs r0, 0x80
	lsls r0, 1
	adds r7, r2, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r1, r3, 2
	adds r0, r1, r0
	ldrh r0, [r0, 0x2]
	str r1, [sp, 0x4]
	mov r9, r2
	cmp r0, 0
	bne _0805DCBC
	adds r0, r4, 0
	bl pokemon_get_pal
	b _0805DCC6
	.pool
_0805DCBC:
	adds r0, r5, 0
	mov r1, r10
	ldr r2, [sp]
	bl species_and_otid_get_pal
_0805DCC6:
	adds r6, r0, 0
	ldr r4, =0x0201c000
	adds r0, r6, 0
	adds r1, r4, 0
	bl LZDecompressWram
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
	mov r1, r9
	adds r1, 0x80
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =0x00000181
	cmp r5, r0
	bne _0805DD1A
	movs r7, 0x80
	lsls r7, 1
	add r7, r9
	ldr r5, =gUnknown_0202449C
	ldr r1, [r5]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4
	adds r0, r6, 0
	bl LZDecompressWram
	ldr r0, =gUnknown_020244E4
	add r0, r8
	ldrb r1, [r0]
	lsls r1, 5
	adds r1, r4
	ldr r0, [r5]
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
_0805DD1A:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldr r1, [sp, 0x4]
	adds r0, r1, r0
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805DD46
	ldr r3, =0x00007fff
	adds r0, r7, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r7, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_0805DD46:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DC0C

	thumb_func_start sub_805DD7C
sub_805DD7C: @ 805DD7C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	movs r1, 0
	bl GetMonData
	str r0, [sp]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	mov r2, r8
	lsls r1, r2, 2
	adds r2, r1, r0
	ldrh r0, [r2, 0x2]
	cmp r0, 0
	bne _0805DDC0
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r4, [sp]
	b _0805DDC8
	.pool
_0805DDC0:
	ldrh r5, [r2, 0x2]
	ldr r0, =gUnknown_020244BC
	adds r0, r1, r0
	ldr r4, [r0]
_0805DDC8:
	adds r0, r6, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x4]
	mov r0, r8
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x1
	mov r1, r8
	bl sub_80688F8
	lsls r0, 24
	lsrs r0, 24
	mov r1, r8
	lsls r1, 2
	mov r10, r1
	cmp r0, 0x1
	beq _0805DE00
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	add r0, r10
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805DE2C
_0805DE00:
	lsls r0, r5, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	lsls r2, r7, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	adds r2, r5, 0
	adds r3, r4, 0
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
	b _0805DE46
	.pool
_0805DE2C:
	lsls r0, r5, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	lsls r2, r7, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	adds r2, r5, 0
	adds r3, r4, 0
	bl DecompressMonPic_DetectFrontOrBack
_0805DE46:
	mov r2, r8
	lsls r1, r2, 4
	movs r0, 0x80
	lsls r0, 1
	adds r7, r1, r0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	add r0, r10
	ldrh r0, [r0, 0x2]
	mov r9, r1
	cmp r0, 0
	bne _0805DE74
	adds r0, r6, 0
	bl pokemon_get_pal
	b _0805DE7E
	.pool
_0805DE74:
	adds r0, r5, 0
	ldr r1, [sp, 0x4]
	ldr r2, [sp]
	bl species_and_otid_get_pal
_0805DE7E:
	adds r6, r0, 0
	ldr r4, =0x0201c000
	adds r0, r6, 0
	adds r1, r4, 0
	bl LZDecompressWram
	adds r0, r4, 0
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
	mov r1, r9
	adds r1, 0x80
	adds r0, r4, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =0x00000181
	cmp r5, r0
	bne _0805DED2
	movs r7, 0x80
	lsls r7, 1
	add r7, r9
	ldr r5, =gUnknown_0202449C
	ldr r1, [r5]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4
	adds r0, r6, 0
	bl LZDecompressWram
	ldr r0, =gUnknown_020244E4
	add r0, r8
	ldrb r1, [r0]
	lsls r1, 5
	adds r1, r4
	ldr r0, [r5]
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x20
	bl LoadPalette
_0805DED2:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	add r0, r10
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805DEFC
	ldr r3, =0x00007fff
	adds r0, r7, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r7, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_0805DEFC:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DD7C

	thumb_func_start nullsub_23
nullsub_23: @ 805DF30
	bx lr
	thumb_func_end nullsub_23

	thumb_func_start nullsub_24
nullsub_24: @ 805DF34
	bx lr
	thumb_func_end nullsub_24

	thumb_func_start sub_805DF38
sub_805DF38: @ 805DF38
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 24
	lsrs r0, 24
	bl battle_get_per_side_status
	lsls r0, 24
	lsls r4, 3
	ldr r2, =gTrainerFrontPicTable
	adds r2, r4, r2
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	movs r2, 0
	bl DecompressPicFromTable_2
	ldr r0, =gTrainerFrontPicPaletteTable
	adds r4, r0
	adds r0, r4, 0
	bl LoadCompressedObjectPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DF38

	thumb_func_start sub_805DF84
sub_805DF84: @ 805DF84
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsls r5, 3
	ldr r2, =gTrainerBackPicTable
	adds r2, r5, r2
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	lsrs r0, 22
	adds r1, 0x4
	adds r1, r0
	ldr r1, [r1]
	adds r0, r2, 0
	movs r2, 0
	bl DecompressPicFromTable_2
	ldr r0, =gTrainerBackPicPaletteTable
	adds r5, r0
	ldr r0, [r5]
	lsls r4, 20
	movs r1, 0x80
	lsls r1, 17
	adds r4, r1
	lsrs r4, 16
	adds r1, r4, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DF84

	thumb_func_start nullsub_25
nullsub_25: @ 805DFE0
	bx lr
	thumb_func_end nullsub_25

	thumb_func_start sub_805DFE4
sub_805DFE4: @ 805DFE4
	push {lr}
	lsls r0, 16
	ldr r1, =gTrainerFrontPicPaletteTable
	lsrs r0, 13
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl FreeObjectPaletteByTag
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DFE4

	thumb_func_start sub_805DFFC
sub_805DFFC: @ 805DFFC
	push {r4-r7,lr}
	ldr r4, =gUnknown_0832C128
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	bne _0805E034
	ldr r0, =gUnknown_0832C0D0
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_0832C0D8
	bl LoadCompressedObjectPic
	movs r5, 0x2
	b _0805E056
	.pool
_0805E034:
	ldr r4, =gUnknown_0832C0E0
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	ldr r4, =gUnknown_0832C0F0
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadCompressedObjectPic
	movs r5, 0x4
_0805E056:
	movs r4, 0
	cmp r4, r5
	bcs _0805E076
	ldr r7, =gUnknown_02024076
	ldr r6, =gUnknown_0832C108
_0805E060:
	adds r0, r4, r7
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, r6
	bl LoadCompressedObjectPic
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r5
	bcc _0805E060
_0805E076:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805DFFC

	thumb_func_start sub_805E08C
sub_805E08C: @ 805E08C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r6, 0
	cmp r4, 0
	bne _0805E09C
	b _0805E1AE
_0805E09C:
	cmp r4, 0x1
	bne _0805E0B8
	ldr r4, =gUnknown_0832C128
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	adds r4, 0x8
	adds r0, r4, 0
	bl LoadTaggedObjectPalette
	b _0805E1AE
	.pool
_0805E0B8:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	bne _0805E120
	cmp r4, 0x2
	bne _0805E0F0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0805E0E4
	ldr r0, =gUnknown_0832C100
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E0E4:
	ldr r0, =gUnknown_0832C0D0
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E0F0:
	cmp r4, 0x3
	bne _0805E100
	ldr r0, =gUnknown_0832C0D8
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E100:
	cmp r4, 0x4
	bne _0805E110
	ldr r0, =gUnknown_02024076
	ldrb r0, [r0]
	b _0805E198
	.pool
_0805E110:
	cmp r4, 0x5
	bne _0805E1AC
	ldr r0, =gUnknown_02024076
	ldrb r0, [r0, 0x1]
	b _0805E198
	.pool
_0805E120:
	cmp r4, 0x2
	bne _0805E130
	ldr r0, =gUnknown_0832C0E0
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E130:
	cmp r4, 0x3
	bne _0805E140
	ldr r0, =gUnknown_0832C0E8
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E140:
	cmp r4, 0x4
	bne _0805E150
	ldr r0, =gUnknown_0832C0F0
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E150:
	cmp r4, 0x5
	bne _0805E160
	ldr r0, =gUnknown_0832C0F8
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E160:
	cmp r4, 0x6
	bne _0805E170
	ldr r0, =gUnknown_02024076
	ldrb r0, [r0]
	b _0805E198
	.pool
_0805E170:
	cmp r4, 0x7
	bne _0805E180
	ldr r0, =gUnknown_02024076
	ldrb r0, [r0, 0x1]
	b _0805E198
	.pool
_0805E180:
	cmp r4, 0x8
	bne _0805E190
	ldr r0, =gUnknown_02024076
	ldrb r0, [r0, 0x2]
	b _0805E198
	.pool
_0805E190:
	cmp r5, 0x9
	bne _0805E1AC
	ldr r0, =gUnknown_02024076
	ldrb r0, [r0, 0x3]
_0805E198:
	lsls r0, 3
	ldr r1, =gUnknown_0832C108
	adds r0, r1
	bl LoadCompressedObjectPic
	b _0805E1AE
	.pool
_0805E1AC:
	movs r6, 0x1
_0805E1AE:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_805E08C

	thumb_func_start load_gfxc_health_bar
load_gfxc_health_bar: @ 805E1B8
	push {lr}
	ldr r0, =gUnknown_08C093F0
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	movs r2, 0xBA
	lsls r2, 1
	adds r1, r2
	ldr r1, [r1]
	bl LZDecompressWram
	pop {r0}
	bx r0
	.pool
	thumb_func_end load_gfxc_health_bar

	thumb_func_start battle_load_something
battle_load_something: @ 805E1D8
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r6, 0
	ldrb r0, [r5]
	cmp r0, 0x6
	bls _0805E1E8
	b _0805E346
_0805E1E8:
	lsls r0, 2
	ldr r1, =_0805E1F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0805E1F8:
	.4byte _0805E214
	.4byte _0805E21A
	.4byte _0805E324
	.4byte _0805E230
	.4byte _0805E260
	.4byte _0805E29C
	.4byte _0805E33C
_0805E214:
	bl sub_805E378
	b _0805E324
_0805E21A:
	ldrb r0, [r4]
	bl sub_805E08C
	lsls r0, 24
	cmp r0, 0
	beq _0805E228
	b _0805E320
_0805E228:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	b _0805E346
_0805E230:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0805E24C
	ldrb r0, [r4]
	cmp r0, 0
	bne _0805E24C
	bl battle_make_oam_safari_battle
	b _0805E252
	.pool
_0805E24C:
	ldrb r0, [r4]
	bl battle_make_oam_normal_battle
_0805E252:
	ldr r2, =gUnknown_03005D70
	ldrb r1, [r4]
	adds r1, r2
	strb r0, [r1]
	b _0805E30E
	.pool
_0805E260:
	ldrb r0, [r4]
	bl sub_8072B18
	ldr r0, =gUnknown_02024076
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _0805E288
	ldr r0, =gUnknown_03005D70
	adds r0, r1, r0
	ldrb r0, [r0]
	movs r1, 0
	bl nullsub_30
	b _0805E30E
	.pool
_0805E288:
	ldr r0, =gUnknown_03005D70
	adds r0, r1, r0
	ldrb r0, [r0]
	movs r1, 0x1
	bl nullsub_30
	b _0805E30E
	.pool
_0805E29C:
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805E2E4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0805E302
	ldr r0, =gUnknown_03005D70
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gPlayerParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	b _0805E302
	.pool
_0805E2E4:
	ldr r0, =gUnknown_03005D70
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
_0805E302:
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r4]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
_0805E30E:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _0805E346
_0805E320:
	movs r0, 0
	strb r0, [r4]
_0805E324:
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	b _0805E346
	.pool
_0805E33C:
	bl sub_805EC84
	bl sub_81B8C68
	movs r6, 0x1
_0805E346:
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end battle_load_something

	thumb_func_start sub_805E350
sub_805E350: @ 805E350
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	movs r1, 0
	movs r2, 0x30
	bl memset
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	movs r1, 0
	movs r2, 0x10
	bl memset
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E350

	thumb_func_start sub_805E378
sub_805E378: @ 805E378
	push {lr}
	bl sub_805E350
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, 0
	movs r2, 0x10
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E378

	thumb_func_start sub_805E394
sub_805E394: @ 805E394
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r4, 0
	ldr r5, =gNoOfAllBanks
	ldrb r0, [r5]
	cmp r4, r0
	bge _0805E3EA
	ldr r0, =gUnknown_02020630
	mov r9, r0
	movs r0, 0x1
	mov r12, r0
	movs r0, 0x2
	negs r0, r0
	mov r8, r0
	ldr r7, =gUnknown_020244D0
	ldr r6, =gUnknown_020241E4
_0805E3B8:
	ldr r0, [r7]
	ldr r0, [r0]
	lsls r3, r4, 2
	adds r3, r0
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r1, 29
	lsrs r1, 31
	mov r0, r12
	ands r1, r0
	ldrb r2, [r3]
	mov r0, r8
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r4, 0x1
	ldrb r0, [r5]
	cmp r4, r0
	blt _0805E3B8
_0805E3EA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E394

	thumb_func_start sub_805E408
sub_805E408: @ 805E408
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_020244D0
	ldr r1, [r1]
	ldr r1, [r1]
	lsls r3, r0, 2
	adds r3, r1
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	lsls r1, 29
	lsrs r1, 31
	ldrb r2, [r3]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bx lr
	.pool
	thumb_func_end sub_805E408

	thumb_func_start sub_805E448
sub_805E448: @ 805E448
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	lsls r2, 24
	cmp r2, 0
	beq _0805E51C
	ldr r0, =gUnknown_020241E4
	adds r5, r7, r0
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	mov r8, r1
	add r0, r8
	ldr r4, =gUnknown_020244D0
	ldr r1, [r4]
	ldr r1, [r1, 0x8]
	ldrb r1, [r1]
	bl StartObjectImageAnim
	lsls r0, r7, 20
	movs r2, 0x80
	lsls r2, 17
	adds r0, r2
	lsrs r6, r0, 16
	ldr r2, =gUnknown_0202449C
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrh r1, [r0]
	lsls r1, 5
	movs r3, 0x80
	lsls r3, 1
	adds r1, r3
	ldr r0, [r2]
	adds r0, r1
	adds r1, r6, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r1, =gUnknown_020244E4
	adds r1, r7, r1
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	ldrh r0, [r0, 0x2]
	cmp r0, 0
	beq _0805E4DE
	ldr r3, =0x00007fff
	adds r0, r6, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r6, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
_0805E4DE:
	adds r0, r7, 0
	bl sub_80A6138
	ldrb r2, [r5]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x22]
	b _0805E77A
	.pool
_0805E51C:
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0805E558
	movs r0, 0
	mov r10, r0
	ldr r0, =gUnknown_02039F34
	ldr r0, [r0]
	ldr r2, [r0, 0x18]
	ldrh r1, [r2, 0x2]
	mov r8, r1
	ldr r3, [r2, 0x8]
	mov r9, r3
	ldr r4, [r2, 0xC]
	lsls r0, r1, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	ldr r1, [r1, 0x4]
	ldr r3, [r2, 0x10]
	b _0805E5FA
	.pool
_0805E558:
	adds r0, r7, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, [sp]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805E58C
	ldr r1, =gBattlePartyID
	ldr r2, [sp]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	b _0805E59C
	.pool
_0805E58C:
	ldr r1, =gBattlePartyID
	ldr r3, [sp]
	lsls r0, r3, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
_0805E59C:
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0805E618
	ldr r0, =gBattlePartyID
	lsls r4, r7, 1
	adds r4, r0
	ldrh r0, [r4]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrh r0, [r4]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	adds r4, r0, 0
	mov r1, r8
	lsls r0, r1, 3
	ldr r1, =gMonBackPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	mov r3, r10
	lsls r2, r3, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	ldr r3, =gUnknown_020244BC
	lsls r2, r7, 2
	adds r2, r3
	ldr r3, [r2]
_0805E5FA:
	mov r2, r8
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
	b _0805E662
	.pool
_0805E618:
	ldr r0, =gBattlePartyID
	lsls r4, r7, 1
	adds r4, r0
	ldrh r0, [r4]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0
	bl GetMonData
	mov r9, r0
	ldrh r0, [r4]
	muls r0, r6
	adds r0, r5
	movs r1, 0x1
	bl GetMonData
	adds r4, r0, 0
	mov r1, r8
	lsls r0, r1, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	mov r3, r10
	lsls r2, r3, 2
	adds r1, 0x4
	adds r1, r2
	ldr r1, [r1]
	ldr r3, =gUnknown_020244BC
	lsls r2, r7, 2
	adds r2, r3
	ldr r3, [r2]
	mov r2, r8
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
_0805E662:
	ldr r0, =gUnknown_020244D4
	ldr r0, [r0]
	mov r2, r10
	lsls r1, r2, 2
	adds r0, 0x4
	adds r0, r1
	ldr r2, [r0]
	ldr r0, =gUnknown_020241E4
	adds r0, r7
	mov r10, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r3, =gUnknown_02020630
	adds r0, r3
	ldrh r0, [r0, 0x4]
	lsls r0, 22
	lsrs r0, 17
	ldr r1, =0x06010000
	adds r0, r1
	ldr r1, =0x040000d4
	str r2, [r1]
	str r0, [r1, 0x4]
	ldr r0, =0x84000200
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	lsls r0, r7, 20
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r6, r0, 16
	mov r0, r8
	adds r1, r4, 0
	mov r2, r9
	bl species_and_otid_get_pal
	mov r9, r0
	ldr r4, =0x0201c000
	adds r1, r4, 0
	bl LZDecompressWram
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =0x00000181
	cmp r8, r0
	bne _0805E70A
	mov r2, r10
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r1, 0x8
	adds r0, r1
	ldr r1, =gUnknown_08309AAC
	mov r3, r8
	lsls r2, r3, 2
	adds r1, r2
	ldr r1, [r1]
	str r1, [r0]
	ldr r5, =gUnknown_0202449C
	ldr r1, [r5]
	movs r4, 0x80
	lsls r4, 1
	adds r1, r4
	mov r0, r9
	bl LZDecompressWram
	ldr r0, =gUnknown_020244E4
	ldr r1, [sp]
	adds r0, r1, r0
	ldrb r1, [r0]
	lsls r1, 5
	adds r1, r4
	ldr r0, [r5]
	adds r0, r1
	adds r1, r6, 0
	movs r2, 0x20
	bl LoadPalette
_0805E70A:
	ldr r3, =0x00007fff
	adds r0, r6, 0
	movs r1, 0x10
	movs r2, 0x6
	bl BlendPalette
	lsls r1, r6, 1
	ldr r0, =gPlttBufferFaded
	adds r0, r1, r0
	ldr r2, =gPlttBufferUnfaded
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0805E74A
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r7, 2
	adds r0, r1
	mov r2, r8
	strh r2, [r0, 0x2]
	ldr r0, =gUnknown_020244E4
	adds r1, r7, r0
	ldr r3, [sp]
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r1]
_0805E74A:
	adds r0, r7, 0
	bl sub_80A6138
	mov r1, r10
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	ldr r2, =gUnknown_02020630
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x22]
	mov r3, r10
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =gUnknown_020244E4
	adds r1, r7, r1
	ldrb r1, [r1]
	bl StartObjectImageAnim
_0805E77A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E448

	thumb_func_start sub_805E7DC
sub_805E7DC: @ 805E7DC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	lsls r1, 24
	cmp r1, 0
	bne _0805E898
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0805E7F8
	movs r4, 0
	b _0805E802
_0805E7F8:
	adds r0, r4, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r4, r0, 24
_0805E802:
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	beq _0805E814
	ldr r0, =gUnknown_08C2D120
	b _0805E822
	.pool
_0805E814:
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0805E83C
	ldr r0, =gUnknown_08C2CEE0
_0805E822:
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	lsls r4, 2
	adds r1, 0x4
	adds r1, r4
	ldr r1, [r1]
	bl LZDecompressVram
	b _0805E84E
	.pool
_0805E83C:
	ldr r0, =gUnknown_08C2D120
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	lsls r4, 2
	adds r1, 0x4
	adds r1, r4
	ldr r1, [r1]
	bl LZDecompressVram
_0805E84E:
	movs r3, 0x1
	lsls r6, r5, 4
	ldr r7, =gUnknown_08C2CEBC
	ldr r0, =gUnknown_020244D4
	ldr r0, [r0]
	adds r0, 0x4
	adds r4, r0, r4
	ldr r2, =0x040000d4
	ldr r5, =0x84000200
_0805E860:
	ldr r0, [r4]
	lsls r1, r3, 11
	adds r1, r0, r1
	str r0, [r2]
	str r1, [r2, 0x4]
	str r5, [r2, 0x8]
	ldr r0, [r2, 0x8]
	adds r3, 0x1
	cmp r3, 0x3
	ble _0805E860
	movs r0, 0x80
	lsls r0, 1
	adds r1, r6, r0
	adds r0, r7, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	b _0805E8E6
	.pool
_0805E898:
	bl sub_80A4DF0
	lsls r0, 24
	cmp r0, 0
	bne _0805E8E6
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0805E8D0
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r1, r4, 0
	bl sub_805DC0C
	b _0805E8E6
	.pool
_0805E8D0:
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r5, 0
	bl sub_805DD7C
_0805E8E6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E7DC

	thumb_func_start refresh_graphics_maybe
refresh_graphics_maybe: @ 805E8F4
	push {r4-r6,lr}
	adds r5, r1, 0
	adds r4, r2, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	adds r1, r5, 0
	bl sub_805E7DC
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r4, r0, r1
	ldr r0, =gUnknown_020244E4
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	bl StartObjectImageAnim
	cmp r5, 0
	bne _0805E938
	adds r0, r6, 0
	bl sub_80A614C
	b _0805E93E
	.pool
_0805E938:
	adds r0, r6, 0
	bl sub_80A6138
_0805E93E:
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end refresh_graphics_maybe

	thumb_func_start sub_805E94C
sub_805E94C: @ 805E94C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0xA4
	bne _0805E96C
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r1, r2, 2
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
_0805E96C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805E94C

	thumb_func_start sub_805E974
sub_805E974: @ 805E974
	lsls r0, 24
	ldr r1, =gUnknown_020244D0
	ldr r1, [r1]
	ldr r1, [r1]
	lsrs r0, 22
	adds r0, r1
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_805E974

	thumb_func_start sub_805E990
sub_805E990: @ 805E990
	push {r4-r7,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r6, r1, 24
	adds r7, r6, 0
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8075060
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805EA08
	ldr r7, =gUnknown_020244D0
	ldr r0, [r7]
	ldr r2, [r0]
	lsls r4, r6, 2
	adds r0, r4, r2
	ldrb r1, [r0]
	movs r5, 0x2
	movs r3, 0x2
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0805EA5A
	adds r0, r6, 0
	eors r0, r5
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _0805E9F6
	movs r0, 0x5A
	bl audio_play
_0805E9F6:
	ldr r0, [r7]
	ldr r1, [r0]
	adds r1, r4, r1
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	b _0805EA5A
	.pool
_0805EA08:
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r0, [r0]
	lsls r1, r6, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	bne _0805EA34
	movs r0, 0x5A
	bl m4aSongNumStop
	b _0805EA5A
	.pool
_0805EA34:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805EA5A
	ldr r1, [r4]
	movs r0, 0x2
	eors r7, r0
	ldr r1, [r1]
	lsls r0, r7, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0805EA5A
	movs r0, 0x5A
	bl m4aSongNumStop
_0805EA5A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_805E990

	thumb_func_start sub_805EA60
sub_805EA60: @ 805EA60
	push {r4-r6,lr}
	movs r0, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gUnknown_020244D0
	ldr r0, [r5]
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r6, 0x3
	negs r6, r6
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805EAA2
	ldr r2, [r5]
	movs r0, 0x2
	adds r1, r4, 0
	eors r1, r0
	ldr r0, [r2]
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	adds r0, r6, 0
	ands r0, r2
	strb r0, [r1]
_0805EAA2:
	movs r0, 0x5A
	bl m4aSongNumStop
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EA60

	thumb_func_start sub_805EAB4
sub_805EAB4: @ 805EAB4
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8075060
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_805EAB4

	thumb_func_start sub_805EAE8
sub_805EAE8: @ 805EAE8
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805EB7E
	movs r0, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0x2
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r5, =gBattlePartyID
	mov r1, r8
	lsls r0, r1, 1
	adds r0, r5
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r1, r9
	lsls r0, r1, 1
	adds r0, r5
	ldrb r0, [r0]
	bl pokemon_order_func
	lsls r0, 24
	lsrs r5, r0, 24
	movs r7, 0x64
	adds r0, r4, 0
	muls r0, r7
	ldr r6, =gPlayerParty
	adds r4, r0, r6
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0805EB5A
	adds r0, r4, 0
	mov r1, r8
	bl sub_805E990
_0805EB5A:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805EB7E
	adds r0, r5, 0
	muls r0, r7
	adds r4, r0, r6
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0805EB7E
	adds r0, r4, 0
	mov r1, r9
	bl sub_805E990
_0805EB7E:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EAE8

	thumb_func_start sub_805EB9C
sub_805EB9C: @ 805EB9C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	bge _0805EC6C
	movs r0, 0x3
	mov r10, r8
	mov r1, r10
	ands r1, r0
	mov r10, r1
	movs r6, 0
	movs r2, 0x3F
	negs r2, r2
	mov r9, r2
_0805EBC8:
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _0805EC60
	ldr r4, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	adds r3, r5, r0
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	movs r7, 0x4
	negs r7, r7
	adds r2, r7, 0
	ands r1, r2
	mov r2, r10
	orrs r1, r2
	strb r1, [r0, 0x1]
	mov r7, r8
	cmp r7, 0
	bne _0805EC3C
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r2, [r0, 0x4]
	adds r2, r6, r2
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x3]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r2, 0x6]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x3]
	mov r2, r9
	ands r1, r2
	strb r1, [r0, 0x3]
	b _0805EC60
	.pool
_0805EC3C:
	ldrb r0, [r3]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r4
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r1, [r0, 0x6]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 1
	ldrb r0, [r2, 0x3]
	mov r3, r9
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x3]
_0805EC60:
	adds r6, 0xC
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _0805EBC8
_0805EC6C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EB9C

	thumb_func_start sub_805EC84
sub_805EC84: @ 805EC84
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_0831C6A0
	bl LoadCompressedObjectPic
	movs r0, 0x1
	bl GetBankByPlayerAI
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0831C6B0
	mov r8, r0
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A5C6C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 8
	movs r0, 0xE8
	lsls r0, 13
	adds r2, r0
	asrs r2, 16
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0xC8
	bl AddObjectToFront
	ldr r6, =gUnknown_020244D0
	ldr r1, [r6]
	ldr r2, [r1, 0x4]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r2, r1, r2
	strb r0, [r2, 0x7]
	ldr r7, =gUnknown_02020630
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldrb r1, [r1, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r5, [r0, 0x2E]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805ED56
	movs r0, 0x3
	bl GetBankByPlayerAI
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	movs r1, 0
	bl sub_80A5C6C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_80A5C6C
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 8
	movs r0, 0xE8
	lsls r0, 13
	adds r2, r0
	asrs r2, 16
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0xC8
	bl AddObjectToFront
	ldr r1, [r6]
	ldr r2, [r1, 0x4]
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r2, r1, r2
	strb r0, [r2, 0x7]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r1, r0
	ldrb r1, [r1, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r5, [r0, 0x2E]
_0805ED56:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EC84

	thumb_func_start sub_805ED70
@ int sub_805ED70(obj *a1)
sub_805ED70: @ 805ED70
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r5, r0, 0
	movs r0, 0
	mov r8, r0
	ldrh r0, [r5, 0x2E]
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_020241E4
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r7, r0, r1
	adds r6, r7, 0
	adds r6, 0x3E
	ldrb r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805EDAC
	adds r0, r4, 0
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	bne _0805EDC0
_0805EDAC:
	ldr r0, =sub_805EE48
	str r0, [r5, 0x1C]
	b _0805EE36
	.pool
_0805EDC0:
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _0805EDD2
	ldrb r1, [r6]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805EDE4
_0805EDD2:
	movs r0, 0x1
	mov r8, r0
	ldr r2, =gUnknown_020244D0
	lsls r4, 2
	b _0805EE06
	.pool
_0805EDE4:
	ldr r2, =gUnknown_020244D0
	ldr r0, [r2]
	ldr r0, [r0]
	lsls r1, r4, 2
	adds r3, r1, r0
	ldrh r0, [r3, 0x2]
	adds r4, r1, 0
	cmp r0, 0
	beq _0805EE06
	ldr r0, =gUnknown_08305DCC
	ldrh r1, [r3, 0x2]
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805EE06
	movs r0, 0x1
	mov r8, r0
_0805EE06:
	ldr r0, [r2]
	ldr r0, [r0]
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805EE1A
	movs r0, 0x1
	mov r8, r0
_0805EE1A:
	ldrh r0, [r7, 0x20]
	strh r0, [r5, 0x20]
	ldrh r0, [r7, 0x24]
	strh r0, [r5, 0x24]
	adds r2, r5, 0
	adds r2, 0x3E
	mov r0, r8
	lsls r3, r0, 2
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_0805EE36:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805ED70

	thumb_func_start sub_805EE48
sub_805EE48: @ 805EE48
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_805EE48

	thumb_func_start sub_805EE54
sub_805EE54: @ 805EE54
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	lsls r1, 16
	lsrs r5, r1, 16
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _0805EED0
	ldr r0, =gUnknown_020244D0
	ldr r3, [r0]
	ldr r1, [r3]
	lsls r0, r4, 2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2]
	cmp r0, 0
	beq _0805EE7E
	adds r5, r0, 0
_0805EE7E:
	ldr r0, =gUnknown_08305DCC
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0805EEB4
	ldr r2, =gUnknown_02020630
	ldr r1, [r3, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_805ED70
	b _0805EECE
	.pool
_0805EEB4:
	ldr r2, =gUnknown_02020630
	ldr r1, [r3, 0x4]
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_805EE48
_0805EECE:
	str r1, [r0]
_0805EED0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EE54

	thumb_func_start sub_805EEE0
sub_805EEE0: @ 805EEE0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020244D0
	ldr r1, [r1]
	ldr r3, [r1, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r1, [r1, 0x7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_805EE48
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_805EEE0

	thumb_func_start sub_805EF14
sub_805EF14: @ 805EF14
	push {r4-r6,lr}
	ldr r3, =0x06000240
	movs r0, 0
	movs r6, 0xF0
	lsls r6, 8
_0805EF1E:
	adds r5, r0, 0x1
	movs r4, 0xF
_0805EF22:
	ldrh r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805EF32
	adds r0, r6, 0
	orrs r0, r1
	strh r0, [r3]
_0805EF32:
	ldrh r1, [r3]
	movs r2, 0xF0
	lsls r2, 4
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0805EF46
	adds r0, r2, 0
	orrs r0, r1
	strh r0, [r3]
_0805EF46:
	ldrh r1, [r3]
	movs r2, 0xF0
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	bne _0805EF58
	adds r0, r1, 0
	orrs r0, r2
	strh r0, [r3]
_0805EF58:
	ldrh r1, [r3]
	movs r2, 0xF
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	bne _0805EF6A
	adds r0, r1, 0
	orrs r0, r2
	strh r0, [r3]
_0805EF6A:
	adds r3, 0x2
	subs r4, 0x1
	cmp r4, 0
	bge _0805EF22
	adds r0, r5, 0
	cmp r0, 0x8
	ble _0805EF1E
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EF14

	thumb_func_start sub_805EF84
sub_805EF84: @ 805EF84
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r2, [r0]
	lsls r0, r4, 2
	adds r0, r2
	movs r3, 0
	movs r2, 0
	strh r2, [r0, 0x2]
	ldr r0, =gUnknown_020244E4
	adds r0, r4, r0
	strb r3, [r0]
	cmp r1, 0
	bne _0805EFAC
	adds r0, r4, 0
	bl sub_805E974
_0805EFAC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805EF84

	thumb_func_start init_uns_table_pokemon_copy
init_uns_table_pokemon_copy: @ 805EFBC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r6, 0
	ldr r4, =gUnknown_020244D4
	str r6, [r4]
	movs r0, 0xC0
	lsls r0, 1
	bl AllocZeroed
	str r0, [r4]
	movs r0, 0x80
	lsls r0, 8
	bl AllocZeroed
	ldr r1, [r4]
	str r0, [r1]
_0805EFE2:
	ldr r0, =gUnknown_020244D4
	ldr r1, [r0]
	lsls r4, r6, 2
	adds r2, r1, 0x4
	adds r2, r4
	lsls r3, r6, 13
	ldr r0, [r1]
	adds r0, r3
	str r0, [r2]
	lsls r3, r6, 1
	adds r0, r3, r6
	lsls r0, 3
	adds r1, r0, r1
	ldr r2, =gUnknown_08329D98
	adds r1, 0x14
	adds r0, r2
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
	ldm r0!, {r2,r5,r7}
	stm r1!, {r2,r5,r7}
	movs r5, 0
	mov r9, r3
	lsls r0, r6, 5
	mov r8, r0
	adds r1, r6, 0x1
	mov r10, r1
	mov r12, r8
	adds r7, r4, 0
_0805F01A:
	ldr r2, =gUnknown_020244D4
	ldr r1, [r2]
	lsls r4, r5, 3
	add r4, r12
	adds r3, r1, 0
	adds r3, 0x74
	adds r3, r4
	adds r0, r1, 0x4
	adds r0, r7
	lsls r2, r5, 11
	ldr r0, [r0]
	adds r0, r2
	str r0, [r3]
	adds r1, r4
	adds r1, 0x78
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _0805F01A
	ldr r1, =gUnknown_020244D4
	ldr r2, [r1]
	mov r5, r9
	adds r0, r5, r6
	lsls r0, 3
	adds r1, r2, 0
	adds r1, 0x20
	adds r1, r0
	mov r0, r8
	adds r0, 0x74
	adds r2, r0
	str r2, [r1]
	mov r7, r10
	lsls r0, r7, 24
	lsrs r6, r0, 24
	cmp r6, 0x3
	bls _0805EFE2
	movs r0, 0x80
	lsls r0, 5
	bl AllocZeroed
	ldr r1, =gUnknown_020244D4
	ldr r1, [r1]
	movs r2, 0xBA
	lsls r2, 1
	adds r1, r2
	str r0, [r1]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end init_uns_table_pokemon_copy

	thumb_func_start sub_805F094
sub_805F094: @ 805F094
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D4
	ldr r0, [r6]
	cmp r0, 0
	beq _0805F106
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0805F0BA
	bl Free
	ldr r0, [r6]
	movs r1, 0xBE
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_0805F0BA:
	ldr r0, [r6]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0805F0D8
	bl Free
	ldr r0, [r6]
	movs r1, 0xBC
	lsls r1, 1
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_0805F0D8:
	ldr r0, [r6]
	movs r5, 0xBA
	lsls r5, 1
	adds r0, r5
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	adds r5, r0, r5
	movs r4, 0
	str r4, [r5]
	ldr r0, [r0]
	bl Free
	ldr r0, [r6]
	str r4, [r0]
	str r4, [r0, 0x4]
	str r4, [r0, 0x8]
	str r4, [r0, 0xC]
	str r4, [r0, 0x10]
	bl Free
	str r4, [r6]
_0805F106:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F094

	thumb_func_start sub_805F110
sub_805F110: @ 805F110
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0x37
	bl GetMonData
	ldr r1, =0x00000fff
	ands r1, r0
	cmp r1, 0
	bne _0805F158
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r4, 16
	asrs r4, 16
	lsls r1, 16
	asrs r1, 16
	adds r0, r4, 0
	bl sub_8075060
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	ble _0805F158
	movs r0, 0x1
	b _0805F15A
	.pool
_0805F158:
	movs r0, 0
_0805F15A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_805F110

	thumb_func_start nullsub_26
nullsub_26: @ 805F160
	bx lr
	thumb_func_end nullsub_26

	thumb_func_start sub_805F164
sub_805F164: @ 805F164
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl7
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_805F164

	thumb_func_start bx_exec_buffer_A_ch0_tbl7
bx_exec_buffer_A_ch0_tbl7: @ 805F180
	push {lr}
	ldr r2, =gUnknown_02024068
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0805F1CC
	ldr r0, =gUnknown_02023064
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _0805F1C8
	ldr r0, =gUnknown_0831C6C8
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _0805F1CC
	.pool
_0805F1C8:
	bl dp01_tbl7_exec_completed
_0805F1CC:
	pop {r0}
	bx r0
	thumb_func_end bx_exec_buffer_A_ch0_tbl7

	thumb_func_start sub_805F1D0
sub_805F1D0: @ 805F1D0
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805F1F4
	bl dp01_tbl7_exec_completed
_0805F1F4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F1D0

	thumb_func_start sub_805F208
sub_805F208: @ 805F208
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805F22C
	bl dp01_tbl7_exec_completed
_0805F22C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F208

	thumb_func_start sub_805F240
sub_805F240: @ 805F240
	push {r4-r6,lr}
	ldr r5, =gUnknown_02020630
	ldr r6, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805F292
	adds r0, r2, r5
	ldrh r0, [r0, 0x6]
	bl sub_805DFE4
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl obj_free_rotscale_entry
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl RemoveObjectAndFreeTiles
	bl dp01_tbl7_exec_completed
_0805F292:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F240

	thumb_func_start sub_805F2A8
sub_805F2A8: @ 805F2A8
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r1, [r4]
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x9]
	subs r0, 0x1
	strb r0, [r1, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _0805F2E0
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl dp01_tbl7_exec_completed
_0805F2E0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F2A8

	thumb_func_start sub_805F2F0
sub_805F2F0: @ 805F2F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F32C
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F31E
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805F32C
_0805F31E:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 8
	ands r0, r1
	cmp r0, 0
	beq _0805F368
_0805F32C:
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_03005D70
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805F34E
	movs r1, 0x1
	mov r10, r1
_0805F34E:
	movs r6, 0
	b _0805F3A2
	.pool
_0805F368:
	ldr r3, =gUnknown_02020630
	ldr r6, =gUnknown_03005D70
	ldr r2, =gActiveBank
	ldrb r4, [r2]
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r3, 0x1C
	adds r0, r3
	ldr r5, [r0]
	ldr r0, =DummyObjectCallback
	cmp r5, r0
	bne _0805F3A0
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	cmp r0, r5
	bne _0805F3A0
	movs r0, 0x1
	mov r10, r0
_0805F3A0:
	movs r6, 0x1
_0805F3A2:
	ldr r3, =gUnknown_020244D8
	ldr r1, =gUnknown_020244D0
	mov r8, r1
	ldr r2, [r1]
	ldr r7, =gActiveBank
	ldrb r1, [r7]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r5, [r2, 0x4]
	adds r0, r5, r0
	str r0, [r3]
	ldr r2, =gUnknown_020244DC
	ldrb r0, [r7]
	movs r1, 0x2
	mov r9, r1
	mov r1, r9
	eors r1, r0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5, r0
	str r0, [r2]
	mov r0, r10
	cmp r0, 0
	bne _0805F3D8
	b _0805F53C
_0805F3D8:
	cmp r6, 0x1
	bne _0805F494
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r5
	ldrb r1, [r4, 0x1]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F3F2
	b _0805F53C
_0805F3F2:
	mov r0, r9
	eors r0, r2
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x1]
	ands r6, r0
	cmp r6, 0
	bne _0805F408
	b _0805F53C
_0805F408:
	ldrb r1, [r4]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4]
	mov r1, r8
	ldr r0, [r1]
	ldrb r2, [r7]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	mov r0, r8
	ldr r2, [r0]
	ldrb r0, [r7]
	mov r1, r9
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	mov r1, r8
	ldr r2, [r1]
	ldrb r0, [r7]
	mov r1, r9
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	ands r4, r1
	strb r4, [r0, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	b _0805F51A
	.pool
_0805F494:
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805F53C
	adds r0, r2, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _0805F4E4
	mov r0, r8
	ldr r2, [r0]
	ldrb r0, [r7]
	mov r1, r9
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	bne _0805F53C
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
_0805F4E4:
	mov r1, r8
	ldr r0, [r1]
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, =gActiveBank
	ldrb r2, [r1]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
_0805F51A:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x9]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F2A8
	str r1, [r0]
_0805F53C:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F2F0

	thumb_func_start sub_805F560
sub_805F560: @ 805F560
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	mov r10, r0
	ldr r5, =gUnknown_020244D0
	ldr r0, [r5]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r6, 0xC4
	lsls r6, 1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F5A6
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_0805F5A6:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00008040
	ands r0, r1
	cmp r0, 0
	bne _0805F5EE
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F5EE
	ldr r2, [r5]
	ldrb r1, [r4]
	movs r0, 0x2
	adds r3, r0, 0
	eors r3, r1
	ldr r1, [r2, 0x4]
	lsls r2, r3, 1
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F5EE
	ldr r0, =gBattlePartyID
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
_0805F5EE:
	ldr r2, =gUnknown_020244D0
	ldr r0, [r2]
	ldr r1, =gActiveBank
	mov r8, r1
	ldrb r4, [r1]
	ldr r5, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r3, r0, r5
	ldrb r1, [r3]
	movs r6, 0x8
	adds r0, r6, 0
	ands r0, r1
	mov r9, r2
	cmp r0, 0
	bne _0805F6D0
	movs r7, 0x2
	adds r1, r7, 0
	eors r1, r4
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0805F6D0
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0805F6B4
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F684
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805F684
	ldr r4, =gUnknown_03005D70
	mov r1, r8
	ldrb r0, [r1]
	adds r1, r7, 0
	eors r1, r0
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	mov r1, r8
	ldrb r0, [r1]
	eors r0, r7
	bl sub_8076918
	mov r1, r8
	ldrb r0, [r1]
	eors r0, r7
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_0805F684:
	ldr r5, =gUnknown_03005D70
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
_0805F6B4:
	ldr r3, =gUnknown_020244D0
	ldr r2, [r3]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x1]
	mov r9, r3
_0805F6D0:
	mov r1, r9
	ldr r0, [r1]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	bne _0805F792
	movs r1, 0x2
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805F792
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _0805F792
	mov r1, r9
	ldr r0, [r1]
	ldrb r4, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0805F774
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _0805F768
	adds r0, r4, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0805F774
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	b _0805F774
	.pool
_0805F768:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_0805F774:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r0, 0x1
	str r0, [sp]
_0805F792:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F7B2
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F810
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0805F810
_0805F7B2:
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_03005D7C
	ldr r1, =gActiveBank
	ldrb r4, [r1]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r3, [r0]
	ldr r0, =DummyObjectCallback
	cmp r3, r0
	bne _0805F86E
	ldr r0, =gUnknown_020241E4
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r3
	bne _0805F86E
	movs r1, 0x1
	mov r10, r1
	b _0805F86E
	.pool
_0805F810:
	ldr r2, =gUnknown_02020630
	ldr r7, =gUnknown_03005D7C
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	adds r0, r3, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r4, [r0]
	ldr r0, =DummyObjectCallback
	cmp r4, r0
	bne _0805F86E
	ldr r6, =gUnknown_020241E4
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r5, [r0]
	cmp r5, r4
	bne _0805F86E
	movs r0, 0x2
	eors r3, r0
	adds r0, r3, r7
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r4, [r0]
	cmp r4, r5
	bne _0805F86E
	adds r0, r3, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	bne _0805F86E
	movs r0, 0x1
	mov r10, r0
_0805F86E:
	ldr r1, [sp]
	cmp r1, 0
	beq _0805F958
	mov r0, r10
	cmp r0, 0
	beq _0805F958
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0805F8D2
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805F8D2
	ldr r1, =gUnknown_03005D7C
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x2
	eors r0, r4
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	bl RemoveObjectAndFreeTiles
	ldrb r0, [r5]
	eors r4, r0
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
_0805F8D2:
	ldr r1, =gUnknown_03005D7C
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	bl RemoveObjectAndFreeTiles
	ldrb r5, [r4]
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_805EE54
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r1, [r2, 0x9]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x9]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F2F0
	str r1, [r0]
_0805F958:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F560

	thumb_func_start sub_805F994
sub_805F994: @ 805F994
	push {r4,r5,lr}
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _0805F9E0
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r2, r3, 1
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 1
	ands r0, r1
	cmp r0, 0
	bne _0805F9E0
	ldr r0, =gBattlePartyID
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
_0805F9E0:
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldr r5, =gActiveBank
	ldrb r3, [r5]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805FA48
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805FA48
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r4]
	ldrb r2, [r5]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	bl dp01_tbl7_exec_completed
_0805FA48:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805F994

	thumb_func_start sub_805FA70
sub_805FA70: @ 805FA70
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	ldr r5, =gUnknown_03005D70
	adds r1, r0, r5
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
	lsls r4, 16
	asrs r1, r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0805FAB8
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _0805FABC
	.pool
_0805FAB8:
	bl dp01_tbl7_exec_completed
_0805FABC:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_805FA70

	thumb_func_start sub_805FAC4
sub_805FAC4: @ 805FAC4
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	bne _0805FAF2
	ldr r0, =gUnknown_03005D70
	adds r0, r3, r0
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl7_exec_completed
_0805FAF2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FAC4

	thumb_func_start sub_805FB08
sub_805FB08: @ 805FB08
	push {r4-r6,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805FB62
	ldr r5, =gUnknown_020241E4
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl RemoveObjectAndFreeTiles
	ldrb r0, [r6]
	bl sub_805EEE0
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl7_exec_completed
_0805FB62:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FB08

	thumb_func_start bx_t7_button_a
bx_t7_button_a: @ 805FB7C
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _0805FB8E
	bl dp01_tbl7_exec_completed
_0805FB8E:
	pop {r0}
	bx r0
	thumb_func_end bx_t7_button_a

	thumb_func_start bx_blink_t7
bx_blink_t7: @ 805FB94
	push {r4,lr}
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gUnknown_02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	bne _0805FBE0
	movs r3, 0
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_020244B9
	strb r3, [r0]
	bl dp01_tbl7_exec_completed
	b _0805FC0A
	.pool
_0805FBE0:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0805FC04
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0805FC04:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_0805FC0A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end bx_blink_t7

	thumb_func_start sub_805FC10
sub_805FC10: @ 805FC10
	push {r4,lr}
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_03005D70
	ldr r4, =gActiveBank
	ldrb r3, [r4]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805FC5C
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0805FC50
	adds r0, r3, 0
	adds r1, r3, 0
	adds r2, r3, 0
	movs r3, 0x6
	bl move_anim_start_t4
_0805FC50:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_803AEDC
	str r0, [r1]
_0805FC5C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FC10

	thumb_func_start bx_803AEDC
bx_803AEDC: @ 805FC80
	push {r4,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0805FCDA
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _0805FCDA
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	beq _0805FCCA
	ldr r0, =nullsub_18
	cmp r1, r0
	bne _0805FCDA
_0805FCCA:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	bl dp01_tbl7_exec_completed
_0805FCDA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_803AEDC

	thumb_func_start sub_805FD00
sub_805FD00: @ 805FD00
	push {r4-r7,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r1, [r3, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0805FDBC
	ldr r7, =gUnknown_02020630
	ldr r6, =gUnknown_020241E4
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r7, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805FDBC
	ldrb r1, [r3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r3]
	ldr r0, [r4]
	ldrb r2, [r5]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0
	bl StartObjectImageAnim
	ldr r4, =gUnknown_03005D70
	ldrb r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r5]
	bl sub_8076918
	ldrb r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
	ldrb r0, [r5]
	bl sub_805E408
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FC10
	str r1, [r0]
_0805FDBC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FD00

	thumb_func_start sub_805FDF0
sub_805FDF0: @ 805FDF0
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	bne _0805FE22
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_0805FE22:
	ldr r4, =gUnknown_02020630
	ldr r0, =gUnknown_03005D7C
	ldrb r2, [r5]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r3, r0, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r3, r0
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0805FE8C
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0805FE8C
	adds r0, r3, r4
	bl RemoveObjectAndFreeTiles
	ldrb r4, [r5]
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FD00
	str r1, [r0]
_0805FE8C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FDF0

	thumb_func_start sub_805FEB8
sub_805FEB8: @ 805FEB8
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0805FEDA
	bl dp01_tbl7_exec_completed
_0805FEDA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_805FEB8

	thumb_func_start bx_803B0F4
bx_803B0F4: @ 805FEE8
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0805FF0A
	bl dp01_tbl7_exec_completed
_0805FF0A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_803B0F4

	thumb_func_start dp01_tbl7_exec_completed
dp01_tbl7_exec_completed: @ 805FF18
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_03005D60
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_exec_buffer_A_ch0_tbl7
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0805FF6C
	bl link_get_multiplayer_id
	mov r1, sp
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	mov r2, sp
	bl dp01_prepare_buffer_wireless_probably
	ldr r1, =gUnknown_02023064
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r1
	movs r1, 0x38
	strb r1, [r0]
	b _0805FF7E
	.pool
_0805FF6C:
	ldr r2, =gUnknown_02024068
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0805FF7E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01_tbl7_exec_completed

	thumb_func_start dp01t_00_7_getattr
dp01t_00_7_getattr: @ 805FF90
	push {r4-r6,lr}
	sub sp, 0x100
	movs r6, 0
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _0805FFC8
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl sub_8060004
	adds r6, r0, 0
	b _0805FFEA
	.pool
_0805FFC8:
	ldrb r4, [r1]
	movs r5, 0
_0805FFCC:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0805FFE2
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl sub_8060004
	adds r6, r0
_0805FFE2:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _0805FFCC
_0805FFEA:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl dp01_tbl7_exec_completed
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_7_getattr

	thumb_func_start sub_8060004
sub_8060004: @ 8060004
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x90
	adds r7, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r2, =gUnknown_02023064
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3B
	bls _0806002E
	bl _0806079A
_0806002E:
	lsls r0, 2
	ldr r1, =_08060044
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08060044:
	.4byte _08060134
	.4byte _08060358
	.4byte _08060368
	.4byte _08060378
	.4byte _080603E0
	.4byte _080603E0
	.4byte _080603E0
	.4byte _080603E0
	.4byte _080603FC
	.4byte _08060438
	.4byte _08060438
	.4byte _08060438
	.4byte _08060438
	.4byte _0806079A
	.4byte _0806079A
	.4byte _0806079A
	.4byte _0806079A
	.4byte _08060454
	.4byte _08060464
	.4byte _08060494
	.4byte _080604A4
	.4byte _080604B4
	.4byte _080604C4
	.4byte _080604D4
	.4byte _080604E4
	.4byte _080604F4
	.4byte _08060504
	.4byte _08060514
	.4byte _08060524
	.4byte _08060534
	.4byte _08060544
	.4byte _08060554
	.4byte _080605A4
	.4byte _080605B4
	.4byte _080605C4
	.4byte _080605D4
	.4byte _080605E4
	.4byte _080605F4
	.4byte _08060604
	.4byte _08060614
	.4byte _08060624
	.4byte _08060658
	.4byte _08060668
	.4byte _08060678
	.4byte _08060688
	.4byte _08060698
	.4byte _080606A8
	.4byte _080606B8
	.4byte _080606C8
	.4byte _080606E8
	.4byte _080606F8
	.4byte _08060708
	.4byte _08060718
	.4byte _08060728
	.4byte _08060738
	.4byte _08060748
	.4byte _08060758
	.4byte _08060768
	.4byte _08060778
	.4byte _08060788
_08060134:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2E]
	movs r6, 0
	add r0, sp, 0x24
	mov r9, r0
	movs r1, 0x3B
	add r1, sp
	mov r10, r1
	mov r2, sp
	adds r2, 0x2B
	str r2, [sp, 0x80]
	mov r0, sp
	adds r0, 0x2A
	str r0, [sp, 0x7C]
	mov r1, sp
	adds r1, 0x68
	str r1, [sp, 0x8C]
	adds r2, 0x5
	str r2, [sp, 0x84]
	adds r0, 0x12
	str r0, [sp, 0x88]
	mov r8, r4
	add r4, sp, 0xC
_08060180:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r8
	bl GetMonData
	strh r0, [r4]
	adds r1, r6, 0
	adds r1, 0x11
	mov r0, r8
	bl GetMonData
	mov r2, r9
	adds r1, r2, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _08060180
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	mov r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	mov r3, sp
	movs r5, 0x1F
	ands r0, r5
	ldrb r2, [r3, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	mov r3, sp
	movs r6, 0x1F
	ands r0, r6
	lsls r0, 5
	ldrh r2, [r3, 0x14]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 2
	ldrb r2, [r3, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [sp, 0x14]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	mov r3, sp
	ands r0, r6
	lsls r0, 4
	ldrh r2, [r3, 0x16]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 1
	ldrb r2, [r3, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x48]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	str r0, [sp, 0x4C]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x7C]
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	mov r3, sp
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r3, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	mov r3, sp
	lsls r0, 7
	ldrb r2, [r3, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x54]
	adds r0, r4, 0
	movs r1, 0x2
	ldr r2, [sp, 0x8C]
	bl GetMonData
	ldr r0, [sp, 0x84]
	ldr r1, [sp, 0x8C]
	bl StringCopy10
	adds r0, r4, 0
	movs r1, 0x7
	ldr r2, [sp, 0x88]
	bl GetMonData
	mov r2, sp
	movs r6, 0
_08060338:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _08060338
	b _0806079A
	.pool
_08060358:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	b _080606D2
	.pool
_08060368:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xC
	b _080606D2
	.pool
_08060378:
	movs r6, 0
	add r2, sp, 0x58
	mov r9, r2
	add r0, sp, 0x60
	mov r10, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r4, r1, r0
	mov r8, r9
_0806038E:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r4, 0
	bl GetMonData
	mov r2, r10
	adds r1, r2, r6
	strb r0, [r1]
	movs r0, 0x2
	add r8, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _0806038E
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1, 0xC]
	mov r2, r9
	movs r6, 0
_080603CC:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _080603CC
	b _0806079A
	.pool
_080603E0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x9
	b _080606D2
	.pool
_080603FC:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gEnemyParty
	mov r8, r2
_08060408:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08060408
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _0806079A
	.pool
_08060438:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x8
	b _08060792
	.pool
_08060454:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1
	b _0806046E
	.pool
_08060464:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x19
_0806046E:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	movs r6, 0x3
	b _0806079A
	.pool
_08060494:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1A
	b _08060792
	.pool
_080604A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1B
	b _08060792
	.pool
_080604B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1C
	b _08060792
	.pool
_080604C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1D
	b _08060792
	.pool
_080604D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1E
	b _08060792
	.pool
_080604E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1F
	b _08060792
	.pool
_080604F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x20
	b _08060792
	.pool
_08060504:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x22
	b _08060792
	.pool
_08060514:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x23
	b _08060792
	.pool
_08060524:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x24
	b _08060792
	.pool
_08060534:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x25
	b _08060792
	.pool
_08060544:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x26
	b _08060792
	.pool
_08060554:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	strb r0, [r7, 0x1]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	strb r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	strb r0, [r7, 0x3]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	strb r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	strb r0, [r7, 0x5]
	movs r6, 0x6
	b _0806079A
	.pool
_080605A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x27
	b _08060792
	.pool
_080605B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x28
	b _08060792
	.pool
_080605C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x29
	b _08060792
	.pool
_080605D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2A
	b _08060792
	.pool
_080605E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2B
	b _08060792
	.pool
_080605F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2C
	b _08060792
	.pool
_08060604:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0
	b _0806062E
	.pool
_08060614:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x9
	b _080606D2
	.pool
_08060624:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x37
_0806062E:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	lsrs r0, r1, 24
	strb r0, [r7, 0x3]
	movs r6, 0x4
	b _0806079A
	.pool
_08060658:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x38
	b _08060792
	.pool
_08060668:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	b _080606D2
	.pool
_08060678:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	b _080606D2
	.pool
_08060688:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3B
	b _080606D2
	.pool
_08060698:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3C
	b _080606D2
	.pool
_080606A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3D
	b _080606D2
	.pool
_080606B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3E
	b _080606D2
	.pool
_080606C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3F
_080606D2:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _0806079A
	.pool
_080606E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x16
	b _08060792
	.pool
_080606F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x17
	b _08060792
	.pool
_08060708:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x18
	b _08060792
	.pool
_08060718:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x21
	b _08060792
	.pool
_08060728:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2F
	b _08060792
	.pool
_08060738:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x30
	b _08060792
	.pool
_08060748:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x32
	b _08060792
	.pool
_08060758:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x33
	b _08060792
	.pool
_08060768:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x34
	b _08060792
	.pool
_08060778:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x35
	b _08060792
	.pool
_08060788:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x36
_08060792:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_0806079A:
	adds r0, r6, 0
	add sp, 0x90
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8060004

	thumb_func_start dp01t_01_2_read_pokmon_data_slice
dp01t_01_2_read_pokmon_data_slice: @ 80607B0
	push {r4-r7,lr}
	sub sp, 0x58
	ldr r2, =gBattlePartyID
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	lsls r0, r1, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0x64
	adds r4, r2, 0
	muls r4, r0
	ldr r3, =gUnknown_02023064
	lsls r1, 9
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r2, [r0]
	ldr r0, =gEnemyParty
	adds r0, r2, r0
	adds r6, r4, r0
	mov r0, sp
	adds r4, r0, r2
	movs r2, 0
	adds r0, r3, 0x2
	adds r1, r0
	adds r7, r5, 0
	mov r12, r3
	ldrb r1, [r1]
	cmp r2, r1
	bcs _08060806
	adds r3, r0, 0
_080607EC:
	adds r1, r4, r2
	adds r0, r6, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	ldrb r0, [r5]
	lsls r0, 9
	adds r0, r3
	ldrb r0, [r0]
	cmp r2, r0
	bcc _080607EC
_08060806:
	ldrb r0, [r7]
	lsls r0, 9
	mov r1, r12
	adds r1, 0x2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl dp01_tbl7_exec_completed
	add sp, 0x58
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_01_2_read_pokmon_data_slice

	thumb_func_start dp01t_02_7_setattr
dp01t_02_7_setattr: @ 8060838
	push {r4,r5,lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08060868
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8060890
	b _08060886
	.pool
_08060868:
	ldrb r4, [r1]
	movs r5, 0
_0806086C:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0806087A
	adds r0, r5, 0
	bl sub_8060890
_0806087A:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _0806086C
_08060886:
	bl dp01_tbl7_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end dp01t_02_7_setattr

	thumb_func_start sub_8060890
sub_8060890: @ 8060890
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	ldr r2, =gUnknown_02023067
	adds r4, r0, r2
	adds r7, r4, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r6, r3, 0
	adds r3, r2, 0
	cmp r0, 0x3B
	bls _080608BE
	bl _0806119C
_080608BE:
	lsls r0, 2
	ldr r1, =_080608D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080608D4:
	.4byte _080609C4
	.4byte _08060B5C
	.4byte _08060B78
	.4byte _08060B94
	.4byte _08060BE8
	.4byte _08060BE8
	.4byte _08060BE8
	.4byte _08060BE8
	.4byte _08060C08
	.4byte _08060C70
	.4byte _08060C70
	.4byte _08060C70
	.4byte _08060C70
	.4byte _0806119C
	.4byte _0806119C
	.4byte _0806119C
	.4byte _0806119C
	.4byte _08060C98
	.4byte _08060CB4
	.4byte _08060CD0
	.4byte _08060CEC
	.4byte _08060D08
	.4byte _08060D24
	.4byte _08060D40
	.4byte _08060D5C
	.4byte _08060D78
	.4byte _08060D94
	.4byte _08060DB0
	.4byte _08060DCC
	.4byte _08060DE8
	.4byte _08060E04
	.4byte _08060E20
	.4byte _08060E94
	.4byte _08060EB0
	.4byte _08060ECC
	.4byte _08060EE8
	.4byte _08060F04
	.4byte _08060F20
	.4byte _08060F3C
	.4byte _08060F58
	.4byte _08060F74
	.4byte _08060F90
	.4byte _08060FAC
	.4byte _08060FC8
	.4byte _08060FE4
	.4byte _08061000
	.4byte _0806101C
	.4byte _08061038
	.4byte _08061054
	.4byte _08061070
	.4byte _0806108C
	.4byte _080610A8
	.4byte _080610C4
	.4byte _080610E0
	.4byte _080610FC
	.4byte _08061118
	.4byte _08061134
	.4byte _08061150
	.4byte _0806116C
	.4byte _08061188
_080609C4:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	adds r2, r7, 0
	bl pokemon_setattr
	adds r2, r7, 0
	adds r2, 0x2E
	adds r0, r4, 0
	movs r1, 0xC
	bl pokemon_setattr
	movs r0, 0
	mov r8, r0
	movs r0, 0x3B
	adds r0, r7
	mov r10, r0
	adds r0, r7, 0
	adds r0, 0x2B
	str r0, [sp, 0x20]
	adds r0, 0x19
	str r0, [sp, 0x28]
	adds r0, 0x4
	str r0, [sp, 0x2C]
	adds r0, 0x4
	str r0, [sp, 0x30]
	subs r0, 0x22
	str r0, [sp, 0x1C]
	subs r0, 0x2
	str r0, [sp, 0x18]
	adds r0, 0x4
	str r0, [sp, 0x24]
	adds r0, r7, 0x2
	str r0, [sp, 0x4]
	adds r0, r7, 0x4
	str r0, [sp, 0x8]
	adds r0, r7, 0x6
	str r0, [sp, 0xC]
	adds r0, 0x2
	str r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x14]
	mov r9, r4
	adds r6, r7, 0
	adds r6, 0x24
	adds r4, r7, 0
	adds r4, 0xC
_08060A2A:
	mov r1, r8
	adds r1, 0xD
	mov r0, r9
	adds r2, r4, 0
	bl pokemon_setattr
	mov r1, r8
	adds r1, 0x11
	mov r0, r9
	adds r2, r6, 0
	bl pokemon_setattr
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08060A2A
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	mov r2, r10
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x20
	ldr r2, [sp, 0x20]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x19
	ldr r2, [sp, 0x28]
	bl pokemon_setattr
	ldrb r0, [r7, 0x14]
	lsls r0, 27
	lsrs r0, 27
	mov r1, sp
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrh r0, [r7, 0x14]
	lsls r0, 22
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x28
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrb r0, [r7, 0x15]
	lsls r0, 25
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x29
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldr r0, [r7, 0x14]
	lsls r0, 12
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2A
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrh r0, [r7, 0x16]
	lsls r0, 23
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2B
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrb r0, [r7, 0x17]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2C
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0
	ldr r2, [sp, 0x2C]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x37
	ldr r2, [sp, 0x30]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x38
	ldr r2, [sp, 0x1C]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x39
	ldr r2, [sp, 0x18]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3A
	ldr r2, [sp, 0x24]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3B
	ldr r2, [sp, 0x4]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3C
	ldr r2, [sp, 0x8]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3D
	ldr r2, [sp, 0xC]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3E
	ldr r2, [sp, 0x10]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3F
	ldr r2, [sp, 0x14]
	bl pokemon_setattr
	b _0806119C
	.pool
_08060B5C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xB
	bl pokemon_setattr
	b _0806119C
	.pool
_08060B78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xC
	bl pokemon_setattr
	b _0806119C
	.pool
_08060B94:
	movs r0, 0
	mov r8, r0
	movs r0, 0xC
	adds r0, r4
	mov r9, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r7, r1, r0
	adds r6, r4, 0
	adds r6, 0x8
_08060BAC:
	mov r1, r8
	adds r1, 0xD
	adds r0, r7, 0
	adds r2, r4, 0
	bl pokemon_setattr
	mov r1, r8
	adds r1, 0x11
	adds r0, r7, 0
	adds r2, r6, 0
	bl pokemon_setattr
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08060BAC
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl pokemon_setattr
	b _0806119C
	.pool
_08060BE8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r3, =gUnknown_02023064
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x9
	b _08060C86
	.pool
_08060C08:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x11
	str r3, [sp, 0x34]
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x12
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x14
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl pokemon_setattr
	b _0806119C
	.pool
_08060C70:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r3, =gUnknown_02023064
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x8
_08060C86:
	adds r3, 0x3
	adds r2, r3
	bl pokemon_setattr
	b _0806119C
	.pool
_08060C98:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1
	bl pokemon_setattr
	b _0806119C
	.pool
_08060CB4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x19
	bl pokemon_setattr
	b _0806119C
	.pool
_08060CD0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1A
	bl pokemon_setattr
	b _0806119C
	.pool
_08060CEC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1B
	bl pokemon_setattr
	b _0806119C
	.pool
_08060D08:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1C
	bl pokemon_setattr
	b _0806119C
	.pool
_08060D24:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1D
	bl pokemon_setattr
	b _0806119C
	.pool
_08060D40:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1E
	bl pokemon_setattr
	b _0806119C
	.pool
_08060D5C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1F
	bl pokemon_setattr
	b _0806119C
	.pool
_08060D78:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x20
	bl pokemon_setattr
	b _0806119C
	.pool
_08060D94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x22
	bl pokemon_setattr
	b _0806119C
	.pool
_08060DB0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x23
	bl pokemon_setattr
	b _0806119C
	.pool
_08060DCC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x24
	bl pokemon_setattr
	b _0806119C
	.pool
_08060DE8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x25
	bl pokemon_setattr
	b _0806119C
	.pool
_08060E04:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x26
	bl pokemon_setattr
	b _0806119C
	.pool
_08060E20:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x27
	str r3, [sp, 0x34]
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x28
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x29
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2A
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2B
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x5
	adds r2, r0
	adds r0, r4, 0
	b _08060F2E
	.pool
_08060E94:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x27
	bl pokemon_setattr
	b _0806119C
	.pool
_08060EB0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x28
	bl pokemon_setattr
	b _0806119C
	.pool
_08060ECC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x29
	bl pokemon_setattr
	b _0806119C
	.pool
_08060EE8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2A
	bl pokemon_setattr
	b _0806119C
	.pool
_08060F04:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2B
	bl pokemon_setattr
	b _0806119C
	.pool
_08060F20:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
_08060F2E:
	movs r1, 0x2C
	bl pokemon_setattr
	b _0806119C
	.pool
_08060F3C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0
	bl pokemon_setattr
	b _0806119C
	.pool
_08060F58:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x9
	bl pokemon_setattr
	b _0806119C
	.pool
_08060F74:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x37
	bl pokemon_setattr
	b _0806119C
	.pool
_08060F90:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x38
	bl pokemon_setattr
	b _0806119C
	.pool
_08060FAC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x39
	bl pokemon_setattr
	b _0806119C
	.pool
_08060FC8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3A
	bl pokemon_setattr
	b _0806119C
	.pool
_08060FE4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3B
	bl pokemon_setattr
	b _0806119C
	.pool
_08061000:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3C
	bl pokemon_setattr
	b _0806119C
	.pool
_0806101C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3D
	bl pokemon_setattr
	b _0806119C
	.pool
_08061038:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3E
	bl pokemon_setattr
	b _0806119C
	.pool
_08061054:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3F
	bl pokemon_setattr
	b _0806119C
	.pool
_08061070:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x16
	bl pokemon_setattr
	b _0806119C
	.pool
_0806108C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x17
	bl pokemon_setattr
	b _0806119C
	.pool
_080610A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x18
	bl pokemon_setattr
	b _0806119C
	.pool
_080610C4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x21
	bl pokemon_setattr
	b _0806119C
	.pool
_080610E0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2F
	bl pokemon_setattr
	b _0806119C
	.pool
_080610FC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x30
	bl pokemon_setattr
	b _0806119C
	.pool
_08061118:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x32
	bl pokemon_setattr
	b _0806119C
	.pool
_08061134:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x33
	bl pokemon_setattr
	b _0806119C
	.pool
_08061150:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x34
	bl pokemon_setattr
	b _0806119C
	.pool
_0806116C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x35
	bl pokemon_setattr
	b _0806119C
	.pool
_08061188:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x36
	bl pokemon_setattr
_0806119C:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8060890

	thumb_func_start sub_80611B0
sub_80611B0: @ 80611B0
	push {r4-r7,lr}
	ldr r1, =gBattlePartyID
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	adds r3, r1, 0
	muls r3, r0
	ldr r4, =gUnknown_02023064
	lsls r2, 9
	adds r0, r4, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r5, r3, r0
	movs r3, 0
	adds r0, r4, 0x2
	adds r2, r0
	ldrb r2, [r2]
	cmp r3, r2
	bcs _08061208
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_080611E6:
	adds r1, r5, r3
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, 0x3
	adds r0, r3, r0
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r3, r0
	bcc _080611E6
_08061208:
	bl dp01_tbl7_exec_completed
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80611B0

	thumb_func_start sub_8061224
sub_8061224: @ 8061224
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	lsls r0, 1
	ldr r1, =gBattlePartyID
	adds r0, r1
	ldrh r0, [r0]
	movs r7, 0x64
	muls r0, r7
	ldr r2, =gEnemyParty
	mov r10, r2
	add r0, r10
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldrb r1, [r6]
	lsls r0, r1, 1
	ldr r2, =gBattlePartyID
	adds r0, r2
	ldrh r0, [r0]
	muls r0, r7
	add r0, r10
	bl sub_805DC0C
	ldrb r0, [r6]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r9, r0
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldrb r0, [r6]
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r6]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r4, =gUnknown_020241E4
	ldrb r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r5, =gUnknown_02020630
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ff10
	strh r1, [r0, 0x24]
	ldrb r2, [r6]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	ldrb r3, [r6]
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r2, [r6]
	adds r4, r2, r4
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r2, r1
	ldrb r1, [r2]
	bl StartObjectImageAnim
	ldrb r4, [r6]
	lsls r0, r4, 1
	ldr r2, =gBattlePartyID
	adds r0, r2
	ldrh r0, [r0]
	muls r0, r7
	add r0, r10
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F994
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061224

	thumb_func_start sub_806137C
sub_806137C: @ 806137C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x5C
	movs r1, 0x6
	strb r1, [r0]
	ldr r1, =gBattlePartyID
	ldrb r0, [r4]
	lsls r2, r0, 1
	adds r2, r1
	ldr r3, =gUnknown_02023064
	lsls r0, 9
	adds r1, r3, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r2]
	ldrb r0, [r4]
	lsls r1, r0, 9
	adds r3, 0x2
	adds r1, r3
	ldrb r1, [r1]
	bl sub_80613DC
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FDF0
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806137C

	thumb_func_start sub_80613DC
sub_80613DC: @ 80613DC
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_805EF84
	ldr r0, =gBattlePartyID
	lsls r4, r6, 1
	adds r4, r0
	ldr r0, =gUnknown_02023064
	lsls r1, r6, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, 0x64
	mov r9, r1
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =sub_805D714
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gUnknown_03005D7C
	mov r10, r1
	add r10, r6
	mov r1, r10
	strb r0, [r1]
	ldrh r0, [r4]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	adds r0, r5
	adds r1, r6, 0
	bl sub_805DC0C
	adds r0, r6, 0
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r9, r0
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r4, =gUnknown_020241E4
	adds r4, r6, r4
	strb r0, [r4]
	ldr r5, =gUnknown_02020630
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r4]
	strh r1, [r0, 0x30]
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r6, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r6, r1
	ldrb r1, [r6]
	bl StartObjectImageAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =DummyObjectCallback
	str r1, [r0]
	movs r0, 0
	movs r1, 0xFE
	bl sub_80753E8
	mov r1, r10
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x2E]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80613DC

	thumb_func_start sub_806156C
sub_806156C: @ 806156C
	push {r4-r6,lr}
	ldr r1, =gUnknown_02023064
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _080615B4
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	strb r3, [r0, 0x4]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8061604
	str r1, [r0]
	b _080615F0
	.pool
_080615B4:
	ldr r5, =gUnknown_020241E4
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl RemoveObjectAndFreeTiles
	ldrb r0, [r6]
	bl sub_805EEE0
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl dp01_tbl7_exec_completed
_080615F0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806156C

	thumb_func_start sub_8061604
sub_8061604: @ 8061604
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r4, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	beq _0806162C
	cmp r0, 0x1
	beq _0806165A
	b _08061682
	.pool
_0806162C:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08061646
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08061646:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _08061682
_0806165A:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08061682
	strb r0, [r3, 0x4]
	ldrb r2, [r5]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x2
	bl move_anim_start_t4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FB08
	str r1, [r0]
_08061682:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061604

	thumb_func_start sub_8061690
sub_8061690: @ 8061690
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 20
	ands r0, r2
	cmp r0, 0
	beq _080616B0
	bl sub_806B830
	b _0806175A
	.pool
_080616B0:
	ldr r3, =gUnknown_02038BCA
	ldrh r1, [r3]
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _080616C8
	bl sub_81A4CB0
	b _0806175A
	.pool
_080616C8:
	movs r0, 0x80
	lsls r0, 19
	ands r0, r2
	cmp r0, 0
	beq _08061708
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _08061700
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _080616F0
	ldrh r0, [r3]
	bl sub_81D5588
	b _0806175A
	.pool
_080616F0:
	ldr r0, =gUnknown_02038BCC
	ldrh r0, [r0]
	bl sub_81D5588
	b _0806175A
	.pool
_08061700:
	ldrh r0, [r3]
	bl sub_81D5588
	b _0806175A
_08061708:
	ldr r0, =0x003f0100
	ands r0, r2
	cmp r0, 0
	beq _0806174C
	ldr r0, =0x00808000
	ands r2, r0
	cmp r2, 0
	beq _08061744
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08061734
	ldrh r0, [r3]
	bl sub_8162AA0
	b _0806175A
	.pool
_08061734:
	ldr r0, =gUnknown_02038BCC
	ldrh r0, [r0]
	bl sub_8162AA0
	b _0806175A
	.pool
_08061744:
	ldrh r0, [r3]
	bl sub_8162AA0
	b _0806175A
_0806174C:
	movs r0, 0x80
	lsls r0, 4
	ands r0, r2
	cmp r0, 0
	beq _08061760
	bl sub_8165244
_0806175A:
	lsls r0, 24
	lsrs r4, r0, 24
	b _08061796
_08061760:
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _08061788
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _08061788
	ldr r2, =gTrainers
	ldr r0, =gUnknown_02038BCC
	ldrh r1, [r0]
	b _0806178C
	.pool
_08061788:
	ldr r2, =gTrainers
	ldrh r1, [r3]
_0806178C:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r4, [r0, 0x3]
_08061796:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00008040
	ands r0, r1
	cmp r0, 0
	beq _080617C8
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl battle_get_per_side_status
	movs r1, 0x2
	ands r1, r0
	movs r7, 0xC8
	cmp r1, 0
	beq _080617CA
	movs r7, 0x98
	b _080617CA
	.pool
_080617C8:
	movs r7, 0xB0
_080617CA:
	mov r8, r4
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	mov r0, r8
	bl sub_805DF38
	ldrb r0, [r5]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl template_build_for_pokemon_or_trainer
	ldr r6, =gUnknown_0202499C
	mov r9, r7
	ldr r1, =gUnknown_083054E0
	mov r2, r8
	lsls r0, r2, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r0, 0xA0
	lsls r0, 14
	adds r4, r0
	asrs r4, 16
	ldrb r0, [r5]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	mov r1, r9
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r6, =gUnknown_020241E4
	ldrb r1, [r5]
	adds r1, r6
	strb r0, [r1]
	ldr r4, =gUnknown_02020630
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ff10
	strh r1, [r0, 0x24]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x2E]
	ldr r1, =gTrainerFrontPicPaletteTable
	mov r2, r8
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl IndexOfObjectPaletteTag
	ldrb r1, [r5]
	adds r1, r6
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r4
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r1, r8
	strh r1, [r0, 0x6]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F1D0
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061690

	thumb_func_start sub_80618D8
sub_80618D8: @ 80618D8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 20
	ands r0, r2
	cmp r0, 0
	beq _080618F8
	bl sub_806B830
	b _080619A2
	.pool
_080618F8:
	ldr r3, =gUnknown_02038BCA
	ldrh r1, [r3]
	ldr r0, =0x000003fe
	cmp r1, r0
	bne _08061910
	bl sub_81A4CB0
	b _080619A2
	.pool
_08061910:
	movs r0, 0x80
	lsls r0, 19
	ands r0, r2
	cmp r0, 0
	beq _08061950
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _08061948
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08061938
	ldrh r0, [r3]
	bl sub_81D5588
	b _080619A2
	.pool
_08061938:
	ldr r0, =gUnknown_02038BCC
	ldrh r0, [r0]
	bl sub_81D5588
	b _080619A2
	.pool
_08061948:
	ldrh r0, [r3]
	bl sub_81D5588
	b _080619A2
_08061950:
	ldr r0, =0x003f0100
	ands r0, r2
	cmp r0, 0
	beq _08061994
	ldr r0, =0x00808000
	ands r2, r0
	cmp r2, 0
	beq _0806198C
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _0806197C
	ldrh r0, [r3]
	bl sub_8162AA0
	b _080619A2
	.pool
_0806197C:
	ldr r0, =gUnknown_02038BCC
	ldrh r0, [r0]
	bl sub_8162AA0
	b _080619A2
	.pool
_0806198C:
	ldrh r0, [r3]
	bl sub_8162AA0
	b _080619A2
_08061994:
	movs r0, 0x80
	lsls r0, 4
	ands r0, r2
	cmp r0, 0
	beq _080619A8
	bl sub_8165244
_080619A2:
	lsls r0, 24
	lsrs r0, 24
	b _080619DE
_080619A8:
	movs r0, 0x80
	lsls r0, 8
	ands r2, r0
	cmp r2, 0
	beq _080619D0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _080619D0
	ldr r2, =gTrainers
	ldr r0, =gUnknown_02038BCC
	ldrh r1, [r0]
	b _080619D4
	.pool
_080619D0:
	ldr r2, =gTrainers
	ldrh r1, [r3]
_080619D4:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x3]
_080619DE:
	mov r8, r0
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	bl sub_805DF38
	ldrb r0, [r6]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r2, =gUnknown_083054E0
	mov r3, r8
	lsls r1, r3, 2
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 14
	adds r2, r1
	asrs r2, 16
	movs r1, 0xB0
	movs r3, 0x1E
	bl AddObjectToFront
	ldr r5, =gUnknown_020241E4
	ldrb r1, [r6]
	adds r1, r5
	strb r0, [r1]
	ldr r4, =gUnknown_02020630
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x60
	strh r1, [r0, 0x24]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x20]
	adds r1, 0x20
	strh r1, [r0, 0x20]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldr r1, =gTrainerFrontPicPaletteTable
	mov r2, r8
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl IndexOfObjectPaletteTag
	ldrb r1, [r6]
	adds r1, r5
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r4
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r3, r8
	strh r3, [r0, 0x6]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F208
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80618D8

	thumb_func_start sub_8061AF0
sub_8061AF0: @ 8061AF0
	push {r4-r6,lr}
	ldr r6, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gUnknown_02020630
	adds r0, r5
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x8C
	lsls r1, 1
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =DummyObjectCallback
	bl oamt_set_x3A_32
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F240
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061AF0

	thumb_func_start sub_8061B9C
sub_8061B9C: @ 8061B9C
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r0, [r4, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r3, r1, r0
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	bne _08061BF0
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08061BD0
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08061BD0:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	adds r1, 0x1
	strb r1, [r0, 0x4]
	b _08061C2C
	.pool
_08061BF0:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08061C2C
	strb r0, [r3, 0x4]
	movs r0, 0x10
	movs r1, 0x3F
	bl audio_play_and_stuff
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldrb r0, [r5]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039934
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FAC4
	str r1, [r0]
_08061C2C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061B9C

	thumb_func_start sub_8061C48
sub_8061C48: @ 8061C48
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8061C48

	thumb_func_start sub_8061C54
sub_8061C54: @ 8061C54
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8061C54

	thumb_func_start sub_8061C60
sub_8061C60: @ 8061C60
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8061C60

	thumb_func_start sub_8061C6C
sub_8061C6C: @ 8061C6C
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8061C6C

	thumb_func_start sub_8061C78
sub_8061C78: @ 8061C78
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _08061C8A
	b _08061D9E
_08061C8A:
	ldr r0, =gUnknown_02023064
	mov r12, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r0, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	mov r1, r12
	adds r1, 0x2
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	ldr r5, =gUnknown_02038432
	mov r1, r12
	adds r1, 0x3
	adds r2, r1
	ldrb r1, [r2]
	strb r1, [r5]
	ldr r4, =gUnknown_02038408
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x4
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x5
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r4, =gUnknown_02038404
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x6
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0x7
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r3, r1
	mov r1, r12
	adds r1, 0x8
	adds r1, r2, r1
	ldrb r1, [r1]
	lsls r1, 16
	orrs r3, r1
	mov r1, r12
	adds r1, 0x9
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 24
	orrs r3, r1
	str r3, [r4]
	ldr r3, =gUnknown_0203841A
	ldrb r1, [r6]
	lsls r1, 9
	mov r2, r12
	adds r2, 0xA
	adds r1, r2
	ldrb r1, [r1]
	strb r1, [r3]
	ldr r4, =gUnknown_0203841C
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0xC
	adds r1, r2, r1
	ldrb r3, [r1]
	mov r1, r12
	adds r1, 0xD
	adds r2, r1
	ldrb r1, [r2]
	lsls r1, 8
	orrs r3, r1
	strh r3, [r4]
	ldr r3, =gUnknown_02038400
	ldrb r2, [r6]
	lsls r2, 9
	mov r1, r12
	adds r1, 0x10
	adds r2, r1
	str r2, [r3]
	ldr r3, =gUnknown_020244BC
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r3
	ldr r2, [r2]
	str r2, [r1]
	ldrb r1, [r5]
	bl sub_805DB8C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _08061D80
	bl dp01_tbl7_exec_completed
	b _08061D9E
	.pool
_08061D80:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x4]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_move_anim_7
	str r1, [r0]
_08061D9E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061C78

	thumb_func_start bx_move_anim_7
bx_move_anim_7: @ 8061DB0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r2, =gUnknown_02023064
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	lsls r1, r3, 9
	adds r0, r2, 0x1
	mov r10, r0
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, r2, 0x2
	mov r9, r5
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	adds r2, 0xB
	adds r1, r2
	ldrb r1, [r1]
	mov r8, r1
	ldr r7, =gUnknown_020244D0
	ldr r5, [r7]
	ldr r1, [r5, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	cmp r2, 0x1
	beq _08061E48
	cmp r2, 0x1
	bgt _08061E08
	cmp r2, 0
	beq _08061E12
	b _08061F24
	.pool
_08061E08:
	cmp r2, 0x2
	beq _08061E72
	cmp r2, 0x3
	beq _08061EE8
	b _08061F24
_08061E12:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _08061E34
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08061E34:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _08061F24
_08061E48:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08061F24
	movs r0, 0
	bl sub_805EB9C
	adds r0, r4, 0
	bl move_anim_start_t1
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0, 0x4]
	b _08061F24
_08061E72:
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _08061F24
	movs r0, 0x1
	bl sub_805EB9C
	ldr r0, [r7]
	ldrb r2, [r6]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08061EC0
	mov r0, r8
	cmp r0, 0x1
	bhi _08061EC0
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r0, [r0]
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_08061EC0:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x4]
	b _08061F24
	.pool
_08061EE8:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08061F24
	bl sub_805E394
	ldrb r0, [r6]
	lsls r2, r0, 9
	mov r3, r10
	adds r1, r2, r3
	ldrb r1, [r1]
	add r2, r9
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	bl sub_805E94C
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r4, [r0, 0x4]
	bl dp01_tbl7_exec_completed
_08061F24:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end bx_move_anim_7

	thumb_func_start sub_8061F34
sub_8061F34: @ 8061F34
	push {r4,r5,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r4, 9
	ldr r0, =gUnknown_02023066
	adds r4, r0
	ldrh r0, [r4]
	bl battle_pick_message
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_t7_button_a
	str r1, [r0]
	ldrb r0, [r5]
	ldrh r1, [r4]
	bl sub_81A57E4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8061F34

	thumb_func_start sub_8061F90
sub_8061F90: @ 8061F90
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8061F90

	thumb_func_start sub_8061F9C
sub_8061F9C: @ 8061F9C
	push {lr}
	bl sub_8063880
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8061F9C

	thumb_func_start sub_8061FAC
sub_8061FAC: @ 8061FAC
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8061FAC

	thumb_func_start sub_8061FB8
sub_8061FB8: @ 8061FB8
	push {r4-r6,lr}
	ldr r0, =gBattleTypeFlags
	ldr r2, [r0]
	movs r0, 0x80
	lsls r0, 10
	ands r0, r2
	cmp r0, 0
	beq _08061FE4
	bl sub_805D19C
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x1
	movs r1, 0xA
_08061FD6:
	bl dp01_build_cmdbuf_x21_a_bb
_08061FDA:
	bl dp01_tbl7_exec_completed
	b _08062156
	.pool
_08061FE4:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r1, =gUnknown_02023068
	adds r5, r0, r1
	movs r0, 0x93
	lsls r0, 3
	ands r2, r0
	cmp r2, 0
	beq _080620C4
	movs r0, 0xF
	bl BattleAI_SetupAIData
	bl sub_8130BA4
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	beq _08062022
	cmp r4, 0x5
	bgt _0806201C
	cmp r4, 0x4
	beq _08062028
	b _08062040
	.pool
_0806201C:
	cmp r4, 0x6
	beq _08062030
	b _08062040
_08062022:
	movs r0, 0x1
	movs r1, 0x4
	b _0806202C
_08062028:
	movs r0, 0x1
	movs r1, 0x3
_0806202C:
	movs r2, 0
	b _08061FD6
_08062030:
	ldr r0, =gBankTarget
	ldrb r2, [r0]
	movs r0, 0x1
	movs r1, 0xF
	b _08061FD6
	.pool
_08062040:
	ldr r3, =gBattleMoves
	lsls r0, r4, 1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x6]
	movs r0, 0x12
	ands r0, r1
	cmp r0, 0
	beq _08062062
	ldr r0, =gBankTarget
	ldr r1, =gActiveBank
	ldrb r1, [r1]
	strb r1, [r0]
_08062062:
	ldrh r1, [r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x6]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806209C
	movs r0, 0
	bl GetBankByPlayerAI
	ldr r5, =gBankTarget
	strb r0, [r5]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0806209C
	movs r0, 0x2
	bl GetBankByPlayerAI
	strb r0, [r5]
_0806209C:
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	movs r0, 0x1
	movs r1, 0xA
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08061FDA
	.pool
_080620C4:
	movs r6, 0x3
_080620C6:
	bl Random
	adds r4, r0, 0
	ands r4, r6
	lsls r0, r4, 1
	adds r0, r5, r0
	ldrh r2, [r0]
	cmp r2, 0
	beq _080620C6
	ldr r1, =gBattleMoves
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x6]
	movs r0, 0x12
	ands r0, r1
	cmp r0, 0
	beq _08062108
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	movs r0, 0x1
	movs r1, 0xA
	adds r2, r4, 0
	bl dp01_build_cmdbuf_x21_a_bb
	b _08062152
	.pool
_08062108:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806213C
	bl Random
	movs r1, 0x2
	ands r1, r0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1, 0
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 16
	orrs r2, r4
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
	b _08062152
	.pool
_0806213C:
	movs r0, 0
	bl GetBankByPlayerAI
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 16
	orrs r2, r4
	movs r0, 0x1
	movs r1, 0xA
	bl dp01_build_cmdbuf_x21_a_bb
_08062152:
	bl dp01_tbl7_exec_completed
_08062156:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8061FB8

	thumb_func_start sub_806215C
sub_806215C: @ 806215C
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsrs r0, 1
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC0
	ldrb r1, [r0]
	movs r0, 0x1
	bl dp01_build_cmdbuf_x23_aa_0
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806215C

	thumb_func_start sub_8062188
sub_8062188: @ 8062188
	push {r4-r7,lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	movs r2, 0xA5
	lsls r2, 2
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _08062254
	bl sub_8063A90
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bne _0806225A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080621D4
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	adds r7, r5, 0
	b _080621E8
	.pool
_080621D4:
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x3
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
_080621E8:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08062214
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08062210
	movs r0, 0
	movs r6, 0x3
	b _08062218
	.pool
_08062210:
	movs r0, 0x3
	b _08062216
_08062214:
	movs r0, 0
_08062216:
	movs r6, 0x6
_08062218:
	adds r4, r0, 0
	b _0806221E
_0806221C:
	adds r4, 0x1
_0806221E:
	cmp r4, r6
	bge _0806225A
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0806221C
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _0806221C
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _0806221C
	b _0806225A
	.pool
_08062254:
	ldrb r4, [r1]
	movs r0, 0x6
	strb r0, [r1]
_0806225A:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	adds r0, 0x5C
	strb r4, [r0]
	lsls r1, r4, 24
	lsrs r1, 24
	movs r0, 0x1
	movs r2, 0
	bl dp01_build_cmdbuf_x22_a_three_bytes
	bl dp01_tbl7_exec_completed
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062188

	thumb_func_start sub_8062288
sub_8062288: @ 8062288
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062288

	thumb_func_start sub_8062294
sub_8062294: @ 8062294
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	bl load_gfxc_health_bar
	ldr r3, =gUnknown_02023064
	ldr r0, =gActiveBank
	mov r9, r0
	ldrb r4, [r0]
	lsls r2, r4, 9
	adds r0, r3, 0x3
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r1, 8
	adds r3, 0x2
	adds r2, r3
	ldrb r0, [r2]
	orrs r0, r1
	lsls r0, 16
	asrs r7, r0, 16
	ldr r0, =0x00007fff
	cmp r7, r0
	beq _08062324
	ldr r6, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gEnemyParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	mov r8, r0
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	mov r2, r8
	bl sub_807294C
	b _0806234E
	.pool
_08062324:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	adds r2, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_807294C
_0806234E:
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FA70
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062294

	thumb_func_start sub_8062384
sub_8062384: @ 8062384
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062384

	thumb_func_start sub_8062390
sub_8062390: @ 8062390
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _080623E4
	ldr r0, =gUnknown_03005D70
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0x9
	bl healthbar_draw_field_maybe
	ldrb r2, [r4]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FEB8
	str r1, [r0]
_080623E4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062390

	thumb_func_start sub_8062408
sub_8062408: @ 8062408
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08062458
	ldr r4, =gUnknown_02023064
	ldrb r3, [r5]
	lsls r3, 9
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	adds r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	adds r2, r4, 0x4
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 16
	orrs r1, r2
	adds r4, 0x5
	adds r3, r4
	ldrb r2, [r3]
	lsls r2, 24
	orrs r1, r2
	bl move_anim_start_t2_for_situation
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805FEB8
	str r1, [r0]
_08062458:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062408

	thumb_func_start sub_8062470
sub_8062470: @ 8062470
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062470

	thumb_func_start sub_806247C
sub_806247C: @ 806247C
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_806247C

	thumb_func_start sub_8062488
sub_8062488: @ 8062488
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062488

	thumb_func_start sub_8062494
sub_8062494: @ 8062494
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062494

	thumb_func_start sub_80624A0
sub_80624A0: @ 80624A0
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_80624A0

	thumb_func_start sub_80624AC
sub_80624AC: @ 80624AC
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_80624AC

	thumb_func_start sub_80624B8
sub_80624B8: @ 80624B8
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_80624B8

	thumb_func_start sub_80624C4
sub_80624C4: @ 80624C4
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_80624C4

	thumb_func_start sub_80624D0
sub_80624D0: @ 80624D0
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_80624D0

	thumb_func_start sub_80624DC
sub_80624DC: @ 80624DC
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80624DC

	thumb_func_start sub_80624F8
sub_80624F8: @ 80624F8
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x7F
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80624F8

	thumb_func_start sub_8062530
sub_8062530: @ 8062530
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062530

	thumb_func_start sub_8062548
sub_8062548: @ 8062548
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, [r3]
	lsls r1, 24
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 7
	ldrb r2, [r3]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062548

	thumb_func_start dp01t_29_7_blink
dp01t_29_7_blink: @ 8062570
	push {r4,lr}
	ldr r3, =gUnknown_02020630
	ldr r2, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _080625A4
	bl dp01_tbl7_exec_completed
	b _080625CE
	.pool
_080625A4:
	ldr r1, =gUnknown_020244B9
	movs r0, 0x1
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x30]
	ldrb r0, [r4]
	bl sub_80769F4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =bx_blink_t7
	str r1, [r0]
_080625CE:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_29_7_blink

	thumb_func_start sub_80625E0
sub_80625E0: @ 80625E0
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_80625E0

	thumb_func_start sub_80625EC
sub_80625EC: @ 80625EC
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _08062600
	movs r3, 0xC0
_08062600:
	ldr r2, =gUnknown_02023064
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	lsls r1, r3, 24
	asrs r1, 24
	bl audio_play_and_stuff
	bl dp01_tbl7_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80625EC

	thumb_func_start sub_8062630
sub_8062630: @ 8062630
	push {r4,r5,lr}
	ldr r4, =gUnknown_02023064
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _0806266C
	bl sub_805EA60
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, r4, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl song_play_for_text
	b _08062680
	.pool
_0806266C:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl fanfare_play
_08062680:
	bl dp01_tbl7_exec_completed
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_8062630

	thumb_func_start sub_806268C
sub_806268C: @ 806268C
	push {lr}
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	movs r2, 0x5
	bl sub_80A32E4
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806268C

	thumb_func_start dp01t_2E_7_battle_intro
dp01t_2E_7_battle_intro: @ 80626C8
	push {lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl battle_intro_launch
	ldr r2, =gUnknown_020243FC
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_2E_7_battle_intro

	thumb_func_start sub_80626FC
sub_80626FC: @ 80626FC
	push {r4-r6,lr}
	ldr r5, =gUnknown_020241E4
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x8C
	lsls r1, 1
	strh r1, [r0, 0x32]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_806280C
	bl oamt_set_x3A_32
	ldr r0, =sub_8062828
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r6]
	strh r0, [r1, 0x8]
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080627BE
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_080627BE:
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_26
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80626FC

	thumb_func_start sub_806280C
sub_806280C: @ 806280C
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x6]
	bl sub_805DFE4
	adds r0, r4, 0
	bl obj_free_rotscale_entry
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806280C

	thumb_func_start sub_8062828
sub_8062828: @ 8062828
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	strb r0, [r7]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0806286C
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0806286C
	movs r0, 0x80
	lsls r0, 8
	ands r1, r0
	cmp r1, 0
	beq _080628A0
_0806286C:
	ldr r0, =gUnknown_02023064
	ldrb r1, [r7]
	lsls r2, r1, 9
	adds r0, 0x1
	adds r2, r0
	ldr r0, =gBattlePartyID
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strb r0, [r2]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_80613DC
	b _080628E0
	.pool
_080628A0:
	ldr r4, =gUnknown_02023064
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r4, 0x1
	adds r1, r4
	ldr r6, =gBattlePartyID
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_80613DC
	ldrb r0, [r7]
	movs r5, 0x2
	eors r0, r5
	strb r0, [r7]
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r1, r4
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_80613DC
	ldrb r0, [r7]
	eors r0, r5
	strb r0, [r7]
_080628E0:
	ldr r1, =gUnknown_03005D60
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_805F560
	str r1, [r0]
	mov r0, r9
	strb r0, [r2]
	mov r0, r8
	bl DestroyTask
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062828

	thumb_func_start dp01t_30_7_0803D67C
dp01t_30_7_0803D67C: @ 8062918
	push {r4-r7,lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08062948
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08062948
	bl dp01_tbl7_exec_completed
	b _08062A12
	.pool
_08062948:
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldr r1, =gUnknown_02023064
	ldrb r2, [r3]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r7, r3, 0
	cmp r0, 0
	beq _080629B4
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r2, [r3, 0x1]
	lsls r1, r2, 27
	lsrs r0, r1, 28
	cmp r0, 0x1
	bhi _080629AC
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	lsls r0, 1
	movs r1, 0x1F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	b _08062A12
	.pool
_080629AC:
	movs r0, 0x1F
	negs r0, r0
	ands r0, r2
	strb r0, [r3, 0x1]
_080629B4:
	adds r5, r7, 0
	ldrb r0, [r5]
	lsls r3, r0, 9
	ldr r4, =gUnknown_02023068
	adds r1, r3, r4
	subs r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	subs r4, 0x2
	adds r3, r4
	ldrb r3, [r3]
	bl sub_80735DC
	ldr r2, =gUnknown_020244B4
	ldrb r1, [r5]
	adds r1, r2
	movs r3, 0
	strb r0, [r1]
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x5]
	ldrb r2, [r5]
	lsls r0, r2, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08062A06
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_08062A06:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r7]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_0803D790_t7
	str r0, [r1]
_08062A12:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_30_7_0803D67C

	thumb_func_start bx_0803D790_t7
bx_0803D790_t7: @ 8062A2C
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	adds r2, r1, 0x1
	strb r2, [r0, 0x5]
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x5C
	bls _08062A64
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl dp01_tbl7_exec_completed
_08062A64:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end bx_0803D790_t7

	thumb_func_start sub_8062A74
sub_8062A74: @ 8062A74
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	ldr r1, [r1, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08062AA6
	ldr r2, =gTasks
	ldr r0, =gUnknown_020244B4
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_8073C30
	str r1, [r0]
_08062AA6:
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062A74

	thumb_func_start sub_8062AC4
sub_8062AC4: @ 8062AC4
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062AC4

	thumb_func_start sub_8062AD0
sub_8062AD0: @ 8062AD0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _08062B16
	ldr r3, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldr r0, =gUnknown_02023064
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	adds r2, 0x3E
	movs r0, 0x1
	ldrb r1, [r1]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4]
	bl sub_805E408
_08062B16:
	bl dp01_tbl7_exec_completed
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062AD0

	thumb_func_start dp01t_34_7_move_anim_start_t3
dp01t_34_7_move_anim_start_t3: @ 8062B30
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08062B88
	ldr r5, =gUnknown_02023064
	ldrb r2, [r6]
	lsls r1, r2, 9
	adds r0, r5, 0x1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r0, r5, 0x2
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, 0x3
	adds r1, r5
	ldrb r0, [r1]
	lsls r0, 8
	orrs r4, r0
	str r4, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _08062B7C
	bl dp01_tbl7_exec_completed
	b _08062B88
	.pool
_08062B7C:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r0, =bx_803B0F4
	str r0, [r1]
_08062B88:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp01t_34_7_move_anim_start_t3

	thumb_func_start sub_8062B98
sub_8062B98: @ 8062B98
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062B98

	thumb_func_start sub_8062BA4
sub_8062BA4: @ 8062BA4
	push {lr}
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	thumb_func_end sub_8062BA4

	thumb_func_start sub_8062BB0
sub_8062BB0: @ 8062BB0
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x6
	ands r0, r1
	cmp r0, 0x2
	bne _08062BDA
	ldr r2, =gMain
	ldr r0, =0x00000439
	adds r3, r2, r0
	ldrb r1, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldr r0, =gUnknown_03005D00
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, [r2, 0x8]
	bl SetMainCallback2
_08062BDA:
	bl dp01_tbl7_exec_completed
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8062BB0

	thumb_func_start nullsub_91
nullsub_91: @ 8062BF4
	bx lr
	thumb_func_end nullsub_91

	thumb_func_start ai_switch_perish_song
ai_switch_perish_song: @ 8062BF8
	push {lr}
	ldr r1, =gStatuses3
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08062C50
	ldr r0, =gDisableStructs
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xF]
	lsls r0, 28
	cmp r0, 0
	bne _08062C50
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, r2, r0
	movs r1, 0xA5
	lsls r1, 2
	adds r0, r1
	movs r1, 0x6
	strb r1, [r0]
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	movs r0, 0x1
	b _08062C52
	.pool
_08062C50:
	movs r0, 0
_08062C52:
	pop {r1}
	bx r1
	thumb_func_end ai_switch_perish_song

	thumb_func_start sub_8062C58
sub_8062C58: @ 8062C58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08062C72
	b _08062E2C
_08062C72:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl battle_get_per_side_status
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, =gBattleMons
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x58
	muls r0, r1
	adds r0, r4
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x19
	beq _08062C9E
	b _08062E2C
_08062C9E:
	mov r0, r10
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r2, r0, 24
	movs r6, 0
	mov r8, r4
	movs r7, 0x58
	adds r0, r2, 0
	muls r0, r7
	adds r4, r0, r4
	movs r0, 0x20
	adds r0, r4
	mov r9, r0
_08062CBA:
	lsls r1, r6, 1
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	muls r0, r7
	adds r1, r0
	mov r0, r8
	adds r0, 0xC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _08062CE8
	ldrh r1, [r4]
	mov r3, r9
	ldrb r2, [r3]
	bl ai_rate_move
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0x2
	ands r1, r0
	cmp r1, 0
	beq _08062CE8
	b _08062E2C
_08062CE8:
	adds r6, 0x1
	cmp r6, 0x3
	ble _08062CBA
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08062D50
	ldrb r1, [r5]
	movs r0, 0x2
	ands r0, r1
	adds r1, r5, 0
	cmp r0, 0
	bne _08062D20
	movs r4, 0
	movs r0, 0x3
	str r0, [sp]
	b _08062D58
	.pool
_08062D20:
	movs r4, 0x3
	movs r3, 0x6
	str r3, [sp]
	b _08062D58
_08062D28:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	movs r1, 0xA5
	lsls r1, 2
	adds r0, r1
	strb r6, [r0]
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	movs r0, 0x1
	b _08062E2E
	.pool
_08062D50:
	movs r4, 0
	movs r3, 0x6
	str r3, [sp]
	adds r1, r5, 0
_08062D58:
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r9, r1
	cmp r0, 0
	bne _08062D6C
	ldr r3, =gPlayerParty
	mov r9, r3
_08062D6C:
	adds r6, r4, 0
	ldr r0, [sp]
	cmp r6, r0
	bge _08062E2C
_08062D74:
	movs r0, 0x64
	adds r5, r6, 0
	muls r5, r0
	mov r1, r9
	adds r4, r1, r5
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08062E24
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _08062E24
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08062E24
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r6, r0
	beq _08062E24
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	mov r0, r10
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r2, r0, 24
	movs r4, 0
	mov r8, r5
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r5, r0, r1
	adds r7, r5, 0
	adds r7, 0x20
_08062DE0:
	adds r1, r4, 0
	adds r1, 0xD
	mov r0, r9
	add r0, r8
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _08062E1E
	ldrh r1, [r5]
	ldrb r2, [r7]
	bl ai_rate_move
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0x2
	ands r1, r0
	cmp r1, 0
	beq _08062E1E
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1
	bls _08062D28
_08062E1E:
	adds r4, 0x1
	cmp r4, 0x3
	ble _08062DE0
_08062E24:
	adds r6, 0x1
	ldr r3, [sp]
	cmp r6, r3
	blt _08062D74
_08062E2C:
	movs r0, 0
_08062E2E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8062C58

	thumb_func_start sub_8062E54
sub_8062E54: @ 8062E54
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0x1
	bl ai_has_super_effective_move_on_field
	lsls r0, 24
	cmp r0, 0
	beq _08062E82
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _08062E82
	b _080630AC
_08062E82:
	ldr r1, =gUnknown_02024250
	ldr r5, =gActiveBank
	ldrb r3, [r5]
	lsls r0, r3, 1
	adds r4, r0, r1
	ldrh r1, [r4]
	cmp r1, 0
	bne _08062E94
	b _080630AC
_08062E94:
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08062E9C
	b _080630AC
_08062E9C:
	ldr r2, =gBattleMoves
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _08062EB0
	b _080630AC
_08062EB0:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08062F1A
	mov r8, r3
	mov r0, r8
	bl battle_get_per_side_status
	movs r4, 0x2
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08062F04
	ldrb r7, [r5]
	b _08062F1E
	.pool
_08062F04:
	ldrb r0, [r5]
	bl battle_get_per_side_status
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	b _08062F1E
_08062F1A:
	adds r7, r3, 0
	mov r8, r7
_08062F1E:
	ldr r3, =gBattleMoves
	ldr r1, =gUnknown_02024250
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r0, [r0, 0x2]
	cmp r0, 0xA
	bne _08062F4C
	movs r0, 0x12
	b _08062F5E
	.pool
_08062F4C:
	cmp r0, 0xB
	bne _08062F56
	movs r1, 0xB
	str r1, [sp]
	b _08062F60
_08062F56:
	cmp r0, 0xD
	beq _08062F5C
	b _080630AC
_08062F5C:
	movs r0, 0xA
_08062F5E:
	str r0, [sp]
_08062F60:
	ldr r1, =gBattleMons
	ldrb r3, [r2]
	movs r0, 0x58
	muls r0, r3
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	ldr r1, [sp]
	cmp r0, r1
	bne _08062F76
	b _080630AC
_08062F76:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08062FCC
	movs r0, 0x2
	ands r3, r0
	cmp r3, 0
	bne _08062F9C
	movs r4, 0
	movs r0, 0x3
	b _08062FD0
	.pool
_08062F9C:
	movs r4, 0x3
	movs r1, 0x6
	mov r10, r1
	b _08062FD2
_08062FA4:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	movs r2, 0xA5
	lsls r2, 2
	adds r0, r2
	strb r5, [r0]
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	movs r0, 0x1
	b _080630AE
	.pool
_08062FCC:
	movs r4, 0
	movs r0, 0x6
_08062FD0:
	mov r10, r0
_08062FD2:
	ldrb r0, [r2]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	str r1, [sp, 0x4]
	cmp r0, 0
	bne _08062FE6
	ldr r2, =gPlayerParty
	str r2, [sp, 0x4]
_08062FE6:
	adds r5, r4, 0
	cmp r5, r10
	bge _080630AC
	ldr r0, =gBaseStats
	mov r9, r0
_08062FF0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, [sp, 0x4]
	adds r6, r1, r0
	adds r0, r6, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _080630A6
	adds r0, r6, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _080630A6
	adds r0, r6, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _080630A6
	ldr r1, =gBattlePartyID
	mov r2, r8
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _080630A6
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _080630A6
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	adds r0, r2, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r5, r0
	beq _080630A6
	adds r0, r7, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r5, r0
	beq _080630A6
	adds r0, r6, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r6, 0
	movs r1, 0x2E
	bl GetMonData
	cmp r0, 0
	beq _08063088
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	add r0, r9
	ldrb r0, [r0, 0x17]
	b _08063092
	.pool
_08063088:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	add r0, r9
	ldrb r0, [r0, 0x16]
_08063092:
	ldr r1, [sp]
	cmp r1, r0
	bne _080630A6
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _080630A6
	b _08062FA4
_080630A6:
	adds r5, 0x1
	cmp r5, r10
	blt _08062FF0
_080630AC:
	movs r0, 0
_080630AE:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8062E54

	thumb_func_start ai_switchout_natural_cure
ai_switchout_natural_cure: @ 80630C0
	push {r4,r5,lr}
	ldr r3, =gBattleMons
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	movs r0, 0x58
	adds r2, r4, 0
	muls r2, r0
	adds r0, r3, 0
	adds r0, 0x4C
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08063188
	adds r1, r2, r3
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1E
	bne _08063188
	ldrh r0, [r1, 0x2C]
	ldrh r1, [r1, 0x28]
	lsrs r0, 1
	cmp r1, r0
	bcc _08063188
	ldr r1, =gUnknown_02024250
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	cmp r1, 0
	beq _08063106
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08063128
_08063106:
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _08063128
	ldrb r0, [r5]
	b _08063190
	.pool
_08063128:
	ldr r2, =gBattleMoves
	ldr r1, =gUnknown_02024250
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _08063160
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _08063160
	ldrb r0, [r4]
	b _08063190
	.pool
_08063160:
	movs r0, 0x8
	movs r1, 0x1
	bl ai_switchout_something
	lsls r0, 24
	cmp r0, 0
	bne _080631AA
	movs r0, 0x4
	movs r1, 0x1
	bl ai_switchout_something
	lsls r0, 24
	cmp r0, 0
	bne _080631AA
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	bne _0806318C
_08063188:
	movs r0, 0
	b _080631AC
_0806318C:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
_08063190:
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	movs r1, 0xA5
	lsls r1, 2
	adds r0, r1
	movs r1, 0x6
	strb r1, [r0]
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
_080631AA:
	movs r0, 0x1
_080631AC:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ai_switchout_natural_cure

	thumb_func_start ai_has_super_effective_move_on_field
ai_has_super_effective_move_on_field: @ 80631BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl battle_get_per_side_status
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08063256
	movs r4, 0
	ldr r6, =gBattleMons
	movs r7, 0x58
	adds r0, r3, 0
	muls r0, r7
	adds r5, r0, r6
	movs r0, 0x20
	adds r0, r5
	mov r8, r0
_0806320A:
	lsls r1, r4, 1
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	muls r0, r7
	adds r1, r0
	adds r0, r6, 0
	adds r0, 0xC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _08063250
	ldrh r1, [r5]
	mov r3, r8
	ldrb r2, [r3]
	bl ai_rate_move
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0x2
	ands r1, r0
	cmp r1, 0
	beq _08063250
	mov r0, r9
	cmp r0, 0
	bne _08063278
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _08063278
_08063250:
	adds r4, 0x1
	cmp r4, 0x3
	ble _0806320A
_08063256:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0806327C
	b _080632FA
	.pool
_08063278:
	movs r0, 0x1
	b _080632FC
_0806327C:
	movs r1, 0x2
	mov r0, r10
	eors r0, r1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r3, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _080632FA
	movs r4, 0
	ldr r6, =gBattleMons
	movs r7, 0x58
	adds r0, r3, 0
	muls r0, r7
	adds r5, r0, r6
	movs r3, 0x20
	adds r3, r5
	mov r8, r3
_080632AE:
	lsls r1, r4, 1
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	muls r0, r7
	adds r1, r0
	adds r0, r6, 0
	adds r0, 0xC
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _080632F4
	ldrh r1, [r5]
	mov r3, r8
	ldrb r2, [r3]
	bl ai_rate_move
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0x2
	ands r1, r0
	cmp r1, 0
	beq _080632F4
	mov r0, r9
	cmp r0, 0
	bne _08063278
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _08063278
_080632F4:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080632AE
_080632FA:
	movs r0, 0
_080632FC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ai_has_super_effective_move_on_field

	thumb_func_start ai_is_too_invested_in_stat_buffs
ai_is_too_invested_in_stat_buffs: @ 806331C
	push {r4,lr}
	movs r4, 0
	ldr r1, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x18
	adds r2, r0, r1
	movs r3, 0x7
_08063330:
	ldrb r1, [r2]
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0x6
	ble _08063346
	subs r1, 0x6
	lsls r0, r4, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
_08063346:
	adds r2, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08063330
	movs r0, 0
	cmp r4, 0x3
	bls _08063356
	movs r0, 0x1
_08063356:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ai_is_too_invested_in_stat_buffs

	thumb_func_start ai_switchout_something
ai_switchout_something: @ 8063364
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x4]
	ldr r2, =gUnknown_02024250
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	lsls r0, r3, 1
	adds r4, r0, r2
	ldrh r2, [r4]
	adds r5, r1, 0
	cmp r2, 0
	bne _08063390
	b _080635EE
_08063390:
	ldr r0, =0x0000ffff
	cmp r2, r0
	bne _08063398
	b _080635EE
_08063398:
	ldr r0, =gUnknown_02024270
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _080633A4
	b _080635EE
_080633A4:
	ldr r2, =gBattleMoves
	ldrh r1, [r4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _080633B8
	b _080635EE
_080633B8:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806342C
	mov r9, r3
	mov r0, r9
	bl battle_get_per_side_status
	movs r4, 0x2
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08063414
	ldrb r5, [r5]
	mov r10, r5
	b _08063430
	.pool
_08063414:
	ldrb r0, [r5]
	bl battle_get_per_side_status
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	b _08063430
_0806342C:
	mov r9, r3
	mov r10, r9
_08063430:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08063490
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	adds r5, r2, 0
	cmp r0, 0
	bne _08063460
	movs r4, 0
	movs r0, 0x3
	str r0, [sp, 0x8]
	b _08063498
	.pool
_08063460:
	movs r4, 0x3
	movs r1, 0x6
	str r1, [sp, 0x8]
	b _08063498
_08063468:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	adds r0, r1
	movs r2, 0xA5
	lsls r2, 2
	adds r0, r2
	strb r6, [r0]
	movs r0, 0x1
	movs r1, 0x2
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	movs r0, 0x1
	b _080635F0
	.pool
_08063490:
	movs r4, 0
	movs r0, 0x6
	str r0, [sp, 0x8]
	ldr r5, =gActiveBank
_08063498:
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	str r1, [sp, 0xC]
	cmp r0, 0
	bne _080634AC
	ldr r2, =gPlayerParty
	str r2, [sp, 0xC]
_080634AC:
	adds r6, r4, 0
	b _080635E6
	.pool
_080634BC:
	movs r0, 0x64
	muls r0, r6
	ldr r1, [sp, 0xC]
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _080634D2
	b _080635E4
_080634D2:
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	bne _080634E0
	b _080635E4
_080634E0:
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _080635E4
	ldr r1, =gBattlePartyID
	mov r2, r9
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r6, r0
	beq _080635E4
	mov r2, r10
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r6, r0
	beq _080635E4
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	mov r2, r9
	adds r0, r2, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r6, r0
	beq _080635E4
	mov r2, r10
	adds r0, r2, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r6, r0
	beq _080635E4
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r5, 0
	movs r1, 0x2E
	bl GetMonData
	cmp r0, 0
	beq _08063558
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r1, =gBaseStats
	adds r0, r1
	ldrb r2, [r0, 0x17]
	b _08063564
	.pool
_08063558:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r2, =gBaseStats
	adds r0, r2
	ldrb r2, [r0, 0x16]
_08063564:
	ldr r1, =gUnknown_02024250
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	adds r1, r4, 0
	bl ai_rate_move
	ldr r1, [sp]
	ands r1, r0
	cmp r1, 0
	beq _080635E4
	ldr r1, =gUnknown_02024270
	ldrb r0, [r5]
	adds r0, r1
	ldrb r0, [r0]
	mov r9, r0
	movs r4, 0
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	mov r8, r1
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r9
	muls r2, r0
	adds r0, r2, 0
	adds r5, r0, r1
	adds r7, r5, 0
	adds r7, 0x20
_080635A2:
	adds r1, r4, 0
	adds r1, 0xD
	ldr r0, [sp, 0xC]
	add r0, r8
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _080635DE
	ldrh r1, [r5]
	ldrb r2, [r7]
	bl ai_rate_move
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0x2
	ands r1, r0
	cmp r1, 0
	beq _080635DE
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x4]
	bl __modsi3
	cmp r0, 0
	bne _080635DE
	b _08063468
_080635DE:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080635A2
_080635E4:
	adds r6, 0x1
_080635E6:
	ldr r0, [sp, 0x8]
	cmp r6, r0
	bge _080635EE
	b _080634BC
_080635EE:
	movs r0, 0
_080635F0:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ai_switchout_something

	thumb_func_start sub_8063614
sub_8063614: @ 8063614
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r6, =gBattleMons
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	movs r5, 0x58
	adds r0, r2, 0
	muls r0, r5
	adds r1, r6, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x0400e000
	ands r0, r1
	cmp r0, 0
	beq _0806363E
	b _0806386C
_0806363E:
	ldr r0, =gStatuses3
	lsls r1, r2, 2
	adds r1, r0
	ldr r1, [r1]
	movs r0, 0x80
	lsls r0, 3
	ands r1, r0
	cmp r1, 0
	beq _08063652
	b _0806386C
_08063652:
	str r1, [sp]
	movs r0, 0xC
	adds r1, r2, 0
	movs r2, 0x17
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0806366A
	b _0806386C
_0806366A:
	ldrb r1, [r4]
	str r0, [sp]
	movs r0, 0xC
	movs r2, 0x47
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08063682
	b _0806386C
_08063682:
	str r0, [sp]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x2A
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _080636B4
	ldrb r0, [r4]
	muls r0, r5
	adds r1, r0, r6
	adds r0, r1, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _080636A8
	b _0806386C
_080636A8:
	adds r0, r1, 0
	adds r0, 0x22
	ldrb r0, [r0]
	cmp r0, 0x8
	bne _080636B4
	b _0806386C
_080636B4:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 11
	ands r0, r1
	cmp r0, 0
	beq _080636C4
	b _0806386C
_080636C4:
	movs r0, 0
	mov r10, r0
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _0806372E
	ldrb r7, [r4]
	adds r0, r7, 0
	bl battle_get_per_side_status
	movs r5, 0x2
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08063718
	ldrb r6, [r4]
	b _08063732
	.pool
_08063718:
	ldrb r0, [r4]
	bl battle_get_per_side_status
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	b _08063732
_0806372E:
	ldrb r6, [r4]
	adds r7, r6, 0
_08063732:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08063768
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08063760
	movs r4, 0
	movs r1, 0x3
	mov r8, r1
	b _08063770
	.pool
_08063760:
	movs r4, 0x3
	movs r0, 0x6
	mov r8, r0
	b _08063770
_08063768:
	movs r4, 0
	movs r1, 0x6
	mov r8, r1
	ldr r2, =gActiveBank
_08063770:
	ldrb r0, [r2]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r9, r1
	cmp r0, 0
	bne _08063784
	ldr r0, =gPlayerParty
	mov r9, r0
_08063784:
	adds r5, r4, 0
	cmp r5, r8
	bge _080637F2
_0806378A:
	movs r0, 0x64
	muls r0, r5
	mov r1, r9
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _080637EC
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _080637EC
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _080637EC
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _080637EC
	lsls r0, r6, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _080637EC
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	adds r0, r7, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r5, r0
	beq _080637EC
	adds r0, r6, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r5, r0
	beq _080637EC
	movs r0, 0x1
	add r10, r0
_080637EC:
	adds r5, 0x1
	cmp r5, r8
	blt _0806378A
_080637F2:
	mov r1, r10
	cmp r1, 0
	beq _0806386C
	bl ai_switch_perish_song
	lsls r0, 24
	cmp r0, 0
	bne _08063852
	bl sub_8062C58
	lsls r0, 24
	cmp r0, 0
	bne _08063852
	bl sub_8062E54
	lsls r0, 24
	cmp r0, 0
	bne _08063852
	bl ai_switchout_natural_cure
	lsls r0, 24
	cmp r0, 0
	bne _08063852
	movs r0, 0
	bl ai_has_super_effective_move_on_field
	lsls r0, 24
	cmp r0, 0
	bne _0806386C
	bl ai_is_too_invested_in_stat_buffs
	lsls r0, 24
	cmp r0, 0
	bne _0806386C
	movs r0, 0x8
	movs r1, 0x2
	bl ai_switchout_something
	lsls r0, 24
	cmp r0, 0
	bne _08063852
	movs r0, 0x4
	movs r1, 0x3
	bl ai_switchout_something
	lsls r0, 24
	cmp r0, 0
	beq _0806386C
_08063852:
	movs r0, 0x1
	b _0806386E
	.pool
_0806386C:
	movs r0, 0
_0806386E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8063614

	thumb_func_start sub_8063880
sub_8063880: @ 8063880
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r6, r0, 24
	adds r5, r6, 0
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r8, r1
	cmp r0, 0
	bne _080638A8
	ldr r2, =gPlayerParty
	mov r8, r2
_080638A8:
	ldr r7, =gBattleTypeFlags
	ldr r0, [r7]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _080638B6
	b _080639E6
_080638B6:
	bl sub_8063614
	lsls r0, 24
	cmp r0, 0
	bne _080638C2
	b _080639DC
_080638C2:
	ldrb r0, [r4]
	ldr r2, =gUnknown_0202449C
	ldr r1, [r2]
	adds r0, r1
	movs r1, 0xA5
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x6
	bne _080639B8
	bl sub_8063A90
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bne _080639A6
	ldr r0, [r7]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08063910
	adds r0, r6, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	b _08063928
	.pool
_08063910:
	adds r0, r5, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x2
	eors r5, r0
	adds r0, r5, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
_08063928:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08063958
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08063954
	movs r0, 0
	movs r7, 0x3
	b _0806395C
	.pool
_08063954:
	movs r0, 0x3
	b _0806395A
_08063958:
	movs r0, 0
_0806395A:
	movs r7, 0x6
_0806395C:
	adds r4, r0, 0
	cmp r4, r7
	bge _080639A6
_08063962:
	movs r0, 0x64
	muls r0, r4
	add r0, r8
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _080639A0
	ldr r1, =gBattlePartyID
	lsls r0, r6, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _080639A0
	lsls r0, r5, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	beq _080639A0
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	adds r0, r6, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r4, r0
	beq _080639A0
	adds r0, r5, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r4, r0
	bne _080639A6
_080639A0:
	adds r4, 0x1
	cmp r4, r7
	blt _08063962
_080639A6:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	ldr r2, =gUnknown_0202449C
	ldr r1, [r2]
	adds r0, r1
	movs r1, 0xA5
	lsls r1, 2
	adds r0, r1
	strb r4, [r0]
_080639B8:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r0, [r2]
	adds r0, r1, r0
	adds r1, r0, 0
	adds r1, 0x5C
	movs r2, 0xA5
	lsls r2, 2
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	b _080639F8
	.pool
_080639DC:
	bl sub_8063EE0
	lsls r0, 24
	cmp r0, 0
	bne _080639F8
_080639E6:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	movs r2, 0x1
	eors r2, r0
	lsls r2, 8
	movs r0, 0x1
	movs r1, 0
	bl dp01_build_cmdbuf_x21_a_bb
_080639F8:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8063880

	thumb_func_start sub_8063A08
sub_8063A08: @ 8063A08
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r3, 0
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	movs r7, 0
	ldr r0, =gUnknown_0831ACE8
	mov r10, r0
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _08063A7A
	mov r5, r10
_08063A36:
	ldrb r0, [r5]
	cmp r0, 0xFE
	beq _08063A6C
	ldr r1, [sp]
	cmp r0, r1
	bne _08063A6C
	ldrb r4, [r5, 0x1]
	cmp r4, r9
	bne _08063A56
	ldrb r1, [r6]
	ldrb r0, [r5, 0x2]
	muls r0, r1
	movs r1, 0xA
	bl __divsi3
	strb r0, [r6]
_08063A56:
	cmp r4, r8
	bne _08063A6C
	cmp r9, r8
	beq _08063A6C
	ldrb r1, [r6]
	ldrb r0, [r5, 0x2]
	muls r0, r1
	movs r1, 0xA
	bl __divsi3
	strb r0, [r6]
_08063A6C:
	adds r5, 0x3
	adds r7, 0x3
	mov r1, r10
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08063A36
_08063A7A:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8063A08

	thumb_func_start sub_8063A90
sub_8063A90: @ 8063A90
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	adds r0, r2, r0
	adds r1, r0, 0
	adds r1, 0x5C
	ldrb r0, [r1]
	cmp r0, 0x6
	beq _08063AB2
	b _08063E50
_08063AB2:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 11
	ands r0, r1
	cmp r0, 0
	beq _08063AE0
	ldr r1, =gBattlePartyID
	lsls r0, r2, 1
	adds r0, r1
	ldrb r0, [r0]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	b _08063E50
	.pool
_08063AE0:
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _08063B6C
	str r2, [sp, 0x10]
	adds r0, r2, 0
	bl battle_get_per_side_status
	movs r5, 0x2
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	ldr r1, =gAbsentBankFlags
	ldrb r1, [r1]
	ldr r2, =gBitTable
	lsls r0, 24
	lsrs r0, 22
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08063B20
	ldrb r4, [r4]
	str r4, [sp, 0x14]
	b _08063B36
	.pool
_08063B20:
	ldrb r0, [r4]
	bl battle_get_per_side_status
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
_08063B36:
	bl Random
	movs r3, 0x2
	ands r0, r3
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldr r4, [sp, 0x4]
	lsls r0, r4, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08063B8A
	eors r4, r3
	lsls r0, r4, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	b _08063B8A
	.pool
_08063B6C:
	adds r0, r2, 0
	bl battle_get_per_side_status
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldrb r4, [r4]
	str r4, [sp, 0x14]
	str r4, [sp, 0x10]
_08063B8A:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00808000
	ands r0, r1
	cmp r0, 0
	beq _08063BC2
	ldr r2, =gActiveBank
	ldrb r1, [r2]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _08063BB8
	movs r0, 0
	str r0, [sp, 0x18]
	movs r1, 0x3
	str r1, [sp, 0x1C]
	b _08063BCC
	.pool
_08063BB8:
	movs r4, 0x3
	str r4, [sp, 0x18]
	movs r0, 0x6
	str r0, [sp, 0x1C]
	b _08063BCC
_08063BC2:
	movs r1, 0
	str r1, [sp, 0x18]
	movs r2, 0x6
	str r2, [sp, 0x1C]
	ldr r2, =gActiveBank
_08063BCC:
	ldrb r0, [r2]
	bl GetBankSide
	lsls r0, 24
	ldr r4, =gEnemyParty
	str r4, [sp, 0x20]
	cmp r0, 0
	bne _08063BE0
	ldr r0, =gPlayerParty
	str r0, [sp, 0x20]
_08063BE0:
	movs r1, 0
	mov r9, r1
_08063BE4:
	movs r2, 0
	str r2, [sp, 0x8]
	movs r4, 0x6
	str r4, [sp, 0xC]
	ldr r7, [sp, 0x18]
	ldr r0, [sp, 0x1C]
	cmp r7, r0
	blt _08063BF6
	b _08063CF2
_08063BF6:
	lsls r0, r7, 2
	ldr r1, =gBitTable
	adds r0, r1
	mov r8, r0
	mov r10, sp
_08063C00:
	movs r0, 0x64
	muls r0, r7
	ldr r2, [sp, 0x20]
	adds r4, r2, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _08063CD8
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08063CD8
	mov r4, r8
	ldr r0, [r4]
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	bne _08063CD8
	ldr r1, =gBattlePartyID
	ldr r2, [sp, 0x10]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	beq _08063CD8
	ldr r4, [sp, 0x14]
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	beq _08063CD8
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	adds r0, r2, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r7, r0
	beq _08063CD8
	adds r0, r4, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r7, r0
	beq _08063CD8
	ldr r1, =gBaseStats
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r5, [r0, 0x6]
	ldrb r6, [r0, 0x7]
	movs r0, 0xA
	mov r1, r10
	strb r0, [r1]
	movs r0, 0x58
	ldr r2, [sp, 0x4]
	adds r4, r2, 0
	muls r4, r0
	ldr r0, =gBattleMons
	adds r4, r0
	adds r0, r4, 0
	adds r0, 0x21
	ldrb r0, [r0]
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, sp
	bl sub_8063A08
	adds r4, 0x22
	ldrb r0, [r4]
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, sp
	bl sub_8063A08
	ldr r2, [sp, 0x8]
	mov r1, r10
	ldrb r1, [r1]
	cmp r2, r1
	bcs _08063CE6
	mov r2, r10
	ldrb r2, [r2]
	str r2, [sp, 0x8]
	lsls r0, r7, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	b _08063CE6
	.pool
_08063CD8:
	mov r4, r8
	ldr r0, [r4]
	mov r1, r9
	orrs r1, r0
	lsls r0, r1, 24
	lsrs r0, 24
	mov r9, r0
_08063CE6:
	movs r2, 0x4
	add r8, r2
	adds r7, 0x1
	ldr r4, [sp, 0x1C]
	cmp r7, r4
	blt _08063C00
_08063CF2:
	ldr r0, [sp, 0xC]
	cmp r0, 0x6
	beq _08063D54
	movs r7, 0
	movs r0, 0x64
	ldr r1, [sp, 0xC]
	adds r5, r1, 0
	muls r5, r0
_08063D02:
	adds r1, r7, 0
	adds r1, 0xD
	ldr r2, [sp, 0x20]
	adds r0, r2, r5
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _08063D2A
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	adds r0, r4, 0
	ldr r2, [sp, 0x4]
	bl move_effectiveness_something
	movs r1, 0x2
	ands r1, r0
	cmp r1, 0
	bne _08063D30
_08063D2A:
	adds r7, 0x1
	cmp r7, 0x3
	ble _08063D02
_08063D30:
	cmp r7, 0x4
	beq _08063D36
	b _08063E4E
_08063D36:
	ldr r4, [sp, 0xC]
	lsls r0, r4, 2
	ldr r1, =gBitTable
	adds r0, r1
	ldr r0, [r0]
	mov r2, r9
	orrs r2, r0
	lsls r0, r2, 24
	lsrs r0, 24
	mov r9, r0
	b _08063D58
	.pool
_08063D54:
	movs r4, 0x3F
	mov r9, r4
_08063D58:
	mov r0, r9
	cmp r0, 0x3F
	beq _08063D60
	b _08063BE4
_08063D60:
	ldr r0, =gUnknown_02024400
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_0202449C
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gUnknown_02024474
	movs r2, 0x1
	strb r2, [r0, 0xE]
	ldr r0, =gBattleMoveFlags
	strb r1, [r0]
	ldr r0, =gCritMultiplier
	strb r2, [r0]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r2, 0x6
	str r2, [sp, 0xC]
	ldr r7, [sp, 0x18]
	ldr r4, [sp, 0x1C]
	cmp r7, r4
	bge _08063E4E
_08063D8A:
	movs r0, 0x64
	adds r6, r7, 0
	muls r6, r0
	ldr r0, [sp, 0x20]
	adds r4, r0, r6
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	adds r1, r7, 0x1
	mov r10, r1
	cmp r0, 0
	beq _08063E46
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08063E46
	ldr r1, =gBattlePartyID
	ldr r2, [sp, 0x10]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	beq _08063E46
	ldr r4, [sp, 0x14]
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	beq _08063E46
	ldr r0, =gUnknown_0202449C
	ldr r1, [r0]
	adds r0, r2, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r7, r0
	beq _08063E46
	adds r0, r4, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r7, r0
	beq _08063E46
	movs r5, 0
	mov r9, r6
	ldr r0, =gBattleMoveDamage
	mov r8, r0
	ldr r6, =gActiveBank
_08063DEE:
	adds r1, r5, 0
	adds r1, 0xD
	ldr r0, [sp, 0x20]
	add r0, r9
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0
	mov r1, r8
	str r0, [r1]
	cmp r4, 0
	beq _08063E2A
	ldr r0, =gBattleMoves
	lsls r1, r4, 1
	adds r1, r4
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0x1
	beq _08063E2A
	ldrb r0, [r6]
	ldr r1, [sp, 0x4]
	bl sub_8046E7C
	ldrb r1, [r6]
	adds r0, r4, 0
	ldr r2, [sp, 0x4]
	bl move_effectiveness_something
_08063E2A:
	mov r2, r8
	ldr r0, [r2]
	ldr r4, [sp, 0x8]
	cmp r4, r0
	bge _08063E40
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	lsls r0, r7, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
_08063E40:
	adds r5, 0x1
	cmp r5, 0x3
	ble _08063DEE
_08063E46:
	mov r7, r10
	ldr r0, [sp, 0x1C]
	cmp r7, r0
	blt _08063D8A
_08063E4E:
	ldr r0, [sp, 0xC]
_08063E50:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8063A90

	thumb_func_start ai_identify_item_effect
ai_identify_item_effect: @ 8063E84
	push {r4,lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x13
	bne _08063E94
	movs r0, 0x1
	b _08063EDA
_08063E94:
	ldrb r1, [r2, 0x4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08063EA2
	movs r0, 0x2
	b _08063EDA
_08063EA2:
	ldrb r4, [r2, 0x3]
	movs r3, 0x3F
	adds r0, r3, 0
	ands r0, r4
	cmp r0, 0
	beq _08063EB2
	movs r0, 0x3
	b _08063EDA
_08063EB2:
	ldrb r1, [r2]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _08063EC8
	ldrb r0, [r2, 0x1]
	cmp r0, 0
	bne _08063EC8
	ldrb r0, [r2, 0x2]
	cmp r0, 0
	beq _08063ECC
_08063EC8:
	movs r0, 0x4
	b _08063EDA
_08063ECC:
	movs r0, 0x80
	ands r0, r4
	cmp r0, 0
	bne _08063ED8
	movs r0, 0x6
	b _08063EDA
_08063ED8:
	movs r0, 0x5
_08063EDA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ai_identify_item_effect

	thumb_func_start sub_8063EE0
sub_8063EE0: @ 8063EE0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	movs r0, 0
	mov r10, r0
	movs r7, 0
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _08063F12
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _08063F12
	b _0806437C
_08063F12:
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	ldr r5, =gEnemyParty
	cmp r0, 0
	bne _08063F24
	ldr r5, =gPlayerParty
_08063F24:
	movs r1, 0
	mov r8, r1
_08063F28:
	movs r0, 0x64
	mov r2, r8
	muls r2, r0
	adds r0, r2, 0
	adds r4, r5, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08063F64
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _08063F64
	adds r0, r4, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08063F64
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
_08063F64:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x5
	ble _08063F28
	movs r2, 0
	mov r8, r2
_08063F72:
	ldr r1, =gBattleStruct
	mov r0, r8
	cmp r0, 0
	beq _08063F8E
	ldr r0, [r1]
	ldr r0, [r0, 0x18]
	adds r0, 0x50
	ldrb r0, [r0]
	mov r2, r8
	subs r0, r2
	adds r0, 0x1
	cmp r10, r0
	ble _08063F8E
	b _08064370
_08063F8E:
	ldr r0, [r1]
	ldr r0, [r0, 0x18]
	mov r2, r8
	lsls r1, r2, 1
	adds r0, 0x48
	adds r0, r1
	ldrh r0, [r0]
	mov r9, r0
	str r1, [sp]
	cmp r0, 0
	bne _08063FA6
	b _08064370
_08063FA6:
	ldr r1, =gItemEffectInfoPointers
	subs r0, 0xD
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	bne _08063FB6
	b _08064370
_08063FB6:
	mov r0, r9
	cmp r0, 0xAF
	bne _08063FE8
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003214
	adds r5, r0, r1
	b _08063FEA
	.pool
_08063FE8:
	adds r5, r1, 0
_08063FEA:
	mov r2, r9
	lsls r0, r2, 24
	lsrs r0, 24
	adds r1, r5, 0
	bl ai_identify_item_effect
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	lsrs r1, 1
	ldr r3, =gUnknown_0202449C
	ldr r2, [r3]
	adds r1, r2
	adds r1, 0xC4
	strb r0, [r1]
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r0, 0x5
	bls _0806401A
	b _08064324
_0806401A:
	lsls r0, 2
	ldr r1, =_08064030
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08064030:
	.4byte _08064048
	.4byte _08064074
	.4byte _080640BC
	.4byte _08064214
	.4byte _080642F4
	.4byte _0806437C
_08064048:
	ldr r2, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r1, [r0, 0x2C]
	ldrh r0, [r0, 0x28]
	lsrs r1, 2
	cmp r0, r1
	bcc _08064060
	b _08064324
_08064060:
	cmp r0, 0
	bne _08064066
	b _08064324
_08064066:
	movs r7, 0x1
	b _08064328
	.pool
_08064074:
	mov r0, r9
	movs r1, 0x4
	movs r2, 0x4
	bl sub_806CDDC
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08064088
	b _08064324
_08064088:
	ldr r2, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r1, r0, r2
	ldrh r2, [r1, 0x28]
	cmp r2, 0
	bne _0806409C
	b _08064324
_0806409C:
	ldrh r3, [r1, 0x2C]
	lsrs r0, r3, 2
	cmp r2, r0
	bcc _08064066
	adds r0, r2, 0
	subs r0, r3, r0
	adds r1, r5, r4
	ldrb r1, [r1]
	cmp r0, r1
	bgt _080640B2
	b _08064324
_080640B2:
	b _08064066
	.pool
_080640BC:
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsrs r0, 1
	ldr r2, =gUnknown_0202449C
	ldr r1, [r2]
	adds r0, r1
	adds r0, 0xC6
	movs r1, 0
	strb r1, [r0]
	ldrb r1, [r5, 0x3]
	movs r6, 0x20
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08064100
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08064100
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_08064100:
	ldrb r1, [r5, 0x3]
	movs r6, 0x10
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0806413A
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806412A
	movs r0, 0x80
	ands r1, r0
	cmp r1, 0
	beq _0806413A
_0806412A:
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_0806413A:
	ldrb r1, [r5, 0x3]
	movs r6, 0x8
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806416C
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0806416C
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_0806416C:
	ldrb r1, [r5, 0x3]
	movs r6, 0x4
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0806419E
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0806419E
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_0806419E:
	ldrb r1, [r5, 0x3]
	movs r6, 0x2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080641D0
	ldr r1, =gBattleMons
	ldrb r4, [r3]
	movs r0, 0x58
	muls r0, r4
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080641D0
	lsrs r1, r4, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	movs r7, 0x1
_080641D0:
	ldrb r1, [r5, 0x3]
	movs r4, 0x1
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080641DE
	b _08064324
_080641DE:
	ldr r1, =gBattleMons
	ldrb r3, [r3]
	movs r0, 0x58
	muls r0, r3
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _080641F6
	b _08064324
_080641F6:
	lsrs r1, r3, 1
	ldr r0, [r2]
	adds r1, r0
	adds r1, 0xC6
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	b _08064066
	.pool
_08064214:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r3, =gUnknown_0202449C
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	movs r1, 0
	strb r1, [r0]
	ldr r1, =gDisableStructs
	ldrb r2, [r4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	beq _08064324
	ldrb r1, [r5]
	movs r6, 0xF
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _08064254
	lsrs r2, 1
	ldr r0, [r3]
	adds r2, r0
	adds r2, 0xC6
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
_08064254:
	ldrb r1, [r5, 0x1]
	movs r7, 0xF0
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _08064272
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
_08064272:
	ldrb r1, [r5, 0x1]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _0806428E
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
_0806428E:
	ldrb r1, [r5, 0x2]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	beq _080642AA
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0]
_080642AA:
	ldrb r1, [r5, 0x2]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _080642C6
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0]
_080642C6:
	ldrb r1, [r5]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	bne _080642D2
	b _08064066
_080642D2:
	ldrb r0, [r4]
	lsrs r0, 1
	ldr r1, [r3]
	adds r0, r1
	adds r0, 0xC6
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	b _08064066
	.pool
_080642F4:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r2, =gDisableStructs
	ldrb r1, [r4]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x16]
	cmp r0, 0
	beq _08064324
	ldr r0, =gSideTimer
	lsls r1, r3, 1
	adds r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _08064324
	b _08064066
_08064324:
	cmp r7, 0
	beq _08064370
_08064328:
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0
	bl dp01_build_cmdbuf_x21_a_bb
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsrs r0, 1
	ldr r1, =gUnknown_0202449C
	ldr r1, [r1]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC0
	mov r1, r9
	strb r1, [r0]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	ldr r0, [r0, 0x18]
	adds r0, 0x48
	ldr r2, [sp]
	adds r0, r2
	movs r1, 0
	strh r1, [r0]
	adds r0, r7, 0
	b _0806437E
	.pool
_08064370:
	movs r0, 0x1
	add r8, r0
	mov r1, r8
	cmp r1, 0x3
	bgt _0806437C
	b _08063F72
_0806437C:
	movs r0, 0
_0806437E:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8063EE0

	thumb_func_start nullsub_28
nullsub_28: @ 8064390
	bx lr
	thumb_func_end nullsub_28

	thumb_func_start sub_8064394
sub_8064394: @ 8064394
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80643B0
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8064394

	thumb_func_start sub_80643B0
sub_80643B0: @ 80643B0
	push {lr}
	ldr r2, =gUnknown_02024068
	ldr r1, =gBitTable
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r2]
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _080643FC
	ldr r0, =gUnknown_02023064
	lsls r1, r3, 9
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0x38
	bhi _080643F8
	ldr r0, =gUnknown_0831C7B4
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	b _080643FC
	.pool
_080643F8:
	bl sub_8065068
_080643FC:
	pop {r0}
	bx r0
	thumb_func_end sub_80643B0

	thumb_func_start sub_8064400
sub_8064400: @ 8064400
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08064424
	bl sub_8065068
_08064424:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064400

	thumb_func_start sub_8064438
sub_8064438: @ 8064438
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _0806445C
	bl sub_8065068
_0806445C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064438

	thumb_func_start sub_8064470
sub_8064470: @ 8064470
	push {r4-r6,lr}
	ldr r5, =gUnknown_02020630
	ldr r6, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _080644C2
	adds r0, r2, r5
	ldrh r0, [r0, 0x6]
	bl sub_805DFE4
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl obj_free_rotscale_entry
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	bl RemoveObjectAndFreeTiles
	bl sub_8065068
_080644C2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064470

	thumb_func_start sub_80644D8
sub_80644D8: @ 80644D8
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r1, [r4]
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x9]
	subs r0, 0x1
	strb r0, [r1, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08064510
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
	bl sub_8065068
_08064510:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80644D8

	thumb_func_start sub_8064520
sub_8064520: @ 8064520
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0
	mov r8, r0
	movs r4, 0
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0806454C
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08064584
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08064584
_0806454C:
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_03005D70
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	adds r7, r3, 0
	cmp r1, r0
	bne _080645C2
	b _080645CA
	.pool
_08064584:
	ldr r3, =gUnknown_02020630
	ldr r6, =gUnknown_03005D70
	ldr r2, =gActiveBank
	ldrb r4, [r2]
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r5, r3, 0
	adds r5, 0x1C
	adds r0, r5
	ldr r3, [r0]
	ldr r0, =DummyObjectCallback
	adds r7, r2, 0
	cmp r3, r0
	bne _080645C0
	movs r0, 0x2
	eors r4, r0
	adds r0, r4, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r0, [r0]
	cmp r0, r3
	bne _080645C0
	movs r1, 0x1
	mov r8, r1
_080645C0:
	movs r4, 0x1
_080645C2:
	mov r0, r8
	cmp r0, 0
	bne _080645CA
	b _08064714
_080645CA:
	cmp r4, 0
	bne _080645DE
	ldrb r1, [r7]
	movs r0, 0x2
	eors r0, r1
	bl b_side_obj__get_some_boolean
	lsls r0, 24
	cmp r0, 0
	bne _0806469C
_080645DE:
	ldr r1, =gUnknown_020244D0
	mov r12, r1
	ldr r0, [r1]
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r4, r0, r3
	ldrb r1, [r4, 0x1]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _08064600
	b _08064714
_08064600:
	movs r6, 0x2
	adds r1, r6, 0
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _08064714
	ldrb r1, [r4]
	movs r3, 0x7F
	adds r0, r3, 0
	ands r0, r1
	strb r0, [r4]
	mov r1, r12
	ldr r0, [r1]
	ldrb r2, [r7]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r4, 0x2
	negs r4, r4
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x1]
	mov r0, r12
	ldr r2, [r0]
	ldrb r0, [r7]
	adds r1, r6, 0
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	ands r3, r1
	strb r3, [r0]
	mov r1, r12
	ldr r2, [r1]
	ldrb r0, [r7]
	adds r1, r6, 0
	eors r1, r0
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	ands r4, r1
	strb r4, [r0, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	b _080646F2
	.pool
_0806469C:
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r1, [r7]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08064714
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	ldrb r2, [r7]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldrb r0, [r7]
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _080646F2
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
_080646F2:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x9]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80644D8
	str r1, [r0]
_08064714:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064520

	thumb_func_start sub_8064734
sub_8064734: @ 8064734
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r10, r0
	ldr r5, =gUnknown_020244D0
	ldr r0, [r5]
	ldr r4, =gActiveBank
	ldrb r2, [r4]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	movs r6, 0xC4
	lsls r6, 1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _08064776
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08064776:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080647B4
	ldr r2, [r5]
	ldrb r1, [r4]
	movs r0, 0x2
	adds r3, r0, 0
	eors r3, r1
	ldr r1, [r2, 0x4]
	lsls r2, r3, 1
	adds r0, r2, r3
	lsls r0, 2
	adds r0, r1
	ldrh r1, [r0]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _080647B4
	ldr r0, =gBattlePartyID
	adds r0, r2, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
_080647B4:
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldr r2, =gActiveBank
	ldrb r5, [r2]
	ldr r4, [r0, 0x4]
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r6, r0, r4
	ldrb r1, [r6]
	movs r0, 0x8
	mov r12, r0
	ands r0, r1
	mov r8, r3
	mov r9, r2
	cmp r0, 0
	bne _08064898
	movs r7, 0x2
	adds r1, r7, 0
	eors r1, r5
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0]
	mov r0, r12
	ands r0, r1
	cmp r0, 0
	bne _08064898
	ldrb r1, [r6, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0806487A
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _0806484A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0806484A
	ldr r4, =gUnknown_03005D70
	mov r1, r9
	ldrb r0, [r1]
	adds r1, r7, 0
	eors r1, r0
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	mov r1, r9
	ldrb r0, [r1]
	eors r0, r7
	bl sub_8076918
	mov r1, r9
	ldrb r0, [r1]
	eors r0, r7
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
_0806484A:
	ldr r5, =gUnknown_03005D70
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	adds r0, r1, r5
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r4]
	bl sub_8076918
	ldrb r0, [r4]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
_0806487A:
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0, 0x1]
	mov r8, r4
	mov r9, r3
_08064898:
	mov r1, r8
	ldr r0, [r1]
	mov r1, r9
	ldrb r2, [r1]
	ldr r3, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	bne _0806495A
	movs r1, 0x2
	eors r1, r2
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r1, [r0, 0x1]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0806495A
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _0806495A
	mov r1, r8
	ldr r0, [r1]
	mov r1, r9
	ldrb r2, [r1]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0806493C
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x42
	ands r0, r1
	cmp r0, 0x42
	bne _08064930
	adds r0, r2, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0806493C
	ldr r0, =gMPlay_BGM
	bl m4aMPlayContinue
	b _0806493C
	.pool
_08064930:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
_0806493C:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r0, 0x1
	mov r10, r0
_0806495A:
	mov r1, r10
	cmp r1, 0
	bne _08064962
	b _08064AC0
_08064962:
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_03005D7C
	ldr r5, =gActiveBank
	ldrb r3, [r5]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r4, [r0]
	ldr r0, =DummyObjectCallback
	cmp r4, r0
	beq _08064982
	b _08064AC0
_08064982:
	ldr r0, =gUnknown_020241E4
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	cmp r0, r4
	beq _08064998
	b _08064AC0
_08064998:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080649E2
	adds r0, r3, 0
	bl battle_get_per_side_status
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bne _080649E2
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r5]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x9]
	adds r0, 0x1
	strb r0, [r1, 0x9]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08064AC0
	ldr r0, [r3]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x9]
_080649E2:
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08064A3A
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08064A3A
	ldr r1, =gUnknown_03005D7C
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x2
	eors r0, r4
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	bl RemoveObjectAndFreeTiles
	ldrb r0, [r5]
	eors r4, r0
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
_08064A3A:
	ldr r1, =gUnknown_03005D7C
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02020630
	adds r0, r1
	bl RemoveObjectAndFreeTiles
	ldrb r5, [r4]
	ldr r1, =gBattlePartyID
	lsls r0, r5, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r5, 0
	bl sub_805EE54
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r1, [r2, 0x9]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x9]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r0, [r3]
	ldrb r2, [r4]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x7F
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064520
	str r1, [r0]
_08064AC0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064734

	thumb_func_start sub_8064B04
sub_8064B04: @ 8064B04
	push {r4-r7,lr}
	ldr r4, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldr r7, =gActiveBank
	ldrb r3, [r7]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08064BB6
	adds r0, r2, r4
	movs r1, 0x24
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08064BB6
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r4, r3, 1
	adds r0, r4, r3
	lsls r0, 2
	adds r2, r0, r1
	ldrb r5, [r2]
	movs r0, 0x80
	ands r0, r5
	cmp r0, 0
	bne _08064B7C
	ldr r0, =gBattlePartyID
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r3, 0
	bl sub_8172EF0
	b _08064BB6
	.pool
_08064B7C:
	ldrb r1, [r2, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08064BB6
	movs r0, 0x7F
	ands r0, r5
	strb r0, [r2]
	ldr r0, [r6]
	ldrb r2, [r7]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	bl sub_8065068
_08064BB6:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064B04

	thumb_func_start sub_8064BC0
sub_8064BC0: @ 8064BC0
	push {r4-r6,lr}
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	ldr r5, =gUnknown_03005D70
	adds r1, r0, r5
	ldrb r1, [r1]
	movs r2, 0
	movs r3, 0
	bl sub_8074AA0
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	bl sub_80729D0
	lsls r4, 16
	asrs r1, r4, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _08064C08
	ldrb r0, [r6]
	adds r0, r5
	ldrb r0, [r0]
	movs r2, 0
	bl heathbar_draw_hp
	b _08064C0C
	.pool
_08064C08:
	bl sub_8065068
_08064C0C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8064BC0

	thumb_func_start sub_8064C14
sub_8064C14: @ 8064C14
	push {lr}
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldr r1, =gActiveBank
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	bne _08064C42
	ldr r0, =gUnknown_03005D70
	adds r0, r3, r0
	ldrb r0, [r0]
	bl sub_8072984
	bl sub_8065068
_08064C42:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064C14

	thumb_func_start sub_8064C58
sub_8064C58: @ 8064C58
	push {r4-r6,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08064CB2
	ldr r5, =gUnknown_020241E4
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl RemoveObjectAndFreeTiles
	ldrb r0, [r6]
	bl sub_805EEE0
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl sub_8065068
_08064CB2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064C58

	thumb_func_start sub_8064CCC
sub_8064CCC: @ 8064CCC
	push {lr}
	movs r0, 0
	bl IsTextPrinterActive
	lsls r0, 16
	cmp r0, 0
	bne _08064CDE
	bl sub_8065068
_08064CDE:
	pop {r0}
	bx r0
	thumb_func_end sub_8064CCC

	thumb_func_start sub_8064CE4
sub_8064CE4: @ 8064CE4
	push {r4,lr}
	ldr r1, =gUnknown_020241E4
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	ldr r2, =gUnknown_02020630
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r2
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x20
	bne _08064D30
	movs r3, 0
	movs r0, 0
	strh r0, [r4, 0x30]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
	ands r0, r1
	strb r0, [r2]
	ldr r0, =gUnknown_020244B9
	strb r3, [r0]
	bl sub_8065068
	b _08064D5A
	.pool
_08064D30:
	ldrh r0, [r4, 0x30]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08064D54
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_08064D54:
	ldrh r0, [r4, 0x30]
	adds r0, 0x1
	strh r0, [r4, 0x30]
_08064D5A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8064CE4

	thumb_func_start sub_8064D60
sub_8064D60: @ 8064D60
	push {r4,lr}
	ldr r2, =gUnknown_02020630
	ldr r0, =gUnknown_03005D70
	ldr r4, =gActiveBank
	ldrb r3, [r4]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08064DAC
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r3, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08064DA0
	adds r0, r3, 0
	adds r1, r3, 0
	adds r2, r3, 0
	movs r3, 0x6
	bl move_anim_start_t4
_08064DA0:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r4]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8064DD0
	str r0, [r1]
_08064DAC:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064D60

	thumb_func_start sub_8064DD0
sub_8064DD0: @ 8064DD0
	push {r4,lr}
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r4, =gActiveBank
	ldrb r1, [r4]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08064E2A
	bl sub_80A36C8
	lsls r0, 24
	cmp r0, 0
	bne _08064E2A
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldrb r0, [r4]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	beq _08064E1A
	ldr r0, =nullsub_18
	cmp r1, r0
	bne _08064E2A
_08064E1A:
	ldr r0, =gMPlay_BGM
	ldr r1, =0x0000ffff
	movs r2, 0x80
	lsls r2, 1
	bl m4aMPlayVolumeControl
	bl sub_8065068
_08064E2A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064DD0

	thumb_func_start sub_8064E50
sub_8064E50: @ 8064E50
	push {r4-r7,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r1, [r3, 0x1]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08064F0C
	ldr r7, =gUnknown_02020630
	ldr r6, =gUnknown_020241E4
	adds r0, r2, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r7, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08064F0C
	ldrb r1, [r3]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r3]
	ldr r0, [r4]
	ldrb r2, [r5]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0x1]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	ldr r4, =0x000027f9
	adds r0, r4, 0
	bl FreeObjectTilesByTag
	adds r0, r4, 0
	bl FreeObjectPaletteByTag
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0
	bl StartObjectImageAnim
	ldr r4, =gUnknown_03005D70
	ldrb r1, [r5]
	adds r0, r1, r4
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0
	bl healthbar_draw_field_maybe
	ldrb r0, [r5]
	bl sub_8076918
	ldrb r0, [r5]
	adds r0, r4
	ldrb r0, [r0]
	bl sub_80729D0
	ldrb r0, [r5]
	bl sub_805E408
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064D60
	str r1, [r0]
_08064F0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064E50

	thumb_func_start sub_8064F40
sub_8064F40: @ 8064F40
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r0, 0x4]
	lsls r3, r2, 1
	adds r0, r3, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	bne _08064F72
	ldr r0, =gBattlePartyID
	adds r0, r3, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r1, r0
	adds r0, r2, 0
	bl sub_8172EF0
_08064F72:
	ldr r4, =gUnknown_02020630
	ldr r0, =gUnknown_03005D7C
	ldrb r2, [r5]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r3, r0, 2
	adds r0, r4, 0
	adds r0, 0x1C
	adds r0, r3, r0
	ldr r1, [r0]
	ldr r0, =DummyObjectCallback
	cmp r1, r0
	bne _08064FDC
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08064FDC
	adds r0, r3, r4
	bl RemoveObjectAndFreeTiles
	ldrb r4, [r5]
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064E50
	str r1, [r0]
_08064FDC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8064F40

	thumb_func_start sub_8065008
sub_8065008: @ 8065008
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0806502A
	bl sub_8065068
_0806502A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065008

	thumb_func_start sub_8065038
sub_8065038: @ 8065038
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0806505A
	bl sub_8065068
_0806505A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065038

	thumb_func_start sub_8065068
sub_8065068: @ 8065068
	push {r4,lr}
	sub sp, 0x4
	ldr r1, =gUnknown_03005D60
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80643B0
	str r1, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080650BC
	bl link_get_multiplayer_id
	mov r1, sp
	strb r0, [r1]
	movs r0, 0x2
	movs r1, 0x4
	mov r2, sp
	bl dp01_prepare_buffer_wireless_probably
	ldr r1, =gUnknown_02023064
	ldrb r0, [r4]
	lsls r0, 9
	adds r0, r1
	movs r1, 0x38
	strb r1, [r0]
	b _080650CE
	.pool
_080650BC:
	ldr r2, =gUnknown_02024068
	ldr r1, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_080650CE:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065068

	thumb_func_start dp01t_00_2_getattr
dp01t_00_2_getattr: @ 80650E0
	push {r4-r6,lr}
	sub sp, 0x100
	movs r6, 0
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _08065118
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	mov r1, sp
	bl dp01_getattr_by_ch1_for_opponent_pokemon
	adds r6, r0, 0
	b _0806513A
	.pool
_08065118:
	ldrb r4, [r1]
	movs r5, 0
_0806511C:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08065132
	lsls r0, r5, 24
	lsrs r0, 24
	mov r2, sp
	adds r1, r2, r6
	bl dp01_getattr_by_ch1_for_opponent_pokemon
	adds r6, r0
_08065132:
	lsrs r4, 1
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806511C
_0806513A:
	lsls r1, r6, 16
	lsrs r1, 16
	movs r0, 0x1
	mov r2, sp
	bl dp01_build_cmdbuf_x1D_1D_numargs_varargs
	bl sub_8065068
	add sp, 0x100
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end dp01t_00_2_getattr

	thumb_func_start dp01_getattr_by_ch1_for_opponent_pokemon
dp01_getattr_by_ch1_for_opponent_pokemon: @ 8065154
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x90
	adds r7, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r6, 0
	ldr r2, =gUnknown_02023064
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	adds r1, r2, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3B
	bls _0806517E
	bl _080658EA
_0806517E:
	lsls r0, 2
	ldr r1, =_08065194
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08065194:
	.4byte _08065284
	.4byte _080654A8
	.4byte _080654B8
	.4byte _080654C8
	.4byte _08065530
	.4byte _08065530
	.4byte _08065530
	.4byte _08065530
	.4byte _0806554C
	.4byte _08065588
	.4byte _08065588
	.4byte _08065588
	.4byte _08065588
	.4byte _080658EA
	.4byte _080658EA
	.4byte _080658EA
	.4byte _080658EA
	.4byte _080655A4
	.4byte _080655B4
	.4byte _080655E4
	.4byte _080655F4
	.4byte _08065604
	.4byte _08065614
	.4byte _08065624
	.4byte _08065634
	.4byte _08065644
	.4byte _08065654
	.4byte _08065664
	.4byte _08065674
	.4byte _08065684
	.4byte _08065694
	.4byte _080656A4
	.4byte _080656F4
	.4byte _08065704
	.4byte _08065714
	.4byte _08065724
	.4byte _08065734
	.4byte _08065744
	.4byte _08065754
	.4byte _08065764
	.4byte _08065774
	.4byte _080657A8
	.4byte _080657B8
	.4byte _080657C8
	.4byte _080657D8
	.4byte _080657E8
	.4byte _080657F8
	.4byte _08065808
	.4byte _08065818
	.4byte _08065838
	.4byte _08065848
	.4byte _08065858
	.4byte _08065868
	.4byte _08065878
	.4byte _08065888
	.4byte _08065898
	.4byte _080658A8
	.4byte _080658B8
	.4byte _080658C8
	.4byte _080658D8
_08065284:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, 0
	movs r1, 0xC
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2E]
	movs r6, 0
	add r0, sp, 0x24
	mov r9, r0
	movs r1, 0x3B
	add r1, sp
	mov r10, r1
	mov r2, sp
	adds r2, 0x2B
	str r2, [sp, 0x80]
	mov r0, sp
	adds r0, 0x2A
	str r0, [sp, 0x7C]
	mov r1, sp
	adds r1, 0x68
	str r1, [sp, 0x8C]
	adds r2, 0x5
	str r2, [sp, 0x84]
	adds r0, 0x12
	str r0, [sp, 0x88]
	mov r8, r4
	add r4, sp, 0xC
_080652D0:
	adds r1, r6, 0
	adds r1, 0xD
	mov r0, r8
	bl GetMonData
	strh r0, [r4]
	adds r1, r6, 0
	adds r1, 0x11
	mov r0, r8
	bl GetMonData
	mov r2, r9
	adds r1, r2, r6
	strb r0, [r1]
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _080652D0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	mov r1, r10
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	bl GetMonData
	ldr r2, [sp, 0x80]
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x19
	bl GetMonData
	str r0, [sp, 0x44]
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	mov r3, sp
	movs r5, 0x1F
	ands r0, r5
	ldrb r2, [r3, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	mov r3, sp
	movs r6, 0x1F
	ands r0, r6
	lsls r0, 5
	ldrh r2, [r3, 0x14]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 2
	ldrb r2, [r3, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [sp, 0x14]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	mov r3, sp
	ands r0, r6
	lsls r0, 4
	ldrh r2, [r3, 0x16]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	mov r3, sp
	ands r0, r5
	lsls r0, 1
	ldrb r2, [r3, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x48]
	adds r0, r4, 0
	movs r1, 0x37
	bl GetMonData
	str r0, [sp, 0x4C]
	adds r0, r4, 0
	movs r1, 0x38
	bl GetMonData
	ldr r1, [sp, 0x7C]
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	mov r1, sp
	strh r0, [r1, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	mov r3, sp
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r3, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	bl GetMonData
	mov r3, sp
	lsls r0, 7
	ldrb r2, [r3, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [sp, 0x54]
	adds r0, r4, 0
	movs r1, 0x2
	ldr r2, [sp, 0x8C]
	bl GetMonData
	ldr r0, [sp, 0x84]
	ldr r1, [sp, 0x8C]
	bl StringCopy10
	adds r0, r4, 0
	movs r1, 0x7
	ldr r2, [sp, 0x88]
	bl GetMonData
	mov r2, sp
	movs r6, 0
_08065488:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0x57
	bls _08065488
	b _080658EA
	.pool
_080654A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	b _08065822
	.pool
_080654B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xC
	b _08065822
	.pool
_080654C8:
	movs r6, 0
	add r2, sp, 0x58
	mov r9, r2
	add r0, sp, 0x60
	mov r10, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r4, r1, r0
	mov r8, r9
_080654DE:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	mov r1, r8
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r4, 0
	bl GetMonData
	mov r2, r10
	adds r1, r2, r6
	strb r0, [r1]
	movs r0, 0x2
	add r8, r0
	adds r6, 0x1
	cmp r6, 0x3
	ble _080654DE
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	mov r1, r9
	strb r0, [r1, 0xC]
	mov r2, r9
	movs r6, 0
_0806551C:
	adds r0, r7, r6
	adds r1, r2, r6
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, 0x1
	cmp r6, 0xF
	bls _0806551C
	b _080658EA
	.pool
_08065530:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x9
	b _08065822
	.pool
_0806554C:
	movs r6, 0
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r2, =gEnemyParty
	mov r8, r2
_08065558:
	adds r1, r6, 0
	adds r1, 0x11
	mov r2, r8
	adds r0, r4, r2
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	cmp r6, 0x3
	ble _08065558
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	bl GetMonData
	adds r1, r7, r6
	strb r0, [r1]
	adds r6, 0x1
	b _080658EA
	.pool
_08065588:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r1, [r3]
	lsls r1, 9
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	adds r1, 0x8
	b _080658E2
	.pool
_080655A4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1
	b _080655BE
	.pool
_080655B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x19
_080655BE:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	movs r6, 0x3
	b _080658EA
	.pool
_080655E4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1A
	b _080658E2
	.pool
_080655F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1B
	b _080658E2
	.pool
_08065604:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1C
	b _080658E2
	.pool
_08065614:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1D
	b _080658E2
	.pool
_08065624:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1E
	b _080658E2
	.pool
_08065634:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x1F
	b _080658E2
	.pool
_08065644:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x20
	b _080658E2
	.pool
_08065654:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x22
	b _080658E2
	.pool
_08065664:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x23
	b _080658E2
	.pool
_08065674:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x24
	b _080658E2
	.pool
_08065684:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x25
	b _080658E2
	.pool
_08065694:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x26
	b _080658E2
	.pool
_080656A4:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x27
	bl GetMonData
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x28
	bl GetMonData
	strb r0, [r7, 0x1]
	adds r0, r4, 0
	movs r1, 0x29
	bl GetMonData
	strb r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x2A
	bl GetMonData
	strb r0, [r7, 0x3]
	adds r0, r4, 0
	movs r1, 0x2B
	bl GetMonData
	strb r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x2C
	bl GetMonData
	strb r0, [r7, 0x5]
	movs r6, 0x6
	b _080658EA
	.pool
_080656F4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x27
	b _080658E2
	.pool
_08065704:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x28
	b _080658E2
	.pool
_08065714:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x29
	b _080658E2
	.pool
_08065724:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2A
	b _080658E2
	.pool
_08065734:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2B
	b _080658E2
	.pool
_08065744:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2C
	b _080658E2
	.pool
_08065754:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0
	b _0806577E
	.pool
_08065764:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x9
	b _08065822
	.pool
_08065774:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x37
_0806577E:
	bl GetMonData
	adds r1, r0, 0
	strb r1, [r7]
	movs r0, 0xFF
	lsls r0, 8
	ands r0, r1
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r0, 0xFF
	lsls r0, 16
	ands r0, r1
	lsrs r0, 16
	strb r0, [r7, 0x2]
	lsrs r0, r1, 24
	strb r0, [r7, 0x3]
	movs r6, 0x4
	b _080658EA
	.pool
_080657A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x38
	b _080658E2
	.pool
_080657B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x39
	b _08065822
	.pool
_080657C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	b _08065822
	.pool
_080657D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3B
	b _08065822
	.pool
_080657E8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3C
	b _08065822
	.pool
_080657F8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3D
	b _08065822
	.pool
_08065808:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3E
	b _08065822
	.pool
_08065818:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3F
_08065822:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	strb r0, [r7]
	lsrs r0, 8
	strb r0, [r7, 0x1]
	movs r6, 0x2
	b _080658EA
	.pool
_08065838:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x16
	b _080658E2
	.pool
_08065848:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x17
	b _080658E2
	.pool
_08065858:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x18
	b _080658E2
	.pool
_08065868:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x21
	b _080658E2
	.pool
_08065878:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x2F
	b _080658E2
	.pool
_08065888:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x30
	b _080658E2
	.pool
_08065898:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x32
	b _080658E2
	.pool
_080658A8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x33
	b _080658E2
	.pool
_080658B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x34
	b _080658E2
	.pool
_080658C8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x35
	b _080658E2
	.pool
_080658D8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x36
_080658E2:
	bl GetMonData
	strb r0, [r7]
	movs r6, 0x1
_080658EA:
	adds r0, r6, 0
	add sp, 0x90
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end dp01_getattr_by_ch1_for_opponent_pokemon

	thumb_func_start sub_8065900
sub_8065900: @ 8065900
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8065900

	thumb_func_start sub_806590C
sub_806590C: @ 806590C
	push {r4,r5,lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0
	bne _0806593C
	ldr r0, =gBattlePartyID
	lsls r1, r2, 1
	adds r1, r0
	ldrb r0, [r1]
	bl sub_8065964
	b _0806595A
	.pool
_0806593C:
	ldrb r4, [r1]
	movs r5, 0
_08065940:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0806594E
	adds r0, r5, 0
	bl sub_8065964
_0806594E:
	lsrs r4, 1
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _08065940
_0806595A:
	bl sub_8065068
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806590C

	thumb_func_start sub_8065964
sub_8065964: @ 8065964
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r3, =gActiveBank
	ldrb r0, [r3]
	lsls r0, 9
	ldr r2, =gUnknown_02023067
	adds r4, r0, r2
	adds r7, r4, 0
	subs r1, r2, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r6, r3, 0
	adds r3, r2, 0
	cmp r0, 0x3B
	bls _08065992
	bl _08066270
_08065992:
	lsls r0, 2
	ldr r1, =_080659A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080659A8:
	.4byte _08065A98
	.4byte _08065C30
	.4byte _08065C4C
	.4byte _08065C68
	.4byte _08065CBC
	.4byte _08065CBC
	.4byte _08065CBC
	.4byte _08065CBC
	.4byte _08065CDC
	.4byte _08065D44
	.4byte _08065D44
	.4byte _08065D44
	.4byte _08065D44
	.4byte _08066270
	.4byte _08066270
	.4byte _08066270
	.4byte _08066270
	.4byte _08065D6C
	.4byte _08065D88
	.4byte _08065DA4
	.4byte _08065DC0
	.4byte _08065DDC
	.4byte _08065DF8
	.4byte _08065E14
	.4byte _08065E30
	.4byte _08065E4C
	.4byte _08065E68
	.4byte _08065E84
	.4byte _08065EA0
	.4byte _08065EBC
	.4byte _08065ED8
	.4byte _08065EF4
	.4byte _08065F68
	.4byte _08065F84
	.4byte _08065FA0
	.4byte _08065FBC
	.4byte _08065FD8
	.4byte _08065FF4
	.4byte _08066010
	.4byte _0806602C
	.4byte _08066048
	.4byte _08066064
	.4byte _08066080
	.4byte _0806609C
	.4byte _080660B8
	.4byte _080660D4
	.4byte _080660F0
	.4byte _0806610C
	.4byte _08066128
	.4byte _08066144
	.4byte _08066160
	.4byte _0806617C
	.4byte _08066198
	.4byte _080661B4
	.4byte _080661D0
	.4byte _080661EC
	.4byte _08066208
	.4byte _08066224
	.4byte _08066240
	.4byte _0806625C
_08065A98:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	adds r2, r7, 0
	bl pokemon_setattr
	adds r2, r7, 0
	adds r2, 0x2E
	adds r0, r4, 0
	movs r1, 0xC
	bl pokemon_setattr
	movs r0, 0
	mov r8, r0
	movs r0, 0x3B
	adds r0, r7
	mov r10, r0
	adds r0, r7, 0
	adds r0, 0x2B
	str r0, [sp, 0x20]
	adds r0, 0x19
	str r0, [sp, 0x28]
	adds r0, 0x4
	str r0, [sp, 0x2C]
	adds r0, 0x4
	str r0, [sp, 0x30]
	subs r0, 0x22
	str r0, [sp, 0x1C]
	subs r0, 0x2
	str r0, [sp, 0x18]
	adds r0, 0x4
	str r0, [sp, 0x24]
	adds r0, r7, 0x2
	str r0, [sp, 0x4]
	adds r0, r7, 0x4
	str r0, [sp, 0x8]
	adds r0, r7, 0x6
	str r0, [sp, 0xC]
	adds r0, 0x2
	str r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x14]
	mov r9, r4
	adds r6, r7, 0
	adds r6, 0x24
	adds r4, r7, 0
	adds r4, 0xC
_08065AFE:
	mov r1, r8
	adds r1, 0xD
	mov r0, r9
	adds r2, r4, 0
	bl pokemon_setattr
	mov r1, r8
	adds r1, 0x11
	mov r0, r9
	adds r2, r6, 0
	bl pokemon_setattr
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08065AFE
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	mov r2, r10
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x20
	ldr r2, [sp, 0x20]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x19
	ldr r2, [sp, 0x28]
	bl pokemon_setattr
	ldrb r0, [r7, 0x14]
	lsls r0, 27
	lsrs r0, 27
	mov r1, sp
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrh r0, [r7, 0x14]
	lsls r0, 22
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x28
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrb r0, [r7, 0x15]
	lsls r0, 25
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x29
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldr r0, [r7, 0x14]
	lsls r0, 12
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2A
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrh r0, [r7, 0x16]
	lsls r0, 23
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2B
	mov r2, sp
	bl pokemon_setattr
	mov r1, sp
	ldrb r0, [r7, 0x17]
	lsls r0, 26
	lsrs r0, 27
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2C
	mov r2, sp
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0
	ldr r2, [sp, 0x2C]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x37
	ldr r2, [sp, 0x30]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x38
	ldr r2, [sp, 0x1C]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x39
	ldr r2, [sp, 0x18]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3A
	ldr r2, [sp, 0x24]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3B
	ldr r2, [sp, 0x4]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3C
	ldr r2, [sp, 0x8]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3D
	ldr r2, [sp, 0xC]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3E
	ldr r2, [sp, 0x10]
	bl pokemon_setattr
	adds r0, r4, 0
	movs r1, 0x3F
	ldr r2, [sp, 0x14]
	bl pokemon_setattr
	b _08066270
	.pool
_08065C30:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xB
	bl pokemon_setattr
	b _08066270
	.pool
_08065C4C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0xC
	bl pokemon_setattr
	b _08066270
	.pool
_08065C68:
	movs r0, 0
	mov r8, r0
	movs r0, 0xC
	adds r0, r4
	mov r9, r0
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r7, r1, r0
	adds r6, r4, 0
	adds r6, 0x8
_08065C80:
	mov r1, r8
	adds r1, 0xD
	adds r0, r7, 0
	adds r2, r4, 0
	bl pokemon_setattr
	mov r1, r8
	adds r1, 0x11
	adds r0, r7, 0
	adds r2, r6, 0
	bl pokemon_setattr
	adds r6, 0x1
	adds r4, 0x2
	movs r0, 0x1
	add r8, r0
	mov r0, r8
	cmp r0, 0x3
	ble _08065C80
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x15
	mov r2, r9
	bl pokemon_setattr
	b _08066270
	.pool
_08065CBC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r3, =gUnknown_02023064
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x9
	b _08065D5A
	.pool
_08065CDC:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x11
	str r3, [sp, 0x34]
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x12
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x13
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x14
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x15
	bl pokemon_setattr
	b _08066270
	.pool
_08065D44:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r3, =gUnknown_02023064
	ldrb r2, [r6]
	lsls r2, 9
	adds r1, r3, 0x1
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r1, 0x8
_08065D5A:
	adds r3, 0x3
	adds r2, r3
	bl pokemon_setattr
	b _08066270
	.pool
_08065D6C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1
	bl pokemon_setattr
	b _08066270
	.pool
_08065D88:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x19
	bl pokemon_setattr
	b _08066270
	.pool
_08065DA4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1A
	bl pokemon_setattr
	b _08066270
	.pool
_08065DC0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1B
	bl pokemon_setattr
	b _08066270
	.pool
_08065DDC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1C
	bl pokemon_setattr
	b _08066270
	.pool
_08065DF8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1D
	bl pokemon_setattr
	b _08066270
	.pool
_08065E14:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1E
	bl pokemon_setattr
	b _08066270
	.pool
_08065E30:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x1F
	bl pokemon_setattr
	b _08066270
	.pool
_08065E4C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x20
	bl pokemon_setattr
	b _08066270
	.pool
_08065E68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x22
	bl pokemon_setattr
	b _08066270
	.pool
_08065E84:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x23
	bl pokemon_setattr
	b _08066270
	.pool
_08065EA0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x24
	bl pokemon_setattr
	b _08066270
	.pool
_08065EBC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x25
	bl pokemon_setattr
	b _08066270
	.pool
_08065ED8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x26
	bl pokemon_setattr
	b _08066270
	.pool
_08065EF4:
	movs r0, 0x64
	adds r4, r5, 0
	muls r4, r0
	ldr r0, =gEnemyParty
	adds r4, r0
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	adds r0, r4, 0
	movs r1, 0x27
	str r3, [sp, 0x34]
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x1
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x28
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x2
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x29
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x3
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2A
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x4
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x2B
	bl pokemon_setattr
	ldrb r2, [r6]
	lsls r2, 9
	ldr r3, [sp, 0x34]
	adds r0, r3, 0x5
	adds r2, r0
	adds r0, r4, 0
	b _08066002
	.pool
_08065F68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x27
	bl pokemon_setattr
	b _08066270
	.pool
_08065F84:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x28
	bl pokemon_setattr
	b _08066270
	.pool
_08065FA0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x29
	bl pokemon_setattr
	b _08066270
	.pool
_08065FBC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2A
	bl pokemon_setattr
	b _08066270
	.pool
_08065FD8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2B
	bl pokemon_setattr
	b _08066270
	.pool
_08065FF4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
_08066002:
	movs r1, 0x2C
	bl pokemon_setattr
	b _08066270
	.pool
_08066010:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0
	bl pokemon_setattr
	b _08066270
	.pool
_0806602C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x9
	bl pokemon_setattr
	b _08066270
	.pool
_08066048:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x37
	bl pokemon_setattr
	b _08066270
	.pool
_08066064:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x38
	bl pokemon_setattr
	b _08066270
	.pool
_08066080:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x39
	bl pokemon_setattr
	b _08066270
	.pool
_0806609C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3A
	bl pokemon_setattr
	b _08066270
	.pool
_080660B8:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3B
	bl pokemon_setattr
	b _08066270
	.pool
_080660D4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3C
	bl pokemon_setattr
	b _08066270
	.pool
_080660F0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3D
	bl pokemon_setattr
	b _08066270
	.pool
_0806610C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3E
	bl pokemon_setattr
	b _08066270
	.pool
_08066128:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x3F
	bl pokemon_setattr
	b _08066270
	.pool
_08066144:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x16
	bl pokemon_setattr
	b _08066270
	.pool
_08066160:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x17
	bl pokemon_setattr
	b _08066270
	.pool
_0806617C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x18
	bl pokemon_setattr
	b _08066270
	.pool
_08066198:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x21
	bl pokemon_setattr
	b _08066270
	.pool
_080661B4:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x2F
	bl pokemon_setattr
	b _08066270
	.pool
_080661D0:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x30
	bl pokemon_setattr
	b _08066270
	.pool
_080661EC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x32
	bl pokemon_setattr
	b _08066270
	.pool
_08066208:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x33
	bl pokemon_setattr
	b _08066270
	.pool
_08066224:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x34
	bl pokemon_setattr
	b _08066270
	.pool
_08066240:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x35
	bl pokemon_setattr
	b _08066270
	.pool
_0806625C:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	ldrb r2, [r6]
	lsls r2, 9
	adds r2, r3
	movs r1, 0x36
	bl pokemon_setattr
_08066270:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8065964

	thumb_func_start sub_8066284
sub_8066284: @ 8066284
	push {r4-r7,lr}
	ldr r1, =gBattlePartyID
	ldr r7, =gActiveBank
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	adds r3, r1, 0
	muls r3, r0
	ldr r4, =gUnknown_02023064
	lsls r2, 9
	adds r0, r4, 0x1
	adds r0, r2, r0
	ldrb r0, [r0]
	ldr r1, =gEnemyParty
	adds r0, r1
	adds r5, r3, r0
	movs r3, 0
	adds r0, r4, 0x2
	adds r2, r0
	ldrb r2, [r2]
	cmp r3, r2
	bcs _080662DC
	adds r6, r4, 0
	adds r2, r7, 0
	adds r4, r0, 0
_080662BA:
	adds r1, r5, r3
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, 0x3
	adds r0, r3, r0
	adds r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r2]
	lsls r0, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r3, r0
	bcc _080662BA
_080662DC:
	bl sub_8065068
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066284

	thumb_func_start sub_80662F8
sub_80662F8: @ 80662F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r7, =gBattlePartyID
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r7
	ldrh r0, [r0]
	movs r1, 0x64
	mov r10, r1
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	ldr r1, =gEnemyParty
	mov r9, r1
	add r0, r9
	movs r1, 0xB
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r1, [r6]
	lsls r0, r1, 1
	adds r0, r7
	ldrh r0, [r0]
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	add r0, r9
	bl sub_805DC0C
	ldrb r0, [r6]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r8, r0
	ldrb r0, [r6]
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldrb r0, [r6]
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r6]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r8
	adds r1, r5, 0
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r4, =gUnknown_020241E4
	ldrb r1, [r6]
	adds r1, r4
	strb r0, [r1]
	ldr r5, =gUnknown_02020630
	ldrb r0, [r6]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =0x0000ff10
	strh r1, [r0, 0x24]
	ldrb r2, [r6]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x2E]
	ldrb r3, [r6]
	adds r0, r3, r4
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r2, [r6]
	adds r4, r2, r4
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r2, r1
	ldrb r1, [r2]
	bl StartObjectImageAnim
	ldrb r4, [r6]
	lsls r0, r4, 1
	adds r0, r7
	ldrh r0, [r0]
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	add r0, r9
	movs r1, 0xB
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	adds r0, r4, 0
	bl sub_805EE54
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064B04
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80662F8

	thumb_func_start sub_8066448
sub_8066448: @ 8066448
	push {r4,lr}
	ldr r1, =gBattlePartyID
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r2, r0, 1
	adds r2, r1
	ldr r3, =gUnknown_02023064
	lsls r0, 9
	adds r1, r3, 0x1
	adds r0, r1
	ldrb r0, [r0]
	strh r0, [r2]
	ldrb r0, [r4]
	lsls r1, r0, 9
	adds r3, 0x2
	adds r1, r3
	ldrb r1, [r1]
	bl sub_8066494
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064F40
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066448

	thumb_func_start sub_8066494
sub_8066494: @ 8066494
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl sub_805EF84
	ldr r0, =gBattlePartyID
	lsls r4, r6, 1
	adds r4, r0
	ldr r0, =gUnknown_02023064
	lsls r1, r6, 9
	adds r0, 0x1
	adds r1, r0
	ldrb r0, [r1]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, 0x64
	mov r9, r1
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	ldr r5, =gEnemyParty
	adds r0, r5
	movs r1, 0xB
	bl GetMonData
	mov r8, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r0, =sub_805D714
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gUnknown_03005D7C
	mov r10, r1
	add r10, r6
	mov r1, r10
	strb r0, [r1]
	ldrh r0, [r4]
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	adds r0, r5
	adds r1, r6, 0
	bl sub_805DC0C
	adds r0, r6, 0
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl sub_806A068
	ldr r0, =gUnknown_0202499C
	mov r9, r0
	adds r0, r6, 0
	movs r1, 0x2
	bl sub_80A5C6C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	bl sub_80A6138
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	mov r0, r9
	adds r1, r5, 0
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r4, =gUnknown_020241E4
	adds r4, r6, r4
	strb r0, [r4]
	ldr r5, =gUnknown_02020630
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r4]
	strh r1, [r0, 0x30]
	mov r0, r10
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x32]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r6, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	mov r1, r8
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	lsls r3, r6, 4
	ldrb r2, [r1, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =gUnknown_020244E4
	adds r6, r1
	ldrb r1, [r6]
	bl StartObjectImageAnim
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =DummyObjectCallback
	str r1, [r0]
	movs r0, 0
	movs r1, 0xFE
	bl sub_80753E8
	mov r1, r10
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r5
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x2E]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066494

	thumb_func_start sub_8066624
sub_8066624: @ 8066624
	push {r4-r6,lr}
	ldr r1, =gUnknown_02023064
	ldr r6, =gActiveBank
	ldrb r2, [r6]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r3, [r0]
	cmp r3, 0
	bne _0806666C
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	strb r3, [r0, 0x4]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80666BC
	str r1, [r0]
	b _080666A8
	.pool
_0806666C:
	ldr r5, =gUnknown_020241E4
	adds r0, r2, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl obj_free_rotscale_entry
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl RemoveObjectAndFreeTiles
	ldrb r0, [r6]
	bl sub_805EEE0
	ldr r1, =gUnknown_03005D70
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	bl sub_8072984
	bl sub_8065068
_080666A8:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066624

	thumb_func_start sub_80666BC
sub_80666BC: @ 80666BC
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r1, [r4, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	beq _080666E4
	cmp r0, 0x1
	beq _08066712
	b _0806673A
	.pool
_080666E4:
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080666FE
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_080666FE:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _0806673A
_08066712:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _0806673A
	strb r0, [r3, 0x4]
	ldrb r2, [r5]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x2
	bl move_anim_start_t4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064C58
	str r1, [r0]
_0806673A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80666BC

	thumb_func_start sub_8066748
sub_8066748: @ 8066748
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r4, =gBattleTypeFlags
	ldr r0, [r4]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08066840
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl battle_get_per_side_status
	movs r1, 0x2
	ands r1, r0
	movs r7, 0xC8
	cmp r1, 0
	beq _08066770
	movs r7, 0x98
_08066770:
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 1
	ands r0, r1
	cmp r0, 0
	beq _080667A8
	ldrb r0, [r5]
	cmp r0, 0x1
	bne _08066794
	ldr r0, =gUnknown_02038BCA
	b _08066796
	.pool
_08066794:
	ldr r0, =gUnknown_02038BCC
_08066796:
	ldrh r0, [r0]
	bl sub_8162AA0
	lsls r0, 24
	lsrs r0, 24
	b _0806694C
	.pool
_080667A8:
	ldrb r0, [r5]
	bl sub_806D864
	ldr r6, =gUnknown_020229E8
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _080667D8
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _080667F4
_080667D8:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _080668AA
	b _080668BC
	.pool
_080667F4:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _08066822
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _08066838
_08066822:
	ldrb r0, [r5]
	bl sub_806D864
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	bne _08066916
	b _08066924
_08066838:
	ldrb r0, [r5]
	bl sub_806D864
	b _0806693A
_08066840:
	movs r7, 0xB0
	ldr r0, =gUnknown_02038BCA
	ldrh r1, [r0]
	movs r0, 0xC0
	lsls r0, 4
	cmp r1, r0
	bne _08066858
	bl sub_8068B48
	b _08066948
	.pool
_08066858:
	bl link_get_multiplayer_id
	ldr r6, =gUnknown_020229E8
	movs r5, 0x1
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	movs r4, 0xFF
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _08066892
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x5
	bne _080668C8
_08066892:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	beq _080668BC
_080668AA:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x4F
	ldrb r0, [r0]
	b _0806694C
	.pool
_080668BC:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x4E
	ldrb r0, [r0]
	b _0806694C
	.pool
_080668C8:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0x2
	beq _080668FE
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrh r0, [r1]
	ands r4, r0
	cmp r4, 0x1
	bne _08066930
_080668FE:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	cmp r0, 0
	beq _08066924
_08066916:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x51
	ldrb r0, [r0]
	b _0806694C
	.pool
_08066924:
	ldr r0, =gTrainerPicIndices
	adds r0, 0x50
	ldrb r0, [r0]
	b _0806694C
	.pool
_08066930:
	bl link_get_multiplayer_id
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
_0806693A:
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x13]
	bl sub_806F000
_08066948:
	lsls r0, 16
	lsrs r0, 16
_0806694C:
	mov r8, r0
	ldr r5, =gActiveBank
	ldrb r1, [r5]
	bl sub_805DF38
	ldrb r0, [r5]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl template_build_for_pokemon_or_trainer
	ldr r6, =gUnknown_0202499C
	mov r9, r7
	ldr r1, =gUnknown_083054E0
	mov r2, r8
	lsls r0, r2, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r4, 0x8
	subs r4, r0
	lsls r4, 18
	movs r0, 0xA0
	lsls r0, 14
	adds r4, r0
	asrs r4, 16
	ldrb r0, [r5]
	bl sub_80A82E4
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	adds r0, r6, 0
	mov r1, r9
	adds r2, r4, 0
	bl AddObjectToFront
	ldr r6, =gUnknown_020241E4
	ldrb r1, [r5]
	adds r1, r6
	strb r0, [r1]
	ldr r4, =gUnknown_02020630
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000ff10
	strh r1, [r0, 0x24]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x2
	strh r1, [r0, 0x2E]
	ldr r1, =gTrainerFrontPicPaletteTable
	mov r2, r8
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl IndexOfObjectPaletteTag
	ldrb r1, [r5]
	adds r1, r6
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r4
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r1, r8
	strh r1, [r0, 0x6]
	ldrb r0, [r5]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064400
	str r1, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066748

	thumb_func_start sub_8066A58
sub_8066A58: @ 8066A58
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _08066A74
	ldr r0, =gUnknown_02038BCA
	b _08066A76
	.pool
_08066A74:
	ldr r0, =gUnknown_02038BCC
_08066A76:
	ldrh r0, [r0]
	bl sub_8162AA0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r6, =gActiveBank
	ldrb r1, [r6]
	bl sub_805DF38
	ldrb r0, [r6]
	bl battle_get_per_side_status
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r0, r8
	bl template_build_for_pokemon_or_trainer
	ldr r0, =gUnknown_0202499C
	ldr r2, =gUnknown_083054E0
	mov r3, r8
	lsls r1, r3, 2
	adds r1, r2
	ldrb r1, [r1]
	movs r2, 0x8
	subs r2, r1
	lsls r2, 18
	movs r1, 0xA0
	lsls r1, 14
	adds r2, r1
	asrs r2, 16
	movs r1, 0xB0
	movs r3, 0x1E
	bl AddObjectToFront
	ldr r5, =gUnknown_020241E4
	ldrb r1, [r6]
	adds r1, r5
	strb r0, [r1]
	ldr r4, =gUnknown_02020630
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x60
	strh r1, [r0, 0x24]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x20]
	adds r1, 0x20
	strh r1, [r0, 0x20]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =0x0000fffe
	strh r1, [r0, 0x2E]
	ldr r1, =gTrainerFrontPicPaletteTable
	mov r2, r8
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl IndexOfObjectPaletteTag
	ldrb r1, [r6]
	adds r1, r5
	ldrb r1, [r1]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	adds r2, r4
	lsls r0, 4
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, 0x5]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	mov r3, r8
	strh r3, [r0, 0x6]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, 0x1C
	adds r0, r4
	ldr r1, =sub_805D7AC
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064438
	str r1, [r0]
	bl sub_8065068
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066A58

	thumb_func_start sub_8066B94
sub_8066B94: @ 8066B94
	push {r4-r6,lr}
	ldr r6, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r5, =gUnknown_02020630
	adds r0, r5
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0x8C
	lsls r1, 1
	strh r1, [r0, 0x32]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r5, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r0, [r4]
	adds r0, r6
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldr r1, =DummyObjectCallback
	bl oamt_set_x3A_32
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064470
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066B94

	thumb_func_start sub_8066C40
sub_8066C40: @ 8066C40
	push {r4-r6,lr}
	ldr r6, =gUnknown_020244D0
	ldr r4, [r6]
	ldr r5, =gActiveBank
	ldrb r2, [r5]
	ldr r0, [r4, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r3, r1, r0
	ldrb r0, [r3, 0x4]
	cmp r0, 0
	bne _08066C94
	ldr r1, [r4]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08066C74
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08066C74:
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x4]
	adds r1, 0x1
	strb r1, [r0, 0x4]
	b _08066CD0
	.pool
_08066C94:
	ldrb r1, [r3]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _08066CD0
	strb r0, [r3, 0x4]
	movs r0, 0x10
	movs r1, 0x3F
	bl audio_play_and_stuff
	ldr r2, =gUnknown_02020630
	ldr r1, =gUnknown_020241E4
	ldrb r0, [r5]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_8039934
	str r1, [r0]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064C14
	str r1, [r0]
_08066CD0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066C40

	thumb_func_start sub_8066CEC
sub_8066CEC: @ 8066CEC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066CEC

	thumb_func_start sub_8066CF8
sub_8066CF8: @ 8066CF8
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066CF8

	thumb_func_start sub_8066D04
sub_8066D04: @ 8066D04
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066D04

	thumb_func_start sub_8066D10
sub_8066D10: @ 8066D10
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8066D10

	thumb_func_start sub_8066D1C
sub_8066D1C: @ 8066D1C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	beq _08066D32
	b _08066E58
_08066D32:
	ldr r0, =gUnknown_02023064
	mov r12, r0
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	mov r0, r12
	adds r0, 0x2
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r6, r0
	ldr r0, =gUnknown_02038432
	mov r8, r0
	mov r0, r12
	adds r0, 0x3
	adds r1, r0
	ldrb r0, [r1]
	mov r1, r8
	strb r0, [r1]
	ldr r3, =gUnknown_02038408
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x4
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0x5
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	strh r2, [r3]
	ldr r3, =gUnknown_02038404
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x6
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0x7
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 8
	orrs r2, r0
	mov r0, r12
	adds r0, 0x8
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r0, 16
	orrs r2, r0
	mov r0, r12
	adds r0, 0x9
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 24
	orrs r2, r0
	str r2, [r3]
	ldr r2, =gUnknown_0203841A
	ldrb r0, [r5]
	lsls r0, 9
	mov r1, r12
	adds r1, 0xA
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r4, =gUnknown_0203841C
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0xC
	adds r0, r1, r0
	ldrb r2, [r0]
	mov r0, r12
	adds r0, 0xD
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 8
	orrs r2, r0
	strh r2, [r4]
	ldr r7, =gUnknown_02038400
	ldrb r1, [r5]
	lsls r1, 9
	mov r0, r12
	adds r0, 0x10
	adds r1, r0
	str r1, [r7]
	ldr r2, =gUnknown_020244BC
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r1]
	str r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, 0
	bl sub_805DB8C
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _08066E30
	bl sub_8065068
	b _08066E58
	.pool
_08066E30:
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x4]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8066E70
	str r1, [r0]
	ldrh r1, [r4]
	ldr r2, [r7]
	adds r0, r6, 0
	bl sub_817E0FC
_08066E58:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066D1C

	thumb_func_start sub_8066E70
sub_8066E70: @ 8066E70
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r2, =gUnknown_02023064
	ldr r6, =gActiveBank
	ldrb r3, [r6]
	lsls r1, r3, 9
	adds r0, r2, 0x1
	mov r10, r0
	adds r0, r1, r0
	ldrb r4, [r0]
	adds r5, r2, 0x2
	mov r9, r5
	adds r0, r1, r5
	ldrb r0, [r0]
	lsls r0, 8
	orrs r4, r0
	adds r2, 0xB
	adds r1, r2
	ldrb r1, [r1]
	mov r8, r1
	ldr r7, =gUnknown_020244D0
	ldr r5, [r7]
	ldr r1, [r5, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x4]
	cmp r2, 0x1
	beq _08066F08
	cmp r2, 0x1
	bgt _08066EC8
	cmp r2, 0
	beq _08066ED2
	b _08066FE4
	.pool
_08066EC8:
	cmp r2, 0x2
	beq _08066F32
	cmp r2, 0x3
	beq _08066FA8
	b _08066FE4
_08066ED2:
	ldr r1, [r5]
	lsls r0, r3, 2
	adds r1, r0, r1
	ldrb r2, [r1]
	movs r0, 0xC
	ands r0, r2
	cmp r0, 0x4
	bne _08066EF4
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1]
	ldrb r2, [r6]
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x5
	bl move_anim_start_t4
_08066EF4:
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0, 0x4]
	b _08066FE4
_08066F08:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _08066FE4
	movs r0, 0
	bl sub_805EB9C
	adds r0, r4, 0
	bl move_anim_start_t1
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0, 0x4]
	b _08066FE4
_08066F32:
	ldr r0, =gUnknown_020383F8
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gUnknown_020383FD
	ldrb r0, [r0]
	cmp r0, 0
	bne _08066FE4
	movs r0, 0x1
	bl sub_805EB9C
	ldr r0, [r7]
	ldrb r2, [r6]
	ldr r1, [r0]
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08066F80
	mov r0, r8
	cmp r0, 0x1
	bhi _08066F80
	adds r0, r2, 0
	adds r1, r2, 0
	movs r3, 0x6
	bl move_anim_start_t4
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r0, [r0]
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_08066F80:
	ldr r0, =gUnknown_020244D0
	ldr r2, [r0]
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	ldr r2, [r2, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3
	strb r1, [r0, 0x4]
	b _08066FE4
	.pool
_08066FA8:
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _08066FE4
	bl sub_805E394
	ldrb r0, [r6]
	lsls r2, r0, 9
	mov r3, r10
	adds r1, r2, r3
	ldrb r1, [r1]
	add r2, r9
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	bl sub_805E94C
	ldr r0, [r7]
	ldrb r1, [r6]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r4, [r0, 0x4]
	bl sub_8065068
_08066FE4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8066E70

	thumb_func_start sub_8066FF4
sub_8066FF4: @ 8066FF4
	push {r4,r5,lr}
	ldr r0, =gUnknown_02022E14
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gUnknown_02022E16
	strh r1, [r0]
	ldr r5, =gActiveBank
	ldrb r4, [r5]
	lsls r4, 9
	ldr r0, =gUnknown_02023066
	adds r4, r0
	ldrh r0, [r4]
	bl battle_pick_message
	ldr r0, =gUnknown_02022E2C
	movs r1, 0
	bl battle_show_message_maybe
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064CCC
	str r1, [r0]
	ldrh r0, [r4]
	bl sub_817C95C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8066FF4

	thumb_func_start sub_806704C
sub_806704C: @ 806704C
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_806704C

	thumb_func_start sub_8067058
sub_8067058: @ 8067058
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067058

	thumb_func_start sub_8067064
sub_8067064: @ 8067064
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067064

	thumb_func_start sub_8067070
sub_8067070: @ 8067070
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067070

	thumb_func_start sub_806707C
sub_806707C: @ 806707C
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_806707C

	thumb_func_start sub_8067088
sub_8067088: @ 8067088
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067088

	thumb_func_start sub_8067094
sub_8067094: @ 8067094
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067094

	thumb_func_start sub_80670A0
sub_80670A0: @ 80670A0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	movs r0, 0
	bl load_gfxc_health_bar
	ldr r3, =gUnknown_02023064
	ldr r0, =gActiveBank
	mov r9, r0
	ldrb r4, [r0]
	lsls r2, r4, 9
	adds r0, r3, 0x2
	adds r0, r2, r0
	ldrb r1, [r0]
	adds r3, 0x3
	adds r2, r3
	ldrb r0, [r2]
	lsls r0, 8
	orrs r1, r0
	lsls r1, 16
	asrs r7, r1, 16
	ldr r0, =0x00007fff
	cmp r7, r0
	beq _08067130
	ldr r6, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	movs r5, 0x64
	muls r0, r5
	ldr r4, =gEnemyParty
	adds r0, r4
	movs r1, 0x3A
	bl GetMonData
	mov r8, r0
	mov r1, r9
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	muls r0, r5
	adds r0, r4
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	mov r2, r8
	bl sub_807294C
	b _0806715A
	.pool
_08067130:
	ldr r1, =gBattlePartyID
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0x3A
	bl GetMonData
	adds r2, r0, 0
	mov r1, r9
	ldrb r0, [r1]
	ldr r1, =gUnknown_03005D70
	adds r1, r0, r1
	ldrb r1, [r1]
	str r7, [sp]
	movs r3, 0
	bl sub_807294C
_0806715A:
	ldr r1, =gUnknown_03005D60
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064BC0
	str r1, [r0]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80670A0

	thumb_func_start sub_8067190
sub_8067190: @ 8067190
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067190

	thumb_func_start sub_806719C
sub_806719C: @ 806719C
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _080671F0
	ldr r0, =gUnknown_03005D70
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r2, =gBattlePartyID
	lsls r1, 1
	adds r1, r2
	ldrh r2, [r1]
	movs r1, 0x64
	muls r1, r2
	ldr r2, =gEnemyParty
	adds r1, r2
	movs r2, 0x9
	bl healthbar_draw_field_maybe
	ldrb r2, [r4]
	ldr r0, =gUnknown_020244D0
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8065008
	str r1, [r0]
_080671F0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806719C

	thumb_func_start sub_8067214
sub_8067214: @ 8067214
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08067264
	ldr r4, =gUnknown_02023064
	ldrb r3, [r5]
	lsls r3, 9
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	adds r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 8
	orrs r1, r2
	adds r2, r4, 0x4
	adds r2, r3, r2
	ldrb r2, [r2]
	lsls r2, 16
	orrs r1, r2
	adds r4, 0x5
	adds r3, r4
	ldrb r2, [r3]
	lsls r2, 24
	orrs r1, r2
	bl move_anim_start_t2_for_situation
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8065008
	str r1, [r0]
_08067264:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067214

	thumb_func_start sub_806727C
sub_806727C: @ 806727C
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_806727C

	thumb_func_start sub_8067288
sub_8067288: @ 8067288
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067288

	thumb_func_start sub_8067294
sub_8067294: @ 8067294
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_8067294

	thumb_func_start sub_80672A0
sub_80672A0: @ 80672A0
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672A0

	thumb_func_start sub_80672AC
sub_80672AC: @ 80672AC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672AC

	thumb_func_start sub_80672B8
sub_80672B8: @ 80672B8
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672B8

	thumb_func_start sub_80672C4
sub_80672C4: @ 80672C4
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672C4

	thumb_func_start sub_80672D0
sub_80672D0: @ 80672D0
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672D0

	thumb_func_start sub_80672DC
sub_80672DC: @ 80672DC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80672DC

	thumb_func_start sub_80672E8
sub_80672E8: @ 80672E8
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80672E8

	thumb_func_start sub_8067304
sub_8067304: @ 8067304
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0x7F
	ands r1, r0
	ldrb r2, [r3]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067304

	thumb_func_start sub_806733C
sub_806733C: @ 806733C
	push {lr}
	ldr r2, =gUnknown_02022D0C
	ldrb r1, [r2]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2]
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806733C

	thumb_func_start sub_8067354
sub_8067354: @ 8067354
	push {lr}
	ldr r3, =gUnknown_02022D0C
	ldr r1, [r3]
	lsls r1, 24
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 7
	ldrb r2, [r3]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067354

	thumb_func_start sub_806737C
sub_806737C: @ 806737C
	push {r4,lr}
	ldr r3, =gUnknown_02020630
	ldr r2, =gUnknown_020241E4
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _080673B0
	bl sub_8065068
	b _080673DA
	.pool
_080673B0:
	ldr r1, =gUnknown_020244B9
	movs r0, 0x1
	strb r0, [r1]
	ldrb r0, [r4]
	adds r0, r2
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x30]
	ldrb r0, [r4]
	bl sub_80769F4
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064CE4
	str r1, [r0]
_080673DA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806737C

	thumb_func_start sub_80673EC
sub_80673EC: @ 80673EC
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80673EC

	thumb_func_start sub_80673F8
sub_80673F8: @ 80673F8
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	movs r3, 0x3F
	cmp r0, 0
	bne _0806740C
	movs r3, 0xC0
_0806740C:
	ldr r2, =gUnknown_02023064
	ldrb r1, [r4]
	lsls r1, 9
	adds r0, r2, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	lsls r1, r3, 24
	asrs r1, 24
	bl audio_play_and_stuff
	bl sub_8065068
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80673F8

	thumb_func_start sub_806743C
sub_806743C: @ 806743C
	push {r4,r5,lr}
	ldr r4, =gUnknown_02023064
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r3, r0, 9
	adds r0, r4, 0x3
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067478
	bl sub_805EA60
	ldrb r1, [r5]
	lsls r1, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	adds r2, r4, 0x2
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl song_play_for_text
	b _0806748C
	.pool
_08067478:
	adds r0, r4, 0x1
	adds r0, r3, r0
	ldrb r0, [r0]
	adds r1, r4, 0x2
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, 8
	orrs r0, r1
	bl fanfare_play
_0806748C:
	bl sub_8065068
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806743C

	thumb_func_start sub_8067498
sub_8067498: @ 8067498
	push {lr}
	ldr r1, =gBattlePartyID
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x19
	movs r2, 0x5
	bl sub_80A32E4
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067498

	thumb_func_start sub_80674D4
sub_80674D4: @ 80674D4
	push {lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	bl battle_intro_launch
	ldr r2, =gUnknown_020243FC
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80674D4

	thumb_func_start sub_8067508
sub_8067508: @ 8067508
	push {r4-r6,lr}
	ldr r5, =gUnknown_020241E4
	ldr r6, =gActiveBank
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gUnknown_02020630
	adds r0, r4
	bl oamt_add_pos2_onto_pos1
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x23
	strh r1, [r0, 0x2E]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x8C
	lsls r1, 1
	strh r1, [r0, 0x32]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrh r1, [r0, 0x22]
	strh r1, [r0, 0x36]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80A6EEC
	str r1, [r0]
	ldrb r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldr r1, =sub_80676FC
	bl oamt_set_x3A_32
	ldr r0, =c3_08038DC4
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r4
	ldrb r0, [r6]
	strh r0, [r1, 0x8]
	ldr r3, =gUnknown_020244D0
	ldr r0, [r3]
	ldrb r2, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080675CA
	ldr r0, =gUnknown_020244B4
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r4
	ldr r1, =sub_8073C30
	str r1, [r0]
_080675CA:
	ldr r0, [r3]
	ldr r2, [r0, 0x8]
	ldrb r0, [r2, 0x9]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x9]
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r1
	ldr r1, =nullsub_28
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067508

	thumb_func_start c3_08038DC4
c3_08038DC4: @ 8067618
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r7, =gActiveBank
	ldrb r0, [r7]
	mov r9, r0
	ldr r1, =gTasks
	mov r2, r8
	lsls r0, r2, 2
	add r0, r8
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x8]
	strb r0, [r7]
	bl battle_type_is_double
	lsls r0, 24
	cmp r0, 0
	beq _08067652
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08067684
_08067652:
	ldr r0, =gUnknown_02023064
	ldrb r1, [r7]
	lsls r2, r1, 9
	adds r0, 0x1
	adds r2, r0
	ldr r0, =gBattlePartyID
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	strb r0, [r2]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_8066494
	b _080676C4
	.pool
_08067684:
	ldr r4, =gUnknown_02023064
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r4, 0x1
	adds r1, r4
	ldr r6, =gBattlePartyID
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_8066494
	ldrb r0, [r7]
	movs r5, 0x2
	eors r0, r5
	strb r0, [r7]
	ldrb r0, [r7]
	lsls r1, r0, 9
	adds r1, r4
	lsls r0, 1
	adds r0, r6
	ldrh r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	movs r1, 0
	bl sub_8066494
	ldrb r0, [r7]
	eors r0, r5
	strb r0, [r7]
_080676C4:
	ldr r1, =gUnknown_03005D60
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_8064734
	str r1, [r0]
	mov r0, r9
	strb r0, [r2]
	mov r0, r8
	bl DestroyTask
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_08038DC4

	thumb_func_start sub_80676FC
sub_80676FC: @ 80676FC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x6]
	bl sub_805DFE4
	adds r0, r4, 0
	bl obj_free_rotscale_entry
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80676FC

	thumb_func_start sub_8067718
sub_8067718: @ 8067718
	push {r4-r7,lr}
	ldr r1, =gUnknown_02023064
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	lsls r0, r2, 9
	adds r1, 0x1
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067748
	adds r0, r2, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08067748
	bl sub_8065068
	b _08067812
	.pool
_08067748:
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	ldr r1, =gUnknown_02023064
	ldrb r2, [r3]
	lsls r0, r2, 9
	adds r1, 0x2
	adds r0, r1
	ldrb r0, [r0]
	adds r7, r3, 0
	cmp r0, 0
	beq _080677B4
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r3, r0, r1
	ldrb r2, [r3, 0x1]
	lsls r1, r2, 27
	lsrs r0, r1, 28
	cmp r0, 0x1
	bhi _080677AC
	adds r0, 0x1
	movs r1, 0xF
	ands r0, r1
	lsls r0, 1
	movs r1, 0x1F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x1]
	b _08067812
	.pool
_080677AC:
	movs r0, 0x1F
	negs r0, r0
	ands r0, r2
	strb r0, [r3, 0x1]
_080677B4:
	adds r5, r7, 0
	ldrb r0, [r5]
	lsls r3, r0, 9
	ldr r4, =gUnknown_02023068
	adds r1, r3, r4
	subs r2, r4, 0x3
	adds r2, r3, r2
	ldrb r2, [r2]
	subs r4, 0x2
	adds r3, r4
	ldrb r3, [r3]
	bl sub_80735DC
	ldr r2, =gUnknown_020244B4
	ldrb r1, [r5]
	adds r1, r2
	movs r3, 0
	strb r0, [r1]
	ldr r6, =gUnknown_020244D0
	ldr r0, [r6]
	ldrb r1, [r5]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strb r3, [r0, 0x5]
	ldrb r2, [r5]
	lsls r0, r2, 9
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0
	beq _08067806
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x5D
	strb r1, [r0, 0x5]
_08067806:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r7]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_806782C
	str r0, [r1]
_08067812:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067718

	thumb_func_start sub_806782C
sub_806782C: @ 806782C
	push {r4,lr}
	ldr r4, =gUnknown_020244D0
	ldr r0, [r4]
	ldr r3, =gActiveBank
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x5]
	adds r2, r1, 0x1
	strb r2, [r0, 0x5]
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x5C
	bls _08067864
	ldr r0, [r4]
	ldrb r1, [r3]
	ldr r2, [r0, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x5]
	bl sub_8065068
_08067864:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806782C

	thumb_func_start sub_8067874
sub_8067874: @ 8067874
	push {lr}
	ldr r0, =gUnknown_020244D0
	ldr r1, [r0]
	ldr r0, =gActiveBank
	ldrb r3, [r0]
	ldr r1, [r1, 0x4]
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080678A6
	ldr r2, =gTasks
	ldr r0, =gUnknown_020244B4
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldr r1, =sub_8073C30
	str r1, [r0]
_080678A6:
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067874

	thumb_func_start sub_80678C4
sub_80678C4: @ 80678C4
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80678C4

	thumb_func_start sub_80678D0
sub_80678D0: @ 80678D0
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl sub_80A6A90
	lsls r0, 24
	cmp r0, 0
	beq _08067916
	ldr r3, =gUnknown_02020630
	ldr r0, =gUnknown_020241E4
	ldrb r1, [r4]
	adds r0, r1, r0
	ldrb r0, [r0]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldr r0, =gUnknown_02023064
	lsls r1, 9
	adds r0, 0x1
	adds r1, r0
	adds r2, 0x3E
	movs r0, 0x1
	ldrb r1, [r1]
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r4]
	bl sub_805E408
_08067916:
	bl sub_8065068
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80678D0

	thumb_func_start sub_8067930
sub_8067930: @ 8067930
	push {r4-r6,lr}
	sub sp, 0x4
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	bl mplay_80342A4
	lsls r0, 24
	cmp r0, 0
	bne _08067992
	ldr r4, =gUnknown_02023064
	ldrb r2, [r5]
	lsls r1, r2, 9
	adds r0, r4, 0x1
	adds r0, r1, r0
	ldrb r6, [r0]
	adds r0, r4, 0x2
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r4, 0x3
	adds r1, r4
	ldrb r0, [r1]
	lsls r0, 8
	orrs r3, r0
	str r3, [sp]
	adds r0, r2, 0
	adds r1, r2, 0
	adds r3, r6, 0
	bl move_anim_start_t3
	lsls r0, 24
	cmp r0, 0
	beq _08067980
	bl sub_8065068
	b _0806798C
	.pool
_08067980:
	ldr r0, =gUnknown_03005D60
	ldrb r1, [r5]
	lsls r1, 2
	adds r1, r0
	ldr r0, =sub_8065038
	str r0, [r1]
_0806798C:
	adds r0, r6, 0
	bl sub_817E32C
_08067992:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8067930

	thumb_func_start sub_80679A4
sub_80679A4: @ 80679A4
	push {lr}
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	lsls r0, 9
	ldr r1, =gUnknown_02023066
	adds r0, r1
	bl sub_81851A8
	bl sub_8065068
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80679A4

	thumb_func_start sub_80679C4
sub_80679C4: @ 80679C4
	push {lr}
	bl sub_8065068
	pop {r0}
	bx r0
	thumb_func_end sub_80679C4

	thumb_func_start sub_80679D0
sub_80679D0: @ 80679D0
	push {r4,r5,lr}
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	lsls r0, 9
	ldr r4, =gUnknown_02023068
	adds r0, r4
	bl sub_81851A8
	ldrb r0, [r5]
	lsls r0, 9
	subs r4, 0x3
	adds r0, r4
	ldrb r2, [r0]
	cmp r2, 0x3
	bne _08067A00
	ldr r0, =gUnknown_0202433A
	strb r2, [r0]
	b _08067A08
	.pool
_08067A00:
	ldr r0, =gUnknown_0202433A
	movs r1, 0x3
	eors r1, r2
	strb r1, [r0]
_08067A08:
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =gUnknown_02023064
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	lsls r0, 9
	adds r1, 0x2
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =0x00000ca9
	adds r3, r1
	movs r1, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r3]
	movs r0, 0x9
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r0, 0x5
	bl sub_80A2F50
	movs r0, 0x3
	bl BeginFastPaletteFade
	bl sub_8065068
	ldr r1, =gUnknown_03005D60
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =sub_80587B0
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80679D0

	thumb_func_start nullsub_92
nullsub_92: @ 8067A70
	bx lr
	thumb_func_end nullsub_92

	.align 2, 0 @ Don't pad with nop.
