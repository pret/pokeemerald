	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start b_movescr_stack_push
b_movescr_stack_push: @ 803FAD8
	push {r4,lr}
	ldr r1, =gBattleResources
	ldr r1, [r1]
	ldr r3, [r1, 0x8]
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
	thumb_func_end b_movescr_stack_push

	thumb_func_start b_movescr_stack_push_cursor
b_movescr_stack_push_cursor: @ 803FAFC
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r2, [r0, 0x8]
	adds r3, r2, 0
	adds r3, 0x20
	ldrb r0, [r3]
	adds r1, r0, 0x1
	strb r1, [r3]
	lsls r0, 24
	lsrs r0, 22
	adds r2, r0
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	str r0, [r2]
	bx lr
	.pool
	thumb_func_end b_movescr_stack_push_cursor

	thumb_func_start b_movescr_stack_pop_cursor
b_movescr_stack_pop_cursor: @ 803FB24
	ldr r3, =gBattlescriptCurrInstr
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r1, [r0, 0x8]
	adds r2, r1, 0
	adds r2, 0x20
	ldrb r0, [r2]
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 22
	adds r1, r0
	ldr r0, [r1]
	str r0, [r3]
	bx lr
	.pool
	thumb_func_end b_movescr_stack_pop_cursor

	thumb_func_start sub_803FB4C
sub_803FB4C: @ 803FB4C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0
	ldr r2, =gBattleMons
	ldr r1, =gBattleBufferB
	ldr r3, =gActiveBank
	ldrb r4, [r3]
	lsls r0, r4, 9
	adds r1, 0x2
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 1
	movs r1, 0x58
	muls r1, r4
	adds r0, r1
	adds r2, 0xC
	adds r0, r2
	ldrh r5, [r0]
	ldr r1, =gBattleStruct
	lsls r0, r4, 1
	adds r0, 0xC8
	ldr r1, [r1]
	adds r1, r0
	mov r8, r1
	ldr r1, =gDisableStructs
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x4]
	adds r7, r3, 0
	adds r3, r1, 0
	cmp r0, r5
	bne _0803FC06
	cmp r5, 0
	beq _0803FC06
	ldr r0, =gBattleScripting
	strb r4, [r0, 0x17]
	ldr r0, =gCurrentMove
	strh r5, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0803FBF8
	ldr r1, =gUnknown_02024230
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DAE2A
	str r1, [r0]
	ldr r0, =gProtectStructs
	ldrb r1, [r7]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	b _0803FC06
	.pool
_0803FBF8:
	ldr r0, =gUnknown_02024220
	ldrb r1, [r7]
	lsls r1, 2
	adds r1, r0
	ldr r0, =gUnknown_082DAE1F
	str r0, [r1]
	movs r6, 0x1
_0803FC06:
	ldr r1, =gUnknown_02024248
	ldrb r2, [r7]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r5, r0
	bne _0803FC90
	cmp r5, 0xA5
	beq _0803FC90
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bge _0803FC90
	adds r0, r2, 0
	bl CancelMultiTurnMoves
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0803FC7C
	ldr r1, =gUnknown_02024230
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB098
	str r1, [r0]
	ldr r0, =gProtectStructs
	ldrb r1, [r7]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	b _0803FC8E
	.pool
_0803FC7C:
	ldr r1, =gUnknown_02024220
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB089
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0803FC8E:
	ldr r3, =gDisableStructs
_0803FC90:
	ldrb r0, [r7]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r0, [r1, 0x13]
	lsls r0, 28
	cmp r0, 0
	beq _0803FD1A
	ldr r0, =gBattleMoves
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _0803FD1A
	ldr r0, =gCurrentMove
	strh r5, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0803FD08
	ldr r1, =gUnknown_02024230
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB0AF
	str r1, [r0]
	ldr r0, =gProtectStructs
	ldrb r1, [r7]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	b _0803FD1A
	.pool
_0803FD08:
	ldr r1, =gUnknown_02024220
	ldrb r0, [r7]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB0A0
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0803FD1A:
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	adds r1, r5, 0
	bl sub_8040130
	lsls r0, 24
	cmp r0, 0
	beq _0803FD8E
	ldr r0, =gCurrentMove
	strh r5, [r0]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0803FD7C
	ldr r1, =gUnknown_02024230
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB185
	str r1, [r0]
	ldr r0, =gProtectStructs
	ldrb r1, [r4]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	b _0803FD8E
	.pool
_0803FD7C:
	ldr r1, =gUnknown_02024220
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB181
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0803FD8E:
	ldr r1, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, r0, r1
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0803FDC4
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x7]
	b _0803FDCE
	.pool
_0803FDC4:
	ldrh r0, [r1, 0x2E]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
_0803FDCE:
	ldr r2, =gUnknown_0202420F
	ldr r1, =gActiveBank
	ldrb r0, [r1]
	strb r0, [r2]
	ldr r0, =gBattleMons
	mov r12, r0
	adds r7, r1, 0
	cmp r4, 0x1D
	bne _0803FE58
	mov r0, r8
	ldrh r1, [r0]
	adds r2, r1, 0
	cmp r2, 0
	beq _0803FE58
	ldr r0, =0x0000ffff
	cmp r2, r0
	beq _0803FE58
	cmp r2, r5
	beq _0803FE58
	ldr r0, =gCurrentMove
	strh r1, [r0]
	ldr r2, =gUnknown_02024208
	ldrb r1, [r7]
	movs r0, 0x58
	muls r0, r1
	add r0, r12
	ldrh r0, [r0, 0x2E]
	strh r0, [r2]
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 10
	ands r1, r0
	ldrb r2, [r7]
	cmp r1, 0
	beq _0803FE48
	ldr r0, =gProtectStructs
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	b _0803FE58
	.pool
_0803FE48:
	ldr r1, =gUnknown_02024220
	lsls r0, r2, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB812
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0803FE58:
	ldr r0, =gBattleBufferB
	ldrb r3, [r7]
	lsls r1, r3, 9
	adds r0, 0x2
	adds r1, r0
	movs r0, 0x58
	muls r0, r3
	ldrb r1, [r1]
	adds r0, r1
	mov r1, r12
	adds r1, 0x24
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803FEB8
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 10
	ands r0, r1
	cmp r0, 0
	beq _0803FEA8
	ldr r0, =gProtectStructs
	lsls r1, r3, 4
	adds r1, r0
	ldrb r0, [r1, 0x2]
	movs r2, 0x10
	orrs r0, r2
	strb r0, [r1, 0x2]
	b _0803FEB8
	.pool
_0803FEA8:
	ldr r1, =gUnknown_02024220
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB076
	str r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0803FEB8:
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_803FB4C

	thumb_func_start sub_803FECC
sub_803FECC: @ 803FECC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	lsrs r3, r2, 24
	ldr r1, =gBattleStruct
	lsls r0, r7, 1
	adds r0, 0xC8
	ldr r1, [r1]
	adds r1, r0
	str r1, [sp, 0x4]
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r1, r0, r1
	ldrh r0, [r1, 0x2E]
	cmp r0, 0xAF
	bne _0803FF1C
	ldr r2, =gEnigmaBerries
	lsls r1, r7, 3
	subs r0, r1, r7
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x7]
	str r0, [sp]
	b _0803FF2E
	.pool
_0803FF1C:
	ldrh r0, [r1, 0x2E]
	str r3, [sp, 0x14]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	lsls r1, r7, 3
	ldr r3, [sp, 0x14]
_0803FF2E:
	ldr r0, =gUnknown_0202420F
	strb r7, [r0]
	movs r0, 0
	mov r9, r0
	lsls r2, r7, 1
	str r2, [sp, 0xC]
	ldr r5, =gDisableStructs
	mov r12, r5
	ldr r0, =gBattleMons
	movs r2, 0x58
	adds r6, r7, 0
	muls r6, r2
	str r6, [sp, 0x8]
	ldr r2, =gUnknown_02024090
	adds r5, r6, r2
	movs r6, 0
	str r6, [sp, 0x10]
	mov r10, r0
	subs r0, r1, r7
	lsls r0, 2
	mov r8, r0
	ldr r6, =gBitTable
_0803FF5A:
	ldrh r0, [r5]
	cmp r0, 0
	bne _0803FF70
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0803FF70
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0803FF70:
	ldr r0, [sp, 0x8]
	add r0, r9
	mov r1, r10
	adds r1, 0x24
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _0803FF90
	movs r0, 0x2
	ands r0, r3
	cmp r0, 0
	beq _0803FF90
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0803FF90:
	mov r1, r8
	add r1, r12
	ldrh r0, [r5]
	ldrh r1, [r1, 0x4]
	cmp r0, r1
	bne _0803FFAC
	movs r0, 0x4
	ands r0, r3
	cmp r0, 0
	beq _0803FFAC
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0803FFAC:
	movs r0, 0x58
	adds r2, r7, 0
	muls r2, r0
	ldr r1, [sp, 0x10]
	adds r0, r1, r2
	ldr r1, =gUnknown_02024090
	adds r0, r1
	mov r12, r0
	ldr r1, =gUnknown_02024248
	ldr r0, [sp, 0xC]
	adds r1, r0, r1
	str r1, [sp, 0x18]
	mov r1, r12
	ldrh r1, [r1]
	mov r12, r1
	ldr r0, [sp, 0x18]
	ldrh r0, [r0]
	cmp r12, r0
	bne _0803FFEE
	movs r0, 0x8
	ands r0, r3
	cmp r0, 0
	beq _0803FFEE
	mov r0, r10
	adds r0, 0x50
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, 0
	bge _0803FFEE
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0803FFEE:
	ldr r0, =gDisableStructs
	add r0, r8
	ldrb r0, [r0, 0x13]
	lsls r0, 28
	cmp r0, 0
	beq _0804001C
	movs r0, 0x10
	ands r0, r3
	cmp r0, 0
	beq _0804001C
	ldr r2, =gBattleMoves
	ldrh r1, [r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _0804001C
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0804001C:
	ldrh r1, [r5]
	adds r0, r7, 0
	str r3, [sp, 0x14]
	bl sub_8040130
	lsls r0, 24
	ldr r3, [sp, 0x14]
	cmp r0, 0
	beq _0804003E
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _0804003E
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0804003E:
	ldr r1, =gDisableStructs
	mov r0, r8
	adds r2, r0, r1
	ldrb r0, [r2, 0xE]
	lsls r0, 28
	mov r12, r1
	cmp r0, 0
	beq _0804005E
	ldrh r0, [r2, 0x6]
	ldrh r1, [r5]
	cmp r0, r1
	beq _0804005E
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_0804005E:
	ldr r2, [sp]
	cmp r2, 0x1D
	bne _08040080
	ldr r0, [sp, 0x4]
	ldrh r1, [r0]
	cmp r1, 0
	beq _08040080
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _08040080
	ldrh r2, [r5]
	cmp r1, r2
	beq _08040080
	ldr r0, [r6]
	orrs r4, r0
	lsls r0, r4, 24
	lsrs r4, r0, 24
_08040080:
	adds r6, 0x4
	adds r5, 0x2
	ldr r0, [sp, 0x10]
	adds r0, 0x2
	str r0, [sp, 0x10]
	movs r1, 0x1
	add r9, r1
	mov r2, r9
	cmp r2, 0x3
	bgt _08040096
	b _0803FF5A
_08040096:
	adds r0, r4, 0
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_803FECC

	thumb_func_start sub_80400C8
sub_80400C8: @ 80400C8
	push {r4,lr}
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0xFF
	bl sub_803FECC
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0xF
	bne _0804010C
	ldr r0, =gProtectStructs
	ldrb r1, [r4]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r1, =gUnknown_02024220
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r1
	ldr r1, =gUnknown_082DB072
	str r1, [r0]
	b _0804011E
	.pool
_0804010C:
	ldr r0, =gProtectStructs
	ldrb r1, [r4]
	lsls r1, 4
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
_0804011E:
	movs r0, 0
	cmp r3, 0xF
	bne _08040126
	movs r0, 0x1
_08040126:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80400C8

	thumb_func_start sub_8040130
sub_8040130: @ 8040130
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	movs r6, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r6, r0
	bge _080401B4
	ldr r7, =gUnknown_02024090
	mov r8, r7
_0804015A:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	adds r3, r4, 0x1
	cmp r9, r0
	beq _080401AA
	ldr r1, =gStatuses3
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 6
	ands r0, r1
	cmp r0, 0
	beq _080401AA
	movs r2, 0
	movs r0, 0x58
	adds r1, r4, 0
	muls r1, r0
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r5, r0
	beq _080401A0
	mov r4, r8
	adds r0, r1, r4
_08040192:
	adds r0, 0x2
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080401AA
	ldrh r1, [r0]
	cmp r5, r1
	bne _08040192
_080401A0:
	cmp r2, 0x3
	bgt _080401AA
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080401AA:
	adds r4, r3, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0804015A
_080401B4:
	adds r0, r6, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8040130

	thumb_func_start sub_80401D0
sub_80401D0: @ 80401D0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	movs r0, 0
	mov r9, r0
	ldr r1, =gBankAttacker
	mov r2, r9
	strb r2, [r1]
	ldr r0, =gNoOfAllBanks
	ldrb r4, [r0]
	adds r6, r1, 0
	mov r10, r0
	ldr r7, =gBankTarget
	ldr r3, =gBattleStruct
	mov r12, r3
	cmp r9, r4
	bcs _08040224
	ldr r2, =gAbsentBankFlags
	ldrb r1, [r2]
	ldr r5, =gBitTable
	ldr r0, [r5]
	ands r1, r0
	cmp r1, 0
	beq _08040224
	adds r3, r6, 0
_08040206:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	bcs _08040224
	ldrb r0, [r2]
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _08040206
_08040224:
	movs r0, 0
	strb r0, [r7]
	mov r0, r10
	ldrb r4, [r0]
	cmp r4, 0
	beq _0804025E
	ldr r2, =gAbsentBankFlags
	ldrb r1, [r2]
	ldr r5, =gBitTable
	ldr r0, [r5]
	ands r1, r0
	cmp r1, 0
	beq _0804025E
	adds r3, r7, 0
_08040240:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r4
	bcs _0804025E
	ldrb r0, [r2]
	ldrb r1, [r7]
	lsls r1, 2
	adds r1, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, 0
	bne _08040240
_0804025E:
	mov r1, r12
	ldr r0, [r1]
	ldrb r0, [r0, 0x3]
	cmp r0, 0xA
	bls _0804026A
	b _080408F6
_0804026A:
	lsls r0, 2
	ldr r1, =_08040290
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08040290:
	.4byte _080402BC
	.4byte _08040342
	.4byte _08040408
	.4byte _080404D4
	.4byte _080405B0
	.4byte _08040668
	.4byte _0804071C
	.4byte _080407A0
	.4byte _08040810
	.4byte _08040868
	.4byte _080408EC
_080402BC:
	movs r5, 0
	ldr r1, =gNoOfAllBanks
	mov r10, r1
	ldrb r2, [r1]
	cmp r5, r2
	bge _080402D6
	ldr r2, =gTurnOrder
_080402CA:
	adds r0, r5, r2
	strb r5, [r0]
	adds r5, 0x1
	ldrb r3, [r1]
	cmp r5, r3
	blt _080402CA
_080402D6:
	movs r5, 0
	b _08040324
	.pool
_080402E4:
	adds r4, r5, 0x1
	adds r6, r4, 0
	ldrb r1, [r1]
	cmp r6, r1
	bge _08040322
	ldr r7, =gTurnOrder
	ldr r0, =gNoOfAllBanks
	mov r10, r0
	lsls r1, r5, 24
	mov r8, r1
_080402F8:
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r1, r4, r7
	ldrb r1, [r1]
	movs r2, 0
	bl b_first_side
	lsls r0, 24
	cmp r0, 0
	beq _08040318
	lsls r1, r4, 24
	lsrs r1, 24
	mov r2, r8
	lsrs r0, r2, 24
	bl sub_803CEDC
_08040318:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _080402F8
_08040322:
	adds r5, r6, 0
_08040324:
	mov r1, r10
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r5, r0
	blt _080402E4
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	ldrb r0, [r1, 0x3]
	adds r0, 0x1
	strb r0, [r1, 0x3]
	ldr r0, [r2]
	adds r0, 0xDB
	movs r1, 0
	strb r1, [r0]
	mov r12, r2
_08040342:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _08040350
	b _0804062C
_08040350:
	ldr r3, =gActiveBank
	mov r8, r3
	movs r7, 0
	ldr r6, =gBankAttacker
	ldr r5, =gBattleTextBuff1
_0804035A:
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r4, [r0]
	ldr r2, =gSideTimers
	lsls r1, r4, 1
	adds r0, r1, r4
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x1]
	strb r0, [r6]
	mov r3, r8
	strb r0, [r3]
	ldr r0, =gUnknown_0202428E
	adds r3, r1, r0
	ldrh r1, [r3]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080403BC
	ldrb r0, [r2]
	subs r0, 0x1
	strb r0, [r2]
	movs r4, 0xFF
	lsls r0, 24
	cmp r0, 0
	bne _080403BC
	ldrh r0, [r3]
	ldr r2, =0x0000fffe
	adds r1, r2, 0
	ands r0, r1
	strh r0, [r3]
	ldr r0, =gUnknown_082DACFA
	bl b_call_bc_move_exec
	movs r0, 0xFD
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, 0x1]
	movs r0, 0x73
	strb r0, [r5, 0x2]
	strb r7, [r5, 0x3]
	ldrb r0, [r5, 0x4]
	orrs r0, r4
	strb r0, [r5, 0x4]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080403BC:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0xDB
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r12, r2
	mov r3, r9
	cmp r3, 0
	beq _080403D2
	b _080408FE
_080403D2:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _0804035A
	b _0804062C
	.pool
_08040408:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _08040416
	b _08040570
_08040416:
	movs r0, 0x2
	mov r10, r0
	movs r2, 0
	mov r8, r2
	ldr r7, =gBankAttacker
	ldr r5, =gBattleTextBuff1
_08040422:
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r4, [r0]
	ldr r2, =gSideTimers
	lsls r1, r4, 1
	adds r0, r1, r4
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x3]
	strb r0, [r7]
	ldr r3, =gActiveBank
	strb r0, [r3]
	ldr r0, =gUnknown_0202428E
	adds r3, r1, r0
	ldrh r1, [r3]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0804048A
	ldrb r0, [r2, 0x2]
	subs r0, 0x1
	strb r0, [r2, 0x2]
	movs r6, 0xFF
	lsls r0, 24
	cmp r0, 0
	bne _0804048A
	ldrh r0, [r3]
	ldr r2, =0x0000fffd
	adds r1, r2, 0
	ands r0, r1
	strh r0, [r3]
	ldr r0, =gUnknown_082DACFA
	bl b_call_bc_move_exec
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	movs r0, 0xFD
	strb r0, [r5]
	mov r3, r10
	strb r3, [r5, 0x1]
	movs r0, 0x71
	strb r0, [r5, 0x2]
	mov r0, r8
	strb r0, [r5, 0x3]
	ldrb r0, [r5, 0x4]
	orrs r0, r6
	strb r0, [r5, 0x4]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0804048A:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0xDB
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r12, r2
	mov r1, r9
	cmp r1, 0
	beq _080404A0
	b _080408FE
_080404A0:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _08040422
	b _08040570
	.pool
_080404D4:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _08040570
	ldr r0, =gActiveBank
	mov r10, r0
	movs r2, 0
	mov r8, r2
	ldr r7, =gBankAttacker
	ldr r5, =gBattleTextBuff1
_080404EC:
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r4, [r0]
	ldr r1, =gSideTimers
	lsls r3, r4, 1
	adds r0, r3, r4
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x5]
	strb r0, [r7]
	mov r2, r10
	strb r0, [r2]
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _0804054E
	subs r0, 0x1
	strb r0, [r1, 0x4]
	movs r6, 0xFF
	lsls r0, 24
	cmp r0, 0
	bne _0804054E
	ldr r2, =gUnknown_0202428E
	adds r2, r3, r2
	ldrh r0, [r2]
	ldr r3, =0x0000feff
	adds r1, r3, 0
	ands r0, r1
	strh r0, [r2]
	ldr r0, =gUnknown_082DACFA
	bl b_call_bc_move_exec
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	movs r0, 0xFD
	strb r0, [r5]
	movs r0, 0x2
	strb r0, [r5, 0x1]
	movs r0, 0x36
	strb r0, [r5, 0x2]
	mov r0, r8
	strb r0, [r5, 0x3]
	ldrb r0, [r5, 0x4]
	orrs r0, r6
	strb r0, [r5, 0x4]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0804054E:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0xDB
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r12, r2
	mov r1, r9
	cmp r1, 0
	beq _08040564
	b _080408FE
_08040564:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _080404EC
_08040570:
	mov r2, r9
	cmp r2, 0
	beq _08040578
	b _080408FE
_08040578:
	mov r3, r12
	ldr r0, [r3]
	ldrb r1, [r0, 0x3]
	adds r1, 0x1
	strb r1, [r0, 0x3]
	ldr r0, [r3]
	adds r0, 0xDB
	strb r2, [r0]
	b _080408F6
	.pool
_080405B0:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bhi _0804062C
	ldr r6, =gActiveBank
	ldr r5, =gBankAttacker
_080405C0:
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r4, [r0]
	ldr r2, =gSideTimers
	lsls r1, r4, 1
	adds r0, r1, r4
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x7]
	strb r0, [r5]
	strb r0, [r6]
	ldr r0, =gUnknown_0202428E
	adds r3, r1, r0
	ldrh r1, [r3]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804060A
	ldrb r0, [r2, 0x6]
	subs r0, 0x1
	strb r0, [r2, 0x6]
	lsls r0, 24
	cmp r0, 0
	bne _0804060A
	ldrh r0, [r3]
	ldr r2, =0x0000ffdf
	adds r1, r2, 0
	ands r0, r1
	strh r0, [r3]
	ldr r0, =gUnknown_082DAD0B
	bl b_call_bc_move_exec
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_0804060A:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0xDB
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r12, r2
	mov r3, r9
	cmp r3, 0
	beq _08040620
	b _080408FE
_08040620:
	mov r1, r12
	ldr r0, [r1]
	adds r0, 0xDB
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _080405C0
_0804062C:
	mov r0, r9
	cmp r0, 0
	beq _08040634
	b _080408FE
_08040634:
	mov r1, r12
	ldr r0, [r1]
	ldrb r1, [r0, 0x3]
	adds r1, 0x1
	strb r1, [r0, 0x3]
	mov r2, r12
	ldr r0, [r2]
	adds r0, 0xDB
	mov r3, r9
	strb r3, [r0]
	b _080408F6
	.pool
_08040668:
	mov r2, r12
	ldr r0, [r2]
	adds r0, 0xDB
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcs _080406E8
	ldr r4, =gActiveBank
	ldr r5, =gTurnOrder
_0804067C:
	ldr r0, [r2]
	adds r0, 0xDB
	ldrb r0, [r0]
	adds r0, r5
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r0, =gUnknown_020243D0
	adds r0, 0x20
	ldrb r2, [r4]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0
	beq _080406C4
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _080406C4
	ldr r1, =gBattleMons
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _080406C4
	ldr r0, =gBankTarget
	strb r2, [r0]
	ldr r0, =gUnknown_082DB0B7
	bl b_call_bc_move_exec
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080406C4:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0xDB
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	mov r12, r2
	mov r3, r9
	cmp r3, 0
	beq _080406DA
	b _080408FE
_080406DA:
	ldr r0, [r2]
	adds r0, 0xDB
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _0804067C
_080406E8:
	mov r0, r9
	cmp r0, 0
	beq _080406F0
	b _080408FE
_080406F0:
	mov r2, r12
	ldr r1, [r2]
	ldrb r0, [r1, 0x3]
	adds r0, 0x1
	strb r0, [r1, 0x3]
	b _080408F6
	.pool
