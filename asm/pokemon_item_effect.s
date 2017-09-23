	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start ExecuteTableBasedItemEffect_
@ bool8 ExecuteTableBasedItemEffect_(struct pokemon *mon, u16 itemId, u8 a3, u8 monMoveIndex)
ExecuteTableBasedItemEffect_: @ 806BD04
	push {r4,lr}
	sub sp, 0x4
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r4, 0
	str r4, [sp]
	bl ExecuteTableBasedItemEffect
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end ExecuteTableBasedItemEffect_

	thumb_func_start ExecuteTableBasedItemEffect
@ bool8 ExecuteTableBasedItemEffect(struct pokemon *mon, u16 itemId, u8 a3, u8 monMoveIndex, u8 a5)
ExecuteTableBasedItemEffect: @ 806BD28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x44
	mov r8, r0
	ldr r0, [sp, 0x64]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp, 0xC]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x10]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x14]
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x18]
	movs r0, 0x1
	str r0, [sp, 0x20]
	movs r1, 0x6
	str r1, [sp, 0x28]
	movs r2, 0
	str r2, [sp, 0x30]
	movs r3, 0x4
	str r3, [sp, 0x38]
	movs r5, 0
	str r5, [sp, 0x3C]
	mov r0, r8
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _0806BDBC
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806BDA8
	ldr r2, =gEnigmaBerries
	ldr r0, =gBankInMenu
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x7]
	b _0806BDC4
	.pool
_0806BDA8:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003226
	adds r0, r2
	ldrb r0, [r0]
	b _0806BDC4
	.pool
_0806BDBC:
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r0, 24
_0806BDC4:
	str r0, [sp, 0x34]
	ldr r1, =gStringBank
	ldr r0, =gBankInMenu
	ldrb r2, [r0]
	strb r2, [r1]
	ldr r0, =gMain
	ldr r3, =0x00000439
	adds r0, r3
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	beq _0806BE64
	ldr r0, =gActiveBank
	strb r2, [r0]
	ldrb r0, [r0]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	str r1, [sp, 0x1C]
	ldr r0, =gNoOfAllBanks
	ldr r4, [sp, 0xC]
	subs r4, 0xD
	ldrb r0, [r0]
	cmp r1, r0
	bge _0806BE70
	ldr r2, =gBattlePartyID
	lsls r0, r1, 1
	adds r0, r2
	ldrh r3, [r0]
	ldr r5, [sp, 0x10]
	lsls r0, r5, 16
	lsrs r1, r0, 16
	adds r5, r0, 0
	cmp r3, r1
	bne _0806BE3C
	ldr r0, [sp, 0x1C]
	str r0, [sp, 0x38]
	b _0806BE70
	.pool
_0806BE3C:
	ldr r1, [sp, 0x1C]
	adds r1, 0x2
	str r1, [sp, 0x1C]
	ldr r0, =gNoOfAllBanks
	ldrb r0, [r0]
	cmp r1, r0
	bge _0806BE70
	lsls r0, r1, 1
	adds r0, r2
	ldrh r1, [r0]
	lsrs r0, r5, 16
	cmp r1, r0
	bne _0806BE3C
	ldr r2, [sp, 0x1C]
	lsls r0, r2, 24
	lsrs r0, 24
	str r0, [sp, 0x38]
	b _0806BE70
	.pool
_0806BE64:
	ldr r0, =gActiveBank
	strb r1, [r0]
	movs r3, 0x4
	str r3, [sp, 0x38]
	ldr r4, [sp, 0xC]
	subs r4, 0xD
_0806BE70:
	lsls r0, r4, 16
	lsrs r0, 16
	cmp r0, 0xA5
	bhi _0806BEF0
	ldr r1, =gItemEffectTable
	lsls r0, r4, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0806BE94
	ldr r5, [sp, 0xC]
	cmp r5, 0xAF
	beq _0806BE9A
	b _0806BEF0
	.pool
_0806BE94:
	ldr r1, [sp, 0xC]
	cmp r1, 0xAF
	bne _0806BEF6
_0806BE9A:
	ldr r0, =gMain
	ldr r2, =0x00000439
	adds r0, r2
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806BECC
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, =gEnigmaBerries + 8
	adds r0, r1
	b _0806BEF6
	.pool
_0806BECC:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00003214
	adds r3, r0, r3
	str r3, [sp, 0x24]
	b _0806BEF8
	.pool
_0806BEE0:
	mov r0, r8
	movs r2, 0
	ldr r3, [sp, 0x10]
	bl sub_813DA40
	movs r0, 0
	bl _0806CD5C
_0806BEF0:
	movs r0, 0x1
	bl _0806CD5C
_0806BEF6:
	str r0, [sp, 0x24]
_0806BEF8:
	movs r5, 0
	str r5, [sp, 0x1C]
_0806BEFC:
	ldr r0, [sp, 0x1C]
	cmp r0, 0x5
	bls _0806BF06
	bl _0806CD4C
