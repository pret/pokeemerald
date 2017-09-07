	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start HealStatusConditions
@ bool8 HealStatusConditions(struct pokemon *a1, int a2, u32 healMask, u8 a4)
HealStatusConditions: @ 806CD6C
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	adds r4, r2, 0
	lsls r3, 24
	lsrs r6, r3, 24
	movs r1, 0x37
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	str r1, [sp]
	ands r0, r4
	cmp r0, 0
	beq _0806CDD0
	mvns r4, r4
	ands r1, r4
	str r1, [sp]
	adds r0, r5, 0
	movs r1, 0x37
	mov r2, sp
	bl SetMonData
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806CDBE
	cmp r6, 0x4
	beq _0806CDBE
	ldr r0, =gBattleMons
	movs r1, 0x58
	muls r1, r6
	adds r0, 0x4C
	adds r1, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
_0806CDBE:
	movs r0, 0
	b _0806CDD2
	.pool
_0806CDD0:
	movs r0, 0x1
_0806CDD2:
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end HealStatusConditions

	thumb_func_start GetItemEffectParamOffset
GetItemEffectParamOffset: @ 806CDDC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r7, 0x6
	ldr r1, =gItemEffectTable
	adds r0, r3, 0
	subs r0, 0xD
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	bne _0806CE08
	cmp r3, 0xAF
	beq _0806CE0C
_0806CE00:
	movs r0, 0
	b _0806CF1C
	.pool
_0806CE08:
	cmp r3, 0xAF
	bne _0806CE1A
_0806CE0C:
	ldr r0, =gActiveBank
	ldrb r1, [r0]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, =gEnigmaBerries + 8
	adds r0, r1
_0806CE1A:
	mov r12, r0
	movs r2, 0
_0806CE1E:
	cmp r2, 0x4
	beq _0806CE3E
	cmp r2, 0x4
	ble _0806CE34
	cmp r2, 0x5
	beq _0806CEC8
	b _0806CF12
	.pool
_0806CE34:
	cmp r2, 0
	blt _0806CF12
	cmp r2, r4
	bne _0806CF12
	b _0806CE00
_0806CE3E:
	mov r0, r12
	ldrb r3, [r0, 0x4]
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _0806CE4E
	movs r0, 0xDF
	ands r3, r0
_0806CE4E:
	movs r6, 0
	cmp r3, 0
	beq _0806CF12
_0806CE54:
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0806CEB4
	cmp r6, 0x7
	bhi _0806CEB4
	lsls r0, r6, 2
	ldr r1, =_0806CE70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806CE70:
	.4byte _0806CE9C
	.4byte _0806CE9C
	.4byte _0806CE90
	.4byte _0806CE9C
	.4byte _0806CEB4
	.4byte _0806CEB4
	.4byte _0806CEB4
	.4byte _0806CEB0
_0806CE90:
	movs r0, 0x10
	ands r0, r3
	cmp r0, 0
	beq _0806CE9C
	movs r0, 0xEF
	ands r3, r0
_0806CE9C:
	cmp r2, r4
	bne _0806CEA8
	adds r0, r3, 0
	ands r0, r5
	cmp r0, 0
	bne _0806CF1A
_0806CEA8:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	b _0806CEB4
_0806CEB0:
	cmp r2, r4
	beq _0806CE00
_0806CEB4:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	lsrs r3, 1
	cmp r2, r4
	bne _0806CEC2
	lsrs r5, 1
_0806CEC2:
	cmp r3, 0
	bne _0806CE54
	b _0806CF12
_0806CEC8:
	mov r0, r12
	ldrb r3, [r0, 0x5]
	movs r6, 0
_0806CECE:
	cmp r3, 0
	beq _0806CF12
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq _0806CF02
	cmp r6, 0
	blt _0806CF02
	cmp r6, 0x6
	ble _0806CEE8
	cmp r6, 0x7
	beq _0806CEFC
	b _0806CF02
_0806CEE8:
	cmp r2, r4
	bne _0806CEF4
	adds r0, r3, 0
	ands r0, r5
	cmp r0, 0
	bne _0806CF1A
_0806CEF4:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	b _0806CF02
_0806CEFC:
	cmp r2, r4
	bne _0806CF02
	b _0806CE00
_0806CF02:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	lsrs r3, 1
	cmp r2, r4
	bne _0806CECE
	lsrs r5, 1
	b _0806CECE
_0806CF12:
	adds r2, 0x1
	cmp r2, 0x5
	bgt _0806CF1A
	b _0806CE1E
_0806CF1A:
	adds r0, r7, 0
_0806CF1C:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetItemEffectParamOffset

	thumb_func_start sub_806CF24
sub_806CF24: @ 806CF24
	push {lr}
	ldr r2, =gBankTarget
	ldr r1, =gUnknown_020244B8
	ldrb r1, [r1]
	strb r1, [r2]
	ldr r3, =gBattleTextBuff1
	ldr r2, =gUnknown_085CBE00
	ldr r1, =gUnknown_08329EC8
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	adds r0, r3, 0
	bl StringCopy
	ldr r0, =gBattleTextBuff2
	ldr r1, =gUnknown_085CB38A
	bl StringCopy
	ldr r0, =gUnknown_085CB3AA
	bl StrCpyDecodeToDisplayedStringBattle
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806CF24

	thumb_func_start sub_806CF78
sub_806CF78: @ 806CF78
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _0806CFCC
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806CFB8
	ldr r2, =gUnknown_020244B8
	ldrb r1, [r2]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	ldr r1, =gEnigmaBerries + 8
	adds r7, r0, r1
	b _0806CFD8
	.pool
_0806CFB8:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003214
	adds r7, r0, r1
	b _0806CFD6
	.pool
_0806CFCC:
	ldr r1, =gItemEffectTable
	subs r0, 0xD
	lsls r0, 2
	adds r0, r1
	ldr r7, [r0]
_0806CFD6:
	ldr r2, =gUnknown_020244B8
_0806CFD8:
	ldr r1, =gUnknown_0202420F
	ldrb r0, [r2]
	strb r0, [r1]
	movs r5, 0
	ldr r0, =gBankAttacker
	mov r8, r0
	movs r6, 0
_0806CFE6:
	adds r4, r7, r5
	ldrb r1, [r4]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _0806CFF8
	adds r0, r6, 0
	bl sub_806CF24
_0806CFF8:
	ldrb r1, [r4]
	movs r0, 0xF0
	ands r0, r1
	cmp r0, 0
	beq _0806D02E
	cmp r5, 0
	beq _0806D020
	adds r0, r6, 0x1
	bl sub_806CF24
	b _0806D02E
	.pool
_0806D020:
	ldr r0, =gUnknown_020244B8
	ldrb r0, [r0]
	mov r1, r8
	strb r0, [r1]
	ldr r0, =gUnknown_085CA459
	bl StrCpyDecodeToDisplayedStringBattle
_0806D02E:
	adds r6, 0x2
	adds r5, 0x1
	cmp r5, 0x2
	ble _0806CFE6
	ldrb r1, [r7, 0x3]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806D04E
	ldr r1, =gBankAttacker
	ldr r0, =gUnknown_020244B8
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, =gUnknown_085CA424
	bl StrCpyDecodeToDisplayedStringBattle
_0806D04E:
	ldr r0, =gDisplayedStringBattle
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806CF78

	thumb_func_start GetNature
@ u8 GetNature(pokemon *mon)
GetNature: @ 806D070
	push {lr}
	movs r1, 0
	movs r2, 0
	bl GetMonData
	movs r1, 0x19
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end GetNature

	thumb_func_start GetNatureFromPersonality
@ u8 GetNatureFromPersonality(u32 personality)
GetNatureFromPersonality: @ 806D088
	push {lr}
	movs r1, 0x19
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end GetNatureFromPersonality

	thumb_func_start GetEvolutionTargetSpecies
GetEvolutionTargetSpecies: @ 806D098
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r8, r0
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 16
	lsrs r2, 16
	mov r9, r2
	movs r0, 0
	mov r10, r0
	mov r0, r8
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	mov r0, r8
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	movs r1, 0
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x17
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	lsrs r4, 16
	str r4, [sp, 0x10]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, 0xAF
	bne _0806D10C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003226
	adds r0, r1
	ldrb r0, [r0]
	b _0806D114
	.pool
_0806D10C:
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r0, 24
_0806D114:
	cmp r0, 0x26
	bne _0806D120
	cmp r5, 0x3
	beq _0806D120
	movs r0, 0
	b _0806D3B0
_0806D120:
	cmp r5, 0x1
	bne _0806D126
	b _0806D340
_0806D126:
	cmp r5, 0x1
	bgt _0806D130
	cmp r5, 0
	beq _0806D144
	b _0806D3AE
_0806D130:
	cmp r5, 0x3
	ble _0806D136
	b _0806D3AE
_0806D136:
	movs r2, 0
	str r2, [sp, 0x4]
	ldr r3, =gEvolutionTable
	lsls r6, r7, 2
	b _0806D38E
	.pool
_0806D144:
	mov r0, r8
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r0, r8
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0x4]
	lsls r6, r7, 2
_0806D16A:
	ldr r1, =gEvolutionTable
	ldr r0, [sp, 0x4]
	lsls r2, r0, 3
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r2, r0
	adds r0, r1
	ldrh r0, [r0]
	subs r0, 0x1
	adds r3, r1, 0
	adds r4, r2, 0
	cmp r0, 0xE
	bls _0806D186
	b _0806D332
_0806D186:
	lsls r0, 2
	ldr r1, =_0806D198
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806D198:
	.4byte _0806D1D4
	.4byte _0806D1E6
	.4byte _0806D208
	.4byte _0806D238
	.4byte _0806D332
	.4byte _0806D332
	.4byte _0806D332
	.4byte _0806D248
	.4byte _0806D272
	.4byte _0806D29C
	.4byte _0806D2CA
	.4byte _0806D2EA
	.4byte _0806D30E
	.4byte _0806D332
	.4byte _0806D31E
_0806D1D4:
	ldr r1, [sp, 0x8]
	cmp r1, 0xDB
	bhi _0806D1DC
	b _0806D332
_0806D1DC:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r0, r3
	b _0806D228
_0806D1E6:
	bl RtcCalcLocalTime
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	subs r0, 0xC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xB
	bls _0806D1FA
	b _0806D332
_0806D1FA:
	ldr r2, [sp, 0x8]
	cmp r2, 0xDB
	bhi _0806D202
	b _0806D332
_0806D202:
	b _0806D21E
	.pool
_0806D208:
	bl RtcCalcLocalTime
	ldr r0, =gLocalTime
	ldrb r0, [r0, 0x2]
	cmp r0, 0xB
	bls _0806D216
	b _0806D332
_0806D216:
	ldr r0, [sp, 0x8]
	cmp r0, 0xDB
	bhi _0806D21E
	b _0806D332
_0806D21E:
	ldr r1, =gEvolutionTable
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r0, r1
_0806D228:
	ldrh r0, [r0, 0x4]
	mov r10, r0
	b _0806D332
	.pool
_0806D238:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r1, r0, r3
	ldrh r0, [r1, 0x2]
	cmp r0, r9
	bhi _0806D332
	b _0806D32E
_0806D248:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r5, r0, r3
	ldrh r0, [r5, 0x2]
	cmp r0, r9
	bhi _0806D332
	mov r0, r8
	movs r1, 0x3B
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x3C
	movs r2, 0
	bl GetMonData
	cmp r4, r0
	bls _0806D332
	b _0806D2C4
_0806D272:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r5, r0, r3
	ldrh r0, [r5, 0x2]
	cmp r0, r9
	bhi _0806D332
	mov r0, r8
	movs r1, 0x3B
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x3C
	movs r2, 0
	bl GetMonData
	cmp r4, r0
	bne _0806D332
	b _0806D2C4