_0804071C:
	ldr r3, =gBattleWeather
	ldrh r2, [r3]
	movs r0, 0x7
	ands r0, r2
	cmp r0, 0
	bne _0804072A
	b _080408C8
_0804072A:
	movs r0, 0x4
	ands r0, r2
	cmp r0, 0
	bne _08040776
	ldr r1, =gUnknown_020243D0
	adds r1, 0x28
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _08040768
	ldr r0, =0x0000fffe
	ands r0, r2
	ldr r1, =0x0000fffd
	ands r0, r1
	strh r0, [r3]
	ldr r1, =gBattleCommunication
	movs r0, 0x2
	strb r0, [r1, 0x5]
	b _08040794
	.pool
_08040768:
	movs r0, 0x2
	ands r0, r2
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _08040782
	b _08040790
_08040776:
	movs r0, 0x2
	ands r0, r2
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _08040790
_08040782:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _08040794
	.pool
_08040790:
	ldr r0, =gBattleCommunication
	strb r1, [r0, 0x5]
_08040794:
	ldr r0, =gUnknown_082DAC2C
	b _080408BA
	.pool
_080407A0:
	ldr r3, =gBattleWeather
	ldrh r2, [r3]
	movs r0, 0x18
	ands r0, r2
	cmp r0, 0
	bne _080407AE
	b _080408C8
_080407AE:
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	bne _080407E8
	ldr r1, =gUnknown_020243D0
	adds r1, 0x28
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _080407E8
	ldr r0, =0x0000fff7
	ands r0, r2
	strh r0, [r3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DACC9
	b _080407EC
	.pool
_080407E8:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAC47
_080407EC:
	str r0, [r1]
	adds r3, r1, 0
	ldr r1, =gBattleScripting
	movs r2, 0
	movs r0, 0xC
	strb r0, [r1, 0x10]
	ldr r0, =gBattleCommunication
	strb r2, [r0, 0x5]
	b _080408B8
	.pool
_08040810:
	ldr r3, =gBattleWeather
	ldrh r2, [r3]
	movs r0, 0x60
	ands r0, r2
	cmp r0, 0
	beq _080408C8
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	bne _08040854
	ldr r1, =gUnknown_020243D0
	adds r1, 0x28
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _08040854
	ldr r0, =0x0000ffdf
	ands r0, r2
	strh r0, [r3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DACE0
	b _08040858
	.pool
_08040854:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DACD2
_08040858:
	str r0, [r1]
	adds r3, r1, 0
	b _080408B8
	.pool
_08040868:
	ldr r3, =gBattleWeather
	ldrh r2, [r3]
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _080408C8
	ldr r1, =gUnknown_020243D0
	adds r1, 0x28
	ldrb r0, [r1]
	subs r0, 0x1
	strb r0, [r1]
	lsls r0, 24
	cmp r0, 0
	bne _080408A4
	ldr r0, =0x0000ff7f
	ands r0, r2
	strh r0, [r3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DACC9
	b _080408A8
	.pool
_080408A4:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAC47
_080408A8:
	str r0, [r1]
	adds r3, r1, 0
	ldr r1, =gBattleScripting
	movs r0, 0xD
	strb r0, [r1, 0x10]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
_080408B8:
	ldr r0, [r3]
_080408BA:
	bl b_call_bc_move_exec
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080408C8:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	ldrb r0, [r1, 0x3]
	adds r0, 0x1
	strb r0, [r1, 0x3]
	mov r12, r2
	b _080408F6
	.pool
_080408EC:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080408F6:
	mov r3, r9
	cmp r3, 0
	bne _080408FE
	b _0804025E
_080408FE:
	ldr r0, =gUnknown_03005D04
	ldr r1, [r0]
	ldr r0, =sub_803B9BC
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80401D0

	thumb_func_start sub_8040924
sub_8040924: @ 8040924
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	movs r0, 0
	mov r9, r0
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0x01000020
	orrs r0, r1
	str r0, [r2]
	ldr r5, =gBattleStruct
	ldr r2, [r5]
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r2, 0x1]
	adds r7, r5, 0
	mov r8, r0
	ldrb r3, [r0]
	cmp r1, r3
	bcc _08040954
	bl _08041338
_08040954:
	bl _0804132E
	.pool
_08040968:
	ldr r3, =gActiveBank
	ldr r4, =gBankAttacker
	ldr r1, =gTurnOrder
	ldr r5, [r5]
	ldrb r0, [r5, 0x1]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4]
	strb r0, [r3]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r3]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	adds r6, r3, 0
	cmp r1, 0
	beq _080409B0
	ldrb r0, [r5, 0x1]
	adds r0, 0x1
	strb r0, [r5, 0x1]
	bl _0804131C
	.pool
_080409B0:
	ldrb r0, [r5]
	cmp r0, 0x13
	bls _080409BA
	bl _08041312
_080409BA:
	lsls r0, 2
	ldr r1, =_080409C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080409C8:
	.4byte _08040A18
	.4byte _08040A78
	.4byte _08040A96
	.4byte _08040AC6
	.4byte _08040B44
	.4byte _08040B8C
	.4byte _08040C0C
	.4byte _08040C54
	.4byte _08040CB8
	.4byte _08040D00
	.4byte _08040E60
	.4byte _08040F7C
	.4byte _08041024
	.4byte _080410E8
	.4byte _0804119C
	.4byte _080411BC
	.4byte _08041208
	.4byte _08041238
	.4byte _08040AAE
	.4byte _08041304
_08040A18:
	ldr r1, =gStatuses3
	ldrb r3, [r6]
	lsls r0, r3, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 3
	ands r0, r1
	cmp r0, 0
	bne _08040A30
	bl _080412DE
_08040A30:
	ldr r0, =gBattleMons
	movs r1, 0x58
	muls r1, r3
	adds r0, r1, r0
	ldrh r2, [r0, 0x28]
	ldrh r5, [r0, 0x2C]
	cmp r2, r5
	bne _08040A44
	bl _080412DE
_08040A44:
	cmp r2, 0
	bne _08040A4C
	bl _080412DE
_08040A4C:
	ldr r1, =gBattleMoveDamage
	ldrh r0, [r0, 0x2C]
	lsrs r0, 4
	str r0, [r1]
	cmp r0, 0
	bne _08040A5C
	movs r0, 0x1
	str r0, [r1]
_08040A5C:
	ldr r0, [r1]
	negs r0, r0
	str r0, [r1]
	ldr r0, =gUnknown_082DB0EE
	bl _080412D0
	.pool
_08040A78:
	ldrb r1, [r6]
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08040A92
	bl _080412DE
_08040A92:
	bl _080412D4
_08040A96:
	ldrb r1, [r6]
	movs r0, 0x1
	movs r2, 0
	bl berry_effects_maybe
	lsls r0, 24
	cmp r0, 0
	bne _08040AAA
	bl _080412DE
_08040AAA:
	bl _080412D4
_08040AAE:
	ldrb r1, [r6]
	movs r0, 0x1
	movs r2, 0x1
	bl berry_effects_maybe
	lsls r0, 24
	cmp r0, 0
	bne _08040AC2
	bl _080412DE
_08040AC2:
	bl _080412D4
_08040AC6:
	ldr r0, =gStatuses3
	ldrb r2, [r6]
	lsls r1, r2, 2
	adds r1, r0
	ldr r1, [r1]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08040ADC
	bl _080412DE
_08040ADC:
	ldr r3, =gBattleMons
	movs r5, 0x3
	ands r5, r1
	movs r1, 0x58
	adds r0, r5, 0
	muls r0, r1
	adds r0, r3
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08040AF4
	bl _080412DE
_08040AF4:
	adds r0, r2, 0
	muls r0, r1
	adds r0, r3
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08040B04
	bl _080412DE
_08040B04:
	ldr r0, =gBankTarget
	strb r5, [r0]
	ldr r2, =gBattleMoveDamage
	ldrb r0, [r6]
	muls r0, r1
	adds r0, r3
	ldrh r0, [r0, 0x2C]
	lsrs r0, 3
	str r0, [r2]
	cmp r0, 0
	bne _08040B1E
	movs r0, 0x1
	str r0, [r2]
_08040B1E:
	ldr r1, =gBattleScripting
	strb r5, [r1, 0x10]
	ldrb r0, [r4]
	strb r0, [r1, 0x11]
	ldr r0, =gUnknown_082DAD15
	b _080412D0
	.pool
_08040B44:
	ldr r2, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	adds r3, r1, 0
	muls r3, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	bne _08040B60
	b _080412DE
_08040B60:
	adds r1, r3, r2
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	bne _08040B6A
	b _080412DE
_08040B6A:
	ldr r2, =gBattleMoveDamage
	ldrh r0, [r1, 0x2C]
	lsrs r0, 3
	str r0, [r2]
	cmp r0, 0
	bne _08040B7A
	movs r0, 0x1
	str r0, [r2]
_08040B7A:
	ldr r0, =gUnknown_082DB23D
	b _080412D0
	.pool
_08040B8C:
	ldr r4, =gBattleMons
	ldrb r0, [r6]
	movs r7, 0x58
	mov r8, r7
	mov r2, r8
	muls r2, r0
	adds r3, r4, 0
	adds r3, 0x4C
	adds r0, r2, r3
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08040BAA
	b _080412DE
_08040BAA:
	adds r1, r2, r4
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	bne _08040BB4
	b _080412DE
_08040BB4:
	ldr r5, =gBattleMoveDamage
	ldrh r0, [r1, 0x2C]
	lsrs r0, 4
	str r0, [r5]
	cmp r0, 0
	bne _08040BC4
	movs r0, 0x1
	str r0, [r5]
_08040BC4:
	ldrb r0, [r6]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r2, r0, r3
	ldr r1, [r2]
	movs r4, 0xF0
	lsls r4, 4
	adds r0, r1, 0
	ands r0, r4
	cmp r0, r4
	beq _08040BE4
	movs r7, 0x80
	lsls r7, 1
	adds r0, r1, r7
	str r0, [r2]
_08040BE4:
	ldrb r0, [r6]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r3
	ldr r0, [r0]
	ands r0, r4
	lsrs r0, 8
	ldr r1, [r5]
	muls r0, r1
	str r0, [r5]
	ldr r0, =gUnknown_082DB23D
	b _080412D0
	.pool
_08040C0C:
	ldr r2, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	adds r3, r1, 0
	muls r3, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	bne _08040C28
	b _080412DE
_08040C28:
	adds r1, r3, r2
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	bne _08040C32
	b _080412DE
_08040C32:
	ldr r2, =gBattleMoveDamage
	ldrh r0, [r1, 0x2C]
	lsrs r0, 3
	str r0, [r2]
	cmp r0, 0
	bne _08040C42
	movs r0, 0x1
	str r0, [r2]
_08040C42:
	ldr r0, =gUnknown_082DB25F
	b _080412D0
	.pool
_08040C54:
	ldr r4, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	muls r1, r0
	adds r0, r4, 0
	adds r0, 0x50
	adds r5, r1, r0
	ldr r2, [r5]
	movs r0, 0x80
	lsls r0, 20
	ands r0, r2
	cmp r0, 0
	bne _08040C70
	b _080412DE
_08040C70:
	adds r3, r1, r4
	ldrh r0, [r3, 0x28]
	cmp r0, 0
	bne _08040C7A
	b _080412DE
_08040C7A:
	adds r0, r4, 0
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08040CAC
	ldr r1, =gBattleMoveDamage
	ldrh r0, [r3, 0x2C]
	lsrs r0, 2
	str r0, [r1]
	cmp r0, 0
	bne _08040C9A
	movs r0, 0x1
	str r0, [r1]
_08040C9A:
	ldr r0, =gUnknown_082DB33F
	b _080412D0
	.pool
_08040CAC:
	ldr r0, =0xf7ffffff
	ands r2, r0
	str r2, [r5]
	b _080412DE
	.pool
_08040CB8:
	ldr r2, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	adds r3, r1, 0
	muls r3, r0
	adds r0, r2, 0
	adds r0, 0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 21
	ands r0, r1
	cmp r0, 0
	bne _08040CD6
	b _080412DE
_08040CD6:
	adds r1, r3, r2
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	bne _08040CE0
	b _080412DE
_08040CE0:
	ldr r2, =gBattleMoveDamage
	ldrh r0, [r1, 0x2C]
	lsrs r0, 2
	str r0, [r2]
	cmp r0, 0
	bne _08040CF0
	movs r0, 0x1
	str r0, [r2]
_08040CF0:
	ldr r0, =gUnknown_082DB350
	b _080412D0
	.pool
_08040D00:
	ldr r3, =gBattleMons
	mov r8, r3
	ldrb r0, [r6]
	movs r3, 0x58
	adds r1, r0, 0
	muls r1, r3
	movs r5, 0x50
	add r5, r8
	mov r10, r5
	adds r4, r1, r5
	ldr r2, [r4]
	movs r5, 0xE0
	lsls r5, 8
	adds r0, r2, 0
	ands r0, r5
	cmp r0, 0
	bne _08040D24
	b _080412DE
_08040D24:
	mov r7, r8
	adds r0, r1, r7
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08040D30
	b _080412DE
_08040D30:
	ldr r1, =0xffffe000
	adds r0, r2, r1
	str r0, [r4]
	ldrb r4, [r6]
	adds r0, r4, 0
	muls r0, r3
	add r0, r10
	ldr r0, [r0]
	ands r0, r5
	cmp r0, 0
	beq _08040DC0
	ldr r1, =gBattleScripting
	ldr r0, =gBattleStruct
	ldr r2, [r0]
	lsls r0, r4, 1
	adds r0, r2
	ldrb r0, [r0, 0x4]
	strb r0, [r1, 0x10]
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0, 0x5]
	strb r0, [r1, 0x11]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0, 0x4]
	strb r0, [r1, 0x2]
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0, 0x5]
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB30E
	str r0, [r1]
	ldr r2, =gBattleMoveDamage
	ldrb r0, [r6]
	muls r0, r3
	add r0, r8
	ldrh r0, [r0, 0x2C]
	lsrs r0, 4
	str r0, [r2]
	cmp r0, 0
	bne _08040DEC
	movs r0, 0x1
	str r0, [r2]
	b _08040DEC
	.pool
_08040DC0:
	ldr r2, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r2]
	movs r0, 0x2
	strb r0, [r2, 0x1]
	ldrb r1, [r6]
	ldr r0, =gBattleStruct
	ldr r3, [r0]
	lsls r1, 1
	adds r1, r3
	ldrb r0, [r1, 0x4]
	strb r0, [r2, 0x2]
	ldrb r0, [r6]
	lsls r0, 1
	adds r0, r3
	ldrb r0, [r0, 0x5]
	strb r0, [r2, 0x3]
	movs r0, 0xFF
	strb r0, [r2, 0x4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB320
	str r0, [r1]
_08040DEC:
	ldr r0, [r1]
	b _080412D0
	.pool
_08040E00:
	movs r0, 0x8
	negs r0, r0
	ands r3, r0
	str r3, [r2]
	ldrb r0, [r6]
	mov r2, r8
	muls r2, r0
	mov r0, r10
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_082DB234
	bl b_call_bc_move_exec
	ldr r4, =gActiveBank
	ldrb r0, [r6]
	strb r0, [r4]
	ldrb r0, [r4]
	mov r3, r8
	muls r3, r0
	adds r0, r3, 0
	add r0, r9
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _08040EC8
	.pool
_08040E60:
	ldr r2, =gBattleMons
	ldrb r1, [r6]
	movs r0, 0x58
	muls r0, r1
	adds r1, r2, 0
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x70
	ands r1, r0
	adds r7, r2, 0
	cmp r1, 0
	beq _08040F6A
	movs r0, 0
	strb r0, [r4]
	mov r5, r8
	ldrb r0, [r5]
	cmp r0, 0
	beq _08040EC8
	mov r10, r7
	adds r6, r4, 0
	movs r1, 0x58
	mov r8, r1
	movs r3, 0x4C
	adds r3, r7
	mov r9, r3
	str r0, [sp, 0x4]
	movs r5, 0x7
	mov r12, r5
_08040E9A:
	ldrb r4, [r6]
	mov r1, r8
	muls r1, r4
	mov r0, r9
	adds r2, r1, r0
	ldr r3, [r2]
	adds r0, r3, 0
	mov r5, r12
	ands r0, r5
	cmp r0, 0
	beq _08040EBA
	adds r0, r1, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x2B
	bne _08040E00
_08040EBA:
	adds r0, r4, 0x1
	strb r0, [r6]
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp, 0x4]
	cmp r0, r1
	bcc _08040E9A
_08040EC8:
	ldr r2, =gBankAttacker
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08040EE8
	movs r3, 0x2
	mov r9, r3
	b _08041318
	.pool
_08040EE8:
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	strb r0, [r2]
	ldr r2, =gBattleMons
	ldrb r0, [r5]
	movs r7, 0x58
	adds r1, r0, 0
	muls r1, r7
	adds r6, r2, 0
	adds r6, 0x50
	adds r1, r6
	ldr r0, [r1]
	subs r0, 0x10
	str r0, [r1]
	ldrb r0, [r5]
	bl sub_803F90C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _08040F2C
	ldrb r0, [r5]
	bl CancelMultiTurnMoves
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	b _08040F60
	.pool
_08040F2C:
	ldrb r3, [r5]
	adds r0, r3, 0
	muls r0, r7
	adds r2, r0, r6
	ldr r0, [r2]
	movs r1, 0x70
	ands r0, r1
	cmp r0, 0
	beq _08040F54
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 5
	orrs r0, r1
	str r0, [r2]
	b _08040F60
	.pool
_08040F54:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	adds r0, r3, 0
	bl CancelMultiTurnMoves
_08040F60:
	ldr r0, =gUnknown_082DB2A6
	bl b_call_bc_move_exec
	movs r5, 0x1
	mov r9, r5
_08040F6A:
	mov r7, r9
	cmp r7, 0x2
	bne _08040F72
	b _08041312
_08040F72:
	b _080412DE
	.pool
_08040F7C:
	ldr r1, =gBattleMons
	ldrb r0, [r6]
	movs r7, 0x58
	muls r0, r7
	adds r5, r1, 0
	adds r5, 0x50
	adds r2, r0, r5
	ldr r1, [r2]
	movs r4, 0xC0
	lsls r4, 4
	adds r0, r1, 0
	ands r0, r4
	cmp r0, 0
	bne _08040F9A
	b _080412DE
_08040F9A:
	ldr r3, =0xfffffc00
	adds r0, r1, r3
	str r0, [r2]
	ldrb r0, [r6]
	bl sub_803F90C
	lsls r0, 24
	cmp r0, 0
	beq _08040FBC
	ldrb r0, [r6]
	bl CancelMultiTurnMoves
	b _080412DE
	.pool
_08040FBC:
	ldrb r0, [r6]
	muls r0, r7
	adds r2, r0, r5
	ldr r1, [r2]
	adds r0, r1, 0
	ands r0, r4
	cmp r0, 0
	beq _08040FCE
	b _080412DE
_08040FCE:
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	bne _08040FDA
	b _080412DE
_08040FDA:
	ldr r0, =0xffffefff
	ands r1, r0
	str r1, [r2]
	ldrb r0, [r6]
	muls r0, r7
	adds r0, r5
	ldr r0, [r0]
	movs r4, 0x7
	ands r0, r4
	cmp r0, 0
	beq _08040FF2
	b _080412DE
_08040FF2:
	ldr r1, =gBattleCommunication
	movs r0, 0x47
	strb r0, [r1, 0x3]
	movs r0, 0x1
	movs r1, 0
	bl sub_8048760
	ldrb r0, [r6]
	muls r0, r7
	adds r0, r5
	ldr r0, [r0]
	ands r0, r4
	cmp r0, 0
	bne _08041010
	b _080412D4
_08041010:
	ldr r0, =gUnknown_082DB2AF
	bl b_call_bc_move_exec
	b _080412D4
	.pool
_08041024:
	ldr r0, =gDisableStructs
	ldrb r3, [r6]
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r5, r1, r0
	ldrb r1, [r5, 0xB]
	lsls r1, 28
	adds r7, r0, 0
	cmp r1, 0
	bne _0804103C
	b _080412DE
_0804103C:
	movs r4, 0
	ldr r2, =gBattleMons
	movs r0, 0x58
	adds r1, r3, 0
	muls r1, r0
	adds r2, 0xC
	adds r1, r2
	ldrh r0, [r5, 0x4]
	ldrh r1, [r1]
	cmp r0, r1
	beq _0804107A
	mov r12, r7
	mov r8, r2
	adds r5, r6, 0
	movs r3, 0x58
_0804105A:
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0804107A
	ldrb r2, [r5]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	add r1, r12
	lsls r0, r4, 1
	muls r2, r3
	adds r0, r2
	add r0, r8
	ldrh r1, [r1, 0x4]
	ldrh r0, [r0]
	cmp r1, r0
	bne _0804105A
_0804107A:
	cmp r4, 0x4
	bne _080410AC
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r7
	movs r1, 0
	strh r1, [r0, 0x4]
	ldrb r0, [r6]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0xB]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0xB]
	b _080412DE
	.pool
_080410AC:
	ldrb r0, [r6]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r2, r7
	ldrb r3, [r2, 0xB]
	lsls r1, r3, 28
	lsrs r1, 28
	subs r1, 0x1
	movs r0, 0xF
	ands r1, r0
	movs r0, 0x10
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0xB]
	adds r2, r1, 0
	cmp r2, 0
	beq _080410D4
	b _080412DE
_080410D4:
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r7
	strh r2, [r0, 0x4]
	ldr r0, =gUnknown_082DAE23
	b _080412D0
	.pool
_080410E8:
	ldr r3, =gDisableStructs
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r2, r0, r3
	ldrb r5, [r2, 0xE]
	lsls r4, r5, 28
	cmp r4, 0
	bne _080410FE
	b _080412DE
_080410FE:
	ldr r7, =gBattleMons
	mov r8, r7
	ldrb r0, [r2, 0xC]
	lsls r0, 1
	movs r7, 0x58
	muls r1, r7
	adds r0, r1
	mov r1, r8
	adds r1, 0xC
	adds r0, r1
	ldrh r0, [r0]
	ldrh r1, [r2, 0x6]
	cmp r0, r1
	beq _0804113C
	movs r0, 0
	strh r0, [r2, 0x6]
	ldrb r0, [r6]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1, 0xE]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0xE]
	b _080412DE
	.pool
_0804113C:
	lsrs r1, r4, 28
	subs r1, 0x1
	movs r0, 0xF
	ands r1, r0
	movs r4, 0x10
	negs r4, r4
	adds r0, r4, 0
	ands r0, r5
	orrs r0, r1
	strb r0, [r2, 0xE]
	cmp r1, 0
	beq _08041172
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r3
	muls r1, r7
	ldrb r0, [r0, 0xC]
	adds r1, r0
	mov r0, r8
	adds r0, 0x24
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0
	beq _08041172
	b _080412DE
_08041172:
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x6]
	ldrb r0, [r6]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r1, 0xE]
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0xE]
	ldr r0, =gUnknown_082DAE37
	b _080412D0
	.pool
_0804119C:
	ldr r0, =gStatuses3
	ldrb r1, [r6]
	lsls r1, 2
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x18
	ands r0, r2
	cmp r0, 0
	beq _080411B4
	adds r0, r2, 0
	subs r0, 0x8
	str r0, [r1]
_080411B4:
	ldr r1, [r7]
	b _080412E2
	.pool
