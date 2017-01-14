	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80E15B8
sub_80E15B8: @ 80E15B8
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x000031f8
	adds r1, r0
	ldr r2, =0x0100001a
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E15B8

	thumb_func_start sub_80E15E4
sub_80E15E4: @ 80E15E4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000031f8
	adds r3, r0, r1
	movs r2, 0
_080E15F2:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x33
	bls _080E15F2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80E15E4

	thumb_func_start sub_80E1610
sub_80E1610: @ 80E1610
	push {lr}
	adds r3, r0, 0
	movs r2, 0
	movs r1, 0
_080E1618:
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r2, r0
	adds r1, 0x1
	cmp r1, 0x2F
	bls _080E1618
	adds r0, r2, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80E1610

	thumb_func_start sub_80E162C
sub_80E162C: @ 80E162C
	push {r4,lr}
	ldr r4, =gSaveBlock1Ptr
	ldr r1, [r4]
	ldr r2, =0x0000320c
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E1674
	ldr r2, =0x00003202
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _080E1674
	ldr r2, =0x000031f8
	adds r0, r1, r2
	bl sub_80E1610
	ldr r1, [r4]
	ldr r2, =0x00003228
	adds r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _080E1674
	movs r0, 0x1
	b _080E1676
	.pool
_080E1674:
	movs r0, 0
_080E1676:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80E162C

	thumb_func_start GetBerryInfo
@ struct berry_info *GetBerryInfo(u8 berryType)
GetBerryInfo: @ 80E167C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2B
	bne _080E16A0
	bl sub_80E162C
	cmp r0, 0
	beq _080E16A0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000031f8
	b _080E16B4
	.pool
_080E16A0:
	subs r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2A
	bls _080E16AC
	movs r4, 0x1
_080E16AC:
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	ldr r1, =gBerries - 0x1c @ 1-based array
_080E16B4:
	adds r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBerryInfo

	thumb_func_start GetBerryTreeInfo
@ struct BerryTreeInfo *GetBerryTreeInfo(u8 berryTreeId)
GetBerryTreeInfo: @ 80E16C0
	lsls r0, 24
	ldr r1, =gSaveBlock1Ptr
	lsrs r0, 21
	ldr r2, =0x0000169c
	adds r0, r2
	ldr r1, [r1]
	adds r1, r0
	adds r0, r1, 0
	bx lr
	.pool
	thumb_func_end GetBerryTreeInfo

	thumb_func_start FieldObjectInteractionWaterBerryTree