_0806D29C:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r5, r0, r3
	ldrh r0, [r5, 0x2]
	cmp r0, r9
	bhi _0806D332
	mov r0, r8
	movs r1, 0x3B
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	mov r0, r8
	movs r1, 0x3C
	movs r2, 0
	bl GetMonData
	cmp r4, r0
	bcs _0806D332
_0806D2C4:
	ldrh r5, [r5, 0x4]
	mov r10, r5
	b _0806D332
_0806D2CA:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r4, r0, r3
	ldrh r0, [r4, 0x2]
	cmp r0, r9
	bhi _0806D332
	ldr r0, [sp, 0x10]
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bhi _0806D332
	b _0806D308
_0806D2EA:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r4, r0, r3
	ldrh r0, [r4, 0x2]
	cmp r0, r9
	bhi _0806D332
	ldr r0, [sp, 0x10]
	movs r1, 0xA
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bls _0806D332
_0806D308:
	ldrh r4, [r4, 0x4]
	mov r10, r4
	b _0806D332
_0806D30E:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r1, r0, r3
	ldrh r0, [r1, 0x2]
	cmp r0, r9
	bhi _0806D332
	b _0806D32E
_0806D31E:
	adds r0, r6, r7
	lsls r0, 3
	adds r0, r4, r0
	adds r1, r0, r3
	ldrh r0, [r1, 0x2]
	ldr r2, [sp, 0xC]
	cmp r0, r2
	bhi _0806D332
_0806D32E:
	ldrh r1, [r1, 0x4]
	mov r10, r1
_0806D332:
	ldr r0, [sp, 0x4]
	adds r0, 0x1
	str r0, [sp, 0x4]
	cmp r0, 0x4
	bgt _0806D33E
	b _0806D16A
_0806D33E:
	b _0806D3AE
_0806D340:
	lsls r6, r7, 2
	ldr r1, =gEvolutionTable
	adds r0, r6, r7
	lsls r0, 3
	adds r4, r0, r1
	mov r5, sp
	movs r1, 0x4
	str r1, [sp, 0x4]
_0806D350:
	ldrh r0, [r4]
	cmp r0, 0x5
	beq _0806D370
	cmp r0, 0x6
	bne _0806D374
	ldrh r0, [r4, 0x2]
	ldrh r1, [r5]
	cmp r0, r1
	bne _0806D374
	movs r0, 0
	strh r0, [r5]
	mov r0, r8
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
_0806D370:
	ldrh r2, [r4, 0x4]
	mov r10, r2
_0806D374:
	adds r4, 0x8
	ldr r0, [sp, 0x4]
	subs r0, 0x1
	str r0, [sp, 0x4]
	cmp r0, 0
	bge _0806D350
	b _0806D3AE
	.pool
_0806D388:
	ldrh r1, [r1, 0x4]
	mov r10, r1
	b _0806D3AE
_0806D38E:
	adds r0, r6, r7
	ldr r1, [sp, 0x4]
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r3
	ldrh r0, [r1]
	cmp r0, 0x7
	bne _0806D3A4
	ldrh r0, [r1, 0x2]
	cmp r0, r9
	beq _0806D388
_0806D3A4:
	ldr r2, [sp, 0x4]
	adds r2, 0x1
	str r2, [sp, 0x4]
	cmp r2, 0x4
	ble _0806D38E
_0806D3AE:
	mov r0, r10
_0806D3B0:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetEvolutionTargetSpecies

	thumb_func_start HoennPokedexNumToSpecies
