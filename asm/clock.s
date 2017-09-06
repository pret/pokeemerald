	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_809E778
sub_809E778: @ 809E778
	push {lr}
	ldr r0, =0x00000895
	bl FlagSet
	bl RtcCalcLocalTime
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	adds r2, 0xA0
	ldr r3, =gLocalTime
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r0, =0x00004040
	ldrh r1, [r3]
	bl VarSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E778

	thumb_func_start sub_809E7B0
sub_809E7B0: @ 809E7B0
	push {r4,lr}
	ldr r0, =0x00000895
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0809E7DA
	bl sub_813B9C0
	lsls r0, 24
	cmp r0, 0
	bne _0809E7DA
	bl RtcCalcLocalTime
	ldr r4, =gLocalTime
	adds r0, r4, 0
	bl sub_809E7E8
	adds r0, r4, 0
	bl sub_809E858
_0809E7DA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E7B0

	thumb_func_start sub_809E7E8
sub_809E7E8: @ 809E7E8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r0, =0x00004040
	bl GetVarPointer
	adds r6, r0, 0
	ldrh r0, [r6]
	movs r2, 0
	ldrsh r1, [r5, r2]
	cmp r0, r1
	beq _0809E84E
	cmp r0, r1
	bgt _0809E84E
	ldrh r4, [r5]
	subs r4, r0
	lsls r4, 16
	lsrs r4, 16
	bl ClearUpperFlags
	adds r0, r4, 0
	bl sub_8122580
	adds r0, r4, 0
	bl sub_80ED888
	adds r0, r4, 0
	bl sub_80AEFBC
	adds r0, r4, 0
	bl UpdatePartyPokerusTime
	adds r0, r4, 0
	bl sub_8137904
	adds r0, r4, 0
	bl sub_8137A20
	adds r0, r4, 0
	bl sub_8139EF4
	adds r0, r4, 0
	bl sub_813A7F4
	adds r0, r4, 0
	bl sub_813945C
	adds r0, r4, 0
	bl sub_8177584
	ldrh r0, [r5]
	strh r0, [r6]
_0809E84E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E7E8

	thumb_func_start sub_809E858
sub_809E858: @ 809E858
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	mov r4, sp
	ldr r6, =gSaveBlock2Ptr
	ldr r1, [r6]
	adds r1, 0xA0
	mov r0, sp
	adds r2, r5, 0
	bl CalcTimeDifference
	mov r0, sp
	movs r2, 0
	ldrsh r1, [r0, r2]
	lsls r0, r1, 1
	adds r0, r1
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	movs r2, 0x2
	ldrsb r2, [r4, r2]
	lsls r0, r2, 4
	subs r0, r2
	lsls r0, 2
	adds r1, r0
	movs r0, 0x3
	ldrsb r0, [r4, r0]
	adds r0, r1, r0
	cmp r0, 0
	beq _0809E8A8
	cmp r0, 0
	blt _0809E8A8
	bl BerryTreeTimeUpdate
	ldr r2, [r6]
	adds r2, 0xA0
	ldr r0, [r5]
	ldr r1, [r5, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
_0809E8A8:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E858

	thumb_func_start sub_809E8B4
sub_809E8B4: @ 809E8B4
	push {lr}
	bl sub_809E778
	ldr r0, =c2_exit_to_overworld_1_continue_scripts_restart_music
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809E8B4

	thumb_func_start Special_StartWallClock
Special_StartWallClock: @ 809E8C8
	push {lr}
	ldr r0, =Cb2_StartWallClock
	bl SetMainCallback2
	ldr r1, =gMain
	ldr r0, =sub_809E8B4
	str r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end Special_StartWallClock

	.align 2, 0 @ Don't pad with nop.