_0806BF06:
	lsls r0, 2
	ldr r1, =_0806BF14
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806BF14:
	.4byte _0806BF2C
	.4byte _0806BFFC
	.4byte _0806C08C
	.4byte _0806C120
	.4byte _0806C300
	.4byte _0806C9BE
_0806BF2C:
	ldr r1, [sp, 0x24]
	ldr r3, [sp, 0x1C]
	adds r2, r1, r3
	ldrb r1, [r2]
	movs r0, 0x80
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _0806BF76
	ldr r0, =gMain
	ldr r5, =0x00000439
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806BF76
	ldr r0, [sp, 0x38]
	cmp r0, 0x4
	beq _0806BF76
	ldr r1, =gBattleMons
	movs r0, 0x58
	ldr r2, [sp, 0x38]
	muls r0, r2
	adds r1, 0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0xF0
	lsls r0, 12
	ands r0, r1
	cmp r0, 0
	beq _0806BF76
	ldr r0, =0xfff0ffff
	ands r1, r0
	str r1, [r2]
	movs r3, 0
	str r3, [sp, 0x20]
_0806BF76:
	ldrb r1, [r6]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0
	beq _0806BFA4
	ldr r1, =gBattleMons
	ldr r0, =gActiveBank
	ldrb r2, [r0]
	movs r0, 0x58
	muls r0, r2
	adds r1, 0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, 0x80
	lsls r3, 13
	adds r0, r1, 0
	ands r0, r3
	cmp r0, 0
	bne _0806BFA4
	orrs r1, r3
	str r1, [r2]
	movs r5, 0
	str r5, [sp, 0x20]
_0806BFA4:
	ldrb r0, [r6]
	movs r3, 0xF
	ands r3, r0
	cmp r3, 0
	bne _0806BFB2
	bl _0806CD4C
_0806BFB2:
	ldr r6, =gBattleMons
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x58
	muls r0, r4
	adds r1, r0, r6
	ldrb r2, [r1, 0x19]
	movs r0, 0x19
	ldrsb r0, [r1, r0]
	cmp r0, 0xB
	ble _0806BFCC
	bl _0806CD4C
_0806BFCC:
	adds r0, r2, r3
	strb r0, [r1, 0x19]
	ldrb r0, [r5]
	muls r0, r4
	adds r1, r0, r6
	movs r0, 0x19
	ldrsb r0, [r1, r0]
	cmp r0, 0xC
	bgt _0806BFE0
	b _0806C110
_0806BFE0:
	movs r0, 0xC
	strb r0, [r1, 0x19]
	b _0806C110
	.pool
_0806BFFC:
	ldr r1, [sp, 0x24]
	ldr r3, [sp, 0x1C]
	adds r2, r1, r3
	ldrb r1, [r2]
	movs r0, 0xF0
	ands r0, r1
	lsls r3, r0, 24
	adds r6, r2, 0
	cmp r3, 0
	beq _0806C042
	ldr r7, =gBattleMons
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x58
	muls r0, r4
	adds r1, r0, r7
	ldrb r2, [r1, 0x1A]
	movs r0, 0x1A
	ldrsb r0, [r1, r0]
	cmp r0, 0xB
	bgt _0806C042
	lsrs r0, r3, 28
	adds r0, r2, r0
	strb r0, [r1, 0x1A]
	ldrb r0, [r5]
	muls r0, r4
	adds r1, r0, r7
	movs r0, 0x1A
	ldrsb r0, [r1, r0]
	cmp r0, 0xC
	ble _0806C03E
	movs r0, 0xC
	strb r0, [r1, 0x1A]
_0806C03E:
	movs r5, 0
	str r5, [sp, 0x20]
_0806C042:
	ldrb r0, [r6]
	movs r3, 0xF
	ands r3, r0
	cmp r3, 0
	bne _0806C050
	bl _0806CD4C
_0806C050:
	ldr r6, =gBattleMons
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x58
	muls r0, r4
	adds r1, r0, r6
	ldrb r2, [r1, 0x1B]
	movs r0, 0x1B
	ldrsb r0, [r1, r0]
	cmp r0, 0xB
	ble _0806C06A
	bl _0806CD4C
_0806C06A:
	adds r0, r2, r3
	strb r0, [r1, 0x1B]
	ldrb r0, [r5]
	muls r0, r4
	adds r1, r0, r6
	movs r0, 0x1B
	ldrsb r0, [r1, r0]
	cmp r0, 0xC
	ble _0806C110
	movs r0, 0xC
	strb r0, [r1, 0x1B]
	b _0806C110
	.pool
_0806C08C:
	ldr r1, [sp, 0x24]
	ldr r3, [sp, 0x1C]
	adds r2, r1, r3
	ldrb r1, [r2]
	movs r0, 0xF0
	ands r0, r1
	lsls r3, r0, 24
	adds r6, r2, 0
	cmp r3, 0
	beq _0806C0D2
	ldr r7, =gBattleMons
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x58
	muls r0, r4
	adds r1, r0, r7
	ldrb r2, [r1, 0x1E]
	movs r0, 0x1E
	ldrsb r0, [r1, r0]
	cmp r0, 0xB
	bgt _0806C0D2
	lsrs r0, r3, 28
	adds r0, r2, r0
	strb r0, [r1, 0x1E]
	ldrb r0, [r5]
	muls r0, r4
	adds r1, r0, r7
	movs r0, 0x1E
	ldrsb r0, [r1, r0]
	cmp r0, 0xC
	ble _0806C0CE
	movs r0, 0xC
	strb r0, [r1, 0x1E]