HoennPokedexNumToSpecies: @ 806D3C0
	push {r4,lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _0806D404
	movs r1, 0
	ldr r3, =gSpeciesToHoennPokedexNum
	ldrh r0, [r3]
	cmp r0, r2
	beq _0806D3EC
	movs r4, 0xCD
	lsls r4, 1
_0806D3D8:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r4
	bhi _0806D3EC
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _0806D3D8
_0806D3EC:
	ldr r0, =0x0000019b
	cmp r1, r0
	beq _0806D404
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	b _0806D406
	.pool
_0806D404:
	movs r0, 0
_0806D406:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end HoennPokedexNumToSpecies

	thumb_func_start NationalPokedexNumToSpecies
NationalPokedexNumToSpecies: @ 806D40C
	push {r4,lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _0806D450
	movs r1, 0
	ldr r3, =gSpeciesToNationalPokedexNum
	ldrh r0, [r3]
	cmp r0, r2
	beq _0806D438
	movs r4, 0xCD
	lsls r4, 1
_0806D424:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r4
	bhi _0806D438
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _0806D424
_0806D438:
	ldr r0, =0x0000019b
	cmp r1, r0
	beq _0806D450
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	b _0806D452
	.pool
_0806D450:
	movs r0, 0
_0806D452:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end NationalPokedexNumToSpecies

	thumb_func_start NationalToHoennOrder
NationalToHoennOrder: @ 806D458
	push {r4,lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0
	beq _0806D49C
	movs r1, 0
	ldr r3, =gHoennToNationalOrder
	ldrh r0, [r3]
	cmp r0, r2
	beq _0806D484
	movs r4, 0xCD
	lsls r4, 1
_0806D470:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r4
	bhi _0806D484
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _0806D470
_0806D484:
	ldr r0, =0x0000019b
	cmp r1, r0
	beq _0806D49C
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r0, 16
	b _0806D49E
	.pool
_0806D49C:
	movs r0, 0
_0806D49E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end NationalToHoennOrder

	thumb_func_start SpeciesToNationalPokedexNum
SpeciesToNationalPokedexNum: @ 806D4A4
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0806D4C0
	ldr r0, =gSpeciesToNationalPokedexNum
	subs r1, 0x1
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	b _0806D4C2
	.pool
_0806D4C0:
	movs r0, 0
_0806D4C2:
	pop {r1}
	bx r1
	thumb_func_end SpeciesToNationalPokedexNum

	thumb_func_start SpeciesToHoennPokedexNum
SpeciesToHoennPokedexNum: @ 806D4C8
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0806D4E4
	ldr r0, =gSpeciesToHoennPokedexNum
	subs r1, 0x1
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	b _0806D4E6
	.pool
_0806D4E4:
	movs r0, 0
_0806D4E6:
	pop {r1}
	bx r1
	thumb_func_end SpeciesToHoennPokedexNum

	thumb_func_start HoennToNationalOrder
HoennToNationalOrder: @ 806D4EC
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _0806D508
	ldr r0, =gHoennToNationalOrder
	subs r1, 0x1
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	b _0806D50A
	.pool
_0806D508:
	movs r0, 0
_0806D50A:
	pop {r1}
	bx r1
	thumb_func_end HoennToNationalOrder

	thumb_func_start SpeciesToCryId
SpeciesToCryId: @ 806D510
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	adds r1, r0, 0
	cmp r0, 0xFA
	bls _0806D53E
	ldr r0, =0x00000113
	cmp r1, r0
	bls _0806D53C
	ldr r0, =gSpeciesIdToCryId
	ldr r2, =0xfffffeec
	adds r1, r2
	lsls r1, 1
	adds r1, r0
	ldrh r0, [r1]
	b _0806D53E
	.pool
_0806D53C:
	movs r0, 0xC8
_0806D53E:
	pop {r1}
	bx r1
	thumb_func_end SpeciesToCryId

	thumb_func_start sub_806D544
sub_806D544: @ 806D544
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r6, r1, 0
	mov r10, r2
	lsls r0, 16
	movs r1, 0x9A
	lsls r1, 17
	cmp r0, r1
	bne _0806D652
	ldr r0, =gUnknown_020244D4
	ldr r1, [r0]
	ldr r0, [r1, 0x4]
	cmp r10, r0
	beq _0806D652
	ldr r0, [r1, 0xC]
	cmp r10, r0
	beq _0806D652
	movs r5, 0
_0806D570:
	lsls r3, r5, 3
	adds r3, r5
	lsls r3, 2
	ldr r0, =gSpindaSpotGraphics
	adds r4, r3, r0
	ldrb r1, [r4]
	adds r1, 0xF8
	movs r2, 0xF
	adds r0, r6, 0
	ands r0, r2
	adds r1, r0
	lsls r1, 24
	lsrs r1, 24
	mov r12, r1
	ldrb r1, [r4, 0x1]
	adds r1, 0xF8
	movs r0, 0xF0
	ands r0, r6
	lsrs r0, 4
	adds r1, r0
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	lsrs r6, 8
	str r6, [sp, 0x4]
	adds r5, 0x1
	str r5, [sp]
	mov r9, r3
_0806D5A8:
	lsls r0, r2, 1
	add r0, r9
	ldr r3, =gSpindaSpotGraphics + 0x2
	adds r0, r3
	ldrh r3, [r0]
	mov r4, r12
	adds r0, r4, 0
	adds r0, 0x10
	adds r7, r1, 0x1
	adds r2, 0x1
	mov r8, r2
	cmp r4, r0
	bge _0806D640
	lsrs r0, r1, 3
	lsls r6, r0, 8
	movs r0, 0x7
	ands r1, r0
	lsls r5, r1, 2
_0806D5CC:
	adds r0, r4, 0
	cmp r4, 0
	bge _0806D5D4
	adds r0, r4, 0x7
_0806D5D4:
	asrs r0, 3
	lsls r2, r0, 5
	add r2, r10
	lsls r0, 3
	subs r0, r4, r0
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	adds r2, r6
	adds r2, r5
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0806D634
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0806D620
	ldrb r1, [r2]
	movs r0, 0xF0
	ands r0, r1
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x20
	bhi _0806D634
	adds r0, r1, 0
	adds r0, 0x40
	b _0806D632
	.pool
_0806D620:
	ldrb r1, [r2]
	movs r0, 0xF
	ands r0, r1
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _0806D634
	adds r0, r1, 0x4
_0806D632:
	strb r0, [r2]
_0806D634:
	asrs r3, 1
	adds r4, 0x1
	mov r0, r12
	adds r0, 0x10
	cmp r4, r0
	blt _0806D5CC
_0806D640:
	lsls r0, r7, 24
	lsrs r1, r0, 24
	mov r2, r8
	cmp r2, 0xF
	ble _0806D5A8
	ldr r6, [sp, 0x4]
	ldr r5, [sp]
	cmp r5, 0x3
	ble _0806D570
_0806D652:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_806D544

	thumb_func_start DrawSpindaSpots
@ void DrawSpindaSpots(u16 species, u32 personality, u8 *pixels, u8 isFrontPic)
DrawSpindaSpots: @ 806D664
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r5, r1, 0
	str r2, [sp]
	lsls r0, 16
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x9A
	lsls r1, 17
	cmp r0, r1
	bne _0806D766
	cmp r3, 0
	beq _0806D766
	movs r6, 0
_0806D688:
	lsls r3, r6, 3
	adds r3, r6
	lsls r3, 2
	ldr r0, =gSpindaSpotGraphics
	adds r4, r3, r0
	ldrb r1, [r4]
	adds r1, 0xF8
	movs r2, 0xF
	adds r0, r5, 0
	ands r0, r2
	adds r1, r0
	lsls r1, 24
	lsrs r1, 24
	mov r12, r1
	ldrb r1, [r4, 0x1]
	adds r1, 0xF8
	movs r0, 0xF0
	ands r0, r5
	lsrs r0, 4
	adds r1, r0
	lsls r1, 24
	lsrs r1, 24
	movs r2, 0
	lsrs r5, 8
	str r5, [sp, 0x4]
	adds r6, 0x1
	mov r10, r6
	mov r9, r3
_0806D6C0:
	lsls r0, r2, 1
	add r0, r9
	ldr r3, =gSpindaSpotGraphics + 0x2
	adds r0, r3
	ldrh r3, [r0]
	mov r4, r12
	adds r0, r4, 0
	adds r0, 0x10
	adds r7, r1, 0x1
	adds r2, 0x1
	mov r8, r2
	cmp r4, r0
	bge _0806D754
	lsrs r0, r1, 3
	lsls r6, r0, 8
	movs r0, 0x7
	ands r1, r0
	lsls r5, r1, 2
_0806D6E4:
	adds r0, r4, 0
	cmp r4, 0
	bge _0806D6EC
	adds r0, r4, 0x7
_0806D6EC:
	asrs r0, 3
	lsls r2, r0, 5
	ldr r1, [sp]
	adds r2, r1, r2
	lsls r0, 3
	subs r0, r4, r0
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	adds r2, r0
	adds r2, r6
	adds r2, r5
	movs r1, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _0806D748
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0806D734
	ldrb r1, [r2]
	movs r0, 0xF0
	ands r0, r1
	subs r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x20
	bhi _0806D748
	adds r0, r1, 0
	adds r0, 0x40
	b _0806D746
	.pool
_0806D734:
	ldrb r1, [r2]
	movs r0, 0xF
	ands r0, r1
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _0806D748
	adds r0, r1, 0x4
_0806D746:
	strb r0, [r2]
_0806D748:
	asrs r3, 1
	adds r4, 0x1
	mov r0, r12
	adds r0, 0x10
	cmp r4, r0
	blt _0806D6E4
_0806D754:
	lsls r0, r7, 24
	lsrs r1, r0, 24
	mov r2, r8
	cmp r2, 0xF
	ble _0806D6C0
	ldr r5, [sp, 0x4]
	mov r6, r10
	cmp r6, 0x3
	ble _0806D688
_0806D766:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DrawSpindaSpots

	thumb_func_start sub_806D778
sub_806D778: @ 806D778
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	ldr r0, =gStringVar1
	mov r9, r0
	adds r0, r5, 0
	movs r1, 0x2
	mov r2, r9
	bl GetMonData
	mov r4, sp
	adds r0, r5, 0
	movs r1, 0x3
	mov r2, sp
	bl GetMonData
	strb r0, [r4]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _0806D7D4
	movs r6, 0xB
	adds r0, r7, 0
	muls r0, r6
	ldr r4, =gSpeciesNames
	adds r0, r4
	mov r1, r9
	bl StringCompare
	cmp r0, 0
	bne _0806D7D4
	mov r2, r8
	muls r2, r6
	adds r2, r4
	adds r0, r5, 0
	movs r1, 0x2
	bl SetMonData
_0806D7D4:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806D778

	thumb_func_start sub_806D7EC
sub_806D7EC: @ 806D7EC
	push {r4,r5,lr}
	movs r5, 0
	ldr r4, =gLinkPlayers
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r0, [r1, 0x18]
	cmp r0, 0x2
	bgt _0806D818
	cmp r0, 0x1
	bge _0806D820
	cmp r0, 0
	beq _0806D81C
	b _0806D822
	.pool
_0806D818:
	cmp r0, 0x3
	bne _0806D822
_0806D81C:
	movs r5, 0
	b _0806D822
_0806D820:
	movs r5, 0x1
_0806D822:
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_806D7EC

	thumb_func_start sub_806D82C
sub_806D82C: @ 806D82C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r3, 0
	ldr r2, =gLinkPlayers
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x18]
	cmp r0, 0x2
	bgt _0806D854
	cmp r0, 0x1
	bge _0806D85C
	cmp r0, 0
	beq _0806D858
	b _0806D85E
	.pool
_0806D854:
	cmp r0, 0x3
	bne _0806D85E
_0806D858:
	movs r3, 0
	b _0806D85E
_0806D85C:
	movs r3, 0x1
_0806D85E:
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end sub_806D82C

	thumb_func_start sub_806D864
sub_806D864: @ 806D864
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r1, =gLinkPlayers
	b _0806D87C
	.pool
_0806D874:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0806D882
_0806D87C:
	ldrh r0, [r1, 0x18]
	cmp r0, r3
	bne _0806D874
_0806D882:
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_806D864

	thumb_func_start GetTrainerEncounterMusicId
@ u8 GetTrainerEncounterMusicId(u16 trainerOpponentId)
GetTrainerEncounterMusicId: @ 806D888
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _0806D8A2
	adds r0, r4, 0
	bl sub_81A9F3C
	b _0806D8CA
_0806D8A2:
	bl sub_81D5C18
	lsls r0, 24
	cmp r0, 0
	bne _0806D8C4
	ldr r1, =gTrainers
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x2]
	movs r0, 0x7F
	ands r0, r1
	b _0806D8CE
	.pool
_0806D8C4:
	adds r0, r5, 0
	bl sub_81D63C8
_0806D8CA:
	lsls r0, 24
	lsrs r0, 24
_0806D8CE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetTrainerEncounterMusicId

	thumb_func_start nature_stat_mod
nature_stat_mod: @ 806D8D4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r3, r1, 16
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0xFF
	lsls r0, 24
	adds r2, r0
	lsrs r2, 24
	cmp r2, 0x4
	bls _0806D8F2
	adds r0, r3, 0
	b _0806D92E
_0806D8F2:
	ldr r0, =gNatureStatTable
	lsls r1, r4, 2
	adds r1, r4
	subs r1, 0x1
	adds r1, r5, r1
	adds r1, r0
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0806D918
	cmp r1, 0x1
	bne _0806D92C
	movs r0, 0x6E
	b _0806D91A
	.pool
_0806D918:
	movs r0, 0x5A
_0806D91A:
	muls r0, r3
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __udivsi3
	lsls r0, 16
	lsrs r0, 16
	b _0806D92E
_0806D92C:
	adds r0, r3, 0
_0806D92E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end nature_stat_mod

	thumb_func_start AdjustFriendship
AdjustFriendship: @ 806D934
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl sub_806F104
	lsls r0, 24
	cmp r0, 0
	beq _0806D94A
	b _0806DAC2
_0806D94A:
	adds r0, r7, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r7, 0
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _0806D9A0
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806D98C
	ldr r0, =gEnigmaBerries
	ldrb r4, [r0, 0x7]
	b _0806D9A8
	.pool
_0806D98C:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003226
	adds r0, r1
	ldrb r4, [r0]
	b _0806D9A8
	.pool
_0806D9A0:
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r4, r0, 24
_0806D9A8:
	cmp r6, 0
	bne _0806D9AE
	b _0806DAC2
_0806D9AE:
	movs r0, 0xCE
	lsls r0, 1
	cmp r6, r0
	bne _0806D9B8
	b _0806DAC2
_0806D9B8:
	movs r6, 0
	adds r0, r7, 0
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x63
	ble _0806D9D6
	movs r6, 0x1
_0806D9D6:
	cmp r0, 0xC7
	ble _0806D9E0
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0806D9E0:
	cmp r5, 0x5
	bne _0806D9F0
	bl Random
	movs r1, 0x1
	ands r1, r0
	cmp r1, 0
	bne _0806DAC2
_0806D9F0:
	cmp r5, 0x3
	bne _0806DA20
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0806DAC2
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r1, [r0, 0x1]
	adds r0, r1, 0
	subs r0, 0x1F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _0806DA20
	cmp r1, 0x26
	bne _0806DAC2
_0806DA20:
	ldr r1, =gUnknown_08329ECE
	lsls r0, r5, 1
	adds r0, r5
	adds r0, r6, r0
	adds r0, r1
	ldrb r2, [r0]
	movs r1, 0
	ldrsb r1, [r0, r1]
	cmp r1, 0
	ble _0806DA46
	cmp r4, 0x1B
	bne _0806DA46
	movs r0, 0x96
	muls r0, r1
	movs r1, 0x64
	bl __divsi3
	lsls r0, 24
	lsrs r2, r0, 24
_0806DA46:
	lsls r2, 24
	asrs r2, 24
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r0, r2
	mov r1, sp
	strh r0, [r1]
	cmp r2, 0
	ble _0806DA98
	adds r0, r7, 0
	movs r1, 0x26
	movs r2, 0
	bl GetMonData
	cmp r0, 0xB
	bne _0806DA74
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r0, 0x1
	mov r1, sp
	strh r0, [r1]
_0806DA74:
	adds r0, r7, 0
	movs r1, 0x23
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	bl sav1_map_get_name
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _0806DA98
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	adds r0, 0x1
	mov r1, sp
	strh r0, [r1]
_0806DA98:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _0806DAA8
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
_0806DAA8:
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0xFF
	ble _0806DAB8
	movs r1, 0xFF
	mov r0, sp
	strh r1, [r0]
_0806DAB8:
	adds r0, r7, 0
	movs r1, 0x20
	mov r2, sp
	bl SetMonData
_0806DAC2:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AdjustFriendship

	thumb_func_start MonGainEVs
MonGainEVs: @ 806DADC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	mov r8, r0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r4, 0
	movs r7, 0
	movs r6, 0
_0806DAF0:
	adds r1, r6, 0
	adds r1, 0x1A
	mov r0, r8
	movs r2, 0
	bl GetMonData
	mov r2, sp
	adds r1, r2, r6
	strb r0, [r1]
	ldrb r0, [r1]
	adds r0, r7, r0
	lsls r0, 16
	lsrs r7, r0, 16
	adds r6, 0x1
	cmp r6, 0x5
	ble _0806DAF0
	movs r6, 0
	b _0806DC72
_0806DB14:
	mov r0, r8
	movs r1, 0
	bl CheckPartyHasHadPokerus
	lsls r0, 24
	movs r2, 0x1
	cmp r0, 0
	beq _0806DB26
	movs r2, 0x2
_0806DB26:
	cmp r6, 0x5
	bhi _0806DBC8
	lsls r0, r6, 2
	ldr r1, =_0806DB38
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806DB38:
	.4byte _0806DB50
	.4byte _0806DB64
	.4byte _0806DB78
	.4byte _0806DB8C
	.4byte _0806DBA0
	.4byte _0806DBB4
_0806DB50:
	ldr r0, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	lsls r0, 30
	b _0806DBC2
	.pool
_0806DB64:
	ldr r0, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	b _0806DBC0
	.pool
_0806DB78:
	ldr r0, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	lsls r0, 26
	b _0806DBC2
	.pool
_0806DB8C:
	ldr r0, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xA]
	lsrs r0, 6
	b _0806DBC4
	.pool
_0806DBA0:
	ldr r0, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xB]
	lsls r0, 30
	b _0806DBC2
	.pool
_0806DBB4:
	ldr r0, =gBaseStats
	lsls r1, r5, 3
	subs r1, r5
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0xB]
_0806DBC0:
	lsls r0, 28
_0806DBC2:
	lsrs r0, 30
_0806DBC4:
	adds r4, r0, 0
	muls r4, r2
_0806DBC8:
	mov r0, r8
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _0806DC14
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806DC00
	ldr r0, =gEnigmaBerries
	ldrb r0, [r0, 0x7]
	b _0806DC1C
	.pool
_0806DC00:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x00003226
	adds r0, r2
	ldrb r0, [r0]
	b _0806DC1C
	.pool
_0806DC14:
	bl ItemId_GetHoldEffect
	lsls r0, 24
	lsrs r0, 24
_0806DC1C:
	cmp r0, 0x18
	bne _0806DC24
	lsls r0, r4, 17
	lsrs r4, r0, 16
_0806DC24:
	lsls r0, r4, 16
	asrs r2, r0, 16
	adds r1, r7, r2
	movs r0, 0xFF
	lsls r0, 1
	cmp r1, r0
	ble _0806DC3C
	adds r0, r2, r0
	adds r1, r7, r4
	subs r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
