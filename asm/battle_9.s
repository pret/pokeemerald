	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

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
	ldr r0, =gBattleStruct
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
	bl GetBankIdentity
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, =gBattleMons
	bl GetBankByIdentity
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
	bl GetBankByIdentity
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
	bl AI_TypeCalc
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
	ldr r1, =gBattleStruct
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
	bl GetBankByIdentity
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
	bl AI_TypeCalc
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
	bl GetBankIdentity
	movs r4, 0x2
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	bl GetBankIdentity
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	ldr r1, =gBattleStruct
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
	ldr r0, =gBattleStruct
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
	ldr r1, =gBattleStruct
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
	bl GetBankIdentity
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl GetBankByIdentity
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
	bl AI_TypeCalc
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
	bl GetBankByIdentity
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
	bl AI_TypeCalc
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
	bl GetBankIdentity
	movs r4, 0x2
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	bl GetBankIdentity
	eors r0, r4
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	ldr r1, =gBattleStruct
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
	ldr r0, =gBattleStruct
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
	bl AI_TypeCalc
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
	bl AI_TypeCalc
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
	bl GetBankIdentity
	movs r5, 0x2
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	bl GetBankIdentity
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	ldr r0, =gBattleStruct
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
	bl GetBankIdentity
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
	ldr r2, =gBattleStruct
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
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	b _08063928
	.pool
_08063910:
	adds r0, r5, 0
	bl GetBankByIdentity
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x2
	eors r5, r0
	adds r0, r5, 0
	bl GetBankByIdentity
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
	ldr r0, =gBattleStruct
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
	ldr r2, =gBattleStruct
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
	ldr r0, =gTypeEffectiveness
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
	ldr r0, =gBattleStruct
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
	bl GetBankIdentity
	movs r5, 0x2
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	bl GetBankIdentity
	eors r0, r5
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	bl GetBankIdentity
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl GetBankByIdentity
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
	ldr r0, =gBattleStruct
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
	bl TypeCalc
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
	ldr r0, =gDynamicBasePower
	movs r1, 0
	strh r1, [r0]
	ldr r0, =gBattleStruct
	ldr r0, [r0]
	strb r1, [r0, 0x13]
	ldr r0, =gBattleScripting
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
	ldr r0, =gBattleStruct
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
	bl AI_CalcDmg
	ldrb r1, [r6]
	adds r0, r4, 0
	ldr r2, [sp, 0x4]
	bl TypeCalc
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
	bl GetBankIdentity
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
	ldr r1, =gBattleResources
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
	ldr r1, =gItemEffectTable
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
	ldr r3, =gBattleStruct
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
	bl GetItemEffectParamOffset
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
	ldr r2, =gBattleStruct
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
	ldr r3, =gBattleStruct
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
	ldr r0, =gSideTimers
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
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	lsls r0, 1
	adds r0, r1
	adds r0, 0xC0
	mov r1, r9
	strb r1, [r0]
	ldr r0, =gBattleResources
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

	.align 2, 0 @ Don't pad with nop.