_080411BC:
	ldr r2, =gDisableStructs
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r3, r0, r2
	ldrb r2, [r3, 0x12]
	lsls r1, r2, 28
	cmp r1, 0
	beq _080411F6
	lsrs r1, 28
	subs r1, 0x1
	movs r0, 0xF
	ands r1, r0
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x12]
	cmp r1, 0
	bne _080411F6
	ldr r0, =gStatuses3
	ldrb r2, [r6]
	lsls r2, 2
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xfffffdff
	ands r0, r1
	str r0, [r2]
_080411F6:
	ldr r1, [r7]
	b _080412E2
	.pool
_08041208:
	ldr r2, =gDisableStructs
	ldrb r1, [r6]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r3, r0, r2
	ldrb r2, [r3, 0x13]
	lsls r1, r2, 28
	cmp r1, 0
	beq _0804122E
	lsrs r1, 28
	subs r1, 0x1
	movs r0, 0xF
	ands r1, r0
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x13]
_0804122E:
	ldr r1, [r7]
	b _080412E2
	.pool
_08041238:
	ldr r4, =gStatuses3
	ldrb r0, [r6]
	lsls r0, 2
	adds r2, r0, r4
	ldr r1, [r2]
	movs r3, 0xC0
	lsls r3, 5
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _080412DE
	ldr r5, =0xfffff800
	adds r0, r1, r5
	str r0, [r2]
	ldrb r2, [r6]
	lsls r0, r2, 2
	adds r0, r4
	ldr r0, [r0]
	ands r0, r3
	cmp r0, 0
	bne _080412DE
	ldr r3, =gBattleMons
	movs r5, 0x58
	adds r1, r2, 0
	muls r1, r5
	adds r4, r3, 0
	adds r4, 0x4C
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, 0
	bne _080412DE
	adds r0, r1, r3
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x48
	beq _080412DE
	cmp r0, 0xF
	beq _080412DE
	adds r0, r2, 0
	bl sub_8050650
	lsls r0, 24
	cmp r0, 0
	bne _080412DE
	ldrb r0, [r6]
	bl CancelMultiTurnMoves
	bl Random
	ldrb r1, [r6]
	adds r2, r1, 0
	muls r2, r5
	adds r2, r4
	movs r1, 0x3
	ands r1, r0
	adds r1, 0x2
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldrb r0, [r6]
	muls r0, r5
	adds r0, r4
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r6]
	bl dp01_battle_side_mark_buffer_for_execution
	ldr r1, =gUnknown_0202420E
	ldrb r0, [r6]
	strb r0, [r1]
	ldr r0, =gUnknown_082DB378
_080412D0:
	bl b_call_bc_move_exec
_080412D4:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080412DE:
	ldr r0, =gBattleStruct
	ldr r1, [r0]
_080412E2:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08041312
	.pool
_08041304:
	ldr r1, [r7]
	movs r0, 0
	strb r0, [r1]
	ldr r1, [r7]
	ldrb r0, [r1, 0x1]
	adds r0, 0x1
	strb r0, [r1, 0x1]
_08041312:
	mov r7, r9
	cmp r7, 0
	beq _0804131C
_08041318:
	mov r0, r9
	b _08041344
_0804131C:
	ldr r5, =gBattleStruct
	ldr r2, [r5]
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r2, 0x1]
	adds r7, r5, 0
	mov r8, r0
	ldrb r0, [r0]
	cmp r1, r0
	bcs _08041338
_0804132E:
	ldrb r0, [r2]
	cmp r0, 0x13
	bhi _08041338
	bl _08040968
_08041338:
	ldr r0, =gHitMarker
	ldr r1, [r0]
	ldr r2, =0xfeffffdf
	ands r1, r2
	str r1, [r0]
	movs r0, 0
_08041344:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8040924

	thumb_func_start sub_8041364
sub_8041364: @ 8041364
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r2, =gHitMarker
	ldr r0, [r2]
	ldr r1, =0x01000020
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gBattleStruct
	ldr r3, [r1]
	movs r4, 0xD0
	lsls r4, 1
	adds r0, r3, r4
	ldrb r0, [r0]
	mov r10, r2
	adds r6, r1, 0
	cmp r0, 0x1
	bne _0804138E
	b _08041548
_0804138E:
	cmp r0, 0x1
	bgt _080413A4
	cmp r0, 0
	beq _080413AC
	b _08041708
	.pool
_080413A4:
	cmp r0, 0x2
	bne _080413AA
	b _0804169A
_080413AA:
	b _08041708
_080413AC:
	ldr r2, =0x000001a1
	adds r0, r3, r2
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	mov r8, r1
	ldrb r7, [r1]
	cmp r0, r7
	bcc _080413BE
	b _08041532
_080413BE:
	ldr r4, =gActiveBank
	ldr r5, =gBattleTextBuff1
	ldr r7, =gUnknown_020243D0
	movs r0, 0x18
	adds r0, r7
	mov r12, r0
_080413CA:
	ldr r0, [r6]
	adds r3, r0, r2
	ldrb r0, [r3]
	strb r0, [r4]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _0804140C
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	b _08041520
	.pool
_0804140C:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	ldr r1, =gUnknown_020243D0
	ldrb r0, [r4]
	adds r2, r0, r1
	ldrb r0, [r2]
	mov r9, r1
	cmp r0, 0
	bne _08041422
	b _08041520
_08041422:
	subs r0, 0x1
	strb r0, [r2]
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	bne _08041520
	ldr r1, =gBattleMons
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08041520
	lsls r0, r2, 1
	add r0, r12
	ldrh r0, [r0]
	cmp r0, 0xF8
	bne _0804145C
	ldr r0, =gBattleCommunication
	strb r3, [r0, 0x5]
	b _08041462
	.pool
_0804145C:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
_08041462:
	movs r0, 0xFD
	strb r0, [r5]
	movs r6, 0x2
	movs r0, 0x2
	strb r0, [r5, 0x1]
	ldrb r0, [r4]
	lsls r0, 1
	add r0, r12
	ldrh r0, [r0]
	strb r0, [r5, 0x2]
	ldrb r0, [r4]
	lsls r0, 1
	add r0, r12
	ldrh r0, [r0]
	lsrs r0, 8
	strb r0, [r5, 0x3]
	movs r0, 0xFF
	strb r0, [r5, 0x4]
	ldr r5, =gBankTarget
	ldrb r0, [r4]
	strb r0, [r5]
	ldr r1, =gBankAttacker
	adds r0, r7, 0x4
	ldrb r2, [r4]
	adds r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r2, =gBattleMoveDamage
	ldrb r0, [r4]
	lsls r0, 2
	adds r1, r7, 0
	adds r1, 0x8
	adds r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r2, =gSpecialStatuses
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, 0x4
	adds r0, r2
	ldr r1, =0x0000ffff
	str r1, [r0]
	ldr r0, =gUnknown_082DAFE4
	bl b_call_bc_move_exec
	ldrb r1, [r4]
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _080414CC
	b _08041664
_080414CC:
	eors r1, r6
	mov r3, r9
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, 0
	beq _080414DA
	b _08041664
_080414DA:
	ldrb r0, [r5]
	bl GetBankIdentity
	ldr r2, =gUnknown_0202428E
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	ands r0, r1
	lsls r0, 1
	adds r0, r2
	ldrh r1, [r0]
	ldr r4, =0x0000ffbf
	adds r2, r4, 0
	ands r1, r2
	strh r1, [r0]
	b _08041664
	.pool
_08041520:
	ldr r0, [r6]
	ldr r2, =0x000001a1
	adds r0, r2
	ldrb r0, [r0]
	mov r1, r8
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08041532
	b _080413CA
_08041532:
	ldr r0, [r6]
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r2
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r6]
	ldr r3, =0x000001a1
	adds r1, r0, r3
	movs r0, 0
	strb r0, [r1]
_08041548:
	adds r3, r6, 0
	ldr r0, [r6]
	ldr r2, =0x000001a1
	adds r0, r2
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r0]
	mov r8, r1
	ldrb r4, [r1]
	cmp r0, r4
	bcc _0804155E
	b _08041684
_0804155E:
	ldr r5, =gActiveBank
	ldr r4, =gBattleTextBuff1
	ldr r7, =gDisableStructs
	mov r12, r7
	ldr r0, =gBankAttacker
	mov r9, r0
_0804156A:
	ldr r1, =gTurnOrder
	ldr r0, [r3]
	adds r3, r0, r2
	ldrb r0, [r3]
	adds r0, r1
	ldrb r0, [r0]
	mov r1, r9
	strb r0, [r1]
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
	beq _080415BC
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	b _08041670
	.pool
_080415BC:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	ldr r7, =gStatuses3
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r7
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08041670
	movs r0, 0xFD
	strb r0, [r4]
	movs r0, 0x1
	strb r0, [r4, 0x1]
	strb r0, [r4, 0x2]
	strb r0, [r4, 0x3]
	ldrb r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	add r0, r12
	ldrb r0, [r0, 0xF]
	lsls r0, 28
	lsrs r0, 28
	strb r0, [r4, 0x4]
	movs r0, 0xFF
	strb r0, [r4, 0x5]
	ldrb r2, [r5]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	mov r3, r12
	adds r4, r0, r3
	ldrb r3, [r4, 0xF]
	lsls r1, r3, 28
	cmp r1, 0
	bne _08041644
	lsls r2, 2
	adds r2, r7
	ldr r0, [r2]
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	str r0, [r2]
	ldr r3, =gBattleMoveDamage
	ldr r2, =gBattleMons
	ldrb r1, [r5]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x28]
	str r0, [r3]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAF05
	b _0804165C
	.pool
_08041644:
	lsrs r1, 28
	subs r1, 0x1
	movs r0, 0xF
	ands r1, r0
	movs r7, 0x10
	negs r7, r7
	adds r0, r7, 0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4, 0xF]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAF20
_0804165C:
	str r0, [r1]
	ldr r0, [r1]
	bl b_call_bc_move_exec
_08041664:
	movs r0, 0x1
	b _08041714
	.pool
_08041670:
	adds r3, r6, 0
	ldr r0, [r6]
	ldr r2, =0x000001a1
	adds r0, r2
	ldrb r0, [r0]
	mov r1, r8
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08041684
	b _0804156A
_08041684:
	ldr r0, [r6]
	movs r2, 0xD0
	lsls r2, 1
	adds r0, r2
	movs r1, 0x2
	strb r1, [r0]
	ldr r0, [r6]
	ldr r3, =0x000001a1
	adds r1, r0, r3
	movs r0, 0
	strb r0, [r1]
_0804169A:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	beq _08041708
	ldr r0, [r6]
	adds r0, 0xDA
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _08041708
	ldr r1, =gBattleMons
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	beq _08041708
	adds r0, r1, 0
	adds r0, 0x80
	ldrh r0, [r0]
	cmp r0, 0
	beq _08041708
	movs r4, 0
_080416C6:
	lsls r0, r4, 24
	lsrs r0, 24
	bl CancelMultiTurnMoves
	adds r4, 0x1
	cmp r4, 0x1
	ble _080416C6
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB8F3
	str r0, [r1]
	bl b_call_bc_move_exec
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	movs r4, 0xD0
	lsls r4, 1
	adds r1, r4
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08041664
	.pool
_08041708:
	mov r7, r10
	ldr r0, [r7]
	ldr r1, =0xfeffffdf
	ands r0, r1
	str r0, [r7]
	movs r0, 0
_08041714:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8041364

	thumb_func_start sub_8041728
sub_8041728: @ 8041728
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08041770
	b _08041A0A
	.pool
_08041744:
	ldr r0, =gUnknown_082DA7C4
	bl b_call_bc_move_exec
	ldr r0, [r5]
	adds r0, 0x4D
	movs r1, 0x2
	b _08041764
	.pool
_08041758:
	ldr r0, =gUnknown_082DA7CD
	bl b_call_bc_move_exec
	ldr r0, [r5]
	adds r0, 0x4D
	movs r1, 0x5
_08041764:
	strb r1, [r0]
_08041766:
	movs r0, 0x1
	b _08041A0C
	.pool
_08041770:
	ldr r0, =gBattleStruct
	mov r8, r0
_08041774:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x4D
	ldrb r0, [r0]
	cmp r0, 0x7
	bls _08041782
	b _080419FC
_08041782:
	lsls r0, 2
	ldr r1, =_08041794
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08041794:
	.4byte _080417B4
	.4byte _08041806
	.4byte _080418A0
	.4byte _080418E2
	.4byte _080418F6
	.4byte _08041960
	.4byte _08041994
	.4byte _080419FC
_080417B4:
	mov r4, r8
	ldr r0, [r4]
	adds r0, 0x4E
	movs r1, 0
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0x4D
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	movs r5, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	bge _08041806
	ldr r6, =gAbsentBankFlags
_080417D4:
	ldrb r0, [r6]
	ldr r2, =gBitTable
	lsls r1, r5, 2
	adds r1, r2
	ldr r4, [r1]
	ands r0, r4
	cmp r0, 0
	beq _080417FC
	lsls r0, r5, 24
	lsrs r0, 24
	movs r1, 0x6
	movs r2, 0x6
	bl sub_80423F4
	lsls r0, 24
	cmp r0, 0
	bne _080417FC
	ldrb r0, [r6]
	bics r0, r4
	strb r0, [r6]
_080417FC:
	adds r5, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r5, r0
	blt _080417D4
_08041806:
	ldr r0, =gBattleStruct
	mov r8, r0
	ldr r1, =gUnknown_0202420D
	mov r12, r1
	ldr r2, =gBankTarget
	mov r5, r8
	ldr r7, =gBattleMons
	ldr r6, =gBattlePartyID
_08041816:
	ldr r3, [r5]
	adds r1, r3, 0
	adds r1, 0x4E
	ldrb r0, [r1]
	strb r0, [r2]
	mov r4, r12
	strb r0, [r4]
	ldrb r4, [r1]
	movs r0, 0x58
	muls r0, r4
	adds r0, r7
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _0804185E
	adds r0, r3, 0
	adds r0, 0xDF
	ldrb r1, [r0]
	ldr r3, =gBitTable
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0804185E
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	lsls r0, r4, 2
	adds r0, r3
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0804185E
	b _08041744
_0804185E:
	ldr r0, [r5]
	adds r0, 0x4E
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, =gNoOfAllBanks
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r0]
	cmp r1, r0
	bne _08041816
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x4D
	movs r1, 0x3
	strb r1, [r0]
	b _080419FC
	.pool
_080418A0:
	ldr r0, =gUnknown_0202420D
	ldrb r0, [r0]
	bl sub_803F9EC
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0x4E
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _080418D8
	ldr r0, [r2]
	adds r0, 0x4D
	movs r1, 0x3
	strb r1, [r0]
	b _080419FA
	.pool
_080418D8:
	ldr r0, [r2]
	adds r0, 0x4D
	movs r1, 0x1
	strb r1, [r0]
	b _080419FA
_080418E2:
	mov r4, r8
	ldr r0, [r4]
	adds r0, 0x4E
	movs r1, 0
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, 0x4D
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080418F6:
	ldr r0, =gUnknown_0202420D
	mov r12, r0
	ldr r7, =gBankTarget
	ldr r5, =gBattleStruct
	ldr r2, =gBattleMons
	ldr r6, =gBitTable
_08041902:
	ldr r0, [r5]
	adds r4, r0, 0
	adds r4, 0x4E
	ldrb r0, [r4]
	strb r0, [r7]
	mov r1, r12
	strb r0, [r1]
	ldrb r3, [r4]
	movs r0, 0x58
	muls r0, r3
	adds r0, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08041930
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	lsls r0, r3, 2
	adds r0, r6
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _08041930
	b _08041758
_08041930:
	adds r0, r3, 0x1
	strb r0, [r4]
	ldr r1, =gNoOfAllBanks
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _08041902
	b _08041978
	.pool
_08041960:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x4E
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, =gNoOfAllBanks
	lsls r1, 24
	lsrs r1, 24
	ldrb r0, [r0]
	cmp r1, r0
	bne _08041988
_08041978:
	mov r4, r8
	ldr r0, [r4]
	adds r0, 0x4D
	movs r1, 0x6
	strb r1, [r0]
	b _080419FC
	.pool
_08041988:
	mov r1, r8
	ldr r0, [r1]
	adds r0, 0x4D
	movs r1, 0x4
	strb r1, [r0]
	b _080419FC
_08041994:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x9
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080419AE
	b _08041766
_080419AE:
	str r0, [sp]
	movs r0, 0xB
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _080419C4
	b _08041766
_080419C4:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x1
	bl berry_effects_maybe
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _080419D8
	b _08041766
_080419D8:
	str r0, [sp]
	movs r0, 0x6
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _080419EE
	b _08041766
_080419EE:
	ldr r2, =gBattleStruct
	ldr r1, [r2]
	adds r1, 0x4D
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_080419FA:
	mov r8, r2
_080419FC:
	mov r4, r8
	ldr r0, [r4]
	adds r0, 0x4D
	ldrb r0, [r0]
	cmp r0, 0x7
	beq _08041A0A
	b _08041774
_08041A0A:
	movs r0, 0
_08041A0C:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8041728

	thumb_func_start b_clear_atk_up_if_hit_flag_unless_enraged
b_clear_atk_up_if_hit_flag_unless_enraged: @ 8041A1C
	push {r4-r6,lr}
	movs r3, 0
	ldr r0, =gNoOfAllBanks
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r3, r0
	bge _08041A54
	ldr r4, =gUnknown_02024274
	movs r6, 0x80
	lsls r6, 16
	ldr r2, =gUnknown_020240D4
_08041A32:
	ldr r1, [r2]
	adds r0, r1, 0
	ands r0, r6
	cmp r0, 0
	beq _08041A48
	ldrh r0, [r4]
	cmp r0, 0x63
	beq _08041A48
	ldr r0, =0xff7fffff
	ands r1, r0
	str r1, [r2]
_08041A48:
	adds r4, 0x2
	adds r2, 0x58
	adds r3, 0x1
	ldrb r0, [r5]
	cmp r3, r0
	blt _08041A32
_08041A54:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_clear_atk_up_if_hit_flag_unless_enraged

	thumb_func_start sub_8041A6C
sub_8041A6C: @ 8041A6C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	movs r0, 0
	mov r9, r0
	ldr r1, =gUnknown_02024478
	mov r10, r1
	ldr r2, =gBattleStruct
	mov r8, r2
	b _08041A9A
	.pool
_08041A90:
	mov r3, r9
	cmp r3, 0
	beq _08041A9A
	bl _08042388
_08041A9A:
	mov r4, r8
	ldr r0, [r4]
	ldr r7, =0x000001a3
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0xE
	bls _08041AAC
	bl _08042376
_08041AAC:
	lsls r0, 2
	ldr r1, =_08041AC0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08041AC0:
	.4byte _08041AFC
	.4byte _08041B48
	.4byte _08041C90
	.4byte _08041D50
	.4byte _08041DC4
	.4byte _08041E40
	.4byte _08041EB8
	.4byte _08041F38
	.4byte _08041FC0
	.4byte _08042028
	.4byte _08042114
	.4byte _08042194
	.4byte _08042234
	.4byte _0804231C
	.4byte _08042376
_08041AFC:
	ldr r1, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r2, [r3]
	movs r0, 0x58
	muls r2, r0
	adds r1, 0x50
	adds r2, r1
	ldr r0, [r2]
	ldr r1, =0xfdffffff
	ands r0, r1
	str r0, [r2]
	ldr r0, =gStatuses3
	ldrb r2, [r3]
	lsls r2, 2
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xffffbfff
	ands r0, r1
	str r0, [r2]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x000001a3
	adds r1, r0, r2
	bl _08042370
	.pool
_08041B48:
	ldr r7, =gBattleMons
	ldr r4, =gBankAttacker
	ldrb r1, [r4]
	movs r5, 0x58
	adds r0, r1, 0
	muls r0, r5
	adds r6, r7, 0
	adds r6, 0x4C
	adds r0, r6
	ldr r0, [r0]
	movs r3, 0x7
	mov r8, r3
	ands r0, r3
	cmp r0, 0
	bne _08041B68
	b _08041C6E
_08041B68:
	adds r0, r1, 0
	bl sub_8050650
	lsls r0, 24
	cmp r0, 0
	beq _08041BC8
	ldrb r0, [r4]
	adds r2, r0, 0
	muls r2, r5
	adds r2, r6
	ldr r0, [r2]
	movs r1, 0x8
	negs r1, r1
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r4]
	adds r2, r0, 0
	muls r2, r5
	adds r0, r7, 0
	adds r0, 0x50
	adds r2, r0
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB220
	str r0, [r1]
	movs r4, 0x2
	mov r9, r4
	b _08041C6E
	.pool
_08041BC8:
	ldrb r0, [r4]
	adds r1, r0, 0
	muls r1, r5
	adds r0, r1, r7
	adds r0, 0x20
	ldrb r0, [r0]
	movs r3, 0x1
	cmp r0, 0x30
	bne _08041BDC
	movs r3, 0x2
_08041BDC:
	adds r2, r1, r6
	ldr r1, [r2]
	adds r0, r1, 0
	mov r7, r8
	ands r0, r7
	cmp r0, r3
	bcs _08041BF4
	movs r0, 0x8
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	b _08041BF8
_08041BF4:
	subs r0, r1, r3
	str r0, [r2]
_08041BF8:
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r1, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r4, [r0]
	movs r0, 0x7
	ands r4, r0
	cmp r4, 0
	beq _08041C50
	ldr r0, =gCurrentMove
	ldrh r0, [r0]
	cmp r0, 0xAD
	beq _08041C6E
	cmp r0, 0xD6
	beq _08041C6E
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB213
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	movs r0, 0x2
	mov r9, r0
	b _08041C6E
	.pool
_08041C50:
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
	ldr r0, =gUnknown_082DB220
	str r0, [r1]
	movs r1, 0x2
	mov r9, r1
_08041C6E:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldr r3, =0x000001a3
	adds r2, r0, r3
	b _0804216A
	.pool
_08041C90:
	ldr r1, =gBattleMons
	ldr r7, =gBankAttacker
	ldrb r0, [r7]
	movs r6, 0x58
	muls r0, r6
	adds r5, r1, 0
	adds r5, 0x4C
	adds r0, r5
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08041D30
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _08041D08
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x7D
	bne _08041CD6
	b _08042162
_08041CD6:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB26A
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 2
	orrs r0, r1
	str r0, [r2]
	b _08041D28
	.pool
_08041D08:
	ldrb r0, [r7]
	adds r2, r0, 0
	muls r2, r6
	adds r2, r5
	ldr r0, [r2]
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	str r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB277
	str r0, [r1]
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
_08041D28:
	movs r7, 0x2
	mov r9, r7
	ldr r0, =gBattleStruct
	mov r8, r0
_08041D30:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x000001a3
	adds r1, r0, r2
	b _08042370
	.pool
_08041D50:
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x36
	beq _08041D66
	b _08042162
_08041D66:
	ldr r0, =gDisableStructs
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x18]
	lsls r0, 31
	cmp r0, 0
	bne _08041D7A
	b _08042162
_08041D7A:
	adds r0, r2, 0
	bl CancelMultiTurnMoves
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB6AD
	str r0, [r1]
	ldr r2, =gBattleMoveFlags
	ldrb r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2]
	b _0804215E
	.pool
_08041DC4:
	ldr r1, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r2, [r3]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x80
	lsls r0, 15
	ands r0, r1
	cmp r0, 0
	beq _08041E10
	ldr r0, =0xffbfffff
	ands r1, r0
	str r1, [r2]
	ldr r2, =gDisableStructs
	ldrb r1, [r3]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x19]
	ldrb r0, [r3]
	bl CancelMultiTurnMoves
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082D9462
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	movs r7, 0x1
	mov r9, r7
_08041E10:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldr r3, =0x000001a3
	adds r2, r0, r3
	b _0804216A
	.pool