_0806DC3C:
	mov r0, sp
	adds r2, r0, r6
	ldrb r3, [r2]
	lsls r0, r4, 16
	asrs r1, r0, 16
	adds r0, r3, r1
	cmp r0, 0xFF
	ble _0806DC58
	adds r0, r1, 0
	adds r0, 0xFF
	adds r1, r3, r4
	subs r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
_0806DC58:
	adds r0, r3, r4
	strb r0, [r2]
	adds r0, r7, r4
	lsls r0, 16
	lsrs r7, r0, 16
	adds r1, r6, 0
	adds r1, 0x1A
	mov r0, r8
	bl SetMonData
	adds r6, 0x1
	cmp r6, 0x5
	bgt _0806DC7A
_0806DC72:
	ldr r0, =0x000001fd
	cmp r7, r0
	bhi _0806DC7A
	b _0806DB14
_0806DC7A:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MonGainEVs

	thumb_func_start GetMonEVCount
GetMonEVCount: @ 806DC8C
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	movs r4, 0
_0806DC94:
	adds r1, r4, 0
	adds r1, 0x1A
	adds r0, r6, 0
	movs r2, 0
	bl GetMonData
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	adds r4, 0x1
	cmp r4, 0x5
	ble _0806DC94
	adds r0, r5, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetMonEVCount

	thumb_func_start RandomlyGivePartyPokerus
RandomlyGivePartyPokerus: @ 806DCB4
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	bl Random
	lsls r0, 16
	lsrs r5, r0, 16
	movs r0, 0x80
	lsls r0, 7
	cmp r5, r0
	beq _0806DCDA
	movs r0, 0x80
	lsls r0, 8
	cmp r5, r0
	beq _0806DCDA
	movs r0, 0xC0
	lsls r0, 8
	cmp r5, r0
	bne _0806DD70
_0806DCDA:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	movs r0, 0x64
	muls r0, r5
	adds r4, r6, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806DCDA
	adds r0, r4, 0
	movs r1, 0x2D
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806DCDA
	ldr r1, =gBitTable
	lsls r0, r5, 2
	adds r0, r1
	ldrb r1, [r0]
	adds r0, r6, 0
	bl CheckPartyHasHadPokerus
	lsls r0, 24
	cmp r0, 0
	bne _0806DD70
	movs r4, 0x7
_0806DD24:
	bl Random
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	adds r2, r0, 0
	adds r1, r2, 0
	ands r1, r4
	cmp r1, 0
	beq _0806DD24
	movs r0, 0xF0
	ands r0, r2
	cmp r0, 0
	beq _0806DD46
	mov r0, sp
	strb r1, [r0]
_0806DD46:
	mov r0, sp
	ldrb r0, [r0]
	lsls r1, r0, 4
	orrs r0, r1
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	movs r1, 0xF3
	ands r1, r0
	mov r0, sp
	strb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	movs r0, 0x64
	muls r0, r5
	adds r0, r6, r0
	movs r1, 0x22
	mov r2, sp
	bl SetMonData
_0806DD70:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RandomlyGivePartyPokerus

	thumb_func_start CheckPartyPokerus
CheckPartyPokerus: @ 806DD7C
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	movs r3, 0
	movs r6, 0x1
	movs r5, 0
	cmp r4, 0
	beq _0806DDC4
_0806DD90:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0806DDB8
	movs r0, 0x64
	muls r0, r3
	adds r0, r7, r0
	movs r1, 0x22
	movs r2, 0
	str r3, [sp]
	bl GetMonData
	movs r1, 0xF
	ands r1, r0
	ldr r3, [sp]
	cmp r1, 0
	beq _0806DDB8
	orrs r5, r6
	lsls r0, r5, 24
	lsrs r5, r0, 24
_0806DDB8:
	adds r3, 0x1
	lsls r6, 1
	lsrs r4, 1
	cmp r4, 0
	bne _0806DD90
	b _0806DDD8
_0806DDC4:
	adds r0, r7, 0
	movs r1, 0x22
	movs r2, 0
	bl GetMonData
	movs r1, 0xF
	ands r1, r0
	cmp r1, 0
	beq _0806DDD8
	movs r5, 0x1
_0806DDD8:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckPartyPokerus

	thumb_func_start CheckPartyHasHadPokerus
CheckPartyHasHadPokerus: @ 806DDE4
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	movs r3, 0
	movs r6, 0x1
	movs r5, 0
	cmp r4, 0
	beq _0806DE28
_0806DDF8:
	movs r0, 0x1
	ands r0, r4
	cmp r0, 0
	beq _0806DE1C
	movs r0, 0x64
	muls r0, r3
	adds r0, r7, r0
	movs r1, 0x22
	movs r2, 0
	str r3, [sp]
	bl GetMonData
	ldr r3, [sp]
	cmp r0, 0
	beq _0806DE1C
	orrs r5, r6
	lsls r0, r5, 24
	lsrs r5, r0, 24
_0806DE1C:
	adds r3, 0x1
	lsls r6, 1
	lsrs r4, 1
	cmp r4, 0
	bne _0806DDF8
	b _0806DE38
_0806DE28:
	adds r0, r7, 0
	movs r1, 0x22
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806DE38
	movs r5, 0x1
_0806DE38:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end CheckPartyHasHadPokerus

	thumb_func_start UpdatePartyPokerusTime
UpdatePartyPokerusTime: @ 806DE44
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r7, r0, 16
	movs r6, 0
	mov r5, sp
_0806DE50:
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806DEB2
	adds r0, r4, 0
	movs r1, 0x22
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	strb r0, [r5]
	movs r1, 0xF
	adds r2, r0, 0
	ands r1, r2
	cmp r1, 0
	beq _0806DEB2
	cmp r1, r7
	bcc _0806DE8A
	cmp r7, 0x4
	bls _0806DE94
_0806DE8A:
	movs r0, 0xF0
	ands r0, r2
	b _0806DE96
	.pool
_0806DE94:
	subs r0, r2, r7
_0806DE96:
	strb r0, [r5]
	ldrb r0, [r5]
	cmp r0, 0
	bne _0806DEA2
	movs r0, 0x10
	strb r0, [r5]
_0806DEA2:
	movs r0, 0x64
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x22
	mov r2, sp
	bl SetMonData
_0806DEB2:
	adds r6, 0x1
	cmp r6, 0x5
	ble _0806DE50
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdatePartyPokerusTime

	thumb_func_start PartySpreadPokerus
PartySpreadPokerus: @ 806DEC4
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _0806DF6A
	movs r5, 0
_0806DEE0:
	movs r0, 0x64
	adds r6, r5, 0
	muls r6, r0
	adds r4, r7, r6
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806DF64
	adds r0, r4, 0
	movs r1, 0x22
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r1, r0, 24
	mov r0, sp
	strb r1, [r0]
	cmp r1, 0
	beq _0806DF64
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0
	beq _0806DF64
	cmp r5, 0
	beq _0806DF3A
	adds r0, r6, 0
	subs r0, 0x64
	adds r4, r7, r0
	adds r0, r4, 0
	movs r1, 0x22
	movs r2, 0
	bl GetMonData
	movs r1, 0xF0
	ands r1, r0
	cmp r1, 0
	bne _0806DF3A
	adds r0, r4, 0
	movs r1, 0x22
	mov r2, sp
	bl SetMonData
_0806DF3A:
	cmp r5, 0x5
	beq _0806DF64
	movs r0, 0x64
	muls r0, r5
	adds r0, 0x64
	adds r4, r7, r0
	adds r0, r4, 0
	movs r1, 0x22
	movs r2, 0
	bl GetMonData
	movs r1, 0xF0
	ands r1, r0
	cmp r1, 0
	bne _0806DF64
	adds r0, r4, 0
	movs r1, 0x22
	mov r2, sp
	bl SetMonData
	adds r5, 0x1
_0806DF64:
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806DEE0
_0806DF6A:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PartySpreadPokerus

	thumb_func_start TryIncrementMonLevel
TryIncrementMonLevel: @ 806DF74
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	adds r0, 0x1
	mov r1, sp
	strb r0, [r1]
	adds r0, r5, 0
	movs r1, 0x19
	movs r2, 0
	bl GetMonData
	str r0, [sp, 0x4]
	ldr r6, =gExperienceTables
	ldr r2, =gBaseStats
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x13]
	movs r1, 0xCA
	lsls r1, 1
	adds r4, r2, 0
	muls r4, r1
	movs r2, 0xC8
	lsls r2, 1
	adds r1, r6, r2
	adds r1, r4, r1
	ldr r1, [r1]
	cmp r0, r1
	bls _0806DFD4
	str r1, [sp, 0x4]
	add r2, sp, 0x4
	adds r0, r5, 0
	movs r1, 0x19
	bl SetMonData
_0806DFD4:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, 0x64
	bhi _0806DFEA
	lsls r0, 2
	adds r0, r4
	adds r0, r6
	ldr r1, [sp, 0x4]
	ldr r0, [r0]
	cmp r1, r0
	bcs _0806DFF8
_0806DFEA:
	movs r0, 0
	b _0806E004
	.pool
_0806DFF8:
	adds r0, r5, 0
	movs r1, 0x38
	mov r2, sp
	bl SetMonData
	movs r0, 0x1
_0806E004:
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end TryIncrementMonLevel

	thumb_func_start CanMonLearnTMHM
CanMonLearnTMHM: @ 806E00C
	push {r4,r5,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	adds r5, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	adds r3, r1, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bne _0806E02E
	movs r0, 0
	b _0806E05A
_0806E02E:
	cmp r4, 0x1F
	bls _0806E04C
	adds r0, r4, 0
	subs r0, 0x20
	movs r2, 0x1
	lsls r2, r0
	ldr r0, =gTMHMLearnsets
	lsls r1, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	ands r0, r2
	b _0806E05A
	.pool
_0806E04C:
	movs r1, 0x1
	lsls r1, r5
	ldr r2, =gTMHMLearnsets
	lsls r0, r3, 3
	adds r0, r2
	ldr r0, [r0]
	ands r0, r1
_0806E05A:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CanMonLearnTMHM

	thumb_func_start CanSpeciesLearnTMHM
CanSpeciesLearnTMHM: @ 806E064
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	adds r4, r3, 0
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r3, r0
	bne _0806E07E
	movs r0, 0
	b _0806E0AA
_0806E07E:
	cmp r1, 0x1F
	bls _0806E09C
	adds r0, r1, 0
	subs r0, 0x20
	movs r2, 0x1
	lsls r2, r0
	ldr r0, =gTMHMLearnsets
	lsls r1, r3, 3
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	ands r0, r2
	b _0806E0AA
	.pool
_0806E09C:
	movs r1, 0x1
	lsls r1, r2
	ldr r2, =gTMHMLearnsets
	lsls r0, r4, 3
	adds r0, r2
	ldr r0, [r0]
	ands r0, r1
_0806E0AA:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CanSpeciesLearnTMHM

	thumb_func_start GetMoveRelearnerMoves
GetMoveRelearnerMoves: @ 806E0B4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	adds r6, r0, 0
	str r1, [sp, 0x8]
	movs r0, 0
	mov r10, r0
	adds r0, r6, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	adds r0, r6, 0
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0xC]
	movs r5, 0
	mov r4, sp
_0806E0EA:
	adds r1, r5, 0
	adds r1, 0xD
	adds r0, r6, 0
	movs r2, 0
	bl GetMonData
	strh r0, [r4]
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806E0EA
	movs r5, 0
	ldr r6, =gLevelUpLearnsets
	lsls r1, r7, 2
	adds r2, r1, r6
	ldr r3, [r2]
	ldrh r0, [r3]
	ldr r4, =0x0000ffff
	str r1, [sp, 0x14]
	cmp r0, r4
	beq _0806E1E4
	mov r9, r2
	str r3, [sp, 0x10]