_0806C0CE:
	movs r5, 0
	str r5, [sp, 0x20]
_0806C0D2:
	ldrb r0, [r6]
	movs r3, 0xF
	ands r3, r0
	cmp r3, 0
	bne _0806C0E0
	bl _0806CD4C
_0806C0E0:
	ldr r6, =gBattleMons
	ldr r5, =gActiveBank
	ldrb r0, [r5]
	movs r4, 0x58
	muls r0, r4
	adds r1, r0, r6
	ldrb r2, [r1, 0x1C]
	movs r0, 0x1C
	ldrsb r0, [r1, r0]
	cmp r0, 0xB
	ble _0806C0FA
	bl _0806CD4C
_0806C0FA:
	adds r0, r2, r3
	strb r0, [r1, 0x1C]
	ldrb r0, [r5]
	muls r0, r4
	adds r1, r0, r6
	movs r0, 0x1C
	ldrsb r0, [r1, r0]
	cmp r0, 0xC
	ble _0806C110
	movs r0, 0xC
	strb r0, [r1, 0x1C]
_0806C110:
	movs r0, 0
	str r0, [sp, 0x20]
	bl _0806CD4C
	.pool
_0806C120:
	ldr r1, [sp, 0x24]
	ldr r3, [sp, 0x1C]
	adds r2, r1, r3
	ldrb r1, [r2]
	movs r0, 0x80
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	beq _0806C168
	ldr r5, =gSideTimers
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	bne _0806C168
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	movs r0, 0x5
	strb r0, [r1, 0x4]
	movs r5, 0
	str r5, [sp, 0x20]
_0806C168:
	ldrb r1, [r6]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0806C1CA
	mov r0, r8
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	cmp r0, 0x64
	beq _0806C1CA
	ldr r5, =gExperienceTables
	mov r0, r8
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
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
	adds r4, r5
	ldr r0, [r4]
	str r0, [sp]
	mov r0, r8
	movs r1, 0x19
	mov r2, sp
	bl SetMonData
	mov r0, r8
	bl CalculateMonStats
	movs r0, 0
	str r0, [sp, 0x20]
_0806C1CA:
	ldrb r1, [r6]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0806C206
	mov r0, r8
	ldr r1, [sp, 0x10]
	movs r2, 0x7
	ldr r3, [sp, 0x38]
	bl HealStatusConditions
	lsls r0, 24
	cmp r0, 0
	bne _0806C206
	ldr r1, [sp, 0x38]
	cmp r1, 0x4
	beq _0806C202
	ldr r1, =gBattleMons
	movs r0, 0x58
	ldr r3, [sp, 0x38]
	adds r2, r3, 0
	muls r2, r0
	adds r1, 0x50
	adds r2, r1
	ldr r0, [r2]
	ldr r1, =0xf7ffffff
	ands r0, r1
	str r0, [r2]
_0806C202:
	movs r5, 0
	str r5, [sp, 0x20]
_0806C206:
	ldrb r1, [r6]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0806C226
	ldr r2, =0x00000f88
	mov r0, r8
	ldr r1, [sp, 0x10]
	ldr r3, [sp, 0x38]
	bl HealStatusConditions
	lsls r0, 24
	cmp r0, 0
	bne _0806C226
	movs r0, 0
	str r0, [sp, 0x20]
_0806C226:
	ldrb r1, [r6]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806C246
	mov r0, r8
	ldr r1, [sp, 0x10]
	movs r2, 0x10
	ldr r3, [sp, 0x38]
	bl HealStatusConditions
	lsls r0, 24
	cmp r0, 0
	bne _0806C246
	movs r1, 0
	str r1, [sp, 0x20]
_0806C246:
	ldrb r1, [r6]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0806C266
	mov r0, r8
	ldr r1, [sp, 0x10]
	movs r2, 0x20
	ldr r3, [sp, 0x38]
	bl HealStatusConditions
	lsls r0, 24
	cmp r0, 0
	bne _0806C266
	movs r2, 0
	str r2, [sp, 0x20]
_0806C266:
	ldrb r1, [r6]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806C286
	mov r0, r8
	ldr r1, [sp, 0x10]
	movs r2, 0x40
	ldr r3, [sp, 0x38]
	bl HealStatusConditions
	lsls r0, 24
	cmp r0, 0
	bne _0806C286
	movs r3, 0
	str r3, [sp, 0x20]
_0806C286:
	ldrb r1, [r6]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0806C294
	bl _0806CD4C
_0806C294:
	ldr r0, =gMain
	ldr r5, =0x00000439
	adds r0, r5
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0806C2A8
	bl _0806CD4C
