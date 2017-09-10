	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

    
	thumb_func_start ClearRoamerData
ClearRoamerData: @ 8161B34
	push {r4,r5,lr}
	ldr r5, =gSaveBlock1Ptr
	ldr r0, [r5]
	ldr r4, =0x000031dc
	adds r0, r4
	movs r1, 0
	movs r2, 0x1C
	bl memset
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =0x00000197
	strh r1, [r0, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearRoamerData

	thumb_func_start ClearRoamerLocationData
ClearRoamerLocationData: @ 8161B60
	push {r4-r6,lr}
	movs r2, 0
	ldr r6, =sRoamerLocation
	ldr r4, =sLocationHistory
	movs r3, 0
	adds r5, r4, 0x1
_08161B6C:
	lsls r1, r2, 1
	adds r0, r1, r4
	strb r3, [r0]
	adds r1, r5
	strb r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x2
	bls _08161B6C
	movs r0, 0
	strb r0, [r6]
	strb r0, [r6, 0x1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearRoamerLocationData

	thumb_func_start CreateInitialRoamerMon
CreateInitialRoamerMon: @ 8161B94
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	lsls r0, 16
	cmp r0, 0
	bne _08161BBC
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x000031dc
	adds r1, r2
	ldr r2, =0x00000197
	b _08161BC8
	.pool
_08161BBC:
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r2, =0x000031dc
	adds r1, r2
	movs r2, 0xCC
	lsls r2, 1
_08161BC8:
	strh r2, [r1, 0x8]
	adds r7, r0, 0
	ldr r6, =gEnemyParty
	ldr r0, [r7]
	ldr r5, =0x000031dc
	adds r0, r5
	ldrh r1, [r0, 0x8]
	movs r4, 0
	str r4, [sp]
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	str r4, [sp, 0xC]
	adds r0, r6, 0
	movs r2, 0x28
	movs r3, 0x20
	bl CreateMon
	ldr r0, [r7]
	adds r0, r5
	movs r1, 0x28
	strb r1, [r0, 0xC]
	ldr r0, [r7]
	adds r0, r5
	strb r4, [r0, 0xD]
	ldr r0, [r7]
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0, 0x13]
	adds r0, r6, 0
	movs r1, 0x42
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	str r0, [r1]
	adds r0, r6, 0
	movs r1, 0
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	str r0, [r1, 0x4]
	adds r0, r6, 0
	movs r1, 0x3A
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	movs r2, 0
	mov r8, r2
	strh r0, [r1, 0xA]
	adds r0, r6, 0
	movs r1, 0x16
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0xE]
	adds r0, r6, 0
	movs r1, 0x17
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0xF]
	adds r0, r6, 0
	movs r1, 0x18
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0x10]
	adds r0, r6, 0
	movs r1, 0x21
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0x11]
	adds r0, r6, 0
	movs r1, 0x2F
	bl GetMonData
	ldr r1, [r7]
	adds r1, r5
	strb r0, [r1, 0x12]
	ldr r4, =sRoamerLocation
	mov r0, r8
	strb r0, [r4]
	bl Random
	ldr r5, =sRoamerLocations
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	adds r1, r5
	ldrb r0, [r1]
	strb r0, [r4, 0x1]
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateInitialRoamerMon

	thumb_func_start InitRoamer
InitRoamer: @ 8161CBC
	push {lr}
	bl ClearRoamerData
	bl ClearRoamerLocationData
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	bl CreateInitialRoamerMon
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitRoamer

	thumb_func_start UpdateLocationHistoryForRoamer
UpdateLocationHistoryForRoamer: @ 8161CD8
	ldr r0, =sLocationHistory
	ldrb r1, [r0, 0x2]
	strb r1, [r0, 0x4]
	ldrb r1, [r0, 0x3]
	strb r1, [r0, 0x5]
	ldrb r1, [r0]
	strb r1, [r0, 0x2]
	ldrb r1, [r0, 0x1]
	strb r1, [r0, 0x3]
	ldr r1, =gSaveBlock1Ptr
	ldr r2, [r1]
	ldrb r1, [r2, 0x4]
	strb r1, [r0]
	ldrb r1, [r2, 0x5]
	strb r1, [r0, 0x1]
	bx lr
	.pool
	thumb_func_end UpdateLocationHistoryForRoamer

	thumb_func_start RoamerMoveToOtherLocationSet
RoamerMoveToOtherLocationSet: @ 8161D00
	push {r4,r5,lr}
	movs r1, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r2, =0x000031dc
	adds r0, r2
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08161D3E
	ldr r0, =sRoamerLocation
	strb r1, [r0]
	ldr r5, =sRoamerLocations
	adds r4, r0, 0
_08161D1A:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x14
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 1
	adds r1, r5
	ldrb r1, [r1]
	ldrb r0, [r4, 0x1]
	cmp r0, r1
	beq _08161D1A
	strb r1, [r4, 0x1]
_08161D3E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RoamerMoveToOtherLocationSet

	thumb_func_start RoamerMove