_08041E40:
	ldr r1, =gBattleMons
	ldr r3, =gBankAttacker
	ldrb r2, [r3]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _08041E8C
	movs r0, 0x9
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	ldr r0, =gProtectStructs
	ldrb r2, [r3]
	lsls r2, 4
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldrb r0, [r3]
	bl CancelMultiTurnMoves
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB29B
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	movs r4, 0x1
	mov r9, r4
_08041E8C:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldr r7, =0x000001a3
	adds r2, r0, r7
	b _0804216A
	.pool
_08041EB8:
	ldr r0, =gDisableStructs
	ldr r3, =gBankAttacker
	ldrb r2, [r3]
	lsls r1, r2, 3
	subs r1, r2
	lsls r1, 2
	adds r1, r0
	ldr r0, =gCurrentMove
	ldrh r1, [r1, 0x4]
	ldrh r0, [r0]
	cmp r1, r0
	bne _08041F04
	cmp r1, 0
	beq _08041F04
	ldr r0, =gProtectStructs
	lsls r2, 4
	adds r2, r0
	ldrb r0, [r2, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldr r1, =gBattleScripting
	ldrb r0, [r3]
	strb r0, [r1, 0x17]
	ldrb r0, [r3]
	bl CancelMultiTurnMoves
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAE14
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	movs r0, 0x1
	mov r9, r0
_08041F04:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldr r3, =0x000001a3
	adds r2, r0, r3
	b _0804216A
	.pool
_08041F38:
	ldr r0, =gDisableStructs
	ldr r4, =gBankAttacker
	ldrb r3, [r4]
	lsls r1, r3, 3
	subs r1, r3
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x13]
	lsls r0, 28
	cmp r0, 0
	beq _08041F8C
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x1]
	cmp r0, 0
	bne _08041F8C
	ldr r0, =gProtectStructs
	lsls r2, r3, 4
	adds r2, r0
	ldrb r0, [r2, 0x2]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x2]
	ldrb r0, [r4]
	bl CancelMultiTurnMoves
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB0A4
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	movs r4, 0x1
	mov r9, r4
_08041F8C:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldr r7, =0x000001a3
	adds r2, r0, r7
	b _0804216A
	.pool
_08041FC0:
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	ldr r1, =gCurrentMove
	ldrh r1, [r1]
	bl sub_8040130
	lsls r0, 24
	cmp r0, 0
	beq _08041FFE
	ldr r0, =gProtectStructs
	ldrb r2, [r4]
	lsls r2, 4
	adds r2, r0
	ldrb r0, [r2, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r0, [r4]
	bl CancelMultiTurnMoves
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB176
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	movs r0, 0x1
	mov r9, r0
_08041FFE:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldr r3, =0x000001a3
	adds r2, r0, r3
	b _0804216A
	.pool
_08042028:
	ldr r7, =gBattleMons
	ldr r5, =gBankAttacker
	ldrb r0, [r5]
	movs r6, 0x58
	muls r0, r6
	adds r4, r7, 0
	adds r4, 0x50
	adds r2, r0, r4
	ldr r1, [r2]
	movs r3, 0x7
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	beq _080420FA
	subs r0, r1, 0x1
	str r0, [r2]
	ldrb r0, [r5]
	muls r0, r6
	adds r0, r4
	ldr r0, [r0]
	ands r0, r3
	cmp r0, 0
	beq _080420E8
	bl Random
	movs r1, 0x1
	movs r2, 0x1
	ands r2, r0
	cmp r2, 0
	beq _0804207C
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
	bl b_movescr_stack_push_cursor
	b _080420C6
	.pool
_0804207C:
	ldr r0, =gBattleCommunication
	movs r4, 0x1
	strb r1, [r0, 0x5]
	ldr r1, =gBankTarget
	ldrb r0, [r5]
	strb r0, [r1]
	ldrb r0, [r5]
	adds r1, r0, 0
	muls r1, r6
	adds r1, r7
	movs r0, 0x28
	str r0, [sp]
	str r2, [sp, 0x4]
	ldrb r0, [r5]
	str r0, [sp, 0x8]
	ldrb r0, [r5]
	str r0, [sp, 0xC]
	adds r0, r1, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_806957C
	ldr r1, =gBattleMoveDamage
	str r0, [r1]
	ldr r0, =gProtectStructs
	ldrb r1, [r5]
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	orrs r0, r4
	strb r0, [r1, 0x1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
_080420C6:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB2BD
	b _080420F0
	.pool
_080420E8:
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB300
_080420F0:
	str r0, [r1]
	movs r4, 0x1
	mov r9, r4
	ldr r7, =gBattleStruct
	mov r8, r7
_080420FA:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x000001a3
	adds r1, r0, r2
	b _08042370
	.pool
_08042114:
	ldr r1, =gBattleMons
	ldr r4, =gBankAttacker
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08042162
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	bne _08042162
	ldr r0, =gProtectStructs
	ldrb r2, [r4]
	lsls r2, 4
	adds r2, r0
	ldrb r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB28B
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
_0804215E:
	movs r3, 0x1
	mov r9, r3
_08042162:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldr r4, =0x000001a3
	adds r2, r0, r4
_0804216A:
	ldrb r0, [r2]
	adds r0, 0x1
	strb r0, [r2]
	mov r8, r1
	b _08042376
	.pool
_08042194:
	ldr r1, =gBattleMons
	ldr r4, =gBankAttacker
	ldrb r2, [r4]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0xF0
	lsls r0, 12
	ands r1, r0
	cmp r1, 0
	beq _0804220E
	lsrs r0, r1, 16
	bl CountTrailingZeroBits
	ldr r1, =gBattleScripting
	strb r0, [r1, 0x17]
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	beq _080421D8
	bl b_movescr_stack_push_cursor
	b _08042200
	.pool
_080421D8:
	ldr r0, =gUnknown_082DB334
	bl b_movescr_stack_push
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
	orrs r0, r1
	str r0, [r2]
	ldr r0, =gProtectStructs
	ldrb r2, [r4]
	lsls r2, 4
	adds r2, r0
	ldrb r0, [r2, 0x1]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r0, [r4]
	bl CancelMultiTurnMoves
_08042200:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB327
	str r0, [r1]
	movs r7, 0x1
	mov r9, r7
	ldr r0, =gBattleStruct
	mov r8, r0
_0804220E:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x000001a3
	adds r1, r0, r2
	b _08042370
	.pool
_08042234:
	ldr r1, =gBattleMons
	ldr r6, =gBankAttacker
	ldrb r0, [r6]
	movs r5, 0x58
	muls r0, r5
	adds r1, 0x50
	adds r3, r0, r1
	ldr r2, [r3]
	movs r4, 0xC0
	lsls r4, 2
	adds r0, r2, 0
	ands r0, r4
	cmp r0, 0
	beq _08042306
	ldr r7, =0xffffff00
	adds r0, r2, r7
	str r0, [r3]
	ldrb r2, [r6]
	adds r0, r2, 0
	muls r0, r5
	adds r0, r1
	ldr r0, [r0]
	ands r0, r4
	cmp r0, 0
	beq _08042280
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAD71
	b _08042300
	.pool
_08042280:
	ldr r3, =gUnknown_020241F8
	lsls r0, r2, 2
	adds r0, r3
	ldr r0, [r0]
	cmp r0, 0
	beq _080422FC
	ldr r1, =gCurrentMove
	movs r0, 0x75
	strh r0, [r1]
	ldrb r0, [r6]
	lsls r0, 2
	adds r0, r3
	ldr r0, [r0]
	lsls r0, 1
	mov r1, r10
	str r0, [r1]
	ldr r4, =gBankTarget
	ldr r1, =gUnknown_02024288
	ldrb r0, [r6]
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	ldrb r0, [r4]
	lsls r0, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _080422CA
	movs r0, 0x75
	movs r1, 0x1
	bl GetMoveTarget
	strb r0, [r4]
_080422CA:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DAD7C
	str r0, [r1]
	ldr r2, =gBattleStruct
	mov r8, r2
	b _08042302
	.pool
_080422FC:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DADC4
_08042300:
	str r0, [r1]
_08042302:
	movs r3, 0x1
	mov r9, r3
_08042306:
	mov r4, r8
	ldr r0, [r4]
	ldr r7, =0x000001a3
	adds r1, r0, r7
	b _08042370
	.pool
_0804231C:
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x4C
	adds r4, r0, r1
	ldr r3, [r4]
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _08042368
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x7D
	bne _08042360
	movs r0, 0x21
	negs r0, r0
	ands r3, r0
	str r3, [r4]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB277
	str r0, [r1]
	ldr r1, =gBattleCommunication
	movs r0, 0x1
	strb r0, [r1, 0x5]
_08042360:
	movs r0, 0x2
	mov r9, r0
	ldr r1, =gBattleStruct
	mov r8, r1
_08042368:
	mov r2, r8
	ldr r0, [r2]
	ldr r3, =0x000001a3
	adds r1, r0, r3
_08042370:
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_08042376:
	mov r4, r8
	ldr r0, [r4]
	ldr r7, =0x000001a3
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0xE
	beq _08042388
	bl _08041A90
_08042388:
	mov r0, r9
	cmp r0, 0x2
	bne _080423B4
	ldr r4, =gActiveBank
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r4]
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
_080423B4:
	mov r0, r9
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8041A6C

	thumb_func_start sub_80423F4
sub_80423F4: @ 80423F4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r2, 24
	mov r9, r2
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08042424
	movs r0, 0
	b _080426A0
	.pool
_08042424:
	movs r0, 0x80
	lsls r0, 15
	ands r0, r1
	cmp r0, 0
	beq _0804249C
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r8, r1
	cmp r0, 0
	bne _08042442
	ldr r2, =gPlayerParty
	mov r8, r2
_08042442:
	movs r0, 0x2
	ands r0, r4
	lsls r0, 24
	lsrs r6, r0, 25
	lsls r0, r6, 1
	adds r4, r0, r6
	adds r0, r4, 0x3
	cmp r4, r0
	bge _0804248C
	adds r7, r0, 0
_08042456:
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08042486
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _08042486
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _0804248C
_08042486:
	adds r4, 0x1
	cmp r4, r7
	blt _08042456
_0804248C:
	movs r1, 0
	lsls r0, r6, 1
	adds r0, r6
	b _08042556
	.pool
_0804249C:
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804256C
	movs r0, 0x80
	lsls r0, 16
	ands r1, r0
	cmp r1, 0
	beq _080424E4
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080424D0
	ldr r2, =gPlayerParty
	mov r8, r2
	adds r0, r4, 0
	bl sub_806D864
	lsls r0, 24
	lsrs r7, r0, 24
	b _08042502
	.pool
_080424D0:
	ldr r0, =gEnemyParty
	mov r8, r0
	movs r1, 0x1
	eors r1, r4
	negs r0, r1
	orrs r0, r1
	lsrs r6, r0, 31
	b _0804250C
	.pool
_080424E4:
	adds r0, r4, 0
	bl sub_806D864
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	ldr r1, =gEnemyParty
	mov r8, r1
	cmp r0, 0
	bne _08042502
	ldr r2, =gPlayerParty
	mov r8, r2
_08042502:
	adds r0, r7, 0
	bl sub_806D82C
	lsls r0, 24
	lsrs r6, r0, 24
_0804250C:
	lsls r0, r6, 1
	adds r4, r0, r6
	adds r1, r4, 0x3
	mov r9, r0
	cmp r4, r1
	bge _08042550
	adds r7, r1, 0
_0804251A:
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804254A
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _0804254A
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	bne _08042550
_0804254A:
	adds r4, 0x1
	cmp r4, r7
	blt _0804251A
_08042550:
	movs r1, 0
	mov r2, r9
	adds r0, r2, r6
_08042556:
	adds r0, 0x3
	cmp r4, r0
	bne _0804255E
	movs r1, 0x1
_0804255E:
	adds r0, r1, 0
	b _080426A0
	.pool
_0804256C:
	movs r0, 0x80
	lsls r0, 8
	ands r1, r0
	cmp r1, 0
	beq _080425DA
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080425DA
	ldr r0, =gEnemyParty
	mov r8, r0
	movs r6, 0x3
	cmp r4, 0x1
	bne _08042590
	movs r6, 0
_08042590:
	adds r4, r6, 0
	adds r6, r4, 0x3
	b _0804259E
	.pool
_0804259C:
	adds r4, 0x1
_0804259E:
	cmp r4, r6
	bge _080425D2
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _0804259C
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _0804259C
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _0804259C
_080425D2:
	movs r0, 0
	cmp r4, r6
	bne _080426A0
	b _0804269E
_080425DA:
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08042608
	movs r0, 0x1
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x3
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gEnemyParty
	mov r8, r2
	b _08042620
	.pool
_08042608:
	movs r0, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	movs r0, 0x2
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gPlayerParty
	mov r8, r0
_08042620:
	mov r1, r10
	cmp r1, 0x6
	bne _08042630
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrb r0, [r0]
	mov r10, r0
_08042630:
	mov r2, r9
	cmp r2, 0x6
	bne _08042640
	ldr r1, =gBattlePartyID
	lsls r0, r6, 1
	adds r0, r1
	ldrb r0, [r0]
	mov r9, r0
_08042640:
	movs r4, 0
_08042642:
	movs r0, 0x64
	muls r0, r4
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _08042692
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	cmp r0, 0
	beq _08042692
	adds r0, r5, 0
	movs r1, 0x41
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08042692
	cmp r4, r10
	beq _08042692
	cmp r4, r9
	beq _08042692
	ldr r0, =gBattleStruct
	ldr r1, [r0]
	adds r0, r7, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r4, r0
	beq _08042692
	adds r0, r6, r1
	adds r0, 0x5C
	ldrb r0, [r0]
	cmp r4, r0
	bne _08042698
_08042692:
	adds r4, 0x1
	cmp r4, 0x5
	ble _08042642
_08042698:
	movs r0, 0
	cmp r4, 0x6
	bne _080426A0
_0804269E:
	movs r0, 0x1
_080426A0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80423F4

	thumb_func_start castform_switch
castform_switch: @ 80426BC
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r6
	adds r4, r0, r1
	ldrh r1, [r4]
	ldr r0, =0x00000181
	cmp r1, r0
	bne _08042760
	adds r0, r4, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x3B
	bne _08042760
	ldrh r0, [r4, 0x28]
	cmp r0, 0
	beq _08042760
	str r5, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _0804270E
	str r5, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _08042734
_0804270E:
	adds r2, r4, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0
	beq _08042734
	adds r1, r4, 0
	adds r1, 0x22
	ldrb r0, [r1]
	cmp r0, 0
	beq _08042734
	strb r5, [r2]
	strb r5, [r1]
	movs r0, 0x1
	b _08042818
	.pool
_08042734:
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
	bne _08042760
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _08042764
_08042760:
	movs r0, 0
	b _08042818
_08042764:
	ldr r1, =gBattleWeather
	ldrh r0, [r1]
	movs r2, 0xE7
	ands r2, r0
	adds r4, r1, 0
	cmp r2, 0
	bne _08042792
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r6
	adds r1, r0, r1
	adds r3, r1, 0
	adds r3, 0x21
	ldrb r0, [r3]
	cmp r0, 0
	beq _08042792
	adds r1, 0x22
	ldrb r0, [r1]
	cmp r0, 0
	beq _08042792
	strb r2, [r3]
	strb r2, [r1]
	movs r5, 0x1
_08042792:
	ldrh r1, [r4]
	movs r0, 0x60
	ands r0, r1
	cmp r0, 0
	beq _080427BE
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r6
	adds r1, r0, r1
	adds r2, r1, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0xA
	beq _080427BE
	adds r1, 0x22
	ldrb r0, [r1]
	cmp r0, 0xA
	beq _080427BE
	movs r0, 0xA
	strb r0, [r2]
	strb r0, [r1]
	movs r5, 0x2
_080427BE:
	ldrh r1, [r4]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	beq _080427EA
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r6
	adds r1, r0, r1
	adds r2, r1, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0xB
	beq _080427EA
	adds r1, 0x22
	ldrb r0, [r1]
	cmp r0, 0xB
	beq _080427EA
	movs r0, 0xB
	strb r0, [r2]
	strb r0, [r1]
	movs r5, 0x3
_080427EA:
	ldrh r1, [r4]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _08042816
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r6
	adds r1, r0, r1
	adds r2, r1, 0
	adds r2, 0x21
	ldrb r0, [r2]
	cmp r0, 0xF
	beq _08042816
	adds r1, 0x22
	ldrb r0, [r1]
	cmp r0, 0xF
	beq _08042816
	movs r0, 0xF
	strb r0, [r2]
	strb r0, [r1]
	movs r5, 0x4
_08042816:
	adds r0, r5, 0
_08042818:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end castform_switch

	thumb_func_start AbilityBattleEffects
AbilityBattleEffects: @ 8042828
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	ldr r4, [sp, 0x48]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r8, r3
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0
	mov r9, r0
	ldr r5, =gBankAttacker
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08042864
	mov r1, r10
	strb r1, [r5]
_08042864:
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08042894
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	b _080428A4
	.pool
_08042894:
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
_080428A4:
	adds r7, r1, r0
	ldr r5, =gBankTarget
	ldr r1, =gNoOfAllBanks
	ldrb r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _080428B6
	mov r2, r10
	strb r2, [r5]
_080428B6:
	ldrb r0, [r5]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080428E8
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	b _080428F8
	.pool
_080428E8:
	ldr r1, =gBattlePartyID
	ldrb r0, [r5]
	lsls r0, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
_080428F8:
	adds r5, r1, r0
	adds r0, r7, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	adds r0, r7, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x10]
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	adds r0, r5, 0
	movs r1, 0
	bl GetMonData
	str r0, [sp, 0x14]
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0804293A
	bl _0804443A
_0804293A:
	mov r3, r8
	cmp r3, 0
	beq _08042958
	ldr r0, =gLastUsedAbility
	strb r3, [r0]
	adds r7, r0, 0
	b _0804296E
	.pool
_08042958:
	ldr r2, =gLastUsedAbility
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r5, r10
	muls r5, r0
	adds r0, r5, 0
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	strb r0, [r2]
	adds r7, r2, 0
_0804296E:
	cmp r4, 0
	beq _08042980
	adds r5, r4, 0
	b _08042984
	.pool
_08042980:
	ldr r0, =gCurrentMove
	ldrh r5, [r0]
_08042984:
	ldr r1, =gBattleStruct
	ldr r0, [r1]
	ldrb r0, [r0, 0x13]
	mov r8, r1
	cmp r0, 0
	beq _080429A0
	movs r3, 0x3F
	ands r3, r0
	b _080429AC
	.pool
_080429A0:
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r3, [r0, 0x2]
_080429AC:
	ldr r0, [sp, 0x4]
	cmp r0, 0x13
	bls _080429B6
	bl _0804441E
_080429B6:
	lsls r0, 2
	ldr r1, =_080429C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080429C8:
	.4byte _08042A18
	.4byte _08042CDC
	.4byte _08042EF8
	.4byte _08042F8C
	.4byte _080431AC
	.4byte _08043908
	.4byte _08043C6C
	.4byte _08043CBC
	.4byte _08043D40
	.4byte _08043DC4
	.4byte _08043FE4
	.4byte _08043E08
	.4byte _08044028
	.4byte _08044084
	.4byte _080440E0
	.4byte _080441DC
	.4byte _08044220
	.4byte _0804427C
	.4byte _080443EC
	.4byte _08044196
_08042A18:
	ldr r2, =gBankAttacker
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r2]
	adds r5, r0, 0
	ldrb r3, [r5]
	cmp r1, r3
	bcc _08042A2A
	mov r0, r10
	strb r0, [r2]
_08042A2A:
	ldrb r0, [r7]
	cmp r0, 0x2D
	bne _08042A32
	b _08042BA8
_08042A32:
	cmp r0, 0x2D
	bgt _08042A64
	cmp r0, 0xD
	bne _08042A3C
	b _08042CA4
_08042A3C:
	cmp r0, 0xD
	bgt _08042A54
	cmp r0, 0x2
	bne _08042A46
	b _08042B78
_08042A46:
	bl _0804441E
	.pool
_08042A54:
	cmp r0, 0x16
	bne _08042A5A
	b _08042C08
_08042A5A:
	cmp r0, 0x24
	bne _08042A60
	b _08042C68
_08042A60:
	bl _0804441E
_08042A64:
	cmp r0, 0x46
	bne _08042A6A
	b _08042BD8
_08042A6A:
	cmp r0, 0x46
	bgt _08042A78
	cmp r0, 0x3B
	bne _08042A74
	b _08042C3C
_08042A74:
	bl _0804441E
_08042A78:
	cmp r0, 0x4D
	bne _08042A7E
	b _08042CA4
_08042A7E:
	cmp r0, 0xFF
	beq _08042A86
	bl _0804441E
_08042A86:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne _08042B4C
	bl weather_get_current
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x3
	cmp r0, 0xA
	bhi _08042B4C
	lsls r0, 2
	ldr r1, =_08042AB4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08042AB4:
	.4byte _08042AE0
	.4byte _08042B4C
	.4byte _08042AE0
	.4byte _08042B4C
	.4byte _08042B4C
	.4byte _08042B04
	.4byte _08042B4C
	.4byte _08042B4C
	.4byte _08042B4C
	.4byte _08042B28
	.4byte _08042AE0
_08042AE0:
	ldr r2, =gBattleWeather
	ldrh r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _08042B4C
	movs r0, 0x5
	strh r0, [r2]
	ldr r1, =gBattleScripting
	movs r0, 0xA
	strb r0, [r1, 0x10]
	mov r2, r10
	strb r2, [r1, 0x17]
	b _08042B42
	.pool
_08042B04:
	ldr r3, =gBattleWeather
	ldrh r1, [r3]
	movs r2, 0x18
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08042B4C
	strh r2, [r3]
	ldr r1, =gBattleScripting
	movs r0, 0xC
	strb r0, [r1, 0x10]
	mov r3, r10
	strb r3, [r1, 0x17]
	b _08042B42
	.pool
_08042B28:
	ldr r3, =gBattleWeather
	ldrh r1, [r3]
	movs r2, 0x60
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08042B4C
	strh r2, [r3]
	ldr r1, =gBattleScripting
	movs r0, 0xB
	strb r0, [r1, 0x10]
	mov r5, r10
	strb r5, [r1, 0x17]
_08042B42:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_08042B4C:
	mov r0, r9
	cmp r0, 0
	bne _08042B56
	bl _0804443A
_08042B56:
	bl weather_get_current
	ldr r1, =gBattleCommunication
	strb r0, [r1, 0x5]
	ldr r0, =gUnknown_082DACE7
	bl b_push_move_exec
	bl _0804441E
	.pool
_08042B78:
	ldr r2, =gBattleWeather
	ldrh r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08042B88
	bl _0804441E
_08042B88:
	movs r0, 0x5
	strh r0, [r2]
	ldr r0, =gUnknown_082DB430
	bl b_push_move_exec
	ldr r0, =gBattleScripting
	mov r1, r10
	strb r1, [r0, 0x17]
	bl _080443D0
	.pool
