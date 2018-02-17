	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GameClear
GameClear: @ 8137734
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x1C
	bl HealPlayerParty
	ldr r4, =0x00000864
	adds r0, r4, 0
	bl FlagGet
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _08137760
	ldr r0, =gHasHallOfFameRecords
	strb r1, [r0]
	b _0813776C
	.pool
_08137760:
	ldr r1, =gHasHallOfFameRecords
	movs r0, 0
	strb r0, [r1]
	adds r0, r4, 0
	bl FlagSet
_0813776C:
	movs r0, 0x1
	bl GetGameStat
	cmp r0, 0
	bne _0813778E
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldrh r1, [r2, 0xE]
	lsls r1, 16
	ldrb r0, [r2, 0x10]
	lsls r0, 8
	orrs r1, r0
	ldrb r0, [r2, 0x11]
	orrs r1, r0
	movs r0, 0x1
	bl SetGameStat
_0813778E:
	bl sub_8076D48
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	cmp r0, 0
	bne _081377AC
	movs r0, 0x1
	bl sub_8084F6C
	b _081377B2
	.pool
_081377AC:
	movs r0, 0x2
	bl sub_8084F6C
_081377B2:
	movs r7, 0
	movs r6, 0
	add r0, sp, 0x18
	mov r8, r0
	mov r5, sp
_081377BC:
	movs r0, 0x64
	adds r1, r6, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	movs r0, 0
	strb r6, [r5]
	strb r0, [r5, 0x1]
	adds r0, r4, 0
	movs r1, 0x5
	bl GetMonData
	cmp r0, 0
	beq _0813780A
	adds r0, r4, 0
	movs r1, 0x6
	bl GetMonData
	cmp r0, 0
	bne _0813780A
	adds r0, r4, 0
	movs r1, 0x43
	bl GetMonData
	cmp r0, 0
	bne _0813780A
	movs r0, 0x1
	mov r1, r8
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x43
	add r2, sp, 0x18
	bl SetMonData
	adds r0, r4, 0
	bl GetRibbonCount
	strb r0, [r5, 0x1]
	movs r7, 0x1
_0813780A:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0x5
	ble _081377BC
	cmp r7, 0x1
	bne _0813785A
	movs r0, 0x2A
	bl IncrementGameStat
	ldr r0, =0x0000089b
	bl FlagSet
	mov r3, sp
	add r2, sp, 0x4
	movs r6, 0x4
_08137828:
	ldrb r1, [r3, 0x1]
	ldrb r0, [r2, 0x1]
	cmp r0, r1
	bls _08137838
	ldr r1, [sp]
	ldr r0, [r2]
	str r0, [sp]
	str r1, [r2]
_08137838:
	adds r2, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _08137828
	mov r0, sp
	ldrb r0, [r0, 0x1]
	cmp r0, 0x4
	bls _0813785A
	mov r0, sp
	ldrb r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x43
	bl sub_80EE4DC
_0813785A:
	ldr r0, =CB2_DoHallOfFameScreen
	bl SetMainCallback2
	movs r0, 0
	add sp, 0x1C
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GameClear

	thumb_func_start sp0C8_whiteout_maybe
sp0C8_whiteout_maybe: @ 813787C
	push {lr}
	ldr r0, =CB2_WhiteOut
	bl SetMainCallback2
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sp0C8_whiteout_maybe