_0806C2A8:
	ldr r0, [sp, 0x38]
	cmp r0, 0x4
	bne _0806C2B2
	bl _0806CD4C
_0806C2B2:
	ldr r1, =gBattleMons
	movs r0, 0x58
	ldr r2, [sp, 0x38]
	muls r0, r2
	adds r1, 0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, 0x7
	ands r0, r1
	cmp r0, 0
	bne _0806C2CC
	bl _0806CD4C
_0806C2CC:
	movs r0, 0x8
	negs r0, r0
	ands r1, r0
	str r1, [r2]
	movs r3, 0
	str r3, [sp, 0x20]
	bl _0806CD4C
	.pool
_0806C300:
	ldr r5, [sp, 0x24]
	ldr r1, [sp, 0x1C]
	adds r0, r5, r1
	ldrb r0, [r0]
	mov r10, r0
	movs r0, 0x20
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	beq _0806C3D8
	movs r0, 0xDF
	ands r2, r0
	mov r10, r2
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	ldr r1, =gUnknown_08329D22
	ldr r3, [sp, 0x14]
	adds r1, r3, r1
	ldrb r1, [r1]
	ands r0, r1
	lsls r1, r3, 1
	lsrs r0, r1
	str r0, [sp]
	adds r5, r3, 0
	adds r5, 0xD
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	ldr r2, [sp, 0x14]
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x2C]
	ldr r0, [sp]
	cmp r0, 0x2
	bhi _0806C3D8
	ldr r0, [sp, 0x2C]
	cmp r0, 0x4
	bls _0806C3D8
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	ldr r1, =gUnknown_08329D2A
	ldr r2, [sp, 0x14]
	adds r1, r2, r1
	ldrb r1, [r1]
	adds r0, r1
	str r0, [sp]
	mov r0, r8
	movs r1, 0x15
	mov r2, sp
	bl SetMonData
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, [sp, 0x14]
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	ldr r3, [sp, 0x2C]
	subs r0, r3
	str r0, [sp]
	ldr r4, [sp, 0x14]
	adds r4, 0x11
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl GetMonData
	ldr r1, [sp]
	adds r0, r1
	str r0, [sp]
	mov r0, r8
	adds r1, r4, 0
	mov r2, sp
	bl SetMonData
	movs r5, 0
	str r5, [sp, 0x20]
_0806C3D8:
	movs r0, 0
	str r0, [sp, 0x2C]
	mov r1, r10
	cmp r1, 0
	bne _0806C3E6
	bl _0806CD4C
_0806C3E6:
	movs r0, 0x1
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	bne _0806C3F2
	b _0806C9AA
_0806C3F2:
	ldr r3, [sp, 0x2C]
	cmp r3, 0x7
	bls _0806C3FA
	b _0806C9AA
_0806C3FA:
	lsls r0, r3, 2
	ldr r1, =_0806C410
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806C410:
	.4byte _0806C430
	.4byte _0806C430
	.4byte _0806C4DC
	.4byte _0806C700
	.4byte _0806C9AA
	.4byte _0806C9AA
	.4byte _0806C9AA
	.4byte _0806C994
_0806C430:
	mov r0, r8
	bl GetMonEVCount
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r5, [sp, 0x24]
	ldr r1, [sp, 0x28]
	adds r0, r5, r1
	ldrb r5, [r0]
	ldr r0, =gUnknown_08329EC2
	ldr r2, [sp, 0x2C]
	adds r0, r2, r0
	ldrb r1, [r0]
	mov r0, r8
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	str r1, [sp, 0x4]
	lsls r0, r5, 24
	asrs r2, r0, 24
	cmp r2, 0
	ble _0806C498
	ldr r0, =0x000001fd
	cmp r6, r0
	bls _0806C466
	b _0806BEF0
_0806C466:
	adds r3, r1, 0
	cmp r3, 0x63
	ble _0806C46E
	b _0806C9AA
_0806C46E:
	adds r1, r3, r2
	cmp r1, 0x64
	ble _0806C484
	adds r0, r2, 0
	adds r0, 0x64
	subs r5, r0, r1
	b _0806C486
	.pool
_0806C484:
	adds r5, r2, 0
_0806C486:
	adds r1, r6, r5
	movs r0, 0xFF
	lsls r0, 1
	cmp r1, r0
	bls _0806C494
	adds r0, r5, r0
	subs r5, r0, r1
_0806C494:
	adds r0, r3, r5
	b _0806C4B2
_0806C498:
	cmp r1, 0
	bne _0806C4A8
	movs r3, 0x1
	str r3, [sp, 0x3C]
	ldr r0, [sp, 0x28]
	adds r0, 0x1
	lsls r0, 24
	b _0806C83E
_0806C4A8:
	adds r0, r1, r2
	str r0, [sp, 0x4]
	cmp r0, 0
	bge _0806C4B4
	movs r0, 0
_0806C4B2:
	str r0, [sp, 0x4]
