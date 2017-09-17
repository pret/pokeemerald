	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


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
	ldr r1, =gBattleMainFunc
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
	ldr r1, =gBattleMainFunc
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, =sub_803E08C
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end b_push_move_exec

	thumb_func_start ItemBattleEffects
ItemBattleEffects: @ 80444DC
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
	ldr r4, =gLastUsedItem
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
	ldr r0, =gStringBank
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
	bl CalculatePPWithBonus
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
	bl EmitSetAttributes
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	bl MarkBufferBankForExecution
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
	ldr r0, =gStringBank
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
	bl RecordItemEffectBattle
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
	bl GetFlavourRelationByPersonality
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
	bl GetFlavourRelationByPersonality
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
	bl GetFlavourRelationByPersonality
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
	bl GetFlavourRelationByPersonality
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
	bl GetFlavourRelationByPersonality
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
	ldr r0, =gEffectBank
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
	ldr r0, =gEffectBank
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
	ldr r0, =gEffectBank
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
	ldr r0, =gEffectBank
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
	ldr r0, =gEffectBank
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
	ldr r5, =gBattleMons + 0x18
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
	ldr r0, =gEffectBank
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
	ldr r1, =gStatusConditionString_PoisonJpn
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
	ldr r1, =gStatusConditionString_SleepJpn
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
	ldr r1, =gStatusConditionString_ParalysisJpn
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
	ldr r1, =gStatusConditionString_BurnJpn
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
	ldr r1, =gStatusConditionString_IceJpn
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
	ldr r1, =gStatusConditionString_ConfusionJpn
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
	ldr r1, =gStatusConditionString_LoveJpn
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
	ldr r0, =gStringBank
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
	ldr r4, =gLastUsedItem
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
	ldr r1, =gStatusConditionString_LoveJpn
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
	ldr r1, =gStatusConditionString_PoisonJpn
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
	ldr r1, =gStatusConditionString_SleepJpn
	bl StringCopy
_08045578:
	ldr r0, [r6]
	movs r1, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0804558A
	ldr r0, =gBattleTextBuff1
	ldr r1, =gStatusConditionString_ParalysisJpn
	bl StringCopy
_0804558A:
	ldr r0, [r6]
	movs r1, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0804559C
	ldr r0, =gBattleTextBuff1
	ldr r1, =gStatusConditionString_BurnJpn
	bl StringCopy
_0804559C:
	ldr r0, [r6]
	movs r1, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080455AE
	ldr r0, =gBattleTextBuff1
	ldr r1, =gStatusConditionString_IceJpn
	bl StringCopy
_080455AE:
	adds r5, r4
	ldr r0, [r5]
	mov r3, r8
	ands r0, r3
	cmp r0, 0
	beq _080455C2
	ldr r0, =gBattleTextBuff1
	ldr r1, =gStatusConditionString_ConfusionJpn
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
	ldr r0, =gStringBank
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
	ldr r0, =gStringBank
	strb r7, [r0]
	ldr r4, =gActiveBank
	strb r7, [r4]
	ldrb r1, [r4]
	movs r0, 0x58
	muls r0, r1
_0804568C:
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
	bl SetMoveEffect
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
	ldr r0, =gLastUsedItem
	mov r1, sp
	ldrh r1, [r1, 0x14]
	strh r1, [r0]
	ldr r0, =gStringBank
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
	thumb_func_end ItemBattleEffects

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
	ldr r1, =gBattleScriptingCommandsTable
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
	bl IsOtherTrainer
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
	bl CheckMoveLimitations
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
	ldr r0, =BattleScript_MoveUsedLoafingAround
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
	bl CalculateBaseDamage
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