@ bool8 FieldObjectInteractionWaterBerryTree()
FieldObjectInteractionWaterBerryTree: @ 80E16DC
	push {lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryTreeInfo
	adds r2, r0, 0
	ldrb r0, [r2, 0x1]
	lsls r0, 25
	lsrs r0, 25
	cmp r0, 0x2
	beq _080E1718
	cmp r0, 0x2
	bgt _080E1708
	cmp r0, 0x1
	beq _080E1712
	b _080E172E
	.pool
_080E1708:
	cmp r0, 0x3
	beq _080E171E
	cmp r0, 0x4
	beq _080E1724
	b _080E172E
_080E1712:
	ldrb r0, [r2, 0x5]
	movs r1, 0x10
	b _080E1728
_080E1718:
	ldrb r0, [r2, 0x5]
	movs r1, 0x20
	b _080E1728
_080E171E:
	ldrb r0, [r2, 0x5]
	movs r1, 0x40
	b _080E1728
_080E1724:
	ldrb r0, [r2, 0x5]
	movs r1, 0x80
_080E1728:
	orrs r0, r1
	strb r0, [r2, 0x5]
	b _080E1732
_080E172E:
	movs r0, 0
	b _080E1734
_080E1732:
	movs r0, 0x1
_080E1734:
	pop {r1}
	bx r1
	thumb_func_end FieldObjectInteractionWaterBerryTree

	thumb_func_start IsPlayerFacingPlantedBerryTree
@ bool8 IsPlayerFacingPlantedBerryTree()
IsPlayerFacingPlantedBerryTree: @ 80E1738
	push {lr}
	bl GetFieldObjectScriptPointerForComparison
	ldr r1, =gUnknown_082742F9
	cmp r0, r1
	bne _080E1768
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	bl GetStageByBerryTreeId
	lsls r0, 24
	cmp r0, 0
	bne _080E1768
	movs r0, 0x1
	b _080E176A
	.pool
_080E1768:
	movs r0, 0
_080E176A:
	pop {r1}
	bx r1
	thumb_func_end IsPlayerFacingPlantedBerryTree

	thumb_func_start WaterBerryTree
@ bool8 WaterBerryTree()
WaterBerryTree: @ 80E1770
	push {lr}
	bl GetFieldObjectScriptPointerForComparison
	ldr r1, =gUnknown_082742F9
	cmp r0, r1
	bne _080E178C
	bl FieldObjectInteractionWaterBerryTree
	lsls r0, 24
	lsrs r0, 24
	b _080E178E
	.pool
_080E178C:
	movs r0, 0
_080E178E:
	pop {r1}
	bx r1
	thumb_func_end WaterBerryTree

	thumb_func_start RemoveAllBerryTrees
@ void RemoveAllBerryTrees()
RemoveAllBerryTrees: @ 80E1794
	push {r4-r6,lr}
	movs r2, 0
	ldr r6, =gSaveBlock1Ptr
	ldr r5, =0x0000169c
	ldr r0, =gUnknown_0858ABD0
	ldr r3, [r0]
	ldr r4, [r0, 0x4]
_080E17A2:
	ldr r0, [r6]
	lsls r1, r2, 3
	adds r0, r1
	adds r0, r5
	str r3, [r0]
	str r4, [r0, 0x4]
	adds r2, 0x1
	cmp r2, 0x7F
	ble _080E17A2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveAllBerryTrees

	thumb_func_start BerryTreeGrow
@ bool8 BerryTreeGrow(struct BerryTreeInfo *berryTree)
BerryTreeGrow: @ 80E17C8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r1, [r4, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080E17DA
_080E17D6:
	movs r0, 0
	b _080E1866
_080E17DA:
	lsls r0, r1, 25
	lsrs r0, 25
	cmp r0, 0x5
	bhi _080E1864
	lsls r0, 2
	ldr r1, =_080E17F0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080E17F0:
	.4byte _080E17D6
	.4byte _080E1810
	.4byte _080E1810
	.4byte _080E1810
	.4byte _080E1808
	.4byte _080E1828
_080E1808:
	adds r0, r4, 0
	bl CalcBerryYield
	strb r0, [r4, 0x4]
_080E1810:
	ldrb r2, [r4, 0x1]
	lsls r1, r2, 25
	lsrs r1, 25
	adds r1, 0x1
	movs r0, 0x7F
	ands r1, r0
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x1]
	b _080E1864
_080E1828:
	ldrb r0, [r4, 0x5]
	movs r1, 0x11
	negs r1, r1
	ands r1, r0
	movs r0, 0x21
	negs r0, r0
	ands r1, r0
	subs r0, 0x20
	ands r1, r0
	movs r0, 0x7F
	ands r1, r0
	movs r0, 0
	strb r0, [r4, 0x4]
	ldrb r2, [r4, 0x1]
	subs r0, 0x80
	ands r0, r2
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r4, 0x1]
	adds r1, 0x1
	movs r0, 0xF
	ands r1, r0
	strb r1, [r4, 0x5]
	cmp r1, 0xA
	bne _080E1864
	ldr r0, =gUnknown_0858ABD0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r4]
	str r1, [r4, 0x4]
_080E1864:
	movs r0, 0x1
_080E1866:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end BerryTreeGrow

	thumb_func_start BerryTreeTimeUpdate
@ void BerryTreeTimeUpdate(s32 deltaSeconds)
BerryTreeTimeUpdate: @ 80E1870
	push {r4-r7,lr}
	adds r6, r0, 0
	movs r2, 0