_08042BA8:
	ldr r2, =gBattleWeather
	ldrh r1, [r2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08042BB8
	bl _0804441E
_08042BB8:
	movs r0, 0x18
	strh r0, [r2]
	ldr r0, =gUnknown_082DB470
	bl b_push_move_exec
	ldr r0, =gBattleScripting
	mov r2, r10
	strb r2, [r0, 0x17]
	bl _080443D0
	.pool
_08042BD8:
	ldr r2, =gBattleWeather
	ldrh r1, [r2]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08042BE8
	bl _0804441E
_08042BE8:
	movs r0, 0x60
	strh r0, [r2]
	ldr r0, =gUnknown_082DB52A
	bl b_push_move_exec
	ldr r0, =gBattleScripting
	mov r3, r10
	strb r3, [r0, 0x17]
	bl _080443D0
	.pool
_08042C08:
	ldr r0, =gSpecialStatuses
	mov r5, r10
	lsls r2, r5, 2
	adds r1, r2, r5
	lsls r1, 2
	adds r3, r1, r0
	ldrb r0, [r3]
	lsls r0, 28
	cmp r0, 0
	bge _08042C20
	bl _0804441E
_08042C20:
	ldr r1, =gStatuses3
	adds r1, r2, r1
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 12
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x8
	b _08042C92
	.pool
_08042C3C:
	mov r0, r10
	bl castform_switch
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r0, 0
	bne _08042C50
	bl _0804443A
_08042C50:
	ldr r0, =gUnknown_082DB4A9
	bl b_push_move_exec
	ldr r0, =gBattleScripting
	mov r1, r10
	strb r1, [r0, 0x17]
	bl _080442E2
	.pool
_08042C68:
	ldr r0, =gSpecialStatuses
	mov r3, r10
	lsls r2, r3, 2
	adds r1, r2, r3
	lsls r1, 2
	adds r3, r1, r0
	ldrb r0, [r3]
	lsls r0, 27
	cmp r0, 0
	bge _08042C80
	bl _0804441E
_08042C80:
	ldr r1, =gStatuses3
	adds r1, r2, r1
	ldr r0, [r1]
	movs r2, 0x80
	lsls r2, 13
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	movs r1, 0x10
_08042C92:
	orrs r0, r1
	strb r0, [r3]
	bl _0804441E
	.pool
_08042CA4:
	movs r6, 0
	ldrb r5, [r5]
	cmp r6, r5
	bcc _08042CB0
	bl _0804441E
_08042CB0:
	adds r0, r6, 0
	bl castform_switch
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r0, 0
	beq _08042CC4
	bl _080442D8
_08042CC4:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r6, r0
	bcc _08042CB0
	bl _0804441E
	.pool
_08042CDC:
	ldr r5, =gBattleMons
	mov r8, r5
	movs r0, 0x58
	mov r6, r10
	muls r6, r0
	adds r4, r6, r5
	ldrh r0, [r4, 0x28]
	cmp r0, 0
	bne _08042CF2
	bl _0804441E
_08042CF2:
	ldr r0, =gBankAttacker
	mov r1, r10
	strb r1, [r0]
	ldrb r5, [r7]
	cmp r5, 0x2C
	beq _08042D22
	cmp r5, 0x2C
	bgt _08042D14
	cmp r5, 0x3
	bne _08042D08
	b _08042E84
_08042D08:
	bl _0804441E
	.pool
_08042D14:
	cmp r5, 0x36
	bne _08042D1A
	b _08042ED0
_08042D1A:
	cmp r5, 0x3D
	beq _08042DA0
	bl _0804441E
_08042D22:
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
	beq _08042D3E
	bl _0804441E
_08042D3E:
	str r0, [sp]
	movs r0, 0x13
	movs r1, 0
	movs r2, 0x4D
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	beq _08042D56
	bl _0804441E
_08042D56:
	ldr r0, =gBattleWeather
	ldrh r1, [r0]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _08042D66
	bl _0804441E
_08042D66:
	ldrh r0, [r4, 0x2C]
	ldrh r2, [r4, 0x28]
	cmp r0, r2
	bhi _08042D72
	bl _0804441E
_08042D72:
	strb r5, [r7]
	ldr r0, =gUnknown_082DB45C
	bl b_push_move_exec
	ldr r1, =gBattleMoveDamage
	ldrh r0, [r4, 0x2C]
	lsrs r0, 4
	str r0, [r1]
	cmp r0, 0
	bne _08042D8A
	movs r0, 0x1
	str r0, [r1]
_08042D8A:
	ldr r0, [r1]
	negs r0, r0
	str r0, [r1]
	bl _080443D0
	.pool
_08042DA0:
	mov r0, r8
	adds r0, 0x4C
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, 0
	bne _08042DB0
	bl _0804441E
_08042DB0:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _08042DCA
	bl _0804441E
_08042DCA:
	ldr r0, [r5]
	movs r1, 0x88
	ands r0, r1
	cmp r0, 0
	beq _08042DDC
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC70
	bl StringCopy
_08042DDC:
	ldr r0, [r5]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08042DEE
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC78
	bl StringCopy
_08042DEE:
	ldr r0, [r5]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08042E00
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC80
	bl StringCopy
_08042E00:
	ldr r0, [r5]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08042E12
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC88
	bl StringCopy
_08042E12:
	ldr r0, [r5]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08042E24
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC90
	bl StringCopy
_08042E24:
	str r4, [r5]
	mov r1, r8
	adds r1, 0x50
	adds r1, r6, r1
	ldr r0, [r1]
	ldr r2, =0xf7ffffff
	ands r0, r2
	str r0, [r1]
	ldr r0, =gBattleScripting
	ldr r4, =gActiveBank
	mov r3, r10
	strb r3, [r4]
	strb r3, [r0, 0x17]
	ldr r0, =gUnknown_082DB484
	bl b_push_move_exec
	str r5, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	bl _080443D0
	.pool
_08042E84:
	ldrb r2, [r4, 0x1B]
	movs r0, 0x1B
	ldrsb r0, [r4, r0]
	cmp r0, 0xB
	ble _08042E92
	bl _0804441E
_08042E92:
	ldr r0, =gDisableStructs
	mov r5, r10
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x16]
	cmp r0, 0x2
	bne _08042EA8
	bl _0804441E
_08042EA8:
	adds r0, r2, 0x1
	movs r1, 0
	strb r0, [r4, 0x1B]
	ldr r4, =gBattleScripting
	movs r0, 0x11
	strb r0, [r4, 0x10]
	strb r1, [r4, 0x11]
	ldr r0, =gUnknown_082DB444
	bl b_push_move_exec
	strb r5, [r4, 0x17]
	bl _080443D0
	.pool
_08042ED0:
	ldr r2, =gDisableStructs
	ldrb r0, [r0]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r3, [r1, 0x18]
	lsls r0, r3, 31
	lsrs r0, 31
	movs r2, 0x1
	eors r2, r0
	movs r0, 0x2
	negs r0, r0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x18]
	bl _0804441E
	.pool
_08042EF8:
	ldrb r0, [r7]
	cmp r0, 0x2B
	beq _08042F02
	bl _0804441E
_08042F02:
	movs r4, 0
	ldr r0, =gUnknown_0831BCF8
	ldrh r2, [r0]
	ldr r3, =0x0000ffff
	adds r1, r0, 0
	cmp r2, r3
	bne _08042F14
	bl _0804441E
_08042F14:
	cmp r2, r5
	beq _08042F2C
	adds r2, r1, 0
_08042F1A:
	adds r2, 0x2
	adds r4, 0x1
	ldrh r0, [r2]
	cmp r0, r3
	bne _08042F28
	bl _0804441E
_08042F28:
	cmp r0, r5
	bne _08042F1A
_08042F2C:
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08042F3C
	bl _0804441E
_08042F3C:
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
	beq _08042F62
	ldr r0, =gHitMarker
	ldr r1, [r0]
	movs r2, 0x80
	lsls r2, 4
	orrs r1, r2
	str r1, [r0]
_08042F62:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB61F
	str r0, [r1]
	movs r0, 0x1
	mov r9, r0
	bl _08044424
	.pool
_08042F8C:
	cmp r5, 0
	bne _08042F94
	bl _0804441E
_08042F94:
	ldrb r0, [r7]
	cmp r0, 0xB
	beq _08043004
	cmp r0, 0xB
	bgt _08042FA4
	cmp r0, 0xA
	beq _08042FAA
	b _08043126
_08042FA4:
	cmp r0, 0x12
	beq _0804305C
	b _08043126
_08042FAA:
	cmp r3, 0xD
	beq _08042FB0
	b _08043126
_08042FB0:
	ldr r0, =gBattleMoves
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _08042FC2
	b _08043126
_08042FC2:
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 28
	cmp r0, 0
	bge _08042FF0
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB56F
	b _08042FF4
	.pool
_08042FF0:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB56E
_08042FF4:
	str r0, [r1]
	movs r1, 0x1
	b _08043124
	.pool
_08043004:
	cmp r3, 0xB
	beq _0804300A
	b _08043126
_0804300A:
	ldr r0, =gBattleMoves
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _0804301C
	b _08043126
_0804301C:
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 28
	cmp r0, 0
	bge _08043048
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB56F
	b _0804304C
	.pool
_08043048:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB56E
_0804304C:
	str r0, [r1]
	movs r2, 0x1
	mov r9, r2
	b _08043126
	.pool
_0804305C:
	cmp r3, 0xA
	bne _08043126
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r3, r10
	muls r3, r0
	adds r0, r3, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	bne _08043126
	ldr r2, =gBattleResources
	ldr r0, [r2]
	ldr r0, [r0, 0x4]
	mov r5, r10
	lsls r1, r5, 2
	adds r0, r1
	ldr r3, [r0]
	movs r4, 0x1
	ands r3, r4
	adds r5, r1, 0
	cmp r3, 0
	bne _080430EC
	ldr r0, =gBattleCommunication
	strb r3, [r0, 0x5]
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 28
	cmp r0, 0
	bge _080430C8
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB5A8
	b _080430CC
	.pool
_080430C8:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB5A7
_080430CC:
	str r0, [r1]
	ldr r0, [r2]
	ldr r1, [r0, 0x4]
	adds r1, r5
	ldr r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	str r0, [r1]
	movs r0, 0x2
	mov r9, r0
	b _08043126
	.pool
_080430EC:
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 28
	cmp r0, 0
	bge _0804311C
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB5A8
	b _08043120
	.pool
_0804311C:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB5A7
_08043120:
	str r0, [r1]
	movs r1, 0x2
_08043124:
	mov r9, r1
_08043126:
	mov r2, r9
	cmp r2, 0x1
	beq _08043130
	bl _0804441E
_08043130:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r3, r10
	muls r3, r0
	adds r0, r3, 0
	adds r1, r0, r1
	ldrh r0, [r1, 0x2C]
	ldrh r5, [r1, 0x28]
	cmp r0, r5
	bne _0804318C
	ldr r1, =gProtectStructs
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	lsls r0, 4
	adds r0, r1
	ldrb r0, [r0, 0x2]
	lsls r0, 28
	cmp r0, 0
	bge _08043178
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB592
	str r0, [r1]
	bl _0804441E
	.pool
_08043178:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB591
	str r0, [r1]
	bl _0804441E
	.pool
_0804318C:
	ldr r2, =gBattleMoveDamage
	ldrh r0, [r1, 0x2C]
	lsrs r0, 2
	str r0, [r2]
	cmp r0, 0
	bne _0804319C
	mov r0, r9
	str r0, [r2]
_0804319C:
	ldr r0, [r2]
	negs r0, r0
	str r0, [r2]
	bl _0804441E
	.pool
_080431AC:
	ldrb r0, [r7]
	subs r0, 0x9
	cmp r0, 0x2F
	bls _080431B8
	bl _0804441E
_080431B8:
	lsls r0, 2
	ldr r1, =_080431C8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080431C8:
	.4byte _080435E4
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _08043288
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _08043350
	.4byte _0804441E
	.4byte _0804441E
	.4byte _08043410
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _08043508
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _080436C0
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804441E
	.4byte _0804379C
_08043288:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08043298
	bl _0804441E
_08043298:
	cmp r5, 0xA5
	bne _080432A0
	bl _0804441E
_080432A0:
	ldr r0, =gBattleMoves
	lsls r1, r5, 1
	adds r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	cmp r0, 0
	bne _080432B4
	bl _0804441E
_080432B4:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _080432DC
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _080432DC
	bl _0804441E
_080432DC:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	adds r1, r0, r1
	adds r4, r1, 0
	adds r4, 0x21
	ldrb r0, [r4]
	cmp r0, r3
	bne _080432F6
	bl _0804441E
_080432F6:
	adds r2, r1, 0
	adds r2, 0x22
	ldrb r0, [r2]
	cmp r0, r3
	bne _08043304
	bl _0804441E
_08043304:
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	bne _0804330E
	bl _0804441E
_0804330E:
	strb r3, [r4]
	strb r3, [r2]
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x3
	strb r0, [r1, 0x1]
	strb r3, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB64D
	str r0, [r1]
	bl _080443D0
	.pool
_08043350:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08043360
	bl _0804441E
_08043360:
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r3, r0, r1
	ldrh r0, [r3, 0x28]
	cmp r0, 0
	bne _08043376
	bl _0804441E
_08043376:
	ldr r0, =gProtectStructs
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 31
	cmp r0, 0
	beq _08043388
	bl _0804441E
_08043388:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _080433B0
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _080433B0
	bl _0804441E
_080433B0:
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _080433CA
	bl _0804441E
_080433CA:
	ldr r1, =gBattleMoveDamage
	ldrh r0, [r3, 0x2C]
	lsrs r0, 4
	str r0, [r1]
	cmp r0, 0
	bne _080433D8
	str r2, [r1]
_080433D8:
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB654
	str r0, [r1]
	bl _080443D0
	.pool
_08043410:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08043420
	bl _0804441E
_08043420:
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08043436
	bl _0804441E
_08043436:
	ldr r0, =gProtectStructs
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 31
	cmp r0, 0
	beq _08043448
	bl _0804441E
_08043448:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043470
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043470
	bl _0804441E
_08043470:
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08043488
	bl _0804441E
_08043488:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _080434A0
	bl _0804441E
_080434A0:
	ldr r5, =gBattleCommunication
	movs r4, 0x3
_080434A4:
	bl Random
	ands r0, r4
	strb r0, [r5, 0x3]
	cmp r0, 0
	beq _080434A4
	ldr r1, =gBattleCommunication
	ldrb r0, [r1, 0x3]
	cmp r0, 0x3
	bne _080434BC
	adds r0, 0x2
	strb r0, [r1, 0x3]
_080434BC:
	ldrb r0, [r1, 0x3]
	adds r0, 0x40
	strb r0, [r1, 0x3]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB67C
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 6
	orrs r0, r1
	str r0, [r2]
	bl _080443D0
	.pool
_08043508:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _08043518
	bl _0804441E
_08043518:
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _0804352E
	bl _0804441E
_0804352E:
	ldr r0, =gProtectStructs
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 31
	cmp r0, 0
	beq _08043540
	bl _0804441E
_08043540:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043568
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043568
	bl _0804441E
_08043568:
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08043580
	bl _0804441E
_08043580:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _08043598
	bl _0804441E
_08043598:
	ldr r1, =gBattleCommunication
	movs r0, 0x42
	strb r0, [r1, 0x3]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB67C
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 6
	orrs r0, r1
	str r0, [r2]
	bl _080443D0
	.pool
_080435E4:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _080435F4
	bl _0804441E
_080435F4:
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _0804360A
	bl _0804441E
_0804360A:
	ldr r0, =gProtectStructs
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 31
	cmp r0, 0
	beq _0804361C
	bl _0804441E
_0804361C:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043644
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043644
	bl _0804441E
_08043644:
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0804365C
	bl _0804441E
_0804365C:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _08043674
	bl _0804441E
_08043674:
	ldr r1, =gBattleCommunication
	movs r0, 0x45
	strb r0, [r1, 0x3]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB67C
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 6
	orrs r0, r1
	str r0, [r2]
	bl _080443D0
	.pool
_080436C0:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _080436D0
	bl _0804441E
_080436D0:
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _080436E6
	bl _0804441E
_080436E6:
	ldr r0, =gProtectStructs
	lsls r1, r2, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 31
	cmp r0, 0
	beq _080436F8
	bl _0804441E
_080436F8:
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08043710
	bl _0804441E
_08043710:
	ldr r2, =gSpecialStatuses
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043738
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043738
	bl _0804441E
_08043738:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _08043750
	bl _0804441E
_08043750:
	ldr r1, =gBattleCommunication
	movs r0, 0x43
	strb r0, [r1, 0x3]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB67C
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 6
	orrs r0, r1
	str r0, [r2]
	bl _080443D0
	.pool
_0804379C:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _080437AC
	bl _0804441E
_080437AC:
	ldr r6, =gBattleMons
	ldr r3, =gBankAttacker
	mov r8, r3
	ldrb r1, [r3]
	movs r7, 0x58
	adds r0, r1, 0
	muls r0, r7
	adds r0, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _080437C6
	bl _0804441E
_080437C6:
	ldr r0, =gProtectStructs
	lsls r1, 4
	adds r1, r0
	ldrb r0, [r1, 0x1]
	lsls r0, 31
	cmp r0, 0
	beq _080437D8
	bl _0804441E
_080437D8:
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x8]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080437F0
	bl _0804441E
_080437F0:
	ldr r3, =gSpecialStatuses
	ldr r5, =gBankTarget
	ldrb r1, [r5]
	lsls r0, r1, 2
	adds r0, r1
	lsls r2, r0, 2
	adds r0, r3, 0
	adds r0, 0x8
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043818
	adds r0, r3, 0
	adds r0, 0xC
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08043818
	bl _0804441E
_08043818:
	adds r0, r1, 0
	muls r0, r7
	adds r0, r6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	bne _08043828
	bl _0804441E
_08043828:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	beq _08043840
	bl _0804441E
_08043840:
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r7
	adds r0, r6
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0xC
	bne _08043854
	bl _0804441E
_08043854:
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0x10]
	bl pokemon_species_get_gender_info
	adds r4, r0, 0
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x14]
	bl pokemon_species_get_gender_info
	lsls r4, 24
	lsls r0, 24
	cmp r4, r0
	bne _08043872
	bl _0804441E
_08043872:
	mov r2, r8
	ldrb r0, [r2]
	muls r0, r7
	adds r4, r6, 0
	adds r4, 0x50
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0xF0
	lsls r1, 12
	ands r0, r1
	cmp r0, 0
	beq _0804388E
	bl _0804441E
_0804388E:
	ldr r0, [sp, 0x8]
	ldr r1, [sp, 0x10]
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080438A2
	bl _0804441E
_080438A2:
	ldr r0, [sp, 0xC]
	ldr r1, [sp, 0x14]
	bl pokemon_species_get_gender_info
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080438B6
	bl _0804441E
_080438B6:
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r0, 0
	muls r2, r7
	adds r2, r4
	ldr r1, =gBitTable
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	lsls r1, 16
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB66F
	str r0, [r1]
	bl _080443D0
	.pool
_08043908:
	movs r5, 0
	mov r10, r5
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r10, r0
	bcc _08043918
	bl _0804441E
_08043918:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r10
	muls r2, r0
	adds r0, r2, 0
	adds r0, r1
	adds r0, 0x20
	ldrb r0, [r0]
	subs r0, 0x7
	adds r2, r1, 0
	cmp r0, 0x41
	bls _08043932
	b _08043B96
_08043932:
	lsls r0, 2
	ldr r1, =_08043948
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08043948:
	.4byte _08043AAC
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B70
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043AD4
	.4byte _08043B96
	.4byte _08043A50
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043A7C
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B40
	.4byte _08043B10
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043B96
	.4byte _08043AD4
_08043A50:
	movs r0, 0x58
	mov r3, r10
	muls r3, r0
	adds r0, r3, 0
	adds r1, r2, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	ldr r1, =0x00000f88
	ands r0, r1
	cmp r0, 0
	bne _08043A6A
	b _08043B96
_08043A6A:
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC70
	b _08043B5C
	.pool
_08043A7C:
	movs r0, 0x58
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _08043A96
	b _08043B96
_08043A96:
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC98
	bl StringCopy
	movs r2, 0x2
	mov r9, r2
	b _08043B9C
	.pool
_08043AAC:
	movs r0, 0x58
	mov r3, r10
	muls r3, r0
	adds r0, r3, 0
	adds r1, r2, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08043B96
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC80
	b _08043B5C
	.pool
_08043AD4:
	movs r0, 0x58
	mov r3, r10
	muls r3, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08043B96
	adds r2, 0x50
	adds r2, r3, r2
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC78
	bl StringCopy
	movs r0, 0x1
	mov r9, r0
	b _08043B9C
	.pool
_08043B10:
	movs r0, 0x58
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08043B96
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC88
	bl StringCopy
	movs r2, 0x1
	mov r9, r2
	b _08043B9C
	.pool
_08043B40:
	movs r0, 0x58
	mov r3, r10
	muls r3, r0
	adds r0, r3, 0
	adds r1, r2, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _08043B96
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC90
_08043B5C:
	bl StringCopy
	movs r5, 0x1
	mov r9, r5
	b _08043B9C
	.pool
_08043B70:
	movs r0, 0x58
	mov r1, r10
	muls r1, r0
	adds r0, r1, 0
	adds r1, r2, 0
	adds r1, 0x50
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0xF0
	lsls r1, 12
	ands r0, r1
	cmp r0, 0
	beq _08043B96
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BCA0
	bl StringCopy
	movs r2, 0x3
	mov r9, r2
_08043B96:
	mov r3, r9
	cmp r3, 0
	beq _08043C50
_08043B9C:
	mov r5, r9
	cmp r5, 0x2
	beq _08043BD0
	cmp r5, 0x2
	bgt _08043BB4
	cmp r5, 0x1
	beq _08043BBC
	b _08043BFC
	.pool
_08043BB4:
	mov r0, r9
	cmp r0, 0x3
	beq _08043BE8
	b _08043BFC
_08043BBC:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r10
	muls r2, r0
	adds r1, 0x4C
	adds r2, r1
	movs r0, 0
	b _08043BFA
	.pool
_08043BD0:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r10
	muls r2, r0
	adds r1, 0x50
	adds r2, r1
	ldr r0, [r2]
	movs r1, 0x8
	negs r1, r1
	b _08043BF8
	.pool
_08043BE8:
	ldr r1, =gBattleMons
	movs r0, 0x58
	mov r2, r10
	muls r2, r0
	adds r1, 0x50
	adds r2, r1
	ldr r0, [r2]
	ldr r1, =0xfff0ffff
_08043BF8:
	ands r0, r1
_08043BFA:
	str r0, [r2]
_08043BFC:
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB68C
	str r0, [r1]
	ldr r0, =gBattleScripting
	mov r1, r10
	strb r1, [r0, 0x17]
	ldr r4, =gActiveBank
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
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	bl _0804443A
	.pool
_08043C50:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r10, r0
	bcs _08043C64
	b _08043918
_08043C64:
	bl _0804441E
	.pool
_08043C6C:
	movs r2, 0
	mov r10, r2
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r10, r0
	bcc _08043C7A
	b _0804441E
_08043C7A:
	ldr r4, =gBattleMons
_08043C7C:
	movs r0, 0x58
	mov r3, r10
	muls r3, r0
	adds r0, r3, 0
	adds r0, r4
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x3B
	bne _08043CA0
	mov r0, r10
	bl castform_switch
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	cmp r0, 0
	beq _08043CA0
	b _080442FC
_08043CA0:
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r10, r0
	bcc _08043C7C
	b _0804441E
	.pool
_08043CBC:
	ldrb r0, [r7]
	cmp r0, 0x1C
	beq _08043CC4
	b _0804441E
_08043CC4:
	ldr r4, =gHitMarker
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 7
	ands r0, r1
	cmp r0, 0
	bne _08043CD4
	b _0804441E
_08043CD4:
	ldr r0, =0xffffbfff
	ands r1, r0
	str r1, [r4]
	mov r5, r8
	ldr r1, [r5]
	adds r1, 0xB2
	ldrb r2, [r1]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, 0
	adds r1, 0xB2
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _08043CF8
	movs r0, 0x2
	strb r0, [r1]
