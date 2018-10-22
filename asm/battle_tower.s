	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start sub_81659DC
sub_81659DC: @ 81659DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r6, r1, 0
	movs r2, 0
	adds r1, r4, 0
	adds r3, r4, 0
	adds r3, 0x58
_081659F4:
	ldrh r0, [r1, 0x34]
	cmp r0, 0
	beq _081659FC
	adds r2, 0x1
_081659FC:
	adds r1, 0x2C
	cmp r1, r3
	ble _081659F4
	cmp r2, 0x3
	beq _08165A14
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0xA4
	bl memset
	movs r0, 0
	b _08165AD8
_08165A14:
	ldrb r0, [r4]
	strb r0, [r6]
	ldrh r0, [r4, 0x2]
	strh r0, [r6, 0x2]
	movs r2, 0
	ldr r0, =sRubyFacilityClassToEmerald
	ldrb r1, [r0, 0x1]
	ldrb r3, [r4, 0x1]
	mov r12, r0
	adds r5, r6, 0x4
	adds r7, r4, 0x4
	movs r0, 0xC
	adds r0, r6
	mov r9, r0
	movs r0, 0xC
	adds r0, r4
	mov r8, r0
	adds r0, r6, 0
	adds r0, 0x10
	str r0, [sp]
	movs r0, 0x10
	adds r0, r4
	mov r10, r0
	cmp r1, r3
	beq _08165A58
	mov r1, r12
	adds r1, 0x1
_08165A4A:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x51
	bgt _08165A58
	ldrb r0, [r1]
	cmp r0, r3
	bne _08165A4A
_08165A58:
	cmp r2, 0x52
	beq _08165A68
	lsls r0, r2, 1
	add r0, r12
	ldrb r0, [r0]
	b _08165A6A
	.pool
_08165A68:
	movs r0, 0x24
_08165A6A:
	strb r0, [r6, 0x1]
	movs r2, 0
	adds r3, r7, 0
_08165A70:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _08165A70
	movs r2, 0
	mov r5, r9
	mov r3, r8
_08165A84:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x3
	ble _08165A84
	mov r3, r10
	ldr r1, [sp]
	movs r2, 0x5
_08165A98:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, 0x2
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _08165A98
	adds r2, r4, 0
	adds r3, r6, 0
	movs r4, 0x58
	adds r4, r2
	mov r8, r4
_08165AB0:
	adds r1, r3, 0
	adds r1, 0x1C
	adds r0, r2, 0
	adds r0, 0x34
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r4,r5,r7}
	stm r1!, {r4,r5,r7}
	ldm r0!, {r5,r7}
	stm r1!, {r5,r7}
	adds r2, 0x2C
	adds r3, 0x2C
	cmp r2, r8
	ble _08165AB0
	adds r0, r6, 0
	bl CalcRubyBattleTowerChecksum
	movs r0, 0x1
_08165AD8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81659DC

	thumb_func_start sub_8165AE8
sub_8165AE8: @ 8165AE8
	push {r4,lr}
	adds r2, r0, 0
	movs r0, 0
	str r0, [r2, 0x40]
	movs r3, 0
	adds r4, r2, 0
_08165AF4:
	ldr r0, [r2, 0x40]
	ldm r4!, {r1}
	adds r0, r1
	str r0, [r2, 0x40]
	adds r3, 0x1
	cmp r3, 0xF
	bls _08165AF4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8165AE8

	thumb_func_start sub_8165B08
sub_8165B08: @ 8165B08
	push {lr}
	movs r1, 0
	movs r3, 0
	adds r2, r0, 0
_08165B10:
	stm r2!, {r3}
	adds r1, 0x1
	cmp r1, 0x10
	bls _08165B10
	bl ResetApprenticeStruct
	pop {r0}
	bx r0
	thumb_func_end sub_8165B08

	thumb_func_start sub_8165B20
sub_8165B20: @ 8165B20
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
	ldr r0, =gSaveBlock2Ptr
	mov r8, r0
	mov r9, r8
_08165B30:
	lsls r0, r5, 4
	adds r1, r0, r5
	lsls r1, 2
	adds r1, 0xDC
	mov r3, r9
	ldr r2, [r3]
	movs r4, 0
	movs r3, 0
	adds r6, r0, 0
	adds r7, r5, 0x1
	adds r2, r1