_080E1876:
	ldr r1, =gSaveBlock1Ptr
	lsls r0, r2, 3
	ldr r3, =0x0000169c
	adds r0, r3
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	adds r7, r2, 0x1
	cmp r0, 0
	beq _080E1910
	ldrb r1, [r4, 0x1]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0
	beq _080E1910
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080E1910
	ldrb r0, [r4]
	bl GetStageDurationByBerryType
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 3
	subs r1, r0
	cmp r6, r1
	blt _080E18CC
	ldr r0, =gUnknown_0858ABD0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r4]
	str r1, [r4, 0x4]
	b _080E1910
	.pool
_080E18CC:
	adds r5, r6, 0
	cmp r5, 0
	beq _080E1910
	ldrh r1, [r4, 0x2]
	cmp r1, r5
	ble _080E18DC
	subs r0, r1, r5
	b _080E190E
_080E18DC:
	subs r5, r1
	ldrb r0, [r4]
	bl GetStageDurationByBerryType
	strh r0, [r4, 0x2]
	adds r0, r4, 0
	bl BerryTreeGrow
	cmp r0, 0
	beq _080E1910
	ldrb r1, [r4, 0x1]
	movs r0, 0x7F
	ands r0, r1
	cmp r0, 0x5
	bne _080E1900
	ldrh r0, [r4, 0x2]
	lsls r0, 2
	strh r0, [r4, 0x2]
_080E1900:
	cmp r5, 0
	beq _080E1910
	ldrh r0, [r4, 0x2]
	adds r1, r0, 0
	cmp r0, r5
	ble _080E18DC
	subs r0, r5
_080E190E:
	strh r0, [r4, 0x2]
_080E1910:
	adds r2, r7, 0
	cmp r2, 0x7F
	ble _080E1876
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end BerryTreeTimeUpdate

	thumb_func_start PlantBerryTree
@ void PlantBerryTree(u8 berryTreeId, u8 berryType, u8 stage, u8 a4)
PlantBerryTree: @ 80E191C
	push {r4-r7,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r3, 24
	lsrs r7, r3, 24
	bl GetBerryTreeInfo
	adds r6, r0, 0
	ldr r0, =gUnknown_0858ABD0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r6]
	str r1, [r6, 0x4]
	strb r4, [r6]
	adds r0, r4, 0
	bl GetStageDurationByBerryType
	strh r0, [r6, 0x2]
	movs r1, 0x7F
	ands r1, r5
	ldrb r2, [r6, 0x1]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x1]
	cmp r5, 0x5
	bne _080E196E
	adds r0, r6, 0
	bl CalcBerryYield
	strb r0, [r6, 0x4]
	ldrh r0, [r6, 0x2]
	lsls r0, 2
	strh r0, [r6, 0x2]
_080E196E:
	cmp r7, 0
	bne _080E197A
	ldrb r0, [r6, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r6, 0x1]
_080E197A:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PlantBerryTree

	thumb_func_start RemoveBerryTree
@ void RemoveBerryTree(u8 berryTreeId)
RemoveBerryTree: @ 80E1984
	lsls r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	lsrs r0, 21
	adds r2, r0
	ldr r0, =0x0000169c
	adds r2, r0
	ldr r0, =gUnknown_0858ABD0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end RemoveBerryTree

	thumb_func_start GetBerryTypeByBerryTreeId
@ u8 GetBerryTypeByBerryTreeId(u8 berryTreeId)
GetBerryTypeByBerryTreeId: @ 80E19AC
	lsls r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	lsrs r0, 21
	adds r1, r0
	ldr r0, =0x0000169c
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end GetBerryTypeByBerryTreeId

	thumb_func_start GetStageByBerryTreeId
