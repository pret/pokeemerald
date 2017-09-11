	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetAbilityBySpecies
@ int GetAbilityBySpecies(u16 a1, int a2)
GetAbilityBySpecies: @ 806B694
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 24
	cmp r1, 0
	beq _0806B6B8
	ldr r2, =gLastUsedAbility
	ldr r1, =gBaseStats
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x17]
	b _0806B6C6
	.pool
_0806B6B8:
	ldr r2, =gLastUsedAbility
	ldr r1, =gBaseStats
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x16]
_0806B6C6:
	strb r0, [r2]
	ldrb r0, [r2]
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetAbilityBySpecies

	thumb_func_start GetMonAbility
@ u8 GetMonAbility(pokemon *mon)
GetMonAbility: @ 806B6D8
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x2E
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl GetAbilityBySpecies
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetMonAbility

	thumb_func_start CreateSecretBaseEnemyParty
CreateSecretBaseEnemyParty: @ 806B70C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r5, r0, 0
	bl ZeroEnemyPartyMons
	ldr r4, =gBattleResources
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r5, 0
	movs r2, 0xA0
	bl memcpy
	movs r0, 0
	mov r9, r0
_0806B730:
	ldr r1, =gBattleResources
	ldr r3, [r1]
	ldr r2, [r3]
	mov r4, r9
	lsls r7, r4, 1
	adds r0, r2, 0
	adds r0, 0x7C
	adds r1, r0, r7
	ldrh r0, [r1]
	adds r4, 0x1
	str r4, [sp, 0x10]
	cmp r0, 0
	beq _0806B80A
	movs r0, 0x64
	mov r6, r9
	muls r6, r0
	ldr r4, =gEnemyParty
	mov r8, r4
	adds r5, r6, r4
	ldrh r1, [r1]
	adds r0, r2, 0
	adds r0, 0x94
	add r0, r9
	ldrb r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	ldr r0, [r3]
	mov r3, r9
	lsls r4, r3, 2
	adds r0, 0x34
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x4]
	movs r0, 0x2
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	adds r0, r5, 0
	movs r3, 0xF
	bl CreateMon
	ldr r1, =gBattleResources
	ldr r0, [r1]
	adds r1, r7, 0
	adds r1, 0x88
	ldr r2, [r0]
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0xC
	bl SetMonData
	movs r5, 0
	mov r10, r4
	mov r7, r9
	adds r7, 0x9A
	mov r4, r8
_0806B7A0:
	adds r1, r5, 0
	adds r1, 0x1A
	ldr r2, =gBattleResources
	ldr r0, [r2]
	ldr r2, [r0]
	adds r2, r7
	adds r0, r6, r4
	bl SetMonData
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806B7A0
	movs r5, 0
	movs r3, 0x64
	mov r0, r9
	muls r0, r3
	ldr r1, =gEnemyParty
	adds r7, r0, r1
	mov r4, r10
	lsls r0, r4, 1
	adds r6, r0, 0
	adds r6, 0x4C
	adds r4, r0, 0
_0806B7CE:
	adds r1, r5, 0
	adds r1, 0xD
	ldr r2, =gBattleResources
	ldr r0, [r2]
	ldr r2, [r0]
	adds r2, r6
	adds r0, r7, 0
	bl SetMonData
	adds r1, r5, 0
	adds r1, 0x11
	ldr r3, =gBattleResources
	ldr r0, [r3]
	ldr r0, [r0]
	adds r0, 0x4C
	adds r0, r4
	ldrh r0, [r0]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	ldr r0, =gBattleMoves + 0x4 @ PP offset
	adds r2, r0
	adds r0, r7, 0
	bl SetMonData
	adds r6, 0x2
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806B7CE
_0806B80A:
	ldr r4, [sp, 0x10]
	mov r9, r4
	cmp r4, 0x5
	ble _0806B730
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateSecretBaseEnemyParty

	thumb_func_start GetSecretBaseTrainerPicIndex
GetSecretBaseTrainerPicIndex: @ 806B830
	push {r4,r5,lr}
	ldr r5, =gSecretBaseTrainerClasses
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r4, [r0]
	ldrb r0, [r4, 0x9]
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r4, 0x1]
	lsls r2, 27
	lsrs r2, 31
	lsls r1, r2, 2
	adds r1, r2
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	ldr r1, =gTrainerPicIndices
	adds r0, r1
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSecretBaseTrainerPicIndex

	thumb_func_start GetSecretBaseTrainerNameIndex