_08165B46:
	ldm r2!, {r0}
	adds r4, r0
	adds r3, 0x1
	cmp r3, 0xF
	bls _08165B46
	mov r0, r8
	ldr r2, [r0]
	adds r0, r6, r5
	lsls r1, r0, 2
	movs r3, 0x8E
	lsls r3, 1
	adds r0, r2, r3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r4
	beq _08165B70
	adds r0, r1, 0
	adds r0, 0xDC
	adds r0, r2, r0
	bl sub_8165B08
_08165B70:
	adds r5, r7, 0
	cmp r5, 0x3
	ble _08165B30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165B20

	thumb_func_start sub_8165B88
sub_8165B88: @ 8165B88
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r2, r1, 16
	adds r3, r2, 0
	movs r0, 0xFA
	lsls r0, 1
	cmp r2, r0
	bne _08165BA4
	ldr r0, =gGameLanguage
	b _08165C28
	.pool
_08165BA4:
	ldr r0, =0x0000012b
	cmp r2, r0
	bhi _08165BB8
	ldr r0, =gGameLanguage
	b _08165C28
	.pool
_08165BB8:
	ldr r0, =0x0000018f
	cmp r2, r0
	bhi _08165BFC
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08165BDC
	bl sub_81864B4
	b _08165C2A
	.pool
_08165BDC:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0xfffffed4
	adds r2, r1
	movs r1, 0xEC
	muls r1, r2
	adds r0, r1
	ldr r1, =0x0000081c
	adds r0, r1
	b _08165C28
	.pool
_08165BFC:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	beq _08165C14
	bl sub_81864C0
	b _08165C2A
	.pool
_08165C14:
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r0, =0xfffffe70
	adds r1, r3, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r1, =0x0000011b
	adds r0, r2, r1
_08165C28:
	ldrb r0, [r0]
_08165C2A:
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165B88

	thumb_func_start GetFacilityEnemyMonLevel