_0806E118:
	lsls r2, r5, 1
	ldr r1, [sp, 0x10]
	adds r0, r2, r1
	ldrh r3, [r0]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r3
	ldr r4, [sp, 0xC]
	lsls r1, r4, 9
	adds r7, r2, 0
	adds r5, 0x1
	mov r12, r5
	cmp r0, r1
	bgt _0806E1CE
	movs r4, 0
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, =0x000001ff
	ands r0, r3
	cmp r1, r0
	beq _0806E168
	ldr r0, [sp, 0x14]
	ldr r1, =gLevelUpLearnsets
	adds r6, r0, r1
	ldr r2, =0x000001ff
	mov r8, r2
	mov r3, sp
	adds r5, r7, 0
_0806E150:
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0806E168
	ldr r0, [r6]
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r3]
	mov r0, r8
	ands r0, r1
	cmp r2, r0
	bne _0806E150
_0806E168:
	cmp r4, 0x4
	bne _0806E1CE
	movs r4, 0
	cmp r4, r10
	bge _0806E1AC
	mov r1, r9
	ldr r0, [r1]
	adds r0, r7, r0
	ldrh r1, [r0]
	ldr r0, [sp, 0x8]
	ldrh r2, [r0]
	ldr r0, =0x000001ff
	ands r0, r1
	cmp r2, r0
	beq _0806E1AC
	ldr r1, [sp, 0x14]
	ldr r2, =gLevelUpLearnsets
	adds r6, r1, r2
	ldr r0, =0x000001ff
	mov r8, r0
	ldr r3, [sp, 0x8]
	adds r5, r7, 0
_0806E194:
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, r10
	bge _0806E1AC
	ldr r0, [r6]
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r3]
	mov r0, r8
	ands r0, r1
	cmp r2, r0
	bne _0806E194
_0806E1AC:
	cmp r4, r10
	bne _0806E1CE
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r2, r4, 1
	ldr r1, [sp, 0x8]
	adds r2, r1
	mov r4, r9
	ldr r0, [r4]
	adds r0, r7, r0
	ldrh r1, [r0]
	ldr r0, =0x000001ff
	ands r0, r1
	strh r0, [r2]
_0806E1CE:
	mov r5, r12
	cmp r5, 0x13
	bgt _0806E1E4
	mov r1, r9
	ldr r0, [r1]
	lsls r1, r5, 1
	adds r1, r0
	ldrh r0, [r1]
	ldr r2, =0x0000ffff
	cmp r0, r2
	bne _0806E118
_0806E1E4:
	mov r0, r10
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetMoveRelearnerMoves

	thumb_func_start GetLevelUpMovesBySpecies
GetLevelUpMovesBySpecies: @ 806E204
	push {r4-r7,lr}
	adds r6, r1, 0
	lsls r0, 16
	movs r5, 0
	movs r4, 0
	ldr r1, =gLevelUpLearnsets
	lsrs r0, 14
	adds r0, r1
	ldr r2, [r0]
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0806E248
	ldr r0, =0x000001ff
	mov r12, r0
	adds r7, r1, 0
	adds r3, r2, 0
_0806E226:
	adds r1, r5, 0
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 1
	adds r1, r6
	ldrh r2, [r3]
	mov r0, r12
	ands r0, r2
	strh r0, [r1]
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x13
	bgt _0806E248
	ldrh r0, [r3]
	cmp r0, r7
	bne _0806E226
_0806E248:
	adds r0, r5, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetLevelUpMovesBySpecies

	thumb_func_start GetNumberOfRelearnableMoves
GetNumberOfRelearnableMoves: @ 806E25C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	adds r6, r0, 0
	movs r0, 0
	mov r10, r0
	adds r0, r6, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r6, 0
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x30]
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bne _0806E298
	movs r0, 0
	b _0806E3A2
_0806E298:
	movs r5, 0
	lsls r4, 2
	str r4, [sp, 0x38]
	mov r4, sp
_0806E2A0:
	adds r1, r5, 0
	adds r1, 0xD
	adds r0, r6, 0
	movs r2, 0
	bl GetMonData
	strh r0, [r4]
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806E2A0
	movs r5, 0
	ldr r3, =gLevelUpLearnsets
	ldr r2, [sp, 0x38]
	adds r1, r2, r3
	ldr r0, [r1]
	ldrh r0, [r0]
	ldr r2, =0x0000ffff
	cmp r0, r2
	beq _0806E3A0
	mov r9, r1
	mov r4, sp
	adds r4, 0x8
	str r4, [sp, 0x34]
_0806E2D0:
	mov r1, r9
	ldr r0, [r1]
	lsls r2, r5, 1
	adds r0, r2, r0
	ldrh r3, [r0]
	movs r0, 0xFE
	lsls r0, 8
	ands r0, r3
	ldr r4, [sp, 0x30]
	lsls r1, r4, 9
	adds r7, r2, 0
	adds r5, 0x1
	mov r12, r5
	cmp r0, r1
	bgt _0806E38A
	movs r4, 0
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, =0x000001ff
	ands r0, r3
	cmp r1, r0
	beq _0806E322
	ldr r0, [sp, 0x38]
	ldr r1, =gLevelUpLearnsets
	adds r6, r0, r1
	ldr r2, =0x000001ff
	mov r8, r2
	mov r3, sp
	adds r5, r7, 0
_0806E30A:
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x3
	bgt _0806E322
	ldr r0, [r6]
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r3]
	mov r0, r8
	ands r0, r1
	cmp r2, r0
	bne _0806E30A
_0806E322:
	cmp r4, 0x4
	bne _0806E38A
	movs r4, 0
	cmp r4, r10
	bge _0806E368
	mov r1, r9
	ldr r0, [r1]
	adds r0, r7, r0
	ldrh r1, [r0]
	ldr r0, [sp, 0x34]
	ldrh r2, [r0]
	ldr r0, =0x000001ff
	ands r0, r1
	add r1, sp, 0x8
	cmp r2, r0
	beq _0806E368
	ldr r2, [sp, 0x38]
	ldr r0, =gLevelUpLearnsets
	adds r6, r2, r0
	ldr r2, =0x000001ff
	mov r8, r2
	adds r3, r1, 0
	adds r5, r7, 0
_0806E350:
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, r10
	bge _0806E368
	ldr r0, [r6]
	adds r0, r5, r0
	ldrh r1, [r0]
	ldrh r2, [r3]
	mov r0, r8
	ands r0, r1
	cmp r2, r0
	bne _0806E350
_0806E368:
	cmp r4, r10
	bne _0806E38A
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	lsls r2, r4, 1
	ldr r4, [sp, 0x34]
	adds r2, r4, r2
	mov r1, r9
	ldr r0, [r1]
	adds r0, r7, r0
	ldrh r1, [r0]
	ldr r0, =0x000001ff
	ands r0, r1
	strh r0, [r2]
_0806E38A:
	mov r5, r12
	cmp r5, 0x13
	bgt _0806E3A0
	mov r2, r9
	ldr r0, [r2]
	lsls r1, r5, 1
	adds r1, r0
	ldrh r0, [r1]
	ldr r4, =0x0000ffff
	cmp r0, r4
	bne _0806E2D0
_0806E3A0:
	mov r0, r10
_0806E3A2:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetNumberOfRelearnableMoves

	thumb_func_start SpeciesToPokedexNum
SpeciesToPokedexNum: @ 806E3C0
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _0806E3DA
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	b _0806E3F2
_0806E3DA:
	adds r0, r4, 0
	bl SpeciesToHoennPokedexNum
	adds r4, r0, 0
	cmp r4, 0xCA
	bls _0806E3F0
	ldr r0, =0x0000ffff
	b _0806E3F2
	.pool
_0806E3F0:
	adds r0, r4, 0
_0806E3F2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end SpeciesToPokedexNum

	thumb_func_start sub_806E3F8
sub_806E3F8: @ 806E3F8
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl SpeciesToHoennPokedexNum
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xCA
	bhi _0806E40E
	movs r0, 0x1
	b _0806E410
_0806E40E:
	movs r0, 0
_0806E410:
	pop {r1}
	bx r1
	thumb_func_end sub_806E3F8

	thumb_func_start sub_806E414
sub_806E414: @ 806E414
	push {lr}
	ldr r1, =gUnknown_020244E4
	movs r2, 0
	adds r0, r1, 0x3
_0806E41C:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _0806E41C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806E414

	thumb_func_start song_id_for_battle
song_id_for_battle: @ 806E42C
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r1, [r0]
	movs r0, 0x80
	lsls r0, 5
	ands r0, r1
	cmp r0, 0
	beq _0806E448
	movs r0, 0xF0
	lsls r0, 1
	b _0806E646
	.pool
_0806E448:
	movs r0, 0x80
	lsls r0, 7
	ands r0, r1
	cmp r0, 0
	beq _0806E45C
	ldr r0, =0x000001df
	b _0806E646
	.pool
_0806E45C:
	ldr r0, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _0806E466
	b _0806E63C
_0806E466:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	bne _0806E470
	b _0806E642
_0806E470:
	ldr r0, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0806E494
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r0, [r0]
	bl sub_8162BD8
	lsls r0, 24
	lsrs r0, 24
	b _0806E4B2
	.pool
_0806E494:
	movs r0, 0x80
	lsls r0, 19
	ands r1, r0
	cmp r1, 0
	beq _0806E4A2
	movs r0, 0xA
	b _0806E4B2
_0806E4A2:
	ldr r2, =gTrainers
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x1]
_0806E4B2:
	subs r0, 0x3
	cmp r0, 0x3D
	bls _0806E4BA
	b _0806E63C
_0806E4BA:
	lsls r0, 2
	ldr r1, =_0806E4D0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806E4D0:
	.4byte _0806E5D0
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E5D0
	.4byte _0806E63C
	.4byte _0806E5D0
	.4byte _0806E63C
	.4byte _0806E5C8
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E62C
	.4byte _0806E5D8
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E5E0
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E5D0
	.4byte _0806E5E6
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E5C8
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E63C
	.4byte _0806E632
	.4byte _0806E632
	.4byte _0806E632
	.4byte _0806E632
	.4byte _0806E632
	.4byte _0806E632
	.4byte _0806E632
_0806E5C8:
	ldr r0, =0x000001e3
	b _0806E646
	.pool
_0806E5D0:
	ldr r0, =0x000001db
	b _0806E646
	.pool
_0806E5D8:
	ldr r0, =0x000001dd
	b _0806E646
	.pool
_0806E5E0:
	movs r0, 0xEF
	lsls r0, 1
	b _0806E646
_0806E5E6:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x003f0100
	ands r0, r1
	cmp r0, 0
	beq _0806E604
_0806E5F2:
	ldr r0, =0x000001e1
	b _0806E646
	.pool