GetSecretBaseTrainerNameIndex: @ 806B870
	push {r4,r5,lr}
	ldr r5, =gSecretBaseTrainerClasses
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r4, [r0]
	ldrb r0, [r4, 0x9]
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r4, 0x1]
	lsls r2, 27
	lsrs r2, 31
	lsls r1, r2, 2
	adds r1, r2
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	ldr r1, =gTrainerClassNameIndices
	adds r0, r1
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSecretBaseTrainerNameIndex

	thumb_func_start PlayerPartyAndPokemonStorageFull
PlayerPartyAndPokemonStorageFull: @ 806B8B0
	push {r4,lr}
	movs r4, 0
_0806B8B4:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806B8D0
	movs r0, 0
	b _0806B8DE
	.pool
_0806B8D0:
	adds r4, 0x1
	cmp r4, 0x5
	ble _0806B8B4
	bl PokemonStorageFull
	lsls r0, 24
	lsrs r0, 24
_0806B8DE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PlayerPartyAndPokemonStorageFull

	thumb_func_start PokemonStorageFull
PokemonStorageFull: @ 806B8E4
	push {r4-r6,lr}
	movs r6, 0
_0806B8E8:
	movs r4, 0
	lsls r5, r6, 24
_0806B8EC:
	lsls r1, r4, 24
	lsrs r1, 24
	lsrs r0, r5, 24
	movs r2, 0xB
	bl GetBoxMonDataFromAnyBox
	cmp r0, 0
	bne _0806B900
	movs r0, 0
	b _0806B90E
_0806B900:
	adds r4, 0x1
	cmp r4, 0x1D
	ble _0806B8EC
	adds r6, 0x1
	cmp r6, 0xD
	ble _0806B8E8
	movs r0, 0x1
_0806B90E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end PokemonStorageFull

	thumb_func_start GetSpeciesName
@ void GetSpeciesName(u8 *dest, u16 speciesId)
GetSpeciesName: @ 806B914
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r1, 0
	movs r0, 0xCE
	lsls r0, 1
	mov r12, r0
	ldr r7, =gSpeciesNames
	movs r0, 0xB
	muls r0, r5
	adds r3, r0, r7
	adds r2, r6, 0
	b _0806B93A
	.pool
_0806B934:
	adds r3, 0x1
	adds r2, 0x1
	adds r1, 0x1
_0806B93A:
	adds r4, r6, r1
	cmp r1, 0xA
	bgt _0806B954
	cmp r5, r12
	bls _0806B94A
	adds r0, r1, r7
	ldrb r0, [r0]
	b _0806B94C
_0806B94A:
	ldrb r0, [r3]
_0806B94C:
	strb r0, [r2]
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _0806B934
_0806B954:
	movs r0, 0xFF
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GetSpeciesName

	thumb_func_start CalculatePPWithBonus
@ u16 CalculatePPWithBonus(u16 moveId, s32 ppUpCounts, u8 monMoveIndex)
CalculatePPWithBonus: @ 806B960
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 24
	lsrs r2, 24
	ldr r4, =gBattleMoves
	lsls r3, r0, 1
	adds r3, r0
	lsls r3, 2
	adds r3, r4
	ldrb r4, [r3, 0x4]
	ldr r0, =gUnknown_08329D22
	adds r0, r2, r0
	ldrb r3, [r0]
	ands r3, r1
	lsls r2, 1
	asrs r3, r2
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	muls r0, r4
	movs r1, 0x64
	bl __divsi3
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CalculatePPWithBonus

	thumb_func_start RemoveMonPPBonus
RemoveMonPPBonus: @ 806B9A8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	ldr r1, =gUnknown_08329D26
	adds r4, r1
	ldrb r1, [r4]
	ands r1, r0
	mov r0, sp
	strb r1, [r0]
	adds r0, r5, 0
	movs r1, 0x15
	mov r2, sp
	bl SetMonData
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveMonPPBonus

	thumb_func_start RemoveBattleMonPPBonus
RemoveBattleMonPPBonus: @ 806B9E4
	lsls r1, 24
	lsrs r1, 24
	adds r0, 0x3B
	ldr r2, =gUnknown_08329D26
	adds r1, r2
	ldrb r2, [r0]
	ldrb r1, [r1]
	ands r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end RemoveBattleMonPPBonus

	thumb_func_start CopyPlayerPartyMonToBattleData