@ u8 GetStageByBerryTreeId(u8 berryTreeId)
GetStageByBerryTreeId: @ 80E19C8
	lsls r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	lsrs r0, 21
	adds r1, r0
	ldr r0, =0x0000169d
	adds r1, r0
	ldrb r0, [r1]
	lsls r0, 25
	lsrs r0, 25
	bx lr
	.pool
	thumb_func_end GetStageByBerryTreeId

	thumb_func_start ItemIdToBerryType
@ u8 ItemIdToBerryType(u16 itemId)
ItemIdToBerryType: @ 80E19E8
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =0xff7b0000
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0x2A
	bhi _080E1A08
	adds r0, r1, 0
	adds r0, 0x7C
	lsls r0, 24
	lsrs r0, 24
	b _080E1A0A
	.pool
_080E1A08:
	movs r0, 0x1
_080E1A0A:
	pop {r1}
	bx r1
	thumb_func_end ItemIdToBerryType

	thumb_func_start BerryTypeToItemId
@ u16 BerryTypeToItemId(u16 berryType)
BerryTypeToItemId: @ 80E1A10
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r2, =0xffff0000
	adds r0, r2
	lsrs r0, 16
	cmp r0, 0x2A
	bhi _080E1A30
	adds r0, r1, 0
	adds r0, 0x84
	lsls r0, 16
	lsrs r0, 16
	b _080E1A32
	.pool
_080E1A30:
	movs r0, 0x85
_080E1A32:
	pop {r1}
	bx r1
	thumb_func_end BerryTypeToItemId

	thumb_func_start GetBerryNameByBerryType