_08043CF8:
	ldr r1, =gBattleCommunication
	mov r2, r8
	ldr r0, [r2]
	adds r0, 0xB2
	ldrb r0, [r0]
	adds r0, 0x40
	strb r0, [r1, 0x3]
	ldr r1, =gBattleScripting
	ldr r0, =gBankTarget
	ldrb r0, [r0]
	strb r0, [r1, 0x17]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB67F
	str r0, [r1]
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 6
	orrs r0, r1
	str r0, [r4]
	b _080443D0
	.pool
_08043D40:
	ldrb r0, [r7]
	cmp r0, 0x1C
	beq _08043D48
	b _0804441E
_08043D48:
	ldr r4, =gHitMarker
	ldr r1, [r4]
	movs r0, 0x80
	lsls r0, 7
	ands r0, r1
	cmp r0, 0
	bne _08043D58
	b _0804441E
_08043D58:
	ldr r0, =0xffffbfff
	ands r1, r0
	str r1, [r4]
	mov r3, r8
	ldr r1, [r3]
	adds r1, 0xB2
	ldrb r2, [r1]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	adds r1, r0, 0
	adds r1, 0xB2
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _08043D7C
	movs r0, 0x2
	strb r0, [r1]
_08043D7C:
	ldr r1, =gBattleCommunication
	mov r3, r8
	ldr r0, [r3]
	adds r0, 0xB2
	ldrb r0, [r0]
	strb r0, [r1, 0x3]
	ldr r1, =gBattleScripting
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	strb r0, [r1, 0x17]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB67F
	str r0, [r1]
	ldr r0, [r4]
	movs r1, 0x80
	lsls r1, 6
	orrs r0, r1
	str r0, [r4]
	b _080443D0
	.pool
_08043DC4:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	cmp r4, r1
	blt _08043DD0
	b _0804441E
_08043DD0:
	ldr r0, =gBattleMons
	adds r5, r1, 0
	ldr r2, =gStatuses3
	adds r3, r0, 0
	adds r3, 0x20
	movs r6, 0x80
	lsls r6, 12
_08043DDE:
	ldrb r1, [r3]
	cmp r1, 0x16
	bne _08043DEE
	ldr r0, [r2]
	ands r0, r6
	cmp r0, 0
	beq _08043DEE
	b _08044324
_08043DEE:
	adds r2, 0x4
	adds r3, 0x58
	adds r4, 0x1
	cmp r4, r5
	blt _08043DDE
	b _0804441E
	.pool
_08043E08:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043E14
	b _0804441E
_08043E14:
	ldr r5, =gActiveBank
	mov r8, r5
	ldr r0, =gBattleMons
	adds r0, 0x20
	str r0, [sp, 0x1C]
	movs r1, 0
	str r1, [sp, 0x20]
_08043E22:
	ldr r2, [sp, 0x1C]
	ldrb r0, [r2]
	cmp r0, 0x24
	beq _08043E2C
	b _08043FBE
_08043E2C:
	ldr r0, =gStatuses3
	ldr r3, [sp, 0x20]
	adds r0, r3, r0
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 13
	ands r1, r0
	str r3, [sp, 0x18]
	cmp r1, 0
	bne _08043E42
	b _08043FBE
_08043E42:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankIdentity
	movs r1, 0x1
	adds r5, r0, 0
	eors r5, r1
	ands r5, r1
	adds r0, r5, 0
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0x2
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r2, 0x1
	ands r0, r2
	cmp r0, 0
	bne _08043E74
	b _08043F84
_08043E74:
	movs r1, 0x58
	adds r0, r6, 0
	muls r0, r1
	ldr r3, =gBattleMons
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043F40
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	beq _08043EFC
	movs r1, 0x58
	adds r0, r7, 0
	muls r0, r1
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043EFC
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	beq _08043EFC
	str r2, [sp, 0x24]
	bl Random
	ldr r2, [sp, 0x24]
	adds r1, r2, 0
	ands r1, r0
	lsls r1, 1
	orrs r5, r1
	adds r0, r5, 0
	bl GetBankByPlayerAI
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, 0x58
	muls r0, r3
	ldr r5, =gBattleMons
	adds r0, r5
	adds r0, 0x20
	ldrb r0, [r0]
	ldr r1, [sp, 0x1C]
	strb r0, [r1]
	ldrb r0, [r2]
	muls r0, r3
	adds r0, r5
	adds r0, 0x20
	ldrb r0, [r0]
	ldr r2, =gLastUsedAbility
	strb r0, [r2]
	b _08043FAC
	.pool
_08043EFC:
	ldr r3, =gBattleMons
	movs r2, 0x58
	adds r0, r6, 0
	muls r0, r2
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043F40
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	beq _08043F40
	mov r5, r8
	strb r6, [r5]
	adds r1, r4, 0
	muls r1, r2
	adds r1, r3
	ldrb r0, [r5]
	muls r0, r2
	adds r0, r3
	adds r0, 0x20
	ldrb r0, [r0]
	adds r1, 0x20
	strb r0, [r1]
	ldrb r0, [r5]
	muls r0, r2
	adds r0, r3
	adds r0, 0x20
	ldrb r0, [r0]
	b _08043FA8
	.pool
_08043F40:
	ldr r3, =gBattleMons
	movs r2, 0x58
	adds r0, r7, 0
	muls r0, r2
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0
	beq _08043FB6
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	beq _08043FB6
	mov r5, r8
	strb r7, [r5]
	adds r1, r4, 0
	muls r1, r2
	adds r1, r3
	ldrb r0, [r5]
	muls r0, r2
	adds r0, r3
	adds r0, 0x20
	ldrb r0, [r0]
	adds r1, 0x20
	strb r0, [r1]
	ldrb r0, [r5]
	muls r0, r2
	adds r0, r3
	adds r0, 0x20
	ldrb r0, [r0]
	b _08043FA8
	.pool
_08043F84:
	mov r2, r8
	strb r6, [r2]
	movs r3, 0x58
	adds r0, r6, 0
	muls r0, r3
	ldr r5, =gBattleMons
	adds r0, r5
	adds r2, r0, 0
	adds r2, 0x20
	ldrb r1, [r2]
	cmp r1, 0
	beq _08043FB6
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08043FB6
	ldr r0, [sp, 0x1C]
	strb r1, [r0]
	ldrb r0, [r2]
_08043FA8:
	ldr r1, =gLastUsedAbility
	strb r0, [r1]
_08043FAC:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_08043FB6:
	mov r2, r9
	cmp r2, 0
	beq _08043FBE
	b _08044340
_08043FBE:
	ldr r3, [sp, 0x1C]
	adds r3, 0x58
	str r3, [sp, 0x1C]
	ldr r5, [sp, 0x20]
	adds r5, 0x4
	str r5, [sp, 0x20]
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	bge _08043FD6
	b _08043E22
_08043FD6:
	b _0804441E
	.pool
_08043FE4:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	cmp r4, r1
	blt _08043FF0
	b _0804441E
_08043FF0:
	ldr r0, =gBattleMons
	adds r5, r1, 0
	ldr r2, =gStatuses3
	adds r3, r0, 0
	adds r3, 0x20
	movs r6, 0x80
	lsls r6, 12
_08043FFE:
	ldrb r1, [r3]
	cmp r1, 0x16
	bne _0804400E
	ldr r0, [r2]
	ands r0, r6
	cmp r0, 0
	beq _0804400E
	b _080443B4
_0804400E:
	adds r2, 0x4
	adds r3, 0x58
	adds r4, 0x1
	cmp r4, r5
	blt _08043FFE
	b _0804441E
	.pool
_08044028:
	mov r0, r10
	bl GetBankSide
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0804403E
	b _0804441E
_0804403E:
	ldr r7, =gBattleMons
_08044040:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	adds r3, r4, 0x1
	cmp r0, r5
	beq _0804406A
	movs r0, 0x58
	muls r0, r4
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _0804406A
	ldr r0, =gLastUsedAbility
	strb r6, [r0]
	lsls r0, r3, 24
	lsrs r0, 24
	mov r9, r0
_0804406A:
	adds r4, r3, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08044040
	b _0804441E
	.pool
_08044084:
	mov r0, r10
	bl GetBankSide
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0804409A
	b _0804441E
_0804409A:
	ldr r7, =gBattleMons
_0804409C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	adds r3, r4, 0x1
	cmp r0, r5
	bne _080440C6
	movs r0, 0x58
	muls r0, r4
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _080440C6
	ldr r0, =gLastUsedAbility
	strb r6, [r0]
	lsls r0, r3, 24
	lsrs r0, 24
	mov r9, r0
_080440C6:
	adds r4, r3, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _0804409C
	b _0804441E
	.pool
_080440E0:
	ldrb r0, [r7]
	cmp r0, 0xFD
	beq _08044104
	cmp r0, 0xFE
	beq _0804413C
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	adds r5, r0, 0
	ldrb r0, [r5]
	cmp r4, r0
	blt _080440F8
	b _0804441E
_080440F8:
	ldr r2, =gBattleMons
	b _08044174
	.pool
_08044104:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08044110
	b _0804441E
_08044110:
	ldr r5, =gStatuses3
	movs r2, 0x80
	lsls r2, 9
	adds r1, r0, 0
_08044118:
	lsls r0, r4, 2
	adds r0, r5
	ldr r0, [r0]
	ands r0, r2
	adds r3, r4, 0x1
	cmp r0, 0
	beq _0804412C
	lsls r0, r3, 24
	lsrs r0, 24
	mov r9, r0
_0804412C:
	adds r4, r3, 0
	cmp r4, r1
	blt _08044118
	b _0804441E
	.pool
_0804413C:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08044148
	b _0804441E
_08044148:
	ldr r5, =gStatuses3
	movs r2, 0x80
	lsls r2, 10
	adds r1, r0, 0
_08044150:
	lsls r0, r4, 2
	adds r0, r5
	ldr r0, [r0]
	ands r0, r2
	adds r3, r4, 0x1
	cmp r0, 0
	beq _08044164
	lsls r0, r3, 24
	lsrs r0, 24
	mov r9, r0
_08044164:
	adds r4, r3, 0
	cmp r4, r1
	blt _08044150
	b _0804441E
	.pool
_08044174:
	movs r0, 0x58
	muls r0, r4
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	adds r3, r4, 0x1
	cmp r0, r6
	bne _0804418C
	strb r6, [r7]
	lsls r0, r3, 24
	lsrs r0, 24
	mov r9, r0
_0804418C:
	adds r4, r3, 0
	ldrb r1, [r5]
	cmp r4, r1
	blt _08044174
	b _0804441E
_08044196:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _080441A2
	b _0804441E
_080441A2:
	ldr r2, =gBattleMons
	mov r8, r2
	adds r2, r0, 0
	movs r5, 0x58
_080441AA:
	adds r0, r4, 0
	muls r0, r5
	mov r3, r8
	adds r1, r0, r3
	adds r0, r1, 0
	adds r0, 0x20
	ldrb r0, [r0]
	adds r3, r4, 0x1
	cmp r0, r6
	bne _080441CC
	ldrh r0, [r1, 0x28]
	cmp r0, 0
	beq _080441CC
	strb r6, [r7]
	lsls r0, r3, 24
	lsrs r0, 24
	mov r9, r0
_080441CC:
	adds r4, r3, 0
	cmp r4, r2
	blt _080441AA
	b _0804441E
	.pool
_080441DC:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _080441E8
	b _0804441E
_080441E8:
	ldr r7, =gBattleMons
	adds r1, r0, 0
	movs r5, 0x58
	ldr r2, =gLastUsedAbility
_080441F0:
	adds r0, r4, 0
	muls r0, r5
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	adds r3, r4, 0x1
	cmp r0, r6
	bne _0804420C
	cmp r4, r10
	beq _0804420C
	strb r6, [r2]
	lsls r0, r3, 24
	lsrs r0, 24
	mov r9, r0
_0804420C:
	adds r4, r3, 0
	cmp r4, r1
	blt _080441F0
	b _0804441E
	.pool
_08044220:
	mov r0, r10
	bl GetBankSide
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08044236
	b _0804441E
_08044236:
	ldr r7, =gBattleMons
_08044238:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	beq _08044264
	movs r0, 0x58
	muls r0, r4
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _08044264
	ldr r0, =gLastUsedAbility
	strb r6, [r0]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_08044264:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08044238
	b _0804441E
	.pool
_0804427C:
	mov r0, r10
	bl GetBankSide
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08044292
	b _0804441E
_08044292:
	ldr r7, =gBattleMons
_08044294:
	lsls r0, r4, 24
	lsrs r0, 24
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, r5
	bne _080442C0
	movs r0, 0x58
	muls r0, r4
	adds r0, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _080442C0
	ldr r0, =gLastUsedAbility
	strb r6, [r0]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080442C0:
	adds r4, 0x1
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r4, r0
	blt _08044294
	b _0804441E
	.pool
_080442D8:
	ldr r0, =gUnknown_082DB4A9
	bl b_push_move_exec
	ldr r0, =gBattleScripting
	strb r6, [r0, 0x17]
_080442E2:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x7F
	mov r1, r9
	subs r1, 0x1
	strb r1, [r0]
	b _0804441E
	.pool
_080442FC:
	ldr r0, =gUnknown_082DB4A9
	bl b_push_move_exec
	ldr r0, =gBattleScripting
	mov r5, r10
	strb r5, [r0, 0x17]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x7F
	mov r1, r9
	subs r1, 0x1
	strb r1, [r0]
	b _0804443A
	.pool
_08044324:
	strb r1, [r7]
	ldr r0, [r2]
	ldr r1, =0xfff7ffff
	ands r0, r1
	str r0, [r2]
	ldr r0, =gUnknown_082DB4B8
	bl b_push_move_exec
	b _080443C8
	.pool
_08044340:
	ldr r0, =gUnknown_082DB452
	bl b_push_move_exec
	ldr r1, =gStatuses3
	ldr r0, [sp, 0x18]
	adds r1, r0, r1
	ldr r0, [r1]
	ldr r2, =0xffefffff
	ands r0, r2
	str r0, [r1]
	ldr r0, =gBattleScripting
	strb r4, [r0, 0x17]
	ldr r1, =gBattleTextBuff1
	movs r4, 0xFD
	strb r4, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x1]
	ldr r2, =gActiveBank
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
	ldr r1, =gBattleTextBuff2
	strb r4, [r1]
	movs r0, 0x9
	strb r0, [r1, 0x1]
	ldr r0, =gLastUsedAbility
	ldrb r0, [r0]
	strb r0, [r1, 0x2]
	movs r0, 0x1
	negs r0, r0
	strb r0, [r1, 0x3]
	b _0804441E
	.pool
_080443B4:
	strb r1, [r7]
	ldr r0, [r2]
	ldr r1, =0xfff7ffff
	ands r0, r1
	str r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB4C1
	str r0, [r1]
_080443C8:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0xD8
	strb r4, [r0]
_080443D0:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	b _0804441E
	.pool
_080443EC:
	movs r4, 0
	ldr r0, =gNoOfAllBanks
	ldrb r1, [r0]
	cmp r4, r1
	bge _0804441E
	ldr r0, =gBattleMons
	adds r2, r1, 0
	adds r1, r0, 0
	adds r1, 0x20
	ldr r3, =gLastUsedAbility
_08044400:
	ldrb r0, [r1]
	cmp r0, r6
	bne _08044416
	cmp r4, r10
	beq _08044416
	strb r6, [r3]
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_08044416:
	adds r1, 0x58
	adds r4, 0x1
	cmp r4, r2
	blt _08044400
_0804441E:
	mov r1, r9
	cmp r1, 0
	beq _0804443A
_08044424:
	ldr r2, [sp, 0x4]
	cmp r2, 0xB
	bhi _0804443A
	ldr r1, =gLastUsedAbility
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0804443A
	adds r1, r0, 0
	mov r0, r10
	bl RecordAbilityBattle
_0804443A:
	mov r0, r9
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AbilityBattleEffects

	thumb_func_start b_call_bc_move_exec
b_call_bc_move_exec: @ 8044458
	ldr r1, =gBattlescriptCurrInstr
	str r0, [r1]
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	adds r3, r2, 0
	adds r3, 0x20
	ldrb r0, [r3]
	adds r1, r0, 0x1
	strb r1, [r3]
	lsls r0, 24
	lsrs r0, 22
	adds r2, r0
	ldr r1, =gUnknown_03005D04
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, =bc_move_exec_returning
	str r0, [r1]
	ldr r1, =gFightStateTracker
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end b_call_bc_move_exec

	thumb_func_start b_push_move_exec
b_push_move_exec: @ 8044498
	push {r4,lr}
	adds r4, r0, 0
	bl b_movescr_stack_push_cursor
	ldr r0, =gBattlescriptCurrInstr
	str r4, [r0]
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r2, [r0, 0xC]
	adds r3, r2, 0
	adds r3, 0x20
	ldrb r0, [r3]
	adds r1, r0, 0x1
	strb r1, [r3]
	lsls r0, 24
	lsrs r0, 22
	adds r2, r0
	ldr r1, =gUnknown_03005D04
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, =sub_803E08C
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_push_move_exec

	thumb_func_start berry_effects_maybe
berry_effects_maybe: @ 80444DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	movs r0, 0
	mov r10, r0
	movs r1, 0
	str r1, [sp, 0xC]
	add r0, sp, 0x4
	strb r1, [r0]
	ldr r4, =gUnknown_02024208
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r0, r1
	ldrh r0, [r0, 0x2E]
	strh r0, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _08044534
	ldr r1, =gEnigmaBerries
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r5, [r0, 0x7]
	ldrb r0, [r0, 0x1A]
	b _08044548
	.pool
_08044534:
	ldrh r0, [r4]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r0, 24
_08044548:
	mov r9, r0
	ldr r1, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldrh r0, [r0, 0x2E]
	str r0, [sp, 0x14]
	cmp r0, 0xAF
	bne _0804457C
	ldr r1, =gEnigmaBerries
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r3, [r0, 0x7]
	mov r8, r3
	ldrb r0, [r0, 0x1A]
	b _08044592
	.pool
_0804457C:
	ldr r0, [sp, 0x14]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, [sp, 0x14]
	bl ItemId_GetHoldEffectParam
	lsls r0, 24
	lsrs r0, 24
_08044592:
	str r0, [sp, 0x10]
	ldr r2, =gBattleMons
	ldr r0, =gBankTarget
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r4, [r0, 0x2E]
	cmp r4, 0xAF
	beq _080445B2
	adds r0, r4, 0
	bl ItemId_GetHoldEffect
	adds r0, r4, 0
	bl ItemId_GetHoldEffectParam
_080445B2:
	ldr r0, [sp, 0x8]
	cmp r0, 0x4
	bls _080445BC
	bl _0804582A
_080445BC:
	lsls r0, 2
	ldr r1, =_080445D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080445D4:
	.4byte _080445E8
	.4byte _08044688
	.4byte _0804582A
	.4byte _08045280
	.4byte _080456D0
_080445E8:
	cmp r5, 0x17
	beq _08044618
	cmp r5, 0x20
	beq _080445F4
	bl _0804582A
_080445F4:
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	beq _08044604
	bl _0804582A
_08044604:
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	adds r0, 0x4A
	movs r1, 0x2
	strb r1, [r0]
	bl _0804582A
	.pool
_08044618:
	ldr r1, =gBattleMons
	mov r8, r1
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x18
	adds r1, r0
	movs r2, 0x6
	movs r3, 0x7
	mov r10, r3
_0804462E:
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0x5
	bgt _0804463C
	strb r2, [r1]
	movs r5, 0x5
	str r5, [sp, 0xC]
_0804463C:
	adds r1, 0x1
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r3, r10
	cmp r3, 0
	bge _0804462E
	ldr r5, [sp, 0xC]
	cmp r5, 0
	bne _08044654
	bl _0804582A
_08044654:
	ldr r0, =gBattleScripting
	strb r7, [r0, 0x17]
	ldr r0, =gUnknown_0202420F
	strb r7, [r0]
	ldr r1, =gActiveBank
	ldr r0, =gBankAttacker
	strb r7, [r0]
	strb r7, [r1]
	ldr r0, =gUnknown_082DB7AE
	bl b_call_bc_move_exec
	bl _0804582A
	.pool
_08044688:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r0, r1
	ldrh r0, [r0, 0x28]
	mov r8, r1
	cmp r0, 0
	bne _0804469C
	bl _0804582A
_0804469C:
	subs r0, r5, 0x1
	cmp r0, 0x2A
	bls _080446A6
	bl _080451D6
_080446A6:
	lsls r0, 2
	ldr r1, =_080446B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080446B8:
	.4byte _08044764
	.4byte _08044F44
	.4byte _08045008
	.4byte _08044F74
	.4byte _08044FA8
	.4byte _08044FD8
	.4byte _080447B0
	.4byte _08045044
	.4byte _08045074
	.4byte _0804497C
	.4byte _080449FC
	.4byte _08044A78
	.4byte _08044B0C
	.4byte _08044BA0
	.4byte _08044C34
	.4byte _08044C9C
	.4byte _08044CF0
	.4byte _08044D44
	.4byte _08044DAC
	.4byte _08044E10
	.4byte _08044E5C
	.4byte _080451D6
	.4byte _080448B0
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451A0
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _080451D6
	.4byte _0804491C
_08044764:
	movs r0, 0x58
	muls r0, r7
	mov r1, r8
	adds r2, r0, r1
	ldrh r0, [r2, 0x2C]
	ldrh r1, [r2, 0x28]
	lsrs r0, 1
	cmp r1, r0
	bls _0804477A
	bl _080451D6
_0804477A:
	cmp r6, 0
	beq _08044782
	bl _080451D6
_08044782:
	ldr r4, =gBattleMoveDamage
	mov r3, r9
	str r3, [r4]
	ldrh r3, [r2, 0x28]
	mov r5, r9
	adds r0, r3, r5
	ldrh r1, [r2, 0x2C]
	cmp r0, r1
	ble _08044798
	subs r0, r1, r3
	str r0, [r4]
_08044798:
	ldr r0, [r4]
	negs r0, r0
	str r0, [r4]
	ldr r0, =gUnknown_082DB7C4
	bl b_call_bc_move_exec
	b _08044B02
	.pool
_080447B0:
	cmp r6, 0
	beq _080447B8
	bl _080451D6
_080447B8:
	adds r0, r7, 0
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _080447DC
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	b _080447EA
	.pool
_080447DC:
	ldr r1, =gBattlePartyID
	lsls r0, r7, 1
	adds r0, r1
	ldrh r1, [r0]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gEnemyParty
_080447EA:
	adds r4, r1, r0
	movs r1, 0
	mov r10, r1
	add r5, sp, 0x4
_080447F2:
	mov r1, r10
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	mov r1, r10
	adds r1, 0x11
	adds r0, r4, 0
	bl GetMonData
	strb r0, [r5]
	adds r0, r4, 0
	movs r1, 0x15
	bl GetMonData
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r6, 0
	beq _08044822
	ldrb r0, [r5]
	cmp r0, 0
	beq _0804482C
_08044822:
	movs r2, 0x1
	add r10, r2
	mov r3, r10
	cmp r3, 0x3
	ble _080447F2
_0804482C:
	mov r5, r10
	cmp r5, 0x4
	bne _08044836
	bl _080451D6
_08044836:
	lsls r2, r5, 24
	lsrs r2, 24
	adds r0, r6, 0
	bl CalcPPWithPPUps
	lsls r0, 24
	lsrs r2, r0, 24
	add r0, sp, 0x4
	ldrb r0, [r0]
	mov r3, r9
	adds r1, r0, r3
	cmp r1, r2
	ble _08044860
	add r0, sp, 0x4
	strb r2, [r0]
	b _08044864
	.pool
_08044860:
	add r0, sp, 0x4
	strb r1, [r0]