_0806E604:
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r1, [r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTrainers + 0x4 @ name offset
	adds r0, r1
	ldr r1, =gUnknown_085CCB98
	bl StringCompare
	cmp r0, 0
	beq _0806E63C
	b _0806E5F2
	.pool
_0806E62C:
	movs r0, 0xF1
	lsls r0, 1
	b _0806E646
_0806E632:
	ldr r0, =0x000001d7
	b _0806E646
	.pool
_0806E63C:
	movs r0, 0xEE
	lsls r0, 1
	b _0806E646
_0806E642:
	movs r0, 0xED
	lsls r0, 1
_0806E646:
	pop {r1}
	bx r1
	thumb_func_end song_id_for_battle

	thumb_func_start sub_806E64C
sub_806E64C: @ 806E64C
	push {lr}
	bl ResetMapMusic
	bl m4aMPlayAllStop
	bl song_id_for_battle
	lsls r0, 16
	lsrs r0, 16
	bl PlayBGM
	pop {r0}
	bx r0
	thumb_func_end sub_806E64C

	thumb_func_start PlayNewMapMusic__default_for_battle
PlayNewMapMusic__default_for_battle: @ 806E668
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl ResetMapMusic
	bl m4aMPlayAllStop
	cmp r4, 0
	beq _0806E682
	adds r0, r4, 0
	bl PlayNewMapMusic
	b _0806E68E
_0806E682:
	bl song_id_for_battle
	lsls r0, 16
	lsrs r0, 16
	bl PlayNewMapMusic
_0806E68E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PlayNewMapMusic__default_for_battle

	thumb_func_start sub_806E694
sub_806E694: @ 806E694
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl ResetMapMusic
	bl m4aMPlayAllStop
	ldr r0, =sub_806E6CC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806E694

	thumb_func_start sub_806E6CC
sub_806E6CC: @ 806E6CC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r1, r0, r1
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0806E6F0
	ldrh r0, [r1, 0x8]
	bl PlayNewMapMusic
	b _0806E6FC
	.pool
_0806E6F0:
	bl song_id_for_battle
	lsls r0, 16
	lsrs r0, 16
	bl PlayNewMapMusic
_0806E6FC:
	adds r0, r4, 0
	bl DestroyTask
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806E6CC

	thumb_func_start pokemon_get_pal
pokemon_get_pal: @ 806E708
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0
	bl GetMonData
	adds r6, r0, 0
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	adds r2, r0, 0
	adds r0, r4, 0
	adds r1, r6, 0
	bl species_and_otid_get_pal
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end pokemon_get_pal

	thumb_func_start species_and_otid_get_pal
species_and_otid_get_pal: @ 806E740
	push {r4,r5,lr}
	adds r3, r2, 0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bls _0806E75C
	ldr r0, =gMonPaletteTable
	ldr r0, [r0]
	b _0806E788
	.pool
_0806E75C:
	lsrs r0, r1, 16
	ldr r2, =0x0000ffff
	ands r1, r2
	eors r0, r1
	lsrs r1, r3, 16
	eors r0, r1
	ands r3, r2
	eors r0, r3
	cmp r0, 0x7
	bls _0806E780
	ldr r0, =gMonPaletteTable
	lsls r1, r4, 3
	b _0806E784
	.pool
_0806E780:
	ldr r0, =gMonShinyPaletteTable
	lsls r1, r5, 3
_0806E784:
	adds r1, r0
	ldr r0, [r1]
_0806E788:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end species_and_otid_get_pal

	thumb_func_start sub_806E794
sub_806E794: @ 806E794
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x1
	movs r2, 0
	bl GetMonData
	adds r6, r0, 0
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	adds r2, r0, 0
	adds r0, r4, 0
	adds r1, r6, 0
	bl sub_806E7CC
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_806E794

	thumb_func_start sub_806E7CC
sub_806E7CC: @ 806E7CC
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsrs r0, r1, 16
	ldr r3, =0x0000ffff
	ands r1, r3
	eors r0, r1
	lsrs r1, r2, 16
	eors r0, r1
	ands r2, r3
	eors r0, r2
	cmp r0, 0x7
	bls _0806E7F4
	lsls r0, r4, 3
	ldr r1, =gMonPaletteTable
	b _0806E7F8
	.pool
_0806E7F4:
	lsls r0, r4, 3
	ldr r1, =gMonShinyPaletteTable
_0806E7F8:
	adds r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806E7CC

	thumb_func_start IsHMMove2
IsHMMove2: @ 806E804
	push {r4,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r2, =gHMMoves
	ldrh r0, [r2]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0806E836
	adds r4, r1, 0
	adds r1, r2, 0
_0806E818:
	ldrh r0, [r2]
	adds r1, 0x2
	adds r2, 0x2
	cmp r0, r3
	bne _0806E830
	movs r0, 0x1
	b _0806E838
	.pool
_0806E830:
	ldrh r0, [r1]
	cmp r0, r4
	bne _0806E818
_0806E836:
	movs r0, 0
_0806E838:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end IsHMMove2

	thumb_func_start sub_806E840
sub_806E840: @ 806E840
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gBaseStats
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x19]
	lsrs r0, 7
	bx lr
	.pool
	thumb_func_end sub_806E840

	thumb_func_start GetMonFlavourRelation
GetMonFlavourRelation: @ 806E858
	push {r4,lr}
	lsls r4, r1, 24
	lsrs r4, 24
	bl GetNature
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gPokeblockFlavorCompatibilityTable
	lsls r1, r0, 2
	adds r1, r0
	adds r1, r4
	adds r1, r2
	movs r0, 0
	ldrsb r0, [r1, r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetMonFlavourRelation

	thumb_func_start GetFlavourRelationByPersonality
GetFlavourRelationByPersonality: @ 806E880
	push {r4,lr}
	lsls r4, r1, 24
	lsrs r4, 24
	bl GetNatureFromPersonality
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gPokeblockFlavorCompatibilityTable
	lsls r1, r0, 2
	adds r1, r0
	adds r1, r4
	adds r1, r2
	movs r0, 0
	ldrsb r0, [r1, r0]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetFlavourRelationByPersonality

	thumb_func_start IsTradedMon
IsTradedMon: @ 806E8A8
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r1, 0x7
	mov r2, sp
	bl GetMonData
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl GetMonData
	mov r1, sp
	bl IsOtherTrainer
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end IsTradedMon

	thumb_func_start IsOtherTrainer
IsOtherTrainer: @ 806E8D4
	push {r4,r5,lr}
	adds r5, r1, 0
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	ldrb r2, [r3, 0xA]
	ldrb r1, [r3, 0xB]
	lsls r1, 8
	orrs r2, r1
	ldrb r1, [r3, 0xC]
	lsls r1, 16
	orrs r2, r1
	ldrb r1, [r3, 0xD]
	lsls r1, 24
	orrs r2, r1
	cmp r0, r2
	bne _0806E91C
	movs r4, 0
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _0806E912
	adds r2, r5, 0
_0806E8FE:
	adds r1, r3, r4
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0806E91C
	adds r2, 0x1
	adds r4, 0x1
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _0806E8FE
_0806E912:
	movs r0, 0
	b _0806E91E
	.pool
_0806E91C:
	movs r0, 0x1
_0806E91E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end IsOtherTrainer

	thumb_func_start MonRestorePP
MonRestorePP: @ 806E924
	push {lr}
	bl BoxMonRestorePP
	pop {r0}
	bx r0
	thumb_func_end MonRestorePP

	thumb_func_start BoxMonRestorePP
BoxMonRestorePP: @ 806E930
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0
_0806E938:
	adds r4, r6, 0
	adds r4, 0xD
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl GetBoxMonData
	cmp r0, 0
	beq _0806E984
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl GetBoxMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x15
	movs r2, 0
	bl GetBoxMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r2, r6, 24
	lsrs r2, 24
	adds r0, r4, 0
	bl CalculatePPWithBonus
	mov r1, sp
	strb r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r5, 0
	mov r2, sp
	bl SetBoxMonData
_0806E984:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0806E938
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end BoxMonRestorePP

	thumb_func_start sub_806E994
sub_806E994: @ 806E994
	push {r4,r5,lr}
	ldr r2, =gLastUsedAbility
	ldr r5, =gBattleStruct
	ldr r1, [r5]
	adds r0, r1, 0
	adds r0, 0xB0
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r4, =gBattleTextBuff1
	movs r0, 0xFD
	strb r0, [r4]
	movs r0, 0x4
	strb r0, [r4, 0x1]
	adds r1, 0x49
	ldrb r0, [r1]
	strb r0, [r4, 0x2]
	movs r0, 0xFF
	strb r0, [r4, 0x4]
	ldrb r0, [r1]
	bl GetBankSide
	lsls r0, 24
	cmp r0, 0
	bne _0806E9E8
	ldr r1, =gBattlePartyID
	ldr r0, [r5]
	adds r0, 0x49
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	b _0806E9F6
	.pool
_0806E9E8:
	ldr r1, =gBattlePartyID
	ldr r0, [r5]
	adds r0, 0x49
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
_0806E9F6:
	strb r0, [r4, 0x3]
	ldr r4, =gBattleTextBuff2
	movs r0, 0xFD
	strb r0, [r4]
	movs r0, 0x4
	strb r0, [r4, 0x1]
	ldr r1, =gUnknown_020244B8
	ldrb r0, [r1]
	strb r0, [r4, 0x2]
	ldr r2, =gBattlePartyID
	ldrb r0, [r1]
	lsls r0, 1
	adds r0, r2
	ldrb r0, [r0]
	bl pokemon_order_func
	strb r0, [r4, 0x3]
	movs r0, 0xFF
	strb r0, [r4, 0x4]
	ldr r0, =gUnknown_085CB2A1
	ldr r1, =gStringVar4
	bl StrCpyDecodeBattle
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806E994

	thumb_func_start GetWildMonTableIdInAlteringCave
GetWildMonTableIdInAlteringCave: @ 806EA40
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r1, 0
	ldr r2, =gUnknown_08329EFC
_0806EA4A:
	ldrh r0, [r2]
	cmp r0, r3
	bne _0806EA58
	adds r0, r1, 0
	b _0806EA62
	.pool
_0806EA58:
	adds r2, 0x4
	adds r1, 0x1
	cmp r1, 0x8
	ble _0806EA4A
	movs r0, 0
_0806EA62:
	pop {r1}
	bx r1
	thumb_func_end GetWildMonTableIdInAlteringCave

	thumb_func_start SetWildMonHeldItem
SetWildMonHeldItem: @ 806EA68
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x00302008
	ands r0, r1
	cmp r0, 0
	beq _0806EA7C
	b _0806EB90
_0806EA7C:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x64
	bl __umodsi3
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =gEnemyParty
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x2D
	mov r8, r0
	movs r7, 0x5F
	ldr r5, =gPlayerParty
	adds r0, r5, 0
	movs r1, 0x6
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806EAC6
	adds r0, r5, 0
	bl GetMonAbility
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE
	bne _0806EAC6
	movs r2, 0x14
	mov r8, r2
	movs r7, 0x50
_0806EAC6:
	ldr r0, =gUnknown_02037318
	ldrh r1, [r0, 0x12]
	movs r0, 0xD2
	lsls r0, 1
	cmp r1, r0
	bne _0806EB2C
	adds r0, r4, 0
	bl GetWildMonTableIdInAlteringCave
	adds r2, r0, 0
	cmp r2, 0
	beq _0806EB04
	cmp r6, r7
	bcc _0806EB90
	ldr r0, =gEnemyParty
	lsls r2, 2
	ldr r1, =gAlteringCaveWildMonHeldItems
	b _0806EB6C
	.pool
_0806EB04:
	cmp r6, r8
	bcc _0806EB90
	cmp r6, r7
	bcs _0806EB18
	ldr r0, =gEnemyParty
	lsls r2, r4, 3
	b _0806EB66
	.pool
_0806EB18:
	ldr r0, =gEnemyParty
	lsls r2, r4, 3
	subs r2, r4
	lsls r2, 2
	ldr r1, =gBaseStats + 0xe @ item 2 offset
	b _0806EB6C
	.pool
_0806EB2C:
	ldr r0, =gBaseStats
	mov r12, r0
	lsls r0, r4, 3
	subs r1, r0, r4
	lsls r5, r1, 2
	mov r2, r12
	adds r1, r5, r2
	ldrh r3, [r1, 0xC]
	adds r2, r0, 0
	ldrh r1, [r1, 0xE]
	cmp r3, r1
	bne _0806EB5C
	cmp r3, 0
	beq _0806EB5C
	ldr r0, =gEnemyParty
	mov r2, r12
	adds r2, 0xC
	adds r2, r5, r2
	b _0806EB6E
	.pool
_0806EB5C:
	cmp r6, r8
	bcc _0806EB90
	cmp r6, r7
	bcs _0806EB80
	ldr r0, =gEnemyParty
_0806EB66:
	subs r2, r4
	lsls r2, 2
	ldr r1, =gBaseStats + 0xc @ item 1 offset
_0806EB6C:
	adds r2, r1
_0806EB6E:
	movs r1, 0xC
	bl SetMonData
	b _0806EB90
	.pool
_0806EB80:
	ldr r0, =gEnemyParty
	subs r2, r4
	lsls r2, 2
	ldr r1, =gBaseStats + 0xe @ item 2 offset
	adds r2, r1
	movs r1, 0xC
	bl SetMonData
_0806EB90:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetWildMonHeldItem

	thumb_func_start IsMonShiny
IsMonShiny: @ 806EBA4
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x1
	movs r2, 0
	bl GetMonData
	adds r5, r0, 0
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	adds r0, r5, 0
	bl IsShinyOtIdPersonality
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end IsMonShiny

	thumb_func_start IsShinyOtIdPersonality
IsShinyOtIdPersonality: @ 806EBD0
	push {r4,lr}
	movs r4, 0
	lsrs r2, r0, 16
	ldr r3, =0x0000ffff
	ands r0, r3
	eors r2, r0
	lsrs r0, r1, 16
	eors r2, r0
	ands r1, r3
	eors r2, r1
	cmp r2, 0x7
	bhi _0806EBEA
	movs r4, 0x1
_0806EBEA:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end IsShinyOtIdPersonality

	thumb_func_start sub_806EBF8
sub_806EBF8: @ 806EBF8
	push {r4,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _0806EC3C
	ldr r2, =gUnknown_02038BCE
	ldrh r1, [r2]
	ldr r0, =0x00000c03
	cmp r1, r0
	bne _0806EC28
	ldr r0, =gTrainers + TRAINER_STEVEN * 0x28 + 0x4 @ Steven's name
	b _0806EC64
	.pool
_0806EC28:
	ldr r4, =gStringVar1
	ldrh r1, [r2]
	adds r0, r4, 0
	bl sub_8162E20
	adds r0, r4, 0
	b _0806EC64
	.pool
_0806EC3C:
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gLinkPlayers
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r4
	ldrh r1, [r1, 0x18]
	movs r0, 0x2
	eors r0, r1
	bl sub_806D864
	adds r1, r0, 0
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r4, 0x8
	adds r0, r4
_0806EC64:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806EBF8

	thumb_func_start sub_806EC70
sub_806EC70: @ 806EC70
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0xE]
	subs r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _0806ECA0
	ldrh r0, [r2, 0x8]
	ldrh r1, [r2, 0xA]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0xC]
	bl sub_817F544
	adds r0, r4, 0
	bl DestroyTask
_0806ECA0:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806EC70

	thumb_func_start sub_806ECAC
sub_806ECAC: @ 806ECAC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0xE]
	subs r0, 0x1
	strh r0, [r2, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _0806ECE2
	ldrh r0, [r2, 0x8]
	ldrh r1, [r2, 0xA]
	lsls r1, 16
	orrs r0, r1
	ldrb r1, [r2, 0xC]
	bl sub_817F578
	movs r0, 0xFF
	bl sub_81C488C
	adds r0, r4, 0
	bl DestroyTask
_0806ECE2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806ECAC

	thumb_func_start sub_806ECEC
sub_806ECEC: @ 806ECEC
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806ED30
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	bne _0806ED30
	movs r0, 0x80
	orrs r3, r0
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806ED40
	b _0806ED38
	.pool
_0806ED30:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_806ED40
_0806ED38:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_806ECEC

	thumb_func_start sub_806ED40
sub_806ED40: @ 806ED40
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x7F
	ands r0, r3
	cmp r0, 0
	beq _0806ED60
	cmp r0, 0x1
	beq _0806ED64
	movs r1, 0
	b _0806ED66
_0806ED60:
	movs r1, 0xE7
	b _0806ED66
_0806ED64:
	movs r1, 0x19
_0806ED66:
	movs r0, 0x80
	ands r0, r3
	cmp r0, 0
	beq _0806ED84
	cmp r2, 0
	bne _0806ED7C
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl PlayCry1
_0806ED7C:
	ldr r0, =SpriteCallbackDummy
	b _0806EDFA
	.pool
_0806ED84:
	cmp r2, 0
	bne _0806EDA6
	lsls r1, 24
	asrs r1, 24
	adds r0, r4, 0
	bl PlayCry1
	adds r0, r4, 0
	bl sub_806F0D4
	lsls r0, 24
	cmp r0, 0
	beq _0806EDA6
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0806EDA6:
	ldr r0, =gUnknown_08329B87
	subs r4, 0x1
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, 0
	beq _0806EDEC
	ldr r0, =sub_806EC70
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r5, [r1, 0x8]
	lsrs r0, r5, 16
	strh r0, [r1, 0xA]
	ldr r0, =gUnknown_083299EC
	adds r0, r4, r0
	ldrb r0, [r0]
	strh r0, [r1, 0xC]
	ldrb r0, [r6]
	strh r0, [r1, 0xE]
	b _0806EDF8
	.pool
_0806EDEC:
	ldr r0, =gUnknown_083299EC
	adds r0, r4, r0
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_817F544
_0806EDF8:
	ldr r0, =nullsub_18
_0806EDFA:
	str r0, [r5, 0x1C]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806ED40

	thumb_func_start sub_806EE0C
sub_806EE0C: @ 806EE0C
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	cmp r2, 0
	bne _0806EE2E
	adds r0, r4, 0
	bl sub_806F0D4
	lsls r0, 24
	cmp r0, 0
	beq _0806EE2E
	adds r0, r5, 0
	movs r1, 0x1
	bl StartSpriteAnim
_0806EE2E:
	ldr r0, =gUnknown_08329B87
	subs r4, 0x1
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, 0
	beq _0806EE80
	ldr r0, =sub_806ECAC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r1
	strh r5, [r2, 0x8]
	lsrs r1, r5, 16
	strh r1, [r2, 0xA]
	ldr r1, =gUnknown_083299EC
	adds r1, r4, r1
	ldrb r1, [r1]
	strh r1, [r2, 0xC]
	ldrb r1, [r6]
	strh r1, [r2, 0xE]
	bl sub_81C488C
	adds r0, r5, 0
	bl sub_817F60C
	b _0806EE8C
	.pool
_0806EE80:
	ldr r0, =gUnknown_083299EC
	adds r0, r4, r0
	ldrb r1, [r0]
	adds r0, r5, 0
	bl sub_817F578
_0806EE8C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806EE0C

	thumb_func_start sub_806EE98
sub_806EE98: @ 806EE98
	push {lr}
	ldr r0, =sub_806ECAC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _0806EEAC
	bl DestroyTask
_0806EEAC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806EE98

	thumb_func_start sub_806EEB4
sub_806EEB4: @ 806EEB4
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r2, r1, 16
	ldr r0, =gHitMarker
	ldr r0, [r0]
	movs r1, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0806EEE8
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	bne _0806EEE8
	ldr r0, =SpriteCallbackDummy
	b _0806EEFC
	.pool
_0806EEE8:
	adds r0, r2, 0
	bl sub_817F474
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_817F594
	ldr r0, =nullsub_18
_0806EEFC:
	str r0, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806EEB4

	thumb_func_start sub_806EF08
sub_806EF08: @ 806EF08
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r5, 0
	bl GetMultiplayerId
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gLinkPlayers
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x18]
	cmp r0, 0x1
	beq _0806EF4C
	cmp r0, 0x1
	bgt _0806EF38
	cmp r0, 0
	beq _0806EF42
	b _0806EF56
	.pool