_0806C4B4:
	ldr r0, =gUnknown_08329EC2
	ldr r5, [sp, 0x2C]
	adds r0, r5, r0
	ldrb r1, [r0]
	add r2, sp, 0x4
	mov r0, r8
	bl SetMonData
	mov r0, r8
	bl CalculateMonStats
	ldr r0, [sp, 0x28]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x28]
	b _0806C978
	.pool
_0806C4DC:
	movs r0, 0x10
	mov r1, r10
	ands r0, r1
	cmp r0, 0
	beq _0806C59C
	mov r0, r8
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806C4FC
	ldr r0, [sp, 0x28]
	adds r0, 0x1
	lsls r0, 24
	b _0806C83E
_0806C4FC:
	ldr r0, =gMain
	ldr r2, =0x00000439
	adds r0, r2
	ldrb r1, [r0]
	movs r4, 0x2
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806C5B2
	ldr r3, [sp, 0x38]
	cmp r3, 0x4
	beq _0806C55C
	ldr r2, =gAbsentBankFlags
	ldr r1, =gBitTable
	lsls r0, r3, 2
	adds r0, r1
	ldr r1, [r0]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	ldr r1, =gBattlePartyID
	lsls r0, r3, 1
	adds r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, [sp, 0x38]
	bl CopyPlayerPartyMonToBattleData
	ldr r0, =gActiveBank
	ldrb r0, [r0]
	b _0806C574
	.pool
_0806C55C:
	ldr r3, =gAbsentBankFlags
	ldr r1, =gBitTable
	ldr r2, =gActiveBank
	ldrb r0, [r2]
	eors r0, r4
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	ldrb r0, [r3]
	bics r0, r1
	strb r0, [r3]
	ldrb r0, [r2]
_0806C574:
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0806C5B2
	ldr r1, =gBattleResults
	ldrb r0, [r1, 0x4]
	cmp r0, 0xFE
	bhi _0806C5B2
	adds r0, 0x1
	strb r0, [r1, 0x4]
	b _0806C5B2
	.pool
_0806C59C:
	mov r0, r8
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806C5B2
	ldr r0, [sp, 0x28]
	adds r0, 0x1
	lsls r0, 24
	b _0806C83E
_0806C5B2:
	ldr r1, [sp, 0x28]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x28]
	ldr r5, [sp, 0x24]
	adds r1, r5, r1
	ldrb r1, [r1]
	str r1, [sp]
	adds r0, r1, 0
	cmp r0, 0xFE
	beq _0806C5F4
	cmp r0, 0xFE
	bhi _0806C5D4
	cmp r0, 0xFD
	beq _0806C60A
	b _0806C612
_0806C5D4:
	cmp r1, 0xFF
	bne _0806C612
	mov r0, r8
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	subs r4, r0
	str r4, [sp]
	b _0806C612
_0806C5F4:
	mov r0, r8
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	lsrs r0, 1
	str r0, [sp]
	cmp r0, 0
	bne _0806C612
	movs r0, 0x1
	b _0806C610
_0806C60A:
	ldr r0, =gBattleScripting
	adds r0, 0x23
	ldrb r0, [r0]
_0806C610:
	str r0, [sp]
_0806C612:
	mov r0, r8
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	cmp r4, r0
	beq _0806C6F0
	ldr r0, [sp, 0x18]
	cmp r0, 0
	bne _0806C6E4
	mov r0, r8
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	ldr r1, [sp]
	adds r0, r1
	str r0, [sp]
	mov r0, r8
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	ldr r1, [sp]
	cmp r1, r0
	bls _0806C65E
	mov r0, r8
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	str r0, [sp]
_0806C65E:
	mov r0, r8
	movs r1, 0x39
	mov r2, sp
	bl SetMonData
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806C6EC
	ldr r2, [sp, 0x38]
	cmp r2, 0x4
	beq _0806C6EC
	ldr r1, =gBattleMons
	movs r0, 0x58
	muls r0, r2
	adds r0, r1
	ldr r1, [sp]
	strh r1, [r0, 0x28]
	movs r0, 0x10
	mov r3, r10
	ands r0, r3
	cmp r0, 0
	bne _0806C6EC
	ldr r4, =gActiveBank
	ldrb r0, [r4]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0806C6EC
	ldr r1, =gBattleResults
	ldrb r0, [r1, 0x3]
	cmp r0, 0xFE
	bhi _0806C6AE
	adds r0, 0x1
	strb r0, [r1, 0x3]