@ void GetBerryNameByBerryType(u8 berryType, u8 *dest)
GetBerryNameByBerryType: @ 80E1A38
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryInfo
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0x6
	bl memcpy
	movs r0, 0xFF
	strb r0, [r4, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetBerryNameByBerryType

	thumb_func_start GetBerryCountStringByBerryType
@ void GetBerryCountStringByBerryType(u8 berryType, u8 *dest, u32 berryCount)
GetBerryCountStringByBerryType: @ 80E1A58
	push {r4,r5,lr}
	adds r4, r1, 0
	adds r5, r2, 0
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryInfo
	adds r1, r0, 0
	adds r0, r4, 0
	adds r2, r5, 0
	bl GetBerryCountString
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end GetBerryCountStringByBerryType

	thumb_func_start ResetBerryTreeSparkleFlag
@ void ResetBerryTreeSparkleFlag(u8 berryTreeId)
ResetBerryTreeSparkleFlag: @ 80E1A78
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryTreeInfo
	ldrb r2, [r0, 0x1]
	movs r1, 0x7F
	ands r1, r2
	strb r1, [r0, 0x1]
	pop {r0}
	bx r0
	thumb_func_end ResetBerryTreeSparkleFlag

	thumb_func_start BerryTreeGetNumStagesWatered
@ u8 BerryTreeGetNumStagesWatered(struct BerryTreeInfo *berryTree)
BerryTreeGetNumStagesWatered: @ 80E1A90
	push {lr}
	ldrb r2, [r0, 0x5]
	movs r0, 0x10
	ands r0, r2
	lsls r0, 24
	lsrs r0, 24
	negs r0, r0
	lsrs r1, r0, 31
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _080E1AAA
	adds r1, 0x1
_080E1AAA:
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _080E1AB8
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
_080E1AB8:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _080E1AC6
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
_080E1AC6:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end BerryTreeGetNumStagesWatered

	thumb_func_start GetNumStagesWateredByBerryTreeId
@ u8 GetNumStagesWateredByBerryTreeId(u8 berryTreeId)
GetNumStagesWateredByBerryTreeId: @ 80E1ACC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryTreeInfo
	bl BerryTreeGetNumStagesWatered
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end GetNumStagesWateredByBerryTreeId

	thumb_func_start CalcBerryYieldInternal
@ u8 CalcBerryYieldInternal(u16 max, u16 min, u8 numStagesWatered)
CalcBerryYieldInternal: @ 80E1AE4
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r2, 24
	lsrs r2, 24
	cmp r2, 0
	bne _080E1AFA
	lsls r0, r6, 24
	b _080E1B2E
_080E1AFA:
	subs r1, r0, r6
	subs r0, r2, 0x1
	adds r5, r1, 0
	muls r5, r0
	adds r4, r1, 0
	muls r4, r2
	bl GenerateRandomNumber
	lsls r0, 16
	lsrs r0, 16
	subs r4, r5
	adds r4, 0x1
	adds r1, r4, 0
	bl __umodsi3
	adds r5, r0
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0x1
	bls _080E1B28
	lsrs r0, r5, 2
	adds r0, 0x1
	b _080E1B2A
_080E1B28:
	lsrs r0, r5, 2
_080E1B2A:
	adds r0, r6
	lsls r0, 24
_080E1B2E:
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CalcBerryYieldInternal

	thumb_func_start CalcBerryYield
@ u8 CalcBerryYield(struct BerryTreeInfo *berryTree)
CalcBerryYield: @ 80E1B38
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrb r0, [r4]
	bl GetBerryInfo
	ldrb r6, [r0, 0xB]
	ldrb r5, [r0, 0xA]
	adds r0, r4, 0
	bl BerryTreeGetNumStagesWatered
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r6, 0
	bl CalcBerryYieldInternal
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CalcBerryYield

	thumb_func_start GetBerryCountByBerryTreeId
@ u8 GetBerryCountByBerryTreeId(u8 berryTreeId)
GetBerryCountByBerryTreeId: @ 80E1B64
	lsls r0, 24
	ldr r1, =gSaveBlock1Ptr
	ldr r1, [r1]
	lsrs r0, 21
	adds r1, r0
	movs r0, 0xB5
	lsls r0, 5
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end GetBerryCountByBerryTreeId

	thumb_func_start GetStageDurationByBerryType
@ u16 GetStageDurationByBerryType(u8 berryType)
GetStageDurationByBerryType: @ 80E1B7C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryInfo
	ldrb r1, [r0, 0x14]
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 18
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end GetStageDurationByBerryType

	thumb_func_start FieldObjectInteractionGetBerryTreeData
@ void FieldObjectInteractionGetBerryTreeData()
FieldObjectInteractionGetBerryTreeData: @ 80E1B94
	push {r4-r6,lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl GetBerryTypeByBerryTreeId
	lsls r0, 24
	lsrs r6, r0, 24
	adds r0, r5, 0
	bl ResetBerryTreeSparkleFlag
	ldr r0, =gUnknown_020375F2
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl sub_8092E9C
	lsls r0, 24
	cmp r0, 0
	beq _080E1BE0
	ldr r1, =gUnknown_020375E0
	movs r0, 0xFF
	strh r0, [r1]
	b _080E1BEE
	.pool
_080E1BE0:
	ldr r4, =gUnknown_020375E0
	adds r0, r5, 0
	bl GetStageByBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
_080E1BEE:
	ldr r4, =gUnknown_020375E2
	adds r0, r5, 0
	bl GetNumStagesWateredByBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r4, =gUnknown_020375E4
	adds r0, r5, 0
	bl GetBerryCountByBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	ldr r1, =gStringVar1
	ldrh r2, [r4]
	adds r0, r6, 0
	bl GetBerryCountStringByBerryType
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectInteractionGetBerryTreeData

	thumb_func_start FieldObjectInteractionGetBerryName
@ void FieldObjectInteractionGetBerryName()
FieldObjectInteractionGetBerryName: @ 80E1C2C
	push {lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	bl GetBerryTypeByBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar1
	bl GetBerryNameByBerryType
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectInteractionGetBerryName

	thumb_func_start FieldObjectInteractionGetBerryCountString
@ void FieldObjectInteractionGetBerryCountString()
FieldObjectInteractionGetBerryCountString: @ 80E1C54
	push {r4,r5,lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl GetBerryTypeByBerryTreeId
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r4, 0
	bl GetBerryCountByBerryTreeId
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetBerryCountStringByBerryType
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectInteractionGetBerryCountString

	thumb_func_start ChooseBerry
@ void ChooseBerry()
ChooseBerry: @ 80E1C94
	push {lr}
	ldr r0, =CB2_ChooseBerry
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end ChooseBerry

	thumb_func_start FieldObjectInteractionPlantBerryTree
@ void FieldObjectInteractionPlantBerryTree()
FieldObjectInteractionPlantBerryTree: @ 80E1CA4
	push {r4,lr}
	ldr r0, =gUnknown_0203CE7C
	ldrh r0, [r0]
	bl ItemIdToBerryType
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x1
	bl PlantBerryTree
	bl FieldObjectInteractionGetBerryTreeData
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectInteractionPlantBerryTree

	thumb_func_start FieldObjectInteractionPickBerryTree
@ void FieldObjectInteractionPickBerryTree()
FieldObjectInteractionPickBerryTree: @ 80E1CDC
	push {r4-r6,lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl GetBerryTypeByBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_020375E0
	bl BerryTypeToItemId
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	bl GetBerryCountByBerryTreeId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl bag_add_item
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectInteractionPickBerryTree

	thumb_func_start FieldObjectInteractionRemoveBerryTree
@ void FieldObjectInteractionRemoveBerryTree()
FieldObjectInteractionRemoveBerryTree: @ 80E1D28
	push {lr}
	ldr r0, =gUnknown_03005DF0
	ldrb r0, [r0]
	bl FieldObjectGetBerryTreeId
	lsls r0, 24
	lsrs r0, 24
	bl RemoveBerryTree
	ldr r0, =gUnknown_020375F2
	ldrb r0, [r0]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x5]
	ldrb r2, [r2, 0x4]
	bl sub_8092EF0
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldObjectInteractionRemoveBerryTree

	thumb_func_start PlayerHasBerries
@ bool8 PlayerHasBerries()
PlayerHasBerries: @ 80E1D5C
	push {lr}
	movs r0, 0x4
	bl IsBagPocketNonEmpty
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end PlayerHasBerries

	thumb_func_start ResetBerryTreeSparkleFlags
@ void ResetBerryTreeSparkleFlags()
ResetBerryTreeSparkleFlags: @ 80E1D6C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl GetCameraCoords
	mov r0, sp
	ldrh r2, [r0]
	ldrh r1, [r4]
	adds r1, 0x3
	adds r3, r2, 0
	adds r3, 0xE
	lsls r1, 16
	movs r5, 0x80
	lsls r5, 12
	adds r0, r1, r5
	lsrs r0, 16
	mov r10, r0
	mov r5, sp
	lsls r2, 16
	asrs r2, 16
	mov r9, r2
	ldr r4, =gUnknown_02037350
	lsls r3, 16
	asrs r3, 16
	mov r8, r3
	asrs r7, r1, 16
	movs r6, 0xF
_080E1DB0:
	ldrb r0, [r4]
	lsls r0, 31
	cmp r0, 0
	beq _080E1DEC
	ldrb r0, [r4, 0x6]
	cmp r0, 0xC
	bne _080E1DEC
	ldrh r0, [r4, 0x10]
	strh r0, [r5]
	ldrh r0, [r4, 0x12]
	mov r1, sp
	strh r0, [r1, 0x2]
	movs r2, 0
	ldrsh r1, [r5, r2]
	cmp r9, r1
	bgt _080E1DEC
	cmp r1, r8
	bgt _080E1DEC
	lsls r0, 16
	asrs r1, r0, 16
	cmp r7, r1
	bgt _080E1DEC
	mov r2, r10
	lsls r0, r2, 16
	asrs r0, 16
	cmp r1, r0
	bgt _080E1DEC
	ldrb r0, [r4, 0x1D]
	bl ResetBerryTreeSparkleFlag
_080E1DEC:
	adds r4, 0x24
	subs r6, 0x1
	cmp r6, 0
	bge _080E1DB0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetBerryTreeSparkleFlags

	.align 2, 0 @ Don't pad with nop.