GetFacilityEnemyMonLevel: @ 8165C40
	push {lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0x2
	beq _08165C84
	ldr r1, =gFacilityTrainers
	ldr r0, =gBattleFrontierTrainers
	str r0, [r1]
	ldr r1, =gFacilityTrainerMons
	ldr r0, =gBattleFrontierMons
	str r0, [r1]
	ldrb r0, [r2]
	lsls r0, 30
	lsrs r0, 30
	bl GetFrontierEnemyMonLevel
	b _08165C88
	.pool
_08165C84:
	bl GetTentEnemyMonLevel
_08165C88:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end GetFacilityEnemyMonLevel

	thumb_func_start GetFrontierEnemyMonLevel
GetFrontierEnemyMonLevel: @ 8165C90
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08165C9E
	cmp r0, 0x1
	beq _08165CA2
_08165C9E:
	movs r0, 0x32
	b _08165CB0
_08165CA2:
	bl sub_8165CB4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3B
	bhi _08165CB0
	movs r0, 0x3C
_08165CB0:
	pop {r1}
	bx r1
	thumb_func_end GetFrontierEnemyMonLevel

	thumb_func_start sub_8165CB4
sub_8165CB4: @ 8165CB4
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
_08165CBA:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _08165CF4
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _08165CF4
	adds r0, r4, 0
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	cmp r0, r6
	ble _08165CF4
	adds r6, r0, 0
_08165CF4:
	adds r5, 0x1
	cmp r5, 0x5
	ble _08165CBA
	adds r0, r6, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8165CB4

	thumb_func_start GetFrontierTrainerFixedIvs
GetFrontierTrainerFixedIvs: @ 8165D08
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	cmp r0, 0x63
	bls _08165D3A
	movs r1, 0x6
	cmp r0, 0x77
	bls _08165D3A
	movs r1, 0x9
	cmp r0, 0x8B
	bls _08165D3A
	movs r1, 0xC
	cmp r0, 0x9F
	bls _08165D3A
	movs r1, 0xF
	cmp r0, 0xB3
	bls _08165D3A
	movs r1, 0x12
	cmp r0, 0xC7
	bls _08165D3A
	movs r1, 0x1F
	cmp r0, 0xDB
	bhi _08165D3A
	movs r1, 0x15
_08165D3A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end GetFrontierTrainerFixedIvs

	thumb_func_start sub_8165D40
sub_8165D40: @ 8165D40
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	beq _08165D58
	cmp r0, 0x3
	beq _08165D58
	cmp r0, 0x4
	bne _08165D70
_08165D58:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1E
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	b _08165D72
	.pool
_08165D70:
	movs r0, 0
_08165D72:
	pop {r1}
	bx r1
	thumb_func_end sub_8165D40

	thumb_func_start GetTentEnemyMonLevel
GetTentEnemyMonLevel: @ 8165D78
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x4
	bne _08165DA8
	ldr r1, =gFacilityTrainers
	ldr r0, =gSlateportBattleTentTrainers
	str r0, [r1]
	ldr r1, =gFacilityTrainerMons
	ldr r0, =gSlateportBattleTentMons
	b _08165DF2
	.pool
_08165DA8:
	cmp r0, 0x2
	bne _08165DC8
	ldr r1, =gFacilityTrainers
	ldr r0, =gVerdanturfBattleTentTrainers
	str r0, [r1]
	ldr r1, =gFacilityTrainerMons
	ldr r0, =gVerdanturfBattleTentMons
	b _08165DF2
	.pool
_08165DC8:
	cmp r0, 0x3
	bne _08165DE8
	ldr r1, =gFacilityTrainers
	ldr r0, =gFallarborBattleTentTrainers
	str r0, [r1]
	ldr r1, =gFacilityTrainerMons
	ldr r0, =gFallarborBattleTentMons
	b _08165DF2
	.pool
_08165DE8:
	ldr r1, =gFacilityTrainers
	ldr r0, =gBattleFrontierTrainers
	str r0, [r1]
	ldr r1, =gFacilityTrainerMons
	ldr r0, =gBattleFrontierMons
_08165DF2:
	str r0, [r1]
	bl sub_8165CB4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1D
	bhi _08165E02
	movs r0, 0x1E
_08165E02:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTentEnemyMonLevel

	thumb_func_start sub_8165E18
sub_8165E18: @ 8165E18
	push {r4,r5,lr}
	ldr r5, =gSaveBlock2Ptr
_08165E1C:
	bl sub_8165D40
	lsls r0, 16
	lsrs r4, r0, 16
	movs r3, 0
	ldr r1, [r5]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r3, r0
	bge _08165E58
	adds r2, 0x2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, r4
	beq _08165E58
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	subs r2, 0x2
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r0, =0x00000cb4
	adds r1, r0
_08165E4A:
	adds r1, 0x2
	adds r3, 0x1
	cmp r3, r2
	bge _08165E58
	ldrh r0, [r1]
	cmp r0, r4
	bne _08165E4A
_08165E58:
	ldr r0, [r5]
	ldr r1, =0x00000cb2
	adds r0, r1
	ldrh r0, [r0]
	cmp r3, r0
	bne _08165E1C
	ldr r5, =gTrainerBattleOpponent_A
	strh r4, [r5]
	ldrh r0, [r5]
	movs r1, 0
	bl SetBattleFacilityTrainerGfxId
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldr r2, =0x00000cb2
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r2, 0x1
	cmp r0, 0x2
	bgt _08165E8C
	lsls r0, r2, 1
	ldr r2, =0x00000cb4
	adds r1, r2
	adds r1, r0
	ldrh r0, [r5]
	strh r0, [r1]
_08165E8C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165E18

	thumb_func_start sub_8165EA4
sub_8165EA4: @ 8165EA4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x18]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x1C]
	bl GetTentEnemyMonLevel
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x20]
	ldr r0, =gTrainerBattleOpponent_A
	ldrh r2, [r0]
	ldr r0, =gFacilityTrainers
	ldr r1, [r0]
	movs r0, 0x34
	muls r0, r2
	adds r0, r1
	ldr r0, [r0, 0x30]
	str r0, [sp, 0x28]
	movs r0, 0
	str r0, [sp, 0x24]
	ldr r2, [sp, 0x28]
	ldrh r1, [r2]
	b _08165EFE
	.pool
_08165EEC:
	ldr r0, [sp, 0x24]
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x24]
	lsls r0, 1
	ldr r6, [sp, 0x28]
	adds r0, r6
	ldrh r1, [r0]