_0806EF38:
	cmp r0, 0x2
	beq _0806EF42
	cmp r0, 0x3
	beq _0806EF4C
	b _0806EF56
_0806EF42:
	movs r5, 0x3
	cmp r4, 0
	beq _0806EF56
	movs r5, 0x1
	b _0806EF56
_0806EF4C:
	negs r0, r4
	orrs r0, r4
	asrs r5, r0, 31
	movs r0, 0x2
	ands r5, r0
_0806EF56:
	movs r2, 0
	ldr r4, =gLinkPlayers
	ldrh r0, [r4, 0x18]
	adds r1, r5, 0
	cmp r0, r1
	beq _0806EF74
	adds r3, r1, 0
	adds r1, r4, 0
_0806EF66:
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	bgt _0806EF74
	ldrh r0, [r1, 0x18]
	cmp r0, r3
	bne _0806EF66
_0806EF74:
	lsls r0, r2, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806EF08

	thumb_func_start sub_806EF84
sub_806EF84: @ 806EF84
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r4, 0
	ldr r2, =gLinkPlayers
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x18]
	cmp r0, 0x1
	beq _0806EFC4
	cmp r0, 0x1
	bgt _0806EFB0
	cmp r0, 0
	beq _0806EFBA
	b _0806EFCE
	.pool
_0806EFB0:
	cmp r0, 0x2
	beq _0806EFBA
	cmp r0, 0x3
	beq _0806EFC4
	b _0806EFCE
_0806EFBA:
	movs r4, 0x3
	cmp r3, 0
	beq _0806EFCE
	movs r4, 0x1
	b _0806EFCE
_0806EFC4:
	negs r0, r3
	orrs r0, r3
	asrs r4, r0, 31
	movs r0, 0x2
	ands r4, r0
_0806EFCE:
	movs r3, 0
	ldrh r0, [r2, 0x18]
	adds r1, r4, 0
	cmp r0, r1
	beq _0806EFE6
_0806EFD8:
	adds r2, 0x1C
	adds r3, 0x1
	cmp r3, 0x3
	bgt _0806EFE6
	ldrh r0, [r2, 0x18]
	cmp r0, r1
	bne _0806EFD8
_0806EFE6:
	lsls r0, r3, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_806EF84

	thumb_func_start TrainerClassToTrainerPic
@ u8 TrainerClassToTrainerPic(u16 trainerClassId)
TrainerClassToTrainerPic: @ 806EFF0
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gTrainerPicIndices
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end TrainerClassToTrainerPic

	thumb_func_start sub_806F000
sub_806F000: @ 806F000
	push {lr}
	lsls r0, 24
	cmp r0, 0
	bne _0806F00C
	movs r0, 0x3C
	b _0806F00E
_0806F00C:
	movs r0, 0x3F
_0806F00E:
	bl TrainerClassToTrainerPic
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_806F000

	thumb_func_start SetPokedexFlag
@ void SetPokedexFlag(u16 nationalPokedexNum, u8 op, u32 personality)
SetPokedexFlag: @ 806F01C
	push {r4-r7,lr}
	adds r7, r2, 0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	lsls r1, 24
	lsrs r5, r1, 24
	movs r0, 0x2
	eors r0, r5
	negs r1, r0
	orrs r1, r0
	lsrs r1, 31
	adds r0, r4, 0
	bl pokedex_flag_operation
	lsls r0, 24
	cmp r0, 0
	bne _0806F072
	adds r0, r4, 0
	adds r1, r5, 0
	bl pokedex_flag_operation
	adds r0, r4, 0
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC9
	bne _0806F05C
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	str r7, [r0, 0x1C]
_0806F05C:
	adds r0, r6, 0
	bl NationalPokedexNumToSpecies
	lsls r0, 16
	movs r1, 0x9A
	lsls r1, 17
	cmp r0, r1
	bne _0806F072
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	str r7, [r0, 0x20]
_0806F072:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetPokedexFlag

	thumb_func_start sub_806F07C
sub_806F07C: @ 806F07C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x00000356
	cmp r2, r0
	bls _0806F08A
	movs r2, 0
_0806F08A:
	ldr r1, =gTrainers
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	ldrb r1, [r0, 0x1]
	movs r0, 0xD
	muls r0, r1
	ldr r1, =gTrainerClassNames
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F07C

	thumb_func_start sub_806F0B0