_08044864:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x2
	strb r0, [r1, 0x1]
	strb r6, [r1, 0x2]
	lsrs r0, r6, 8
	strb r0, [r1, 0x3]
	movs r0, 0xFF
	strb r0, [r1, 0x4]
	ldr r0, =gUnknown_082DB7E1
	bl b_call_bc_move_exec
	mov r1, r10
	adds r1, 0x9
	lsls r1, 24
	lsrs r1, 24
	add r5, sp, 0x4
	str r5, [sp]
	movs r0, 0
	movs r2, 0
	movs r3, 0x1
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl dp01_battle_side_mark_buffer_for_execution
	movs r0, 0x3
	str r0, [sp, 0xC]
	bl _080451DE
	.pool
_080448B0:
	ldr r0, =gBattleMons
	movs r1, 0x58
	muls r1, r7
	adds r0, 0x18
	adds r1, r0
	movs r2, 0x6
	movs r3, 0x7
	mov r10, r3
_080448C0:
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0x5
	bgt _080448CE
	strb r2, [r1]
	movs r5, 0x5
	str r5, [sp, 0xC]
_080448CE:
	adds r1, 0x1
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r3, r10
	cmp r3, 0
	bge _080448C0
	movs r5, 0x8
	mov r10, r5
	ldr r0, [sp, 0xC]
	cmp r0, 0
	bne _080448EA
	bl _0804582A
_080448EA:
	ldr r0, =gBattleScripting
	strb r7, [r0, 0x17]
	ldr r0, =gUnknown_0202420F
	strb r7, [r0]
	ldr r1, =gActiveBank
	ldr r0, =gBankAttacker
	strb r7, [r0]
	strb r7, [r1]
	ldr r0, =gUnknown_082DB7AE
	bl b_call_bc_move_exec
	bl _080451D6
	.pool
_0804491C:
	movs r0, 0x58
	muls r0, r7
	mov r2, r8
	adds r1, r0, r2
	ldrh r0, [r1, 0x28]
	ldrh r3, [r1, 0x2C]
	cmp r0, r3
	bcc _08044930
	bl _080451D6
_08044930:
	cmp r6, 0
	beq _08044938
	bl _080451D6
_08044938:
	ldr r3, =gBattleMoveDamage
	ldrh r0, [r1, 0x2C]
	lsrs r0, 4
	str r0, [r3]
	cmp r0, 0
	bne _08044948
	movs r0, 0x1
	str r0, [r3]
_08044948:
	ldrh r2, [r1, 0x28]
	ldr r0, [r3]
	adds r0, r2, r0
	ldrh r1, [r1, 0x2C]
	cmp r0, r1
	ble _08044958
	subs r0, r1, r2
	str r0, [r3]
_08044958:
	ldr r0, [r3]
	negs r0, r0
	str r0, [r3]
	ldr r0, =gUnknown_082DB7F1
	bl b_call_bc_move_exec
	movs r0, 0x4
	str r0, [sp, 0xC]
	adds r0, r7, 0
	adds r1, r5, 0
	bl b_history__record_item_x12_of_player
	bl _080451D6
	.pool
_0804497C:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	str r1, [sp, 0x18]
	adds r4, r1, 0
	add r4, r8
	ldrh r0, [r4, 0x2C]
	ldrh r1, [r4, 0x28]
	lsrs r0, 1
	cmp r1, r0
	bls _08044996
	bl _080451D6
_08044996:
	cmp r6, 0
	beq _0804499E
	bl _080451D6
_0804499E:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x8
	strb r0, [r1, 0x1]
	strb r6, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r5, =gBattleMoveDamage
	ldrh r0, [r4, 0x2C]
	mov r1, r9
	bl __divsi3
	str r0, [r5]
	cmp r0, 0
	bne _080449C2
	movs r0, 0x1
	str r0, [r5]
_080449C2:
	ldrh r2, [r4, 0x28]
	ldr r0, [r5]
	adds r0, r2, r0
	ldrh r1, [r4, 0x2C]
	cmp r0, r1
	ble _080449D2
	subs r0, r1, r2
	str r0, [r5]
_080449D2:
	ldr r0, [r5]
	negs r0, r0
	str r0, [r5]
	mov r0, r8
	adds r0, 0x48
	ldr r2, [sp, 0x18]
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0
	bl sub_806E880
	lsls r0, 24
	cmp r0, 0
	bge _080449F0
	b _08044B7C
_080449F0:
	b _08044B90
	.pool
_080449FC:
	movs r0, 0x58
	adds r5, r7, 0
	muls r5, r0
	str r5, [sp, 0x1C]
	add r5, r8
	ldrh r0, [r5, 0x2C]
	ldrh r1, [r5, 0x28]
	lsrs r0, 1
	cmp r1, r0
	bls _08044A14
	bl _080451D6
_08044A14:
	cmp r6, 0
	beq _08044A1C
	bl _080451D6
_08044A1C:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x8
	strb r0, [r1, 0x1]
	movs r6, 0x1
	strb r6, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r4, =gBattleMoveDamage
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08044A40
	str r6, [r4]
_08044A40:
	ldrh r2, [r5, 0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, 0x2C]
	cmp r0, r1
	ble _08044A50
	subs r0, r1, r2
	str r0, [r4]
_08044A50:
	ldr r0, [r4]
	negs r0, r0
	str r0, [r4]
	mov r0, r8
	adds r0, 0x48
	ldr r1, [sp, 0x1C]
	adds r0, r1, r0
	ldr r0, [r0]
	movs r1, 0x1
	bl sub_806E880
	lsls r0, 24
	cmp r0, 0
	bge _08044A6E
	b _08044C0E
_08044A6E:
	b _08044C24
	.pool
_08044A78:
	movs r0, 0x58
	adds r3, r7, 0
	muls r3, r0
	str r3, [sp, 0x20]
	adds r5, r3, 0
	add r5, r8
	ldrh r0, [r5, 0x2C]
	ldrh r1, [r5, 0x28]
	lsrs r0, 1
	cmp r1, r0
	bls _08044A90
	b _080451D6
_08044A90:
	cmp r6, 0
	beq _08044A96
	b _080451D6
_08044A96:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x8
	strb r0, [r1, 0x1]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r4, =gBattleMoveDamage
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08044ABC
	movs r0, 0x1
	str r0, [r4]
_08044ABC:
	ldrh r2, [r5, 0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, 0x2C]
	cmp r0, r1
	ble _08044ACC
	subs r0, r1, r2
	str r0, [r4]
_08044ACC:
	ldr r0, [r4]
	negs r0, r0
	str r0, [r4]
	mov r0, r8
	adds r0, 0x48
	ldr r5, [sp, 0x20]
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, 0x2
	bl sub_806E880
	lsls r0, 24
	cmp r0, 0
	bge _08044AFC
	ldr r0, =gUnknown_082DB824
	bl b_call_bc_move_exec
	b _08044B02
	.pool
_08044AFC:
	ldr r0, =gUnknown_082DB7C4
	bl b_call_bc_move_exec
_08044B02:
	movs r0, 0x4
	str r0, [sp, 0xC]
	b _080451DE
	.pool
_08044B0C:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	str r1, [sp, 0x24]
	adds r5, r1, 0
	add r5, r8
	ldrh r0, [r5, 0x2C]
	ldrh r1, [r5, 0x28]
	lsrs r0, 1
	cmp r1, r0
	bls _08044B24
	b _080451D6
_08044B24:
	cmp r6, 0
	beq _08044B2A
	b _080451D6
_08044B2A:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x8
	strb r0, [r1, 0x1]
	movs r0, 0x3
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r4, =gBattleMoveDamage
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08044B50
	movs r0, 0x1
	str r0, [r4]
_08044B50:
	ldrh r2, [r5, 0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, 0x2C]
	cmp r0, r1
	ble _08044B60
	subs r0, r1, r2
	str r0, [r4]
_08044B60:
	ldr r0, [r4]
	negs r0, r0
	str r0, [r4]
	mov r0, r8
	adds r0, 0x48
	ldr r2, [sp, 0x24]
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, 0x3
	bl sub_806E880
	lsls r0, 24
	cmp r0, 0
	bge _08044B90
_08044B7C:
	ldr r0, =gUnknown_082DB824
	bl b_call_bc_move_exec
	b _08044B96
	.pool
_08044B90:
	ldr r0, =gUnknown_082DB7C4
	bl b_call_bc_move_exec
_08044B96:
	movs r3, 0x4
	str r3, [sp, 0xC]
	b _080451DE
	.pool
_08044BA0:
	movs r0, 0x58
	adds r5, r7, 0
	muls r5, r0
	str r5, [sp, 0x28]
	add r5, r8
	ldrh r0, [r5, 0x2C]
	ldrh r1, [r5, 0x28]
	lsrs r0, 1
	cmp r1, r0
	bls _08044BB6
	b _080451D6
_08044BB6:
	cmp r6, 0
	beq _08044BBC
	b _080451D6
_08044BBC:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x8
	strb r0, [r1, 0x1]
	movs r0, 0x4
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r4, =gBattleMoveDamage
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	str r0, [r4]
	cmp r0, 0
	bne _08044BE2
	movs r0, 0x1
	str r0, [r4]
_08044BE2:
	ldrh r2, [r5, 0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, 0x2C]
	cmp r0, r1
	ble _08044BF2
	subs r0, r1, r2
	str r0, [r4]
_08044BF2:
	ldr r0, [r4]
	negs r0, r0
	str r0, [r4]
	mov r0, r8
	adds r0, 0x48
	ldr r1, [sp, 0x28]
	adds r0, r1, r0
	ldr r0, [r0]
	movs r1, 0x4
	bl sub_806E880
	lsls r0, 24
	cmp r0, 0
	bge _08044C24
_08044C0E:
	ldr r0, =gUnknown_082DB824
	bl b_call_bc_move_exec
	b _08044C2A
	.pool
_08044C24:
	ldr r0, =gUnknown_082DB7C4
	bl b_call_bc_move_exec
_08044C2A:
	movs r2, 0x4
	str r2, [sp, 0xC]
	b _080451DE
	.pool
_08044C34:
	movs r0, 0x58
	muls r0, r7
	mov r3, r8
	adds r5, r0, r3
	ldrh r4, [r5, 0x28]
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	cmp r4, r0
	ble _08044C4C
	b _080451D6
_08044C4C:
	cmp r6, 0
	beq _08044C52
	b _080451D6
_08044C52:
	movs r0, 0x19
	ldrsb r0, [r5, r0]
	cmp r0, 0xB
	ble _08044C5C
	b _080451D6
_08044C5C:
	ldr r1, =gBattleTextBuff1
	movs r2, 0xFD
	strb r2, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	movs r0, 0x1
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r1, =gBattleTextBuff2
	strb r2, [r1]
	strb r6, [r1, 0x1]
	movs r0, 0xD2
	strb r0, [r1, 0x2]
	strb r6, [r1, 0x3]
	subs r0, 0xD3
	strb r0, [r1, 0x4]
	ldr r0, =gUnknown_0202420E
	strb r7, [r0]
	ldr r1, =gBattleScripting
	movs r0, 0x11
	strb r0, [r1, 0x1A]
	movs r0, 0xF
	b _08044DF0
	.pool
_08044C9C:
	movs r0, 0x58
	muls r0, r7
	mov r1, r8
	adds r5, r0, r1
	ldrh r4, [r5, 0x28]
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	cmp r4, r0
	ble _08044CB4
	b _080451D6
_08044CB4:
	cmp r6, 0
	beq _08044CBA
	b _080451D6
_08044CBA:
	movs r0, 0x1A
	ldrsb r0, [r5, r0]
	cmp r0, 0xB
	ble _08044CC4
	b _080451D6
_08044CC4:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	movs r0, 0x2
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r0, =gUnknown_0202420E
	strb r7, [r0]
	ldr r1, =gBattleScripting
	movs r0, 0x12
	strb r0, [r1, 0x1A]
	movs r0, 0x10
	b _08044D8A
	.pool
_08044CF0:
	movs r0, 0x58
	muls r0, r7
	mov r3, r8
	adds r5, r0, r3
	ldrh r4, [r5, 0x28]
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	cmp r4, r0
	ble _08044D08
	b _080451D6
_08044D08:
	cmp r6, 0
	beq _08044D0E
	b _080451D6
_08044D0E:
	movs r0, 0x1B
	ldrsb r0, [r5, r0]
	cmp r0, 0xB
	ble _08044D18
	b _080451D6
_08044D18:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	movs r0, 0x3
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r0, =gUnknown_0202420E
	strb r7, [r0]
	ldr r1, =gBattleScripting
	movs r0, 0x13
	strb r0, [r1, 0x1A]
	movs r0, 0x11
	b _08044DF0
	.pool
_08044D44:
	movs r0, 0x58
	muls r0, r7
	mov r1, r8
	adds r5, r0, r1
	ldrh r4, [r5, 0x28]
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	cmp r4, r0
	ble _08044D5C
	b _080451D6
_08044D5C:
	cmp r6, 0
	beq _08044D62
	b _080451D6
_08044D62:
	movs r0, 0x1C
	ldrsb r0, [r5, r0]
	cmp r0, 0xB
	ble _08044D6C
	b _080451D6
_08044D6C:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	movs r0, 0x4
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r0, =gUnknown_0202420E
	strb r7, [r0]
	ldr r1, =gBattleScripting
	movs r0, 0x14
	strb r0, [r1, 0x1A]
	movs r0, 0x12
_08044D8A:
	strb r0, [r1, 0x10]
	strb r6, [r1, 0x11]
	ldr r0, =gUnknown_082DB84E
	bl b_call_bc_move_exec
	movs r2, 0x5
	str r2, [sp, 0xC]
	b _080451DE
	.pool
_08044DAC:
	movs r0, 0x58
	muls r0, r7
	mov r3, r8
	adds r5, r0, r3
	ldrh r4, [r5, 0x28]
	ldrh r0, [r5, 0x2C]
	mov r1, r9
	bl __divsi3
	cmp r4, r0
	ble _08044DC4
	b _080451D6
_08044DC4:
	cmp r6, 0
	beq _08044DCA
	b _080451D6
_08044DCA:
	movs r0, 0x1D
	ldrsb r0, [r5, r0]
	cmp r0, 0xB
	ble _08044DD4
	b _080451D6
_08044DD4:
	ldr r1, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r0, =gUnknown_0202420E
	strb r7, [r0]
	ldr r1, =gBattleScripting
	movs r0, 0x15
	strb r0, [r1, 0x1A]
	movs r0, 0x13
_08044DF0:
	strb r0, [r1, 0x10]
	strb r6, [r1, 0x11]
	ldr r0, =gUnknown_082DB84E
	bl b_call_bc_move_exec
	movs r5, 0x5
	str r5, [sp, 0xC]
	b _080451DE
	.pool
_08044E10:
	movs r0, 0x58
	adds r5, r7, 0
	muls r5, r0
	mov r1, r8
	adds r0, r5, r1
	ldrh r4, [r0, 0x28]
	ldrh r0, [r0, 0x2C]
	mov r1, r9
	bl __divsi3
	cmp r4, r0
	ble _08044E2A
	b _080451D6
_08044E2A:
	cmp r6, 0
	beq _08044E30
	b _080451D6
_08044E30:
	mov r0, r8
	adds r0, 0x50
	adds r1, r5, r0
	ldr r2, [r1]
	movs r3, 0x80
	lsls r3, 13
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _08044E46
	b _080451D6
_08044E46:
	orrs r2, r3
	str r2, [r1]
	ldr r0, =gUnknown_082DB869
	bl b_call_bc_move_exec
	movs r2, 0x2
	str r2, [sp, 0xC]
	b _080451DE
	.pool
_08044E5C:
	cmp r6, 0
	beq _08044E62
	b _080451D6
_08044E62:
	movs r0, 0x58
	adds r5, r7, 0
	muls r5, r0
	mov r3, r8
	adds r0, r5, r3
	ldrh r4, [r0, 0x28]
	ldrh r0, [r0, 0x2C]
	mov r1, r9
	bl __divsi3
	cmp r4, r0
	ble _08044E7C
	b _080451D6
_08044E7C:
	movs r0, 0
	mov r10, r0
	adds r0, r5, 0x1
	mov r1, r8
	adds r1, 0x18
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xB
	ble _08044EAC
	mov r0, r8
	adds r0, 0x19
	adds r1, r5, r0
_08044E98:
	adds r1, 0x1
	movs r2, 0x1
	add r10, r2
	mov r3, r10
	cmp r3, 0x4
	bgt _08044EAC
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0xB
	bgt _08044E98
_08044EAC:
	mov r5, r10
	cmp r5, 0x5
	bne _08044EB4
	b _080451D6
_08044EB4:
	movs r0, 0x58
	muls r0, r7
	adds r4, r0, 0x1
	ldr r5, =gUnknown_0202409C
_08044EBC:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	adds r0, r4
	adds r0, r5
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0xC
	beq _08044EBC
	ldr r1, =gBattleTextBuff1
	movs r2, 0
	movs r3, 0xFD
	strb r3, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x1]
	mov r0, r10
	adds r0, 0x1
	strb r0, [r1, 0x2]
	movs r0, 0xFF
	strb r0, [r1, 0x3]
	ldr r0, =gBattleTextBuff2
	strb r3, [r0]
	strb r2, [r0, 0x1]
	movs r1, 0xD1
	strb r1, [r0, 0x2]
	strb r2, [r0, 0x3]
	strb r2, [r0, 0x4]
	movs r1, 0xD2
	strb r1, [r0, 0x5]
	strb r2, [r0, 0x6]
	subs r1, 0xD3
	strb r1, [r0, 0x7]
	ldr r0, =gUnknown_0202420E
	strb r7, [r0]
	ldr r1, =gBattleScripting
	mov r0, r10
	adds r0, 0x21
	strb r0, [r1, 0x1A]
	adds r0, 0x6
	strb r0, [r1, 0x10]
	strb r2, [r1, 0x11]
	ldr r0, =gUnknown_082DB84E
	bl b_call_bc_move_exec
	movs r0, 0x5
	str r0, [sp, 0xC]
	b _080451DE
	.pool
_08044F44:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x4C
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	bne _08044F5C
	b _080451D6
_08044F5C:
	movs r0, 0x41
	negs r0, r0
	ands r2, r0
	str r2, [r1]
	ldr r0, =gUnknown_082DB706
	bl b_call_bc_move_exec
	movs r1, 0x1
	str r1, [sp, 0xC]
	b _080451DE
	.pool
_08044F74:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x4C
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x88
	ands r0, r2
	cmp r0, 0
	bne _08044F8C
	b _080451D6
_08044F8C:
	ldr r0, =0xfffff077
	ands r2, r0
	str r2, [r1]
	ldr r0, =gUnknown_082DB71E
	bl b_call_bc_move_exec
	movs r2, 0x1
	str r2, [sp, 0xC]
	b _080451DE
	.pool
_08044FA8:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x4C
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	bne _08044FC0
	b _080451D6
_08044FC0:
	movs r0, 0x11
	negs r0, r0
	ands r2, r0
	str r2, [r1]
	ldr r0, =gUnknown_082DB736
	bl b_call_bc_move_exec
	movs r3, 0x1
	str r3, [sp, 0xC]
	b _080451DE
	.pool
_08044FD8:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x4C
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	bne _08044FF0
	b _080451D6
_08044FF0:
	movs r0, 0x21
	negs r0, r0
	ands r2, r0
	str r2, [r1]
	ldr r0, =gUnknown_082DB74E
	bl b_call_bc_move_exec
	movs r5, 0x1
	str r5, [sp, 0xC]
	b _080451DE
	.pool
_08045008:
	movs r0, 0x58
	adds r3, r7, 0
	muls r3, r0
	mov r0, r8
	adds r0, 0x4C
	adds r2, r3, r0
	ldr r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _08045020
	b _080451D6
_08045020:
	movs r0, 0x8
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	mov r1, r8
	adds r1, 0x50
	adds r1, r3, r1
	ldr r0, [r1]
	ldr r2, =0xf7ffffff
	ands r0, r2
	str r0, [r1]
	ldr r0, =gUnknown_082DB766
	b _0804518A
	.pool
_08045044:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x50
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0x7
	ands r0, r2
	cmp r0, 0
	bne _0804505C
	b _080451D6
_0804505C:
	movs r0, 0x8
	negs r0, r0
	ands r2, r0
	str r2, [r1]
	ldr r0, =gUnknown_082DB77E
	bl b_call_bc_move_exec
	movs r1, 0x2
	str r1, [sp, 0xC]
	b _080451DE
	.pool
_08045074:
	movs r0, 0x58
	adds r5, r7, 0
	muls r5, r0
	mov r0, r8
	adds r0, 0x4C
	adds r4, r5, r0
	ldr r2, [r4]
	ldrb r0, [r4]
	cmp r0, 0
	bne _0804509A
	mov r0, r8
	adds r0, 0x50
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0804509A
	b _080451D6
_0804509A:
	movs r3, 0
	mov r10, r3
	movs r0, 0x88
	ands r2, r0
	cmp r2, 0
	beq _080450B2
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC70
	bl StringCopy
	movs r0, 0x1
	mov r10, r0
_080450B2:
	ldr r0, [r4]
	movs r1, 0x7
	mov r9, r1
	ands r0, r1
	mov r6, r8
	adds r6, 0x50
	cmp r0, 0
	beq _080450D8
	adds r2, r5, r6
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC78
	bl StringCopy
	movs r2, 0x1
	add r10, r2
_080450D8:
	ldr r0, [r4]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080450EE
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC80
	bl StringCopy
	movs r3, 0x1
	add r10, r3
_080450EE:
	ldr r0, [r4]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _08045104
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC88
	bl StringCopy
	movs r0, 0x1
	add r10, r0
_08045104:
	ldr r0, [r4]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804511A
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC90
	bl StringCopy
	movs r1, 0x1
	add r10, r1
_0804511A:
	adds r0, r5, r6
	ldr r0, [r0]
	mov r2, r9
	ands r0, r2
	cmp r0, 0
	beq _08045132
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC98
	bl StringCopy
	movs r3, 0x1
	add r10, r3
_08045132:
	mov r5, r10
	cmp r5, 0x1
	bgt _08045164
	ldr r1, =gBattleCommunication
	movs r0, 0
	b _08045168
	.pool
_08045164:
	ldr r1, =gBattleCommunication
	movs r0, 0x1
_08045168:
	strb r0, [r1, 0x5]
	ldr r2, =gBattleMons
	movs r0, 0x58
	adds r3, r7, 0
	muls r3, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r0, r3, r0
	movs r1, 0
	str r1, [r0]
	adds r2, 0x50
	adds r3, r2
	ldr r0, [r3]
	subs r1, 0x8
	ands r0, r1
	str r0, [r3]
	ldr r0, =gUnknown_082DB794
_0804518A:
	bl b_call_bc_move_exec
	movs r0, 0x1
	str r0, [sp, 0xC]
	b _080451DE
	.pool
_080451A0:
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x50
	adds r1, r0
	ldr r2, [r1]
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r2
	cmp r0, 0
	beq _080451D6
	ldr r0, =0xfff0ffff
	ands r2, r0
	str r2, [r1]
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BCA0
	bl StringCopy
	ldr r0, =gUnknown_082DB794
	bl b_call_bc_move_exec
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
	movs r1, 0x2
	str r1, [sp, 0xC]
_080451D6:
	ldr r2, [sp, 0xC]
	cmp r2, 0
	bne _080451DE
	b _0804582A
_080451DE:
	ldr r0, =gBattleScripting
	strb r7, [r0, 0x17]
	ldr r0, =gUnknown_0202420F
	strb r7, [r0]
	ldr r4, =gActiveBank
	ldr r0, =gBankAttacker
	strb r7, [r0]
	strb r7, [r4]
	ldr r3, [sp, 0xC]
	cmp r3, 0x1
	beq _08045220
	cmp r3, 0x3
	beq _08045226
	b _0804582A
	.pool
_08045220:
	movs r0, 0x58
	muls r0, r7
	b _0804568C
