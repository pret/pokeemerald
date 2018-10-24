	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




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
	bl SetFacilityPtrsGetLevel
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