_08165EFE:
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _08165EEC
	movs r0, 0
	mov r8, r0
	bl Random
	adds r4, r0, 0
	bl Random
	lsls r4, 16
	lsrs r4, 16
	lsls r0, 16
	orrs r4, r0
	str r4, [sp, 0x2C]
	b _08166092
	.pool
_08165F24:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	ldr r1, [sp, 0x24]
	bl __modsi3
	lsls r0, 1
	ldr r2, [sp, 0x28]
	adds r0, r2
	ldrh r4, [r0]
	movs r6, 0
	ldr r7, [sp, 0x18]
	add r7, r8
	b _08165F44
_08165F42:
	adds r6, 0x1
_08165F44:
	cmp r6, r7
	bge _08165F68
	movs r1, 0x64
	adds r0, r6, 0
	muls r0, r1
	ldr r2, =gEnemyParty
	adds r0, r2
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, =gFacilityTrainerMons
	ldr r2, [r1]
	lsls r1, r4, 4
	adds r1, r2
	ldrh r1, [r1]
	cmp r0, r1
	bne _08165F42
_08165F68:
	cmp r6, r7
	beq _08165F6E
	b _08166092
_08165F6E:
	movs r6, 0
	cmp r6, r7
	bge _08165FB8
	ldr r0, =gBattleFrontierHeldItems
	mov r9, r0
	movs r3, 0
_08165F7A:
	ldr r1, =gEnemyParty
	adds r5, r3, r1
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	str r3, [sp, 0x34]
	bl GetMonData
	ldr r3, [sp, 0x34]
	cmp r0, 0
	beq _08165FB0
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	ldr r1, =gFacilityTrainerMons
	ldr r2, [r1]
	lsls r1, r4, 4
	adds r1, r2
	ldrb r1, [r1, 0xA]
	lsls r1, 1
	add r1, r9
	ldr r3, [sp, 0x34]
	ldrh r1, [r1]
	cmp r0, r1
	beq _08165FB8
_08165FB0:
	adds r3, 0x64
	adds r6, 0x1
	cmp r6, r7
	blt _08165F7A
_08165FB8:
	cmp r6, r7
	bne _08166092
	movs r6, 0
	cmp r6, r8
	bge _08165FDA
	add r0, sp, 0xC
	ldrh r0, [r0]
	cmp r0, r4
	beq _08165FDA
	add r1, sp, 0xC
_08165FCC:
	adds r1, 0x2
	adds r6, 0x1
	cmp r6, r8
	bge _08165FDA
	ldrh r0, [r1]
	cmp r0, r4
	bne _08165FCC
_08165FDA:
	cmp r6, r8
	bne _08166092
	mov r2, r8
	lsls r0, r2, 1
	add r0, sp
	adds r0, 0xC
	strh r4, [r0]
	movs r6, 0x64
	adds r0, r7, 0
	muls r0, r6
	ldr r1, =gEnemyParty
	adds r0, r1
	ldr r5, =gFacilityTrainerMons
	ldr r2, [r5]
	lsls r4, 4
	adds r2, r4, r2
	ldrh r1, [r2]
	ldrb r3, [r2, 0xC]
	movs r6, 0
	str r6, [sp]
	ldrb r2, [r2, 0xB]
	str r2, [sp, 0x4]
	ldr r2, [sp, 0x2C]
	str r2, [sp, 0x8]
	ldr r2, [sp, 0x20]
	bl CreateMonWithEVSpreadPersonalityOTID
	add r1, sp, 0x14
	movs r0, 0xFF
	strb r0, [r1]
	mov r9, r4
	mov r0, r8
	adds r0, 0x1
	str r0, [sp, 0x30]
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	mov r8, r1
	adds r3, r5, 0
	mov r5, r9
	ldr r2, =gEnemyParty
	mov r10, r2
_0816602E:
	ldr r0, [r3]
	adds r0, r5, r0
	lsls r4, r6, 1
	adds r0, 0x2
	adds r0, r4
	ldrh r1, [r0]
	lsls r2, r6, 24
	lsrs r2, 24
	mov r0, r8
	add r0, r10
	str r3, [sp, 0x34]
	bl SetMonMoveSlot
	ldr r3, [sp, 0x34]
	ldr r0, [r3]
	adds r0, r5, r0
	adds r0, 0x2
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, 0xDA
	bne _0816605E
	movs r0, 0
	mov r1, sp
	strb r0, [r1, 0x14]