_08045226:
	ldr r4, =gBattleMons
	movs r0, 0x58
	adds r3, r7, 0
	muls r3, r0
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	beq _08045242
	b _0804582A
_08045242:
	ldr r1, =gDisableStructs
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	mov r5, r10
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08045262
	b _0804582A
_08045262:
	adds r1, r5, r3
	adds r0, r4, 0
	adds r0, 0x24
	adds r1, r0
	add r0, sp, 0x4
	ldrb r0, [r0]
	strb r0, [r1]
	b _0804582A
	.pool
_08045280:
	movs r7, 0
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r7, r0
	bcc _0804528C
	b _0804582A
_0804528C:
	ldr r4, =gUnknown_02024208
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r0, r1
	ldrh r0, [r0, 0x2E]
	strh r0, [r4]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _080452C0
	ldr r1, =gEnigmaBerries
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r5, [r0, 0x7]
	b _080452D0
	.pool
_080452C0:
	ldrh r0, [r4]
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r5, r0, 24
	ldrh r0, [r4]
	bl ItemId_GetHoldEffectParam
_080452D0:
	subs r0, r5, 0x2
	cmp r0, 0x1A
	bls _080452D8
	b _08045674
_080452D8:
	lsls r0, 2
	ldr r1, =_080452E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080452E8:
	.4byte _08045354
	.4byte _08045444
	.4byte _08045390
	.4byte _080453CC
	.4byte _08045408
	.4byte _08045674
	.4byte _0804548C
	.4byte _08045520
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045614
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _08045674
	.4byte _080454C8
_08045354:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r1, 0x4C
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0804536A
	b _08045674
_0804536A:
	movs r0, 0x41
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB70C
	str r0, [r1]
	movs r0, 0x1
	str r0, [sp, 0xC]
	b _0804567A
	.pool
_08045390:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r1, 0x4C
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x88
	ands r0, r1
	cmp r0, 0
	bne _080453A6
	b _08045674
_080453A6:
	ldr r0, =0xfffff077
	ands r1, r0
	str r1, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB724
	str r0, [r1]
	movs r1, 0x1
	str r1, [sp, 0xC]
	b _0804567A
	.pool
_080453CC:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r1, 0x4C
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _080453E2
	b _08045674
_080453E2:
	movs r0, 0x11
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB73C
	str r0, [r1]
	movs r2, 0x1
	str r2, [sp, 0xC]
	b _0804567A
	.pool
_08045408:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r1, 0x4C
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _0804541E
	b _08045674
_0804541E:
	movs r0, 0x21
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB754
	str r0, [r1]
	movs r3, 0x1
	str r3, [sp, 0xC]
	b _0804567A
	.pool
_08045444:
	ldr r2, =gBattleMons
	movs r0, 0x58
	adds r4, r7, 0
	muls r4, r0
	adds r0, r2, 0
	adds r0, 0x4C
	adds r3, r4, r0
	ldr r1, [r3]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0804545E
	b _08045674
_0804545E:
	movs r0, 0x8
	negs r0, r0
	ands r1, r0
	str r1, [r3]
	adds r2, 0x50
	adds r2, r4, r2
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB76C
	b _080455DC
	.pool
_0804548C:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r1, 0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _080454A2
	b _08045674
_080454A2:
	movs r0, 0x8
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB784
	str r0, [r1]
	movs r0, 0x2
	str r0, [sp, 0xC]
	b _0804567A
	.pool
_080454C8:
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r7
	adds r1, 0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r1
	cmp r0, 0
	bne _080454E0
	b _08045674
_080454E0:
	ldr r0, =0xfff0ffff
	ands r1, r0
	str r1, [r2]
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BCA0
	bl StringCopy
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattleCommunication
	movs r0, 0
	strb r0, [r1, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB79A
	str r0, [r1]
	movs r1, 0x2
	str r1, [sp, 0xC]
	b _0804567A
	.pool
_08045520:
	ldr r4, =gBattleMons
	movs r0, 0x58
	adds r5, r7, 0
	muls r5, r0
	adds r0, r4, 0
	adds r0, 0x4C
	adds r6, r5, r0
	ldr r2, [r6]
	ldrb r0, [r6]
	cmp r0, 0
	bne _08045548
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	bne _08045548
	b _08045674
_08045548:
	movs r0, 0x88
	ands r2, r0
	cmp r2, 0
	beq _08045558
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC70
	bl StringCopy
_08045558:
	ldr r0, [r6]
	movs r2, 0x7
	mov r8, r2
	ands r0, r2
	adds r4, 0x50
	cmp r0, 0
	beq _08045578
	adds r2, r5, r4
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC78
	bl StringCopy
_08045578:
	ldr r0, [r6]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804558A
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC80
	bl StringCopy
_0804558A:
	ldr r0, [r6]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0804559C
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC88
	bl StringCopy
_0804559C:
	ldr r0, [r6]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080455AE
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC90
	bl StringCopy
_080455AE:
	adds r5, r4
	ldr r0, [r5]
	mov r3, r8
	ands r0, r3
	cmp r0, 0
	beq _080455C2
	ldr r0, =gBattleTextBuff1
	ldr r1, =gUnknown_0831BC98
	bl StringCopy
_080455C2:
	movs r4, 0
	str r4, [r6]
	ldr r0, [r5]
	movs r1, 0x8
	negs r1, r1
	ands r0, r1
	str r0, [r5]
	bl b_movescr_stack_push_cursor
	ldr r0, =gBattleCommunication
	strb r4, [r0, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB79A
_080455DC:
	str r0, [r1]
	movs r5, 0x1
	str r5, [sp, 0xC]
	b _0804567A
	.pool
_08045614:
	ldr r0, =gBattleMons
	mov r8, r0
	movs r0, 0x58
	adds r1, r7, 0
	muls r1, r0
	mov r0, r8
	adds r0, 0x18
	adds r1, r0
	movs r2, 0x6
	movs r3, 0x7
	mov r10, r3
_0804562A:
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0x5
	bgt _08045638
	strb r2, [r1]
	movs r5, 0x5
	str r5, [sp, 0xC]
_08045638:
	adds r1, 0x1
	movs r0, 0x1
	negs r0, r0
	add r10, r0
	mov r3, r10
	cmp r3, 0
	bge _0804562A
	ldr r5, [sp, 0xC]
	cmp r5, 0
	beq _080456B8
	ldr r0, =gBattleScripting
	strb r7, [r0, 0x17]
	ldr r0, =gUnknown_0202420F
	strb r7, [r0]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB7B4
	str r0, [r1]
	b _0804582A
	.pool
_08045674:
	ldr r0, [sp, 0xC]
	cmp r0, 0
	beq _080456B8
_0804567A:
	ldr r0, =gBattleScripting
	strb r7, [r0, 0x17]
	ldr r0, =gUnknown_0202420F
	strb r7, [r0]
	ldr r4, =gActiveBank
	strb r7, [r4]
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
_0804568C:
	ldr r1, =gUnknown_020240D0
	adds r0, r1
	str r0, [sp]
	movs r0, 0
	movs r1, 0x28
	movs r2, 0
	movs r3, 0x4
	bl dp01_build_cmdbuf_x02_a_b_varargs
	ldrb r0, [r4]
	bl dp01_battle_side_mark_buffer_for_execution
	b _0804582A
	.pool
_080456B8:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r7, r0
	bcs _080456C8
	b _0804528C
_080456C8:
	b _0804582A
	.pool
_080456D0:
	ldr r7, =gBattleMoveDamage
	ldr r0, [r7]
	cmp r0, 0
	bne _080456DA
	b _0804582A
_080456DA:
	mov r1, r8
	cmp r1, 0x1E
	beq _080456EC
	cmp r1, 0x3E
	beq _08045794
	b _0804582A
	.pool
_080456EC:
	ldr r0, =gBattleMoveFlags
	ldrb r1, [r0]
	movs r0, 0x29
	ands r0, r1
	cmp r0, 0
	beq _080456FA
	b _0804582A
_080456FA:
	ldr r2, =gSpecialStatuses
	ldr r4, =gBankTarget
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 2
	adds r0, r2, 0
	adds r0, 0x8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08045720
	adds r0, r2, 0
	adds r0, 0xC
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, 0
	bne _08045720
	b _0804582A
_08045720:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	ldr r2, [sp, 0x10]
	cmp r0, r2
	bcs _0804582A
	ldr r2, =gBattleMoves
	ldr r0, =gCurrentMove
	ldrh r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x8]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0804582A
	ldr r2, =gBattleMons
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _0804582A
	ldr r1, =gBattleCommunication
	movs r0, 0x8
	strb r0, [r1, 0x3]
	bl b_movescr_stack_push_cursor
	movs r0, 0
	movs r1, 0
	bl sub_8048760
	bl b_movescr_stack_pop_cursor
	b _0804582A
	.pool
_08045794:
	ldr r0, =gBattleMoveFlags
	ldrb r0, [r0]
	movs r5, 0x29
	ands r5, r0
	cmp r5, 0
	bne _0804582A
	ldr r1, =gSpecialStatuses
	ldr r4, =gBankTarget
	ldrb r2, [r4]
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	adds r6, r1, 0x4
	adds r0, r6
	ldr r1, [r0]
	cmp r1, 0
	beq _0804582A
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _0804582A
	ldr r0, =gBankAttacker
	ldrb r3, [r0]
	cmp r3, r2
	beq _0804582A
	ldr r2, =gBattleMons
	ldrb r1, [r0]
	movs r0, 0x58
	muls r0, r1
	adds r0, r2
	ldrh r1, [r0, 0x28]
	ldrh r0, [r0, 0x2C]
	cmp r1, r0
	beq _0804582A
	cmp r1, 0
	beq _0804582A
	ldr r0, =gUnknown_02024208
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0]
	ldr r0, =gUnknown_0202420F
	strb r3, [r0]
	ldr r0, =gBattleScripting
	strb r3, [r0, 0x17]
	ldrb r1, [r4]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ldr r1, [sp, 0x10]
	bl __divsi3
	negs r0, r0
	str r0, [r7]
	ldrb r1, [r4]
	cmp r0, 0
	bne _0804580C
	movs r0, 0x1
	negs r0, r0
	str r0, [r7]
_0804580C:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	str r5, [r0]
	bl b_movescr_stack_push_cursor
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB7F7
	str r0, [r1]
	ldr r0, [sp, 0xC]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
_0804582A:
	ldr r0, [sp, 0xC]
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end berry_effects_maybe

	thumb_func_start sub_8045868
sub_8045868: @ 8045868
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gDisableStructs
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	movs r2, 0
	strb r2, [r1, 0x10]
	ldr r1, =gBattleMons
	movs r2, 0x58
	adds r3, r0, 0
	muls r3, r2
	adds r1, 0x50
	adds r3, r1
	ldr r1, [r3]
	ldr r2, =0xfdffffff
	ands r1, r2
	str r1, [r3]
	ldr r1, =gStatuses3
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldr r2, =0xffffbfff
	ands r1, r2
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8045868

	thumb_func_start sub_80458B4
sub_80458B4: @ 80458B4
	push {lr}
	ldr r0, =gBattleExecBuffer
	ldr r0, [r0]
	cmp r0, 0
	bne _080458D0
	ldr r1, =gUnknown_0831BD10
	ldr r0, =gBattlescriptCurrInstr
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_080458D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80458B4

	thumb_func_start GetMoveTarget
GetMoveTarget: @ 80458E0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 24
	lsrs r0, r1, 24
	movs r5, 0
	cmp r0, 0
	beq _080458FE
	subs r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	b _0804590A
_080458FE:
	ldr r1, =gBattleMoves
	lsls r0, r7, 1
	adds r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r6, [r0, 0x6]
_0804590A:
	cmp r6, 0x40
	bls _08045910
	b _08045C20
_08045910:
	lsls r0, r6, 2
	ldr r1, =_08045924
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08045924:
	.4byte _08045A28
	.4byte _08045B28
	.4byte _08045C1C
	.4byte _08045C20
	.4byte _08045B40
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045B28
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C1C
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045B28
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045C20
	.4byte _08045B28
_08045A28:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gSideTimers
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r2, r0, r1
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _08045A5A
	ldr r1, =gBattleMons
	ldrb r4, [r2, 0x9]
	movs r0, 0x58
	muls r0, r4
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08045A5A
	b _08045B70
_08045A5A:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r7, 1
	mov r8, r0
_08045A6A:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gNoOfAllBanks
	ldrb r1, [r1]
	bl __modsi3
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gBankAttacker
	ldrb r3, [r6]
	cmp r5, r3
	beq _08045A6A
	adds r0, r5, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	beq _08045A6A
	ldr r0, =gAbsentBankFlags
	ldrb r2, [r0]
	ldr r1, =gBitTable
	lsls r0, r5, 2
	adds r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, 0
	bne _08045A6A
	ldr r0, =gBattleMoves
	mov r3, r8
	adds r1, r3, r7
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	cmp r0, 0xD
	beq _08045AB8
	b _08045C20
_08045AB8:
	ldrb r1, [r6]
	str r2, [sp]
	movs r0, 0x10
	movs r2, 0x1F
	movs r3, 0
	bl AbilityBattleEffects
	lsls r0, 24
	cmp r0, 0
	bne _08045ACE
	b _08045C20
_08045ACE:
	ldr r2, =gBattleMons
	movs r1, 0x58
	adds r0, r5, 0
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x1F
	bne _08045AE2
	b _08045C20
_08045AE2:
	movs r4, 0x2
	eors r5, r4
	adds r0, r5, 0
	muls r0, r1
	adds r0, r2
	adds r0, 0x20
	ldrb r1, [r0]
	adds r0, r5, 0
	bl RecordAbilityBattle
	ldr r1, =gSpecialStatuses
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0]
	orrs r1, r4
	strb r1, [r0]
	b _08045C20
	.pool
_08045B28:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	b _08045BD2
	.pool
_08045B40:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gSideTimers
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r2, r0, r1
	ldrb r0, [r2, 0x8]
	cmp r0, 0
	beq _08045B80
	ldr r1, =gBattleMons
	ldrb r4, [r2, 0x9]
	movs r0, 0x58
	muls r0, r4
	adds r0, r1
	ldrh r0, [r0, 0x28]
	cmp r0, 0
	beq _08045B80
_08045B70:
	adds r5, r4, 0
	b _08045C20
	.pool
_08045B80:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r4, 0x1
	ands r0, r4
	cmp r0, 0
	beq _08045BFC
	movs r0, 0x4
	ands r6, r0
	cmp r6, 0
	beq _08045BFC
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _08045BC0
	bl Random
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	beq _08045BBC
	movs r0, 0x1
	b _08045BD2
	.pool
_08045BBC:
	movs r0, 0x3
	b _08045BD2
_08045BC0:
	bl Random
	adds r1, r4, 0
	ands r1, r0
	cmp r1, 0
	beq _08045BD0
	movs r0, 0
	b _08045BD2
_08045BD0:
	movs r0, 0x2
_08045BD2:
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gAbsentBankFlags
	ldrb r1, [r0]
	ldr r2, =gBitTable
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _08045C20
	movs r0, 0x2
	eors r5, r0
	b _08045C20
	.pool
_08045BFC:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	bl GetBankIdentity
	adds r1, r0, 0
	movs r2, 0x1
	movs r0, 0x1
	ands r0, r1
	eors r0, r2
	bl GetBankByPlayerAI
	lsls r0, 24
	lsrs r5, r0, 24
	b _08045C20
	.pool
_08045C1C:
	ldr r0, =gBankAttacker
	ldrb r5, [r0]
_08045C20:
	ldr r0, =gBankAttacker
	ldrb r0, [r0]
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r0, r1
	strb r5, [r0, 0xC]
	adds r0, r5, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetMoveTarget

	thumb_func_start sub_8045C44
sub_8045C44: @ 8045C44
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08045C8A
	ldr r0, =gBattlePartyID
	lsls r4, 1
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r7, 0x64
	muls r0, r7
	ldr r6, =gPlayerParty
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	movs r1, 0xCD
	lsls r1, 1
	cmp r0, r1
	beq _08045C98
	ldrh r0, [r5]
	muls r0, r7
	adds r0, r6
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0x97
	beq _08045C98
_08045C8A:
	movs r0, 0x1
	b _08045CAE
	.pool
_08045C98:
	ldr r0, =gBattlePartyID
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x50
	movs r2, 0
	bl GetMonData
_08045CAE:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8045C44

	thumb_func_start sub_8045CBC
sub_8045CBC: @ 8045CBC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x10
	movs r6, 0
	ldr r5, =gBattleTypeFlags
	ldr r0, [r5]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	bne _08045DAC
	ldr r4, =gBankAttacker
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08045DAC
	ldrb r0, [r4]
	bl sub_8045C44
	cmp r0, 0
	beq _08045D76
	ldr r0, [r5]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _08045D08
	ldrb r0, [r4]
	bl GetBankIdentity
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	beq _08045DAC
_08045D08:
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	bne _08045DAC
	movs r0, 0x80
	lsls r0, 17
	ands r1, r0
	cmp r1, 0
	bne _08045DAC
	ldr r2, =gBattleMons
	ldr r0, =gBankAttacker
	ldrb r1, [r0]
	movs r0, 0x58
	muls r1, r0
	adds r0, r2, 0
	adds r0, 0x54
	adds r0, r1, r0
	ldr r0, [r0]
	adds r2, 0x3C
	adds r1, r2
	bl sub_806E8D4
	lsls r0, 24
	cmp r0, 0
	beq _08045DAC
	ldr r0, =0x0000086e
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	bne _08045DAC
	movs r6, 0xA
	ldr r0, =0x00000868
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08045D5A
	movs r6, 0x1E
_08045D5A:
	ldr r0, =0x0000086a
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08045D68
	movs r6, 0x32
_08045D68:
	ldr r0, =0x0000086c
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _08045D76
	movs r6, 0x46
_08045D76:
	ldr r5, =gBattleMons
	ldr r0, =gBankAttacker
	mov r8, r0
	ldrb r0, [r0]
	movs r7, 0x58
	muls r0, r7
	adds r0, r5
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, r6
	bls _08045DAC
	bl Random
	movs r1, 0xFF
	ands r1, r0
	mov r2, r8
	ldrb r0, [r2]
	adds r2, r0, 0
	muls r2, r7
	adds r0, r2, r5
	adds r0, 0x2A
	ldrb r0, [r0]
	adds r0, r6
	muls r0, r1
	asrs r4, r0, 8
	cmp r4, r6
	bge _08045DD4
_08045DAC:
	movs r0, 0
	b _08045FD0
	.pool
_08045DD4:
	ldr r3, =gCurrentMove
	ldrh r0, [r3]
	cmp r0, 0x63
	bne _08045DEA
	adds r0, r5, 0
	adds r0, 0x50
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r2, =0xff7fffff
	ands r1, r2
	str r1, [r0]
_08045DEA:
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r7
	adds r1, r5, 0
	adds r1, 0x4C
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x7
	ands r0, r1
	cmp r0, 0
	beq _08045E20
	ldrh r0, [r3]
	cmp r0, 0xAD
	beq _08045E0A
	cmp r0, 0xD6
	bne _08045E20
_08045E0A:
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB695
	b _08045F7A
	.pool
_08045E20:
	bl Random
	movs r5, 0xFF
	adds r1, r5, 0
	ands r1, r0
	ldr r7, =gBattleMons
	ldr r2, =gBankAttacker
	mov r9, r2
	ldrb r3, [r2]
	movs r0, 0x58
	mov r8, r0
	mov r0, r8
	muls r0, r3
	adds r0, r7
	adds r0, 0x2A
	ldrb r2, [r0]
	adds r0, r2, r6
	muls r0, r1
	asrs r4, r0, 8
	cmp r4, r6
	bge _08045EE8
	ldr r6, =gBitTable
	ldr r5, =gCurrMovePos
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r6
	ldrb r1, [r0]
	adds r0, r3, 0
	movs r2, 0xFF
	bl sub_803FECC
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bne _08045E68
	b _08045F6A
_08045E68:
	ldr r1, =gUnknown_020241E9
	mov r8, r1
	movs r7, 0x3
_08045E6E:
	bl Random
	ands r0, r7
	mov r2, r8
	strb r0, [r2]
	strb r0, [r5]
	ldrb r0, [r5]
	lsls r0, 2
	adds r0, r6
	ldr r0, [r0]
	ands r0, r4
	cmp r0, 0
	bne _08045E6E
	ldr r4, =gRandomMove
	ldr r3, =gBattleMons
	ldr r0, =gCurrMovePos
	ldrb r0, [r0]
	lsls r0, 1
	ldr r1, =gBankAttacker
	ldrb r2, [r1]
	movs r1, 0x58
	muls r1, r2
	adds r0, r1
	adds r3, 0xC
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r4]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB6A5
	str r0, [r1]
	ldrh r0, [r4]
	movs r1, 0
	bl GetMoveTarget
	ldr r1, =gBankTarget
	strb r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 14
	b _08045FCA
	.pool
_08045EE8:
	subs r0, r2, r6
	lsls r0, 24
	lsrs r6, r0, 24
	bl Random
	adds r4, r5, 0
	ands r4, r0
	cmp r4, r6
	bge _08045F64
	mov r1, r9
	ldrb r0, [r1]
	mov r1, r8
	muls r1, r0
	adds r0, r7, 0
	adds r0, 0x4C
	adds r0, r1, r0
	ldr r0, [r0]
	ands r0, r5
	cmp r0, 0
	bne _08045F64
	adds r0, r1, r7
	adds r0, 0x20
	ldrb r0, [r0]
	cmp r0, 0x48
	beq _08045F64
	cmp r0, 0xF
	beq _08045F64
	movs r2, 0
	ldr r0, =gNoOfAllBanks
	ldrb r3, [r0]
	mov r8, r0
	cmp r2, r3
	bge _08045F4A
	ldr r0, [r7, 0x50]
	movs r1, 0x70
	ands r0, r1
	cmp r0, 0
	bne _08045F4A
	adds r1, r7, 0
	adds r1, 0x50
	movs r5, 0x70
_08045F3A:
	adds r1, 0x58
	adds r2, 0x1
	cmp r2, r3
	bge _08045F4A
	ldr r0, [r1]
	ands r0, r5
	cmp r0, 0
	beq _08045F3A
_08045F4A:
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	bne _08045F64
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB6D9
	b _08045F7A
	.pool
_08045F64:
	subs r4, r6
	cmp r4, r6
	blt _08045F8C
_08045F6A:
	bl Random
	ldr r2, =gBattleCommunication
	movs r1, 0x3
	ands r1, r0
	strb r1, [r2, 0x5]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB6AD
_08045F7A:
	str r0, [r1]
	movs r0, 0x1
	b _08045FD0
	.pool
_08045F8C:
	ldr r4, =gBankAttacker
	ldrb r1, [r4]
	movs r0, 0x58
	muls r1, r0
	ldr r0, =gBattleMons
	adds r1, r0
	movs r0, 0x28
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	ldrb r0, [r4]
	str r0, [sp, 0x8]
	ldrb r0, [r4]
	str r0, [sp, 0xC]
	adds r0, r1, 0
	movs r2, 0x1
	movs r3, 0
	bl sub_806957C
	ldr r1, =gBattleMoveDamage
	str r0, [r1]
	ldr r1, =gBankTarget
	ldrb r0, [r4]
	strb r0, [r1]
	ldr r1, =gBattlescriptCurrInstr
	ldr r0, =gUnknown_082DB6F0
	str r0, [r1]
	ldr r2, =gHitMarker
	ldr r0, [r2]
	movs r1, 0x80
	lsls r1, 12
_08045FCA:
	orrs r0, r1
	str r0, [r2]
	movs r0, 0x2
_08045FD0:
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8045CBC

	.align 2, 0 @ Don't pad with nop.