sub_806F0B0: @ 806F0B0
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x00000356
	cmp r1, r0
	bls _0806F0BE
	movs r1, 0
_0806F0BE:
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	ldr r1, =gTrainers + 0x4 @ name offset
	adds r0, r1
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F0B0

	thumb_func_start sub_806F0D4
sub_806F0D4: @ 806F0D4
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	ldr r0, =0x00000181
	cmp r2, r0
	beq _0806F0F8
	adds r0, 0x19
	cmp r2, r0
	beq _0806F0F8
	subs r0, 0x66
	cmp r2, r0
	beq _0806F0F8
	movs r1, 0xC9
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	lsrs r1, r0, 31
_0806F0F8:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F0D4

	thumb_func_start sub_806F104
sub_806F104: @ 806F104
	push {lr}
	ldr r2, =gMain
	ldr r1, =0x00000439
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0806F122
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x003f0100
	ands r0, r1
	cmp r0, 0
	bne _0806F144
_0806F122:
	ldr r1, =0x00000439
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0806F158
	bl InBattlePike
	lsls r0, 24
	cmp r0, 0
	bne _0806F144
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	beq _0806F158
_0806F144:
	movs r0, 0x1
	b _0806F15A
	.pool
_0806F158:
	movs r0, 0
_0806F15A:
	pop {r1}
	bx r1
	thumb_func_end sub_806F104

	thumb_func_start sub_806F160
sub_806F160: @ 806F160
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r6, r0, 0
	ldrb r0, [r6]
	lsls r0, 28
	movs r4, 0
	cmp r0, 0
	beq _0806F1EA
_0806F176:
	ldr r0, [r6, 0xC]
	lsls r2, r4, 1
	adds r1, r2, r4
	lsls r1, 3
	adds r0, r1, r0
	ldr r3, =gUnknown_08329D98
	adds r1, r3
	ldm r1!, {r3,r5,r7}
	stm r0!, {r3,r5,r7}
	ldm r1!, {r3,r5,r7}
	stm r0!, {r3,r5,r7}
	movs r5, 0
	ldrb r3, [r6, 0x1]
	ldr r7, [r6, 0xC]
	mov r9, r7
	mov r8, r2
	ldr r0, [r6, 0x10]
	mov r12, r0
	adds r1, r4, 0x1
	mov r10, r1
	cmp r5, r3
	bcs _0806F1C8
	mov r7, r12
	ldr r1, [r6, 0x8]
	lsls r0, r4, 2
	adds r0, r1
	ldr r2, [r0]
_0806F1AC:
	adds r0, r4, 0
	muls r0, r3
	adds r0, r5
	lsls r0, 3
	adds r0, r7
	lsls r1, r5, 11
	adds r1, r2, r1
	str r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r3, [r6, 0x1]
	cmp r5, r3
	bcc _0806F1AC
_0806F1C8:
	mov r3, r8
	adds r1, r3, r4
	lsls r1, 3
	add r1, r9
	ldrb r0, [r6, 0x1]
	muls r0, r4
	lsls r0, 3
	add r0, r12
	str r0, [r1, 0xC]
	mov r5, r10
	lsls r0, r5, 16
	lsrs r4, r0, 16
	ldrb r0, [r6]
	lsls r0, 28
	lsrs r0, 28
	cmp r4, r0
	blt _0806F176
_0806F1EA:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806F160

	thumb_func_start sub_806F1FC
sub_806F1FC: @ 806F1FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r4, r0, 0
	ldrb r0, [r4]
	lsls r0, 28
	movs r3, 0
	cmp r0, 0
	beq _0806F296
	ldr r0, =gUnknown_08329F28
	mov r10, r0
_0806F216:
	ldr r0, [r4, 0xC]
	lsls r2, r3, 1
	adds r1, r2, r3
	lsls r1, 3
	adds r1, r0
	mov r0, r10
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r1!, {r5-r7}
	movs r5, 0
	ldr r0, [r4, 0xC]
	mov r8, r0
	mov r12, r2
	ldr r7, [r4, 0x10]
	adds r1, r3, 0x1
	mov r9, r1
	ldrb r6, [r4, 0x1]
	cmp r5, r6
	bcs _0806F26A
	adds r6, r7, 0
	ldr r1, [r4, 0x8]
	lsls r0, r3, 2
	adds r0, r1
	ldr r2, [r0]
_0806F248:
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	adds r1, r3, 0
	muls r1, r0
	adds r1, r5
	lsls r1, 3
	adds r1, r6
	lsls r0, r5, 11
	adds r0, r2, r0
	str r0, [r1]
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r0, [r4, 0x1]
	cmp r5, r0
	bcc _0806F248
_0806F26A:
	mov r5, r12
	adds r1, r5, r3
	lsls r1, 3
	add r1, r8
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	muls r0, r3
	lsls r0, 3
	adds r0, r7, r0
	str r0, [r1, 0xC]
	ldr r6, =gUnknown_082FF70C
	str r6, [r1, 0x8]
	strh r3, [r1, 0x2]
	mov r7, r9
	lsls r0, r7, 16
	lsrs r3, r0, 16
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	cmp r3, r0
	blt _0806F216
_0806F296:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_806F1FC

	thumb_func_start sub_806F2AC
sub_806F2AC: @ 806F2AC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	movs r7, 0
	movs r0, 0x1
	ands r6, r0
	movs r0, 0x14
	bl AllocZeroed
	adds r4, r0, 0
	cmp r4, 0
	bne _0806F2D0
	movs r0, 0
	b _0806F46E
_0806F2D0:
	cmp r5, 0
	beq _0806F2E6
	cmp r5, 0x2
	bne _0806F2E6
	movs r0, 0x77
	strb r0, [r4]
	movs r0, 0x4
	strb r0, [r4, 0x1]
	movs r0, 0x21
	strb r0, [r4, 0x3]
	b _0806F30E
_0806F2E6:
	ldrb r1, [r4]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	movs r3, 0xF
	ands r0, r3
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x4
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	ands r2, r0
	movs r0, 0x1
	orrs r2, r0
	ands r2, r3
	strb r2, [r4, 0x3]
_0806F30E:
	ldrb r1, [r4, 0x3]
	lsls r1, 28
	lsrs r1, 28
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 15
	muls r0, r1
	bl AllocZeroed
	str r0, [r4, 0x4]
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 23
	bl AllocZeroed
	adds r1, r0, 0
	str r1, [r4, 0x8]
	ldr r2, [r4, 0x4]
	cmp r2, 0
	beq _0806F33A
	cmp r1, 0
	bne _0806F344
_0806F33A:
	movs r0, 0x1
	orrs r7, r0
	lsls r6, 2
	mov r8, r6
	b _0806F378
_0806F344:
	ldrb r0, [r4]
	lsls r0, 28
	movs r3, 0
	lsls r6, 2
	mov r8, r6
	cmp r0, 0
	beq _0806F378
	adds r6, r1, 0
	adds r5, r2, 0
_0806F356:
	lsls r2, r3, 2
	adds r2, r6
	ldrb r0, [r4, 0x3]
	lsls r0, 28
	lsrs r0, 28
	lsls r1, r3, 13
	muls r0, r1
	adds r0, r5, r0
	str r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	cmp r3, r0
	blt _0806F356
_0806F378:
	ldrb r1, [r4]
	lsls r1, 28
	lsrs r1, 28
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	bl AllocZeroed
	str r0, [r4, 0xC]
	ldrb r1, [r4]
	lsls r1, 28
	lsrs r1, 28
	ldrb r0, [r4, 0x1]
	lsls r0, 3
	muls r0, r1
	bl AllocZeroed
	adds r1, r0, 0
	str r1, [r4, 0x10]
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0806F3A8
	cmp r1, 0
	bne _0806F3B2
_0806F3A8:
	movs r0, 0x2
	orrs r7, r0
	lsls r0, r7, 24
	lsrs r7, r0, 24
	b _0806F400
_0806F3B2:
	movs r3, 0
	ldrb r0, [r4, 0x1]
	ldrb r1, [r4]
	lsls r1, 28
	lsrs r1, 28
	muls r0, r1
	cmp r3, r0
	bge _0806F3E2
	movs r2, 0x80
	lsls r2, 4
_0806F3C6:
	ldr r1, [r4, 0x10]
	lsls r0, r3, 3
	adds r0, r1
	strh r2, [r0, 0x4]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	ldrb r1, [r4, 0x1]
	ldrb r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	muls r0, r1
	cmp r3, r0
	blt _0806F3C6
_0806F3E2:
	ldrb r0, [r4, 0x3]
	lsrs r0, 4
	cmp r0, 0
	blt _0806F3FA
	cmp r0, 0x1
	ble _0806F3FA
	cmp r0, 0x2
	bne _0806F3FA
	adds r0, r4, 0
	bl sub_806F1FC
	b _0806F400
_0806F3FA:
	adds r0, r4, 0
	bl sub_806F160
_0806F400:
	movs r0, 0x2
	ands r0, r7
	cmp r0, 0
	beq _0806F424
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0806F416
	bl Free
	movs r0, 0
	str r0, [r4, 0x10]
_0806F416:
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0806F424
	bl Free
	movs r0, 0
	str r0, [r4, 0xC]
_0806F424:
	movs r0, 0x1
	ands r0, r7
	cmp r0, 0
	beq _0806F448
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0806F43A
	bl Free
	movs r0, 0
	str r0, [r4, 0x8]
_0806F43A:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0806F448
	bl Free
	movs r0, 0
	str r0, [r4, 0x4]
_0806F448:
	cmp r7, 0
	beq _0806F45E
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	adds r0, r4, 0
	bl Free
	b _0806F468
_0806F45E:
	movs r0, 0xA3
	strb r0, [r4, 0x2]
	ldr r0, =gUnknown_020249B4
	add r0, r8
	str r4, [r0]
_0806F468:
	ldr r0, =gUnknown_020249B4
	add r0, r8
	ldr r0, [r0]
_0806F46E:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_806F2AC

	thumb_func_start sub_806F47C
sub_806F47C: @ 806F47C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	ands r0, r1
	ldr r1, =gUnknown_020249B4
	lsls r0, 2
	adds r0, r1
	ldr r4, [r0]
	cmp r4, 0
	beq _0806F4F0
	ldrb r0, [r4, 0x2]
	cmp r0, 0xA3
	beq _0806F4A8
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	b _0806F4F0
	.pool
_0806F4A8:
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _0806F4B6
	bl Free
	movs r0, 0
	str r0, [r4, 0x10]
_0806F4B6:
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _0806F4C4
	bl Free
	movs r0, 0
	str r0, [r4, 0xC]
_0806F4C4:
	ldr r0, [r4, 0x8]
	cmp r0, 0
	beq _0806F4D2
	bl Free
	movs r0, 0
	str r0, [r4, 0x8]
_0806F4D2:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _0806F4E0
	bl Free
	movs r0, 0
	str r0, [r4, 0x4]
_0806F4E0:
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x14
	bl memset
	adds r0, r4, 0
	bl Free
_0806F4F0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_806F47C

	thumb_func_start sub_806F4F8
sub_806F4F8: @ 806F4F8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	ldr r2, =gUnknown_020249B4
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	ldrb r0, [r1, 0x2]
	cmp r0, 0xA3
	beq _0806F51C
	movs r0, 0
	b _0806F530
	.pool
_0806F51C:
	ldrb r0, [r1]
	lsls r0, 28
	lsrs r0, 28
	cmp r3, r0
	blt _0806F528
	movs r3, 0
_0806F528:
	ldr r0, [r1, 0x8]
	lsls r1, r3, 2
	adds r1, r0
	ldr r0, [r1]
_0806F530:
	pop {r1}
	bx r1
	thumb_func_end sub_806F4F8

	.align 2, 0 @ Don't pad with nop.
