	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

    
	thumb_func_start sub_8056F28
sub_8056F28: @ 8056F28
	push {r4-r6,lr}
	ldr r5, =gBattleResources
	ldr r6, =gBattleTypeFlags
	ldr r0, [r6]
	movs r1, 0x80
	lsls r1, 19
	ands r0, r1
	cmp r0, 0
	beq _08056F3E
	bl sub_81D55D0
_08056F3E:
	ldr r4, =gBattleStruct
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
	bl CreateSecretBaseEnemyParty
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
	ldr r6, =gBattleResources
	ldr r0, [r6]
	cmp r0, 0
	beq _080570D0
	ldr r4, =gBattleStruct
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

	thumb_func_start AdjustFriendshipOnBattleFaint
AdjustFriendshipOnBattleFaint: @ 80570F4
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
	bl AdjustFriendship
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
	bl AdjustFriendship
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
	bl AdjustFriendship
_080571CE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AdjustFriendshipOnBattleFaint

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
	ldr r4, =gBattleStruct
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
	ldr r4, =gBattleStruct
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
	bl BattleScriptPushCursor
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
	bl BattleScriptPushCursor
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
	bl BattleScriptPushCursor
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
	ldr r1, =gBattleMons + 0x4C
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

    
	.align 2, 0 @ Don't pad with nop.