_0816605E:
	adds r6, 0x1
	cmp r6, 0x3
	ble _0816602E
	movs r2, 0x64
	adds r4, r7, 0
	muls r4, r2
	ldr r6, =gEnemyParty
	adds r4, r6
	adds r0, r4, 0
	movs r1, 0x20
	add r2, sp, 0x14
	bl SetMonData
	ldr r0, =gFacilityTrainerMons
	ldr r0, [r0]
	add r0, r9
	ldrb r2, [r0, 0xA]
	lsls r2, 1
	ldr r0, =gBattleFrontierHeldItems
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0xC
	bl SetMonData
	ldr r0, [sp, 0x30]
	mov r8, r0
_08166092:
	ldr r1, [sp, 0x1C]
	cmp r8, r1
	beq _0816609A
	b _08165F24
_0816609A:
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8165EA4

	thumb_func_start sub_81660B8
sub_81660B8: @ 81660B8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gTowerMaleFacilityClasses
	ldrb r0, [r3]
	cmp r0, r2
	beq _081660DA
_081660C8:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1D
	bhi _081660DA
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081660C8
_081660DA:
	cmp r1, 0x1E
	beq _081660EC
	ldr r0, =gTowerMaleTrainerGfxIds
	b _08166116
	.pool
_081660EC:
	movs r1, 0
	ldr r3, =gTowerFemaleFacilityClasses
	ldrb r0, [r3]
	cmp r0, r2
	beq _08166108
_081660F6:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x13
	bhi _08166108
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081660F6
_08166108:
	cmp r1, 0x14
	bne _08166114
	movs r0, 0x7
	b _0816611A
	.pool
_08166114:
	ldr r0, =gTowerFemaleTrainerGfxIds
_08166116:
	adds r0, r1, r0
	ldrb r0, [r0]
_0816611A:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81660B8

	thumb_func_start sub_8166124
sub_8166124: @ 8166124
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gSaveBlock2Ptr
	movs r0, 0xEC
	muls r0, r6
	movs r1, 0xE7
	lsls r1, 3
	adds r0, r1
	ldr r1, [r2]
	movs r5, 0
	movs r4, 0
	movs r3, 0
	adds r1, r0
_08166140:
	ldm r1!, {r0}
	adds r5, r0
	orrs r4, r0
	adds r3, 0x1
	cmp r3, 0x39
	bls _08166140
	cmp r5, 0
	bne _08166154
	cmp r4, 0
	beq _08166180
_08166154:
	ldr r2, [r2]
	movs r0, 0xEC
	adds r1, r6, 0
	muls r1, r0
	movs r3, 0x82
	lsls r3, 4
	adds r0, r2, r3
	adds r0, r1
	ldr r0, [r0]
	cmp r0, r5
	bne _08166174
	movs r0, 0x1
	b _08166182
	.pool
_08166174:
	movs r3, 0xE7
	lsls r3, 3
	adds r0, r1, r3
	adds r0, r2, r0
	bl ClearBattleTowerRecord
_08166180:
	movs r0, 0
_08166182:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_8166124

	thumb_func_start sub_8166188
sub_8166188: @ 8166188
	push {r4-r7,lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	ldr r1, =0x02000002
	ands r0, r1
	cmp r0, 0
	beq _081661E8
	bl GetFacilityEnemyMonLevel
	lsls r0, 24
	movs r5, 0
	ldr r7, =gBaseStats
	lsrs r0, 22
	ldr r1, =gExperienceTables
	adds r6, r0, r1
_081661A6:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gEnemyParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0
	beq _081661E2
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r7
	ldrb r1, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	adds r2, r1, 0
	muls r2, r0
	adds r2, r6
	adds r0, r4, 0
	movs r1, 0x19
	bl SetMonData
	adds r0, r4, 0
	bl CalculateMonStats
_081661E2:
	adds r5, 0x1
	cmp r5, 0x5
	ble _081661A6
_081661E8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8166188

	.align 2, 0 @ Don't pad with nop.