_0806C6AE:
	ldrb r5, [r4]
	add r0, sp, 0x38
	ldrb r0, [r0]
	strb r0, [r4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl EmitGetAttributes
	ldrb r0, [r4]
	bl MarkBufferBankForExecution
	strb r5, [r4]
	b _0806C6EC
	.pool
_0806C6E4:
	ldr r1, =gBattleMoveDamage
	ldr r0, [sp]
	negs r0, r0
	str r0, [r1]
_0806C6EC:
	movs r1, 0
	str r1, [sp, 0x20]
_0806C6F0:
	movs r0, 0xEF
	mov r2, r10
	ands r2, r0
	mov r10, r2
	b _0806C9AA
	.pool
_0806C700:
	movs r7, 0x2
	mov r0, r10
	ands r0, r7
	cmp r0, 0
	beq _0806C70C
	b _0806C858
_0806C70C:
	movs r5, 0
	ldr r3, [sp, 0x28]
	adds r3, 0x1
	str r3, [sp, 0x40]
_0806C714:
	movs r0, 0x11
	adds r0, r5
	mov r9, r0
	mov r0, r8
	mov r1, r9
	movs r2, 0
	bl GetMonData
	str r0, [sp]
	adds r7, r5, 0
	adds r7, 0xD
	mov r0, r8
	adds r1, r7, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r5, 24
	lsrs r6, r0, 24
	adds r0, r4, 0
	adds r2, r6, 0
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp]
	cmp r1, r0
	beq _0806C832
	ldr r2, [sp, 0x24]
	ldr r3, [sp, 0x28]
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, r1, r0
	str r0, [sp]
	mov r0, r8
	adds r1, r7, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	adds r2, r6, 0
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp]
	cmp r1, r0
	bls _0806C7CC
	mov r0, r8
	adds r1, r7, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	adds r2, r6, 0
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
_0806C7CC:
	mov r0, r8
	mov r1, r9
	mov r2, sp
	bl SetMonData
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806C82E
	ldr r2, [sp, 0x38]
	cmp r2, 0x4
	beq _0806C82E
	ldr r4, =gBattleMons
	movs r0, 0x58
	adds r3, r2, 0
	muls r3, r0
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r3, r0
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 14
	ands r1, r0
	cmp r1, 0
	bne _0806C82E
	ldr r1, =gDisableStructs
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0806C82E
	adds r0, r5, r3
	adds r1, r4, 0
	adds r1, 0x24
	adds r0, r1
	ldr r1, [sp]
	strb r1, [r0]
_0806C82E:
	movs r3, 0
	str r3, [sp, 0x20]
_0806C832:
	adds r5, 0x1
	cmp r5, 0x3
	bgt _0806C83A
	b _0806C714
_0806C83A:
	ldr r5, [sp, 0x40]
	lsls r0, r5, 24
_0806C83E:
	lsrs r0, 24
	str r0, [sp, 0x28]
	b _0806C9AA
	.pool
_0806C858:
	ldr r6, [sp, 0x14]
	adds r6, 0x11
	mov r0, r8
	adds r1, r6, 0
	movs r2, 0
	bl GetMonData
	str r0, [sp]
	ldr r5, [sp, 0x14]
	adds r5, 0xD
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	ldr r2, [sp, 0x14]
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp]
	cmp r2, r0
	bne _0806C8A0
	b _0806C9AA
_0806C8A0:
	ldr r1, [sp, 0x28]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x28]
	ldr r0, [sp, 0x24]
	adds r1, r0, r1
	ldrb r0, [r1]
	adds r0, r2, r0
	str r0, [sp]
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	ldr r2, [sp, 0x14]
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	ldr r1, [sp]
	cmp r1, r0
	bls _0806C914
	mov r0, r8
	adds r1, r5, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	ldr r2, [sp, 0x14]
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
_0806C914:
	mov r0, r8
	adds r1, r6, 0
	mov r2, sp
	bl SetMonData
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	beq _0806C978
	ldr r2, [sp, 0x38]
	cmp r2, 0x4
	beq _0806C978
	ldr r4, =gBattleMons
	movs r0, 0x58
	adds r3, r2, 0
	muls r3, r0
	adds r0, r4, 0
	adds r0, 0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 14
	ands r0, r1
	cmp r0, 0
	bne _0806C978
	ldr r1, =gDisableStructs
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x18]
	lsrs r1, 4
	ldr r2, =gBitTable
	ldr r5, [sp, 0x14]
	lsls r0, r5, 2
	adds r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, 0
	bne _0806C978
	adds r0, r5, r3
	adds r1, r4, 0
	adds r1, 0x24
	adds r0, r1
	ldr r1, [sp]
	strb r1, [r0]
_0806C978:
	movs r0, 0
	str r0, [sp, 0x20]
	b _0806C9AA
	.pool
_0806C994:
	mov r0, r8
	movs r1, 0x2
	ldr r2, [sp, 0xC]
	bl GetEvolutionTargetSpecies
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0806C9AA
	bl _0806BEE0
_0806C9AA:
	ldr r1, [sp, 0x2C]
	adds r1, 0x1
	str r1, [sp, 0x2C]
	mov r2, r10
	lsrs r2, 1
	mov r10, r2
	cmp r2, 0
	beq _0806C9BC
	b _0806C3E6
_0806C9BC:
	b _0806CD4C
_0806C9BE:
	ldr r3, [sp, 0x24]
	ldr r5, [sp, 0x1C]
	adds r0, r3, r5
	ldrb r0, [r0]
	mov r10, r0
	movs r0, 0
	str r0, [sp, 0x2C]
	mov r1, r10
	cmp r1, 0
	bne _0806C9D4
	b _0806CD4C
_0806C9D4:
	movs r0, 0x1
	mov r2, r10
	ands r0, r2
	cmp r0, 0
	bne _0806C9E0
	b _0806CD3A