CopyPlayerPartyMonToBattleData: @ 806B9FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0x64
	mov r5, r9
	muls r5, r0
	ldr r0, =gPlayerParty
	adds r5, r0
	adds r0, r5, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, =gBattleMons
	mov r8, r1
	movs r1, 0x58
	ldr r2, [sp, 0x14]
	adds r4, r2, 0
	muls r4, r1
	mov r3, r8
	adds r6, r4, r3
	strh r0, [r6]
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	strh r0, [r6, 0x2E]
	movs r6, 0
	mov r0, r8
	adds r0, 0x24
	adds r7, r4, r0
_0806BA4E:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r5, 0
	movs r2, 0
	bl GetMonData
	movs r1, 0xC
	add r1, r8
	mov r10, r1
	adds r1, r4, r1
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r5, 0
	movs r2, 0
	bl GetMonData
	strb r0, [r7]
	adds r7, 0x1
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _0806BA4E
	movs r0, 0x64
	mov r4, r9
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	movs r2, 0xC
	negs r2, r2
	add r2, r10
	mov r9, r2
	movs r1, 0x58
	ldr r3, [sp, 0x14]
	adds r5, r3, 0
	muls r5, r1
	adds r7, r5, r2
	adds r1, r7, 0
	adds r1, 0x3B
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	adds r1, r7, 0
	adds r1, 0x2B
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x19
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x38
	adds r1, r5, r1
	str r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	movs r2, 0
	bl GetMonData
	movs r6, 0x1F
	ands r0, r6
	ldrb r2, [r7, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	movs r2, 0
	bl GetMonData
	movs r1, 0x1F
	mov r8, r1
	mov r2, r8
	ands r0, r2
	lsls r0, 5
	ldrh r2, [r7, 0x14]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r7, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	movs r2, 0
	bl GetMonData
	ands r0, r6
	lsls r0, 2
	ldrb r2, [r7, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	movs r2, 0
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [r7, 0x14]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [r7, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	movs r2, 0
	bl GetMonData
	mov r3, r8
	ands r0, r3
	lsls r0, 4
	ldrh r2, [r7, 0x16]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r7, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	movs r2, 0
	bl GetMonData
	ands r0, r6
	lsls r0, 1
	ldrb r2, [r7, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x17]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x3C
	adds r1, r5, r1
	str r0, [r1]
	adds r0, r4, 0
	movs r1, 0x37
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x40
	adds r1, r5, r1
	str r0, [r1]
	adds r0, r4, 0
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	adds r1, r7, 0
	adds r1, 0x2A
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	movs r2, 0
	bl GetMonData
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r7, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	movs r2, 0
	bl GetMonData
	lsls r0, 7
	ldrb r2, [r7, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x48
	adds r1, r5, r1
	str r0, [r1]
	ldr r2, =gBaseStats
	ldrh r1, [r7]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x6]
	adds r1, r7, 0
	adds r1, 0x21
	strb r0, [r1]
	ldrh r1, [r7]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x7]
	adds r1, r7, 0
	adds r1, 0x22
	strb r0, [r1]
	ldrh r0, [r7]
	ldrb r1, [r7, 0x17]
	lsrs r1, 7
	bl GetAbilityBySpecies
	adds r1, r7, 0
	adds r1, 0x20
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, r10
	adds r0, 0x24
	adds r0, r5, r0
	mov r1, sp
	bl StringCopy10
	mov r2, r10
	adds r2, 0x30
	adds r2, r5, r2
	adds r0, r4, 0
	movs r1, 0x7
	bl GetMonData
	ldr r0, [sp, 0x14]
	bl GetBankSide
	ldr r1, =gBattleStruct
	lsls r0, 24
	lsrs r0, 23
	adds r0, 0xA8
	ldr r1, [r1]
	adds r1, r0
	ldrh r0, [r7, 0x28]
	strh r0, [r1]
	movs r2, 0x6
	mov r1, r9
	movs r6, 0x7
	add r5, r10
	adds r0, r5, 0
	adds r0, 0x13
_0806BCB2:
	strb r2, [r0]
	subs r0, 0x1
	subs r6, 0x1
	cmp r6, 0
	bge _0806BCB2
	movs r2, 0
	movs r0, 0x58
	ldr r3, [sp, 0x14]
	muls r0, r3
	adds r1, 0x50
	adds r0, r1
	str r2, [r0]
	ldr r0, [sp, 0x14]
	bl sub_803FA70
	ldr r0, [sp, 0x14]
	movs r1, 0
	bl sub_805EF84
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyPlayerPartyMonToBattleData

	.align 2, 0 @ Don't pad with nop.