RoamerMove: @ 8161D54
	push {r4-r7,lr}
	movs r4, 0
	bl Random
	lsls r0, 16
	movs r1, 0xF0
	lsls r1, 12
	ands r1, r0
	cmp r1, 0
	bne _08161D6E
	bl RoamerMoveToOtherLocationSet
	b _08161DE2
_08161D6E:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000031dc
	adds r0, r1
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08161DE2
	ldr r7, =sRoamerLocation
	ldr r3, =sRoamerLocations
_08161D80:
	lsls r0, r4, 1
	adds r0, r4
	lsls r2, r0, 1
	adds r1, r2, r3
	ldrb r0, [r7, 0x1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08161DD8
	ldr r6, =sRoamerLocations
	adds r5, r2, 0x1
	ldr r4, =sLocationHistory
_08161D96:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	adds r0, r5
	adds r0, r6
	ldrb r1, [r0]
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _08161DBA
	ldrb r0, [r4, 0x5]
	cmp r0, r1
	beq _08161D96
_08161DBA:
	cmp r1, 0xFF
	beq _08161D96
	strb r1, [r7, 0x1]
	b _08161DE2
	.pool
_08161DD8:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _08161D80
_08161DE2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end RoamerMove

	thumb_func_start IsRoamerAt
IsRoamerAt: @ 8161DE8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x000031dc
	adds r0, r3
	ldrb r0, [r0, 0x13]
	cmp r0, 0
	beq _08161E20
	ldr r0, =sRoamerLocation
	ldrb r3, [r0]
	cmp r2, r3
	bne _08161E20
	ldrb r0, [r0, 0x1]
	cmp r1, r0
	bne _08161E20
	movs r0, 0x1
	b _08161E22
	.pool
_08161E20:
	movs r0, 0
_08161E22:
	pop {r1}
	bx r1
	thumb_func_end IsRoamerAt

	thumb_func_start CreateRoamerMonInstance
CreateRoamerMonInstance: @ 8161E28
	push {r4,r5,lr}
	sub sp, 0x4
	ldr r5, =gEnemyParty
	bl ZeroEnemyPartyMons
	ldr r4, =gSaveBlock1Ptr
	ldr r0, [r4]
	ldr r1, =0x000031dc
	adds r0, r1
	ldrh r1, [r0, 0x8]
	ldrb r2, [r0, 0xC]
	ldr r3, [r0]
	ldr r0, [r0, 0x4]
	str r0, [sp]
	adds r0, r5, 0
	bl CreateMonWithIVsPersonality
	ldr r2, [r4]
	ldr r0, =0x000031e9
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x37
	bl SetMonData
	ldr r2, [r4]
	ldr r1, =0x000031e6
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0x39
	bl SetMonData
	ldr r2, [r4]
	ldr r0, =0x000031ea
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x16
	bl SetMonData
	ldr r2, [r4]
	ldr r1, =0x000031eb
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0x17
	bl SetMonData
	ldr r2, [r4]
	ldr r0, =0x000031ec
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x18
	bl SetMonData
	ldr r2, [r4]
	ldr r1, =0x000031ed
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0x21
	bl SetMonData
	ldr r2, [r4]
	ldr r0, =0x000031ee
	adds r2, r0
	adds r0, r5, 0
	movs r1, 0x2F
	bl SetMonData
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateRoamerMonInstance

	thumb_func_start TryStartRoamerEncounter
TryStartRoamerEncounter: @ 8161EDC
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	ldrb r1, [r1, 0x5]
	bl IsRoamerAt
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _08161F10
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	bne _08161F10
	bl CreateRoamerMonInstance
	movs r0, 0x1
	b _08161F12
	.pool
_08161F10:
	movs r0, 0
_08161F12:
	pop {r1}
	bx r1
	thumb_func_end TryStartRoamerEncounter

	thumb_func_start UpdateRoamerHPStatus
UpdateRoamerHPStatus: @ 8161F18
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r1, 0x39
	bl GetMonData
	ldr r5, =gSaveBlock1Ptr
	ldr r1, [r5]
	ldr r4, =0x000031dc
	adds r1, r4
	strh r0, [r1, 0xA]
	adds r0, r6, 0
	movs r1, 0x37
	bl GetMonData
	ldr r1, [r5]
	adds r1, r4
	strb r0, [r1, 0xD]
	bl RoamerMoveToOtherLocationSet
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UpdateRoamerHPStatus

	thumb_func_start SetRoamerInactive
SetRoamerInactive: @ 8161F4C
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x000031dc
	adds r0, r1
	movs r1, 0
	strb r1, [r0, 0x13]
	bx lr
	.pool
	thumb_func_end SetRoamerInactive

	thumb_func_start GetRoamerLocation
GetRoamerLocation: @ 8161F64
	ldr r3, =sRoamerLocation
	ldrb r2, [r3]
	strb r2, [r0]
	ldrb r0, [r3, 0x1]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end GetRoamerLocation

    
	.align 2, 0 @ Don't pad with nop.