_0806C9E0:
	ldr r3, [sp, 0x2C]
	cmp r3, 0x7
	bls _0806C9E8
	b _0806CD3A
_0806C9E8:
	lsls r0, r3, 2
	ldr r1, =_0806C9F8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806C9F8:
	.4byte _0806CA18
	.4byte _0806CA18
	.4byte _0806CA18
	.4byte _0806CA18
	.4byte _0806CAB8
	.4byte _0806CB94
	.4byte _0806CC00
	.4byte _0806CC68
_0806CA18:
	mov r0, r8
	bl GetMonEVCount
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r5, [sp, 0x24]
	ldr r1, [sp, 0x28]
	adds r0, r5, r1
	ldrb r5, [r0]
	ldr r0, =gUnknown_08329EC2
	ldr r4, [sp, 0x2C]
	adds r4, 0x2
	adds r0, r4, r0
	ldrb r1, [r0]
	mov r0, r8
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	str r1, [sp, 0x4]
	lsls r0, r5, 24
	asrs r2, r0, 24
	cmp r2, 0
	ble _0806CA84
	ldr r0, =0x000001fd
	cmp r6, r0
	bls _0806CA52
	bl _0806BEF0
_0806CA52:
	adds r3, r1, 0
	cmp r3, 0x63
	ble _0806CA5A
	b _0806CD3A
_0806CA5A:
	adds r1, r3, r2
	cmp r1, 0x64
	ble _0806CA70
	adds r0, r2, 0
	adds r0, 0x64
	subs r5, r0, r1
	b _0806CA72
	.pool
_0806CA70:
	adds r5, r2, 0
_0806CA72:
	adds r1, r6, r5
	movs r0, 0xFF
	lsls r0, 1
	cmp r1, r0
	bls _0806CA80
	adds r0, r5, r0
	subs r5, r0, r1
_0806CA80:
	adds r0, r3, r5
	b _0806CA98
_0806CA84:
	cmp r1, 0
	bne _0806CA8E
	movs r2, 0x1
	str r2, [sp, 0x3C]
	b _0806CD30
_0806CA8E:
	adds r0, r1, r2
	str r0, [sp, 0x4]
	cmp r0, 0
	bge _0806CA9A
	movs r0, 0
_0806CA98:
	str r0, [sp, 0x4]
_0806CA9A:
	ldr r0, =gUnknown_08329EC2
	adds r0, r4, r0
	ldrb r1, [r0]
	add r2, sp, 0x4
	mov r0, r8
	bl SetMonData
	mov r0, r8
	bl CalculateMonStats
	movs r3, 0
	str r3, [sp, 0x20]
	b _0806CD30
	.pool
_0806CAB8:
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	ldr r1, =gUnknown_08329D22
	ldr r5, [sp, 0x14]
	adds r1, r5, r1
	ldrb r1, [r1]
	ands r0, r1
	lsls r1, r5, 1
	lsrs r0, r1
	str r0, [sp]
	adds r6, r5, 0
	adds r6, 0xD
	mov r0, r8
	adds r1, r6, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	ldr r2, [sp, 0x14]
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, [sp]
	cmp r0, 0x2
	bls _0806CB0A
	b _0806CD3A
_0806CB0A:
	cmp r5, 0x4
	bhi _0806CB10
	b _0806CD3A
_0806CB10:
	mov r0, r8
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	str r0, [sp]
	ldr r1, =gUnknown_08329D26
	ldr r2, [sp, 0x14]
	adds r1, r2, r1
	ldrb r2, [r1]
	ands r2, r0
	str r2, [sp]
	ldr r0, =gUnknown_08329D2A
	ldr r3, [sp, 0x14]
	adds r0, r3, r0
	ldrb r1, [r0]
	lsls r0, r1, 1
	adds r0, r1
	adds r2, r0
	str r2, [sp]
	mov r0, r8
	movs r1, 0x15
	mov r2, sp
	bl SetMonData
	mov r0, r8
	adds r1, r6, 0
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, [sp, 0x14]
	bl CalculatePPWithBonus
	lsls r0, 24
	lsrs r0, 24
	subs r0, r5
	str r0, [sp]
	ldr r4, [sp, 0x14]
	adds r4, 0x11
	mov r0, r8
	adds r1, r4, 0
	movs r2, 0
	bl GetMonData
	ldr r1, [sp]
	adds r0, r1
	str r0, [sp]
	mov r0, r8
	adds r1, r4, 0
	mov r2, sp
	bl SetMonData
	movs r5, 0
	str r5, [sp, 0x20]
	b _0806CD3A
	.pool
_0806CB94:
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	cmp r0, 0x63
	bls _0806CBA4
	b _0806CD30
_0806CBA4:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _0806CBB2
	ldr r1, [sp, 0x3C]
	cmp r1, 0
	bne _0806CBB2
	b _0806CD30
_0806CBB2:
	bl sub_806F104
	lsls r0, 24
	cmp r0, 0
	beq _0806CBBE
	b _0806CD30
_0806CBBE:
	ldr r2, [sp, 0x30]
	cmp r2, 0
	beq _0806CBC6
	b _0806CD30
_0806CBC6:
	ldr r3, [sp, 0x24]
	ldr r5, [sp, 0x28]
	adds r0, r3, r5
	ldrb r0, [r0]
	str r0, [sp, 0x30]
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	adds r5, r0, 0
	str r5, [sp, 0x8]
	ldr r0, [sp, 0x30]
	lsls r4, r0, 24
	asrs r1, r4, 24
	cmp r1, 0
	ble _0806CCCC
	ldr r2, [sp, 0x34]
	cmp r2, 0x1B
	bne _0806CCCC
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, r5, r0
	str r0, [sp, 0x8]
	adds r2, r4, 0
	b _0806CCD8
_0806CC00:
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	cmp r0, 0x63
	bhi _0806CC10
	b _0806CD30
_0806CC10:
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	cmp r0, 0xC7
	bls _0806CC20
	b _0806CD30
_0806CC20:
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _0806CC2E
	ldr r1, [sp, 0x3C]
	cmp r1, 0
	bne _0806CC2E
	b _0806CD30
_0806CC2E:
	bl sub_806F104
	lsls r0, 24
	cmp r0, 0
	bne _0806CD30
	ldr r2, [sp, 0x30]
	cmp r2, 0
	bne _0806CD30
	ldr r3, [sp, 0x24]
	ldr r5, [sp, 0x28]
	adds r0, r3, r5
	ldrb r0, [r0]
	str r0, [sp, 0x30]
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	str r4, [sp, 0x8]
	ldr r0, [sp, 0x30]
	lsls r5, r0, 24
	asrs r1, r5, 24
	cmp r1, 0
	ble _0806CCCC
	ldr r2, [sp, 0x34]
	cmp r2, 0x1B
	beq _0806CCBA
	b _0806CCCC
_0806CC68:
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	cmp r0, 0xC7
	bls _0806CD30
	ldr r0, [sp, 0x20]
	cmp r0, 0
	beq _0806CC82
	ldr r1, [sp, 0x3C]
	cmp r1, 0
	beq _0806CD30
_0806CC82:
	bl sub_806F104
	lsls r0, 24
	cmp r0, 0
	bne _0806CD30
	ldr r2, [sp, 0x30]
	cmp r2, 0
	bne _0806CD30
	ldr r3, [sp, 0x24]
	ldr r5, [sp, 0x28]
	adds r0, r3, r5
	ldrb r0, [r0]
	str r0, [sp, 0x30]
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	str r4, [sp, 0x8]
	ldr r0, [sp, 0x30]
	lsls r5, r0, 24
	asrs r1, r5, 24
	cmp r1, 0
	ble _0806CCCC
	ldr r2, [sp, 0x34]
	cmp r2, 0x1B
	bne _0806CCCC
_0806CCBA:
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	adds r0, r4, r0
	str r0, [sp, 0x8]
	adds r2, r5, 0
	b _0806CCD8
_0806CCCC:
	ldr r3, [sp, 0x30]
	lsls r2, r3, 24
	asrs r1, r2, 24
	ldr r0, [sp, 0x8]
	adds r0, r1
	str r0, [sp, 0x8]
_0806CCD8:
	cmp r2, 0
	ble _0806CD0E
	mov r0, r8
	movs r1, 0x26
	movs r2, 0
	bl GetMonData
	cmp r0, 0xB
	bne _0806CCF0
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
_0806CCF0:
	mov r0, r8
	movs r1, 0x23
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	bl sav1_map_get_name
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0806CD0E
	ldr r0, [sp, 0x8]
	adds r0, 0x1
	str r0, [sp, 0x8]
_0806CD0E:
	ldr r0, [sp, 0x8]
	cmp r0, 0
	bge _0806CD18
	movs r0, 0
	str r0, [sp, 0x8]
_0806CD18:
	ldr r0, [sp, 0x8]
	cmp r0, 0xFF
	ble _0806CD22
	movs r0, 0xFF
	str r0, [sp, 0x8]
_0806CD22:
	add r2, sp, 0x8
	mov r0, r8
	movs r1, 0x20
	bl SetMonData
	movs r5, 0
	str r5, [sp, 0x20]
_0806CD30:
	ldr r0, [sp, 0x28]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x28]
_0806CD3A:
	ldr r0, [sp, 0x2C]
	adds r0, 0x1
	str r0, [sp, 0x2C]
	mov r1, r10
	lsrs r1, 1
	mov r10, r1
	cmp r1, 0
	beq _0806CD4C
	b _0806C9D4
_0806CD4C:
	ldr r2, [sp, 0x1C]
	adds r2, 0x1
	str r2, [sp, 0x1C]
	cmp r2, 0x5
	bgt _0806CD5A
	bl _0806BEFC
_0806CD5A:
	ldr r0, [sp, 0x20]
_0806CD5C:
	add sp, 0x44
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end ExecuteTableBasedItemEffect

	.align 2, 0 @ Don't pad with nop.
    